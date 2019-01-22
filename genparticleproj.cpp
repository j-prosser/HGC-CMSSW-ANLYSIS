
/* C++ */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <getopt.h>

/* ROOT */
#include <TString.h>
#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TApplication.h>
#include <TH1.h>
#include <TH2.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TCanvas.h>
#include <TList.h>
#include <TF1.h>
#include <TLine.h>

/* myIncludes*/
#include "HGCgeom.h"
#include "HistoContainer.h"
#include "HGC.h"
#include "HGCTC.h"
#include "HGCC2D.h"
#include "HGCROC.h"
//#include "Ntuplizer.h"
#include "HGCht.h"

const bool flagTCs = true;
const bool flagC2D = true;
const bool flagC3D = true;
const bool flagGen = true;
const bool flagGenPart = false;
vector<double> _energy_gen;
vector<double> _pt_gen;
vector<double> _energy_mes;

double mean(vector<double> vec) {
		double sum = 0;
		for (unsigned i=0; i< vec.size(); i++) {
				sum += vec.at(i);
		}
		double mean = sum / vec.size();
		return mean;
}


int main(int argc, char **argv){

    /* PARSING THE COMMAND LINE ARGUMENTS */
    int opt;

    // files and event control
    TString fFileListName;
    TString inputFileName;
    TString outputFileName("tmp.root");
    int nEvt = -1;
    int firstEvent=0;

    const struct option longOptions[] = {
        {"help",         no_argument,        0, 'h'},
        {"fileList",     required_argument,  0, 'f'},
        {"iFile",        required_argument,  0, 'i'},
        {"oFile",        required_argument,  0, 'o'},
        {"firstEvent",   required_argument,  0, 'd'},
        {"nEvt",         required_argument,  0, 'n'},
        {"nPhiSectors",  required_argument,  0, 's'}
    };

    int optIndex = 0;
    while ( (opt = getopt_long (argc, argv, "hf:i:o:d:n:s", longOptions, &optIndex) ) != -1 ) {
        
        switch (opt)
        {
        case 'h':
            cout << "Help" << endl;
            cout << " -h(--help        ) :\t shows this help" << endl; 
            cout << " -f(--fileList    ) <files> :\t list of files to be processed" << endl; 
            cout << " -i(--iFile       ) <ifile> :\t single file input" << endl; 
            cout << " -o(--oFile       ) <ofile> :\t output file" << endl; 
            cout << " -d(--firstEvent  ) <firstEvent> :\t first event to be processed (default: 0)" << endl;
            cout << " -n(--nEvt        ) <nEvt> :\t number of events to be processed (default: all)" << endl;
            return 0;
            break;
        case 'f':
            fFileListName = optarg;
            break;
        case 'i':
            inputFileName = optarg;
            break;
	case 'o':
            outputFileName = optarg;
            break;
	case 'n':
            nEvt = atoi( optarg );
            break;
        case 'd':
            firstEvent = atoi( optarg );
            break;            
        default:
            return 0;
        }
    }
    
    cout << "Options "           << endl;
    cout << "  File List Name: " << fFileListName  << endl;
    cout << "  firstEvent: "     << firstEvent     << endl;
    cout << "  nEvts: "          << nEvt           << endl;
    cout << "  OutputFile: "     << outputFileName << endl;
    cout << "  InputFile: "      << inputFileName  << endl;

    /****************/
    /* OPEN fileOUT */

    TFile* fileOut = new TFile( outputFileName, "recreate" ); 

    /***************************************/
    /* get the files and fill the detector */

    TList *fList = new TList();

    if( fFileListName != "" ) {
        ifstream fFileList( fFileListName );    
        string line;
        while( getline( fFileList, line ) ){
            fList->Add( new TObjString( TString(line) ) );
        }
    }
    else {
        fList->Add( new TObjString( inputFileName ) );
    }

    /* build the detector */
    HGC detector( fList, 
                  flagTCs, flagC2D, flagC3D, flagGen, flagGenPart, 
                  true 
        );   


    /********************/
    /* Loop Over Events */
    unsigned totalEvt = detector.getEvents();
    nEvt = (nEvt==-1) ? totalEvt : nEvt;
	std::cout << "events:  " << nEvt << std::endl;

    for( int ievt=firstEvent; ievt<(firstEvent+nEvt); ievt++ ){

        /* Get Entry */
        std::cout << " MAIN >> getting event " << ievt << std::endl;
        detector.getEvent( ievt );
		/* Loop over both endcaps*/

		for (unsigned i=0; i<2; i++) {
				HGCsubdet* subdetector = detector.getSubdet(i, 3);
				vector<HGCgen*> gens = subdetector->getGenAll();
			
				HGCgen* gen = gens.at(0);
				vector<const HGCTC*> TCs = subdetector->getAll<HGCTC>();
				vector<double> tc_energies_0;
				vector<double> tc_energies_1;

				for (unsigned i=0; i<TCs.size(); i++) {
						if (TCs.at(i)->zside() == -1) {
								tc_energies_0.push_back(TCs.at(i)->Pt());
						} else {
								tc_energies_1.push_back(TCs.at(i)->Pt());
						}
				}

								
				/*print the event data for debugging*/
				if (42) {
					std::cout << "Endcap: " << gen->getEndcapId() << std::endl;
					std::cout << "Eta: " << gen->Eta() << std::endl;
					std::cout << "Phi: " << gen->Phi() << std::endl;
					std::cout << "Xn: " << gen->xNorm() << std::endl;
					std::cout << "Yn: " << gen->yNorm() << std::endl;
					std::cout << "Pt: " << gen->Pt() << std::endl;
					std::cout << "Energy: " << gen->Energy() << std::endl;
					if (i == 1) {
						std::cout << "Pt_measured: " << accumulate(tc_energies_0.begin(), tc_energies_0.end(), 0.0) << std::endl;
						_energy_mes.push_back(accumulate(tc_energies_0.begin(), tc_energies_0.end(), 0.0));
					} else { 
						std::cout << "Pt_measured: " << accumulate(tc_energies_1.begin(), tc_energies_1.end(), 0.0) << std::endl;
						_energy_mes.push_back(accumulate(tc_energies_1.begin(), tc_energies_1.end(), 0.0));

					}
							
				}
				//save pt and energy data into list
				_energy_gen.push_back(gen->Energy());
				_pt_gen.push_back(gen->Pt());
		}

    } // end of evt loop

	//print mean of energies and pts for debugging. WHY ARE THEY DIFFERENT FOR GAMMA INPUT?
	if (42) {
		std::cout << "Pt_mean: " << mean(_pt_gen) << std::endl;
		std::cout << "pt_measured_mean: " << mean(_energy_mes) << std::endl;
	}
    return 0;

}




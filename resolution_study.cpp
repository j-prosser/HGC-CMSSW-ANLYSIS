
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

int main(int argc, char **argv){

    /* PARSING THE COMMAND LINE ARGUMENTS */
    int opt;

    // files and event control
    TString fFileListName;
    TString inputFileName;
    TString outputFileName("tmp.root");
    int nEvt = -1;
    int firstEvent=0;
    unsigned nPhiSectors=32; 
    unsigned nLongitudinalSections=4;
    unsigned nNNsearch=9, nNNsum=0;
 
	float c3dRadius = 0.1; 
    
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
    
    // gen 
    TGraph gGenProjXY[HGCgeom::instance()->		nEndcaps()][nLongitudinalSections][nPhiSectors];
    TGraph gGenProjXYnorm[HGCgeom::instance()->	nEndcaps()][nLongitudinalSections][nPhiSectors];
 
	
	// C3D
    double nC3D[nEvt][HGCgeom::instance()->nEndcaps()]; // [events][endcaps (f/b)]  

    TGraph gC3DProjXYnorm[HGCgeom::instance()->nEndcaps()][nLongitudinalSections][nPhiSectors];

    /*********/
    /* trees */
    TTree *tNewC3Ds = new TTree( "newC3Ds", "newC3Ds" );
//    TTree *tForestC3Ds = new TTree( "forestC3Ds", "forestC3Ds" );
//    TTree *tC3DsSingle = new TTree( "C3DsSingle", "C3DsSingle" );

    vector<HGCC3D> newC3Ds[2];
//    vector<HGCC3D> forestC3Ds[2];
//    vector<HGCC3D> C3DsSingle[2];

    tNewC3Ds->Branch( "endcap0", &newC3Ds[0], 64000, 1);
    tNewC3Ds->Branch( "endcap1", &newC3Ds[1], 64000, 1);
    /********************/
    /* Loop Over Events */
    unsigned totalEvt = detector.getEvents();
    nEvt = (nEvt==-1) ? totalEvt : nEvt;

    for( int ievt=firstEvent; ievt<(firstEvent+nEvt); ievt++ ){
		
		/******BUILD DIR HIERARCHY******/
        /* make a directory for this event and the phi sector in iFile */
/*        TDirectory* eventDir;
        if( saveEventByEvent ){
            eventDir = fileOut->mkdir( Frm("event_%d"i, ievt) );
            
            fileOut->mkdir( Form("event_%d/endcap_0/", ievt) );
            fileOut->mkdir( Form("event_%d/endcap_1/", ievt) );
            
            for(unsigned isection=0; isection<nLongitudinalSections; isection++){
                // new folder for phi sector
                fileOut->mkdir( Form("event_%d/endcap_0/section_%d/", ievt, isection) );
                fileOut->mkdir( Form("event_%d/endcap_1/section_%d/", ievt, isection) );
                
                for(unsigned isector=0; isector<nPhiSectors; isector++){   
                    fileOut->mkdir( Form("event_%d/endcap_0/section_%d/sector_%d/", ievt, isection, isector) );
                    fileOut->mkdir( Form("event_%d/endcap_1/section_%d/sector_%d/", ievt, isection, isector) );
                    
                }
                
            }
            
            eventDir->cd();
            
        }
*/

        /* Get Entry */
        std::cout << " MAIN >> getting event " << ievt << std::endl;
        detector.getEvent( ievt );


		/// endcap loop
        for(unsigned iendcap=0; iendcap<HGCgeom::instance()->nEndcaps(); iendcap++) {
		// For each section in iendcap
		for(unsigned isection=0; isection<nLongitudinalSections; isection++){
		
			// Routine here below resembles HGCsubdet::getGenC3D, but for TC not C2D
			// 

			//HGCsubdet* subdector = detector.getSubdet(iendcap, isection); 
		

			/* polarFWtc routine */
			if (isection == 3) { // only full system

			unsigned binSums[36] = { 

				13,                                           // 0
				11, 11, 11,                                   // 1 - 3
				9, 9, 9,                                      // 4 - 6
				7, 7, 7, 7, 7, 7,                             // 7 - 12
				5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,  //13 - 27
				3, 3, 3, 3, 3, 3, 3, 3                        //28 - 35

			};

			HGCpolarHisto<HGCTC> grid = detector.getSubdet(iendcap, isection)->getPolarFwC3D<HGCTC>( c3dRadius );
			newC3Ds[iendcap] = grid.getNewC3Ds( c3dRadius, binSums );

			for(unsigned ic3d=0; ic3d<newC3Ds[iendcap].size(); ++ic3d) {
				newC3Ds[iendcap].at(ic3d).setNearestGen( detector.getGenAll() );
				//Calc energy resolution here(?) 
				//
				cout << "iec:"<< iendcap << "\tnC3D: " << newC3Ds[iendcap].size() << endl;
				newC3Ds[iendcap].at(ic3d).print();
			}

			// get the TCs
			//vector<const HGCTC*>	TCs = subdector->getAll<HGCTC>();
			//vector<HGCgen*>			gens= subdector->getGenAll();  
			
			/*
			float ptCut = ;
			float clusteringNormRadius = 0.2;
			HGCpolarHisto<HGCgenClu> test= subtector->getPolarGenClu( float ptCutGen, float clusteringNormRadius );
			*/
			
			/// Loop for every TC!
			//for(std::vector<const HGCTC*>::iterator tc=TCs.begin(); tc!=TCs.end(); tc++) {
			//EVERY TC ! ! !
			//cout << (*tc)->Pt() < "\n"; 
			//}


			// Implement Strategy here!
			// Should implement similar scheme to polarFW, 
		
			} // END if section==3 loop
		} // Section Loop


		} // Endcap Loop


/*		if ( detector.areGenPresent() ) {
			vector<HGCgen*> gens = detector.getGenAll(); 
			
			
			// Clearly 1 gen per endcap.
//			cout << "\t" << "gens size:\t" << gens.size() << "\n"; 

			// Loop over gens (/endcaps) to seed a polerFW method here, to achieve the best possible energy resolution
			for (unsigned igen=0; igen<gens.size(); igen++) {
				// for each gen <-> ec
				// following some previous conventions
				unsigned iendcap = gen->getEndcapId(); 
				cout << "EC id: " << iendcap << "\tgen id: " << igen << "\n";

			} 
		} 
*/


		tNewC3Ds->Fill(); // Fill new C3Ds
	
		// Cleanup after root files is filled. 
		newC3Ds[0].clear();
		newC3Ds[1].clear();

        cout << " MAIN >> finished event " << ievt << endl;
    } // end of evt loop


	fileOut->cd("/");
	tNewC3Ds->Write(); 


//Unused stuff for output
/*    for(unsigned iendcap=0; iendcap<HGCgeom::instance()->nEndcaps(); iendcap++) {
        for(unsigned isection=0; isection<nLongitudinalSections; isection++) {
            if(isection==3)

            for(unsigned isector=0; isector<nPhiSectors; isector++) {
                fileOut->cd();
            }
        }
    }
*/

	cout << " MAIN >>> The loop over events ended. " << endl;

    /* close the out file */
    fileOut->Close();

    return 0;

}



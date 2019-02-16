
/* C++ */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <getopt.h>

// needed for accumulate?

#include <numeric>

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

typedef map<double, vector<double>> doubledoublevectormap;
doubledoublevectormap _radius_pt_map;


vector<vector<double>> _radii_energy_vec;

double mean(vector<double> vec) {
		double sum = 0;
		for (unsigned i=0; i< vec.size(); i++) {
				sum += vec.at(i);
		}
		double _mean = sum / vec.size();
		return _mean;
}


int radiuscheck(HGCgen gen, HGCTC tc, double radius) {
		double xt = gen.xNorm();
		double yt = gen.yNorm();
		double xtc = tc.xNorm();
		double ytc = tc.yNorm();
		double distance = std::sqrt((xt-xtc)*(xt-xtc) + (yt-ytc)*(yt-ytc));

		if (distance < radius) {
				return 1;
		} else if (distance >=radius) {
				return 0;
		} else {
				return 0;
		}
}

vector<double> genradii(double min_r, double  max_r, double step) {
		vector<double> radii;
		double r = min_r;
		while (r < max_r) {
				radii.push_back(r);
				r += step;
		}
		return radii;
}

double Deviation(std::vector<double>& V) {
		double sq_sum = 0;
		double _mean = mean(V);
		for (unsigned n=0; n<V.size(); n++) {
				sq_sum += (V[n] - _mean) * (V[n] - _mean);
		}
		sq_sum /= static_cast<double>(V.size());
		return std::sqrt(sq_sum);
}


vector<double> radii = genradii(0.01, 0.1, 0.01);

vector<vector<double>> order(vector<vector<double>> vvd, int d) {
		/* this function orders a multidimensional vector by the dth entry of the inner vector*/

		std::sort(vvd.begin(), vvd.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
			    return a[0] < b[0];
		});
		if (0) {
				std::cout << "vvd contains: " << std::endl;
				for (unsigned i=0; i<vvd.size(); i++) {
						for (unsigned j=0; j<vvd[i].size(); j++) {
								std::cout << vvd[i][j] << " ";
						}
						std::cout << std::endl;

				}
		}
		std::cout << vvd.size() << std::endl;
		return vvd;
}

vector<double> split(vector<vector<double>> vvd, int d) {
		vector <double> vd;
		for (unsigned i=0; i< vvd.size(); i++) {
				vd.push_back(vvd[i][d]);
		}
		return vd;
}


vector<vector<double>> resolutionanalysis(vector<vector<double>> vv) {
		/* the input is a vector of vectors, lets call the first list and the second touples.
		 * every touple has elements {radius, measured energy, truth energy, eta}
		 * they are taken over every event which the detector runs over. 
		 * They now need to be split into one for every radius, such that the radius study can be made. 
		 * Note: radii is a global variable */


		vv = order(vv, 0);
		
			
		return vv;
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

		for (unsigned ii=0; ii<2; ii++) {
				HGCsubdet* subdetector = detector.getSubdet(ii, 3);
				vector<HGCgen*> gens = subdetector->getGenAll();
			
				HGCgen* gen = gens.at(0);
				vector<const HGCTC*> TCs = subdetector->getAll<HGCTC>();
				vector<double> tc_energies_0;
				vector<double> tc_energies_1;

				vector<double> r_em_et;

				for (unsigned i=0; i<radii.size(); i++) {
					for (unsigned j=0; j<TCs.size(); j++) {
							if (TCs.at(j)->zside() == -1) {
									if (radiuscheck(*gen, *TCs.at(j), radii.at(i))) {
										tc_energies_0.push_back(TCs.at(j)->Pt());
									}
							} else {
									if (radiuscheck(*gen, *TCs.at(j), radii.at(i))) {
										tc_energies_1.push_back(TCs.at(j)->Pt());
									}
							}
					}
					std::cout << tc_energies_0.size() << " " << tc_energies_1.size() << std::endl;
					if (accumulate(tc_energies_0.begin(), tc_energies_0.end(), 0.0) >= 0) {
						r_em_et.push_back(radii.at(i));
						r_em_et.push_back(accumulate(tc_energies_0.begin(), tc_energies_0.end(), 0.0));
					   	r_em_et.push_back(gen->Pt());
					} else {
						r_em_et.push_back(radii.at(i));
						r_em_et.push_back(accumulate(tc_energies_1.begin(), tc_energies_1.end(), 0.0));
						
					   	r_em_et.push_back(gen->Pt());
					}
					r_em_et.push_back(gen->Eta());
					_radii_energy_vec.push_back(r_em_et);
					r_em_et.clear();
					tc_energies_1.clear();
					tc_energies_0.clear();
				}

								
				/*print the event data for debugging*/
				if (0) {
					std::cout << "Endcap: " << gen->getEndcapId() << std::endl;
					std::cout << "Eta: " << gen->Eta() << std::endl;
					std::cout << "Phi: " << gen->Phi() << std::endl;
					std::cout << "Xn: " << gen->xNorm() << std::endl;
					std::cout << "Yn: " << gen->yNorm() << std::endl;
					std::cout << "Pt: " << gen->Pt() << std::endl;
					std::cout << "Energy: " << gen->Energy() << std::endl;
					if (1 == 1) {
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
	if (0) {
		std::cout << "Pt_mean: " << mean(_pt_gen) << std::endl;
		std::cout << "pt_measured_mean: " << mean(_energy_mes) << std::endl;
	}
	vector<vector<double>> vv = resolutionanalysis(_radii_energy_vec);
	vector<double> _r = split(vv, 0);
	double r[_r.size()];
	std::copy(_r.begin(), _r.end(), r);
	vector<double> _em = split(vv, 1);
	vector<double> _et = split(vv, 2);
	double em[_em.size()];
	double ed[_em.size()];
	vector<double> _ed;
	for (unsigned i=0; i<_et.size(); i++) {
			_ed.push_back(std::sqrt((_em[i]-_et[i])*(_em[i]-_et[i])));
	}

	std::copy(_ed.begin(), _ed.end(), ed);
	std::copy(_em.begin(), _em.end(), em);
	int n = _r.size();

    TFile* fileOut = new TFile( outputFileName, "recreate" ); 
	TGraph* g = new TGraph(n, r, em);
	g->GetYaxis()->SetTitle("Pt diff  measured");
	g->GetXaxis()->SetTitle("Radius");
	g->Write();

	fileOut->Close();
    return 0;

}



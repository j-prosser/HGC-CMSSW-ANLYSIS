

/*************************************************************************/
/* TODO:
 *	- Implement a datastructure for the output
 *		- cluster: clustering radius vs different schemas
 *		- data analysis (per event)
 *
 *	- Data analysis
 *		- Implement a scheme to find the 'best' cluster(s) for polarFWtc
 *		- Implement routine to find Pt differences between gen+tcClu, 
 *		gen+genClu ...
 *		- Save everything, as a root TTree
 *
 *
 *
 */
/*************************************************************************/

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

#include "ResolutionStats.h"
#include "utils.h"

//HGC build options
const bool flagTCs = true;
const bool flagC2D = true;
const bool flagC3D = true;
const bool flagGen = true;
const bool flagGenPart = false;
const int HGCverboselevel = 0; // 0 - Off


/* Deciding structure
 *	Loop over events,
 *	Loop over radius (say 0.01 - 0.5),
 *	
 *	Calcs for different schemes: tc / c2d polar histogram methods
 *		- Energy resolution: 
 *			(SUM(cluster Pt)  - Pt_truth) / SUM(cluster Pt)	
 *		- Position resolution (In normalised co-ordinates)
 *			xNorm, yNorm, rNorm, by calculating euclidian distances
 *
 *	Datastructure for storing resolutions... Make EC independant?:
 *		E_res, X_res, Y_res, R_res (Per radius - independant var) x number of Schema
 *
 * */

/// Datastructures
//typedef vector<HGCC3D*> c3d_vec; // used for output?

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
    //unsigned nNNsearch=9, nNNsum=0;


	/**********************/	
	/*** Radius options ***/

    std::vector<Float_t> c3dRadii;	
	// Radius increment (step)
	Float_t incR = 0.0075;
	// Number of radii to be analysed
	unsigned nR = 15;
	// Create vector of radii
	for (unsigned i=1; i != nR+1; ++i) {c3dRadii.push_back(i*incR);} 

	
	// Command Line Output Options
	bool verbose = false;
	bool saveEventByEvent=false; 

	/****************************/
	/*** Command line options ***/
	// TODO: Implement cmdline options for:
	//			- verbose
	//			- saving efvent by event
	//			- radius options 
	//			- C3D clustering options (later)

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
           std::cout << "Help" << std::endl;
           std::cout << " -h(--help        ) :\t shows this help" << std::endl;
           std::cout << " -f(--fileList    ) <files> :\t list of files to be processed" << std::endl; 
           std::cout << " -i(--iFile       ) <ifile> :\t single file input" << std::endl; 
           std::cout << " -o(--oFile       ) <ofile> :\t output file" << std::endl; 
           std::cout << " -d(--firstEvent  ) <firstEvent> :\t first event to be processed (default: 0)" << std::endl;
           std::cout << " -n(--nEvt        ) <nEvt> :\t number of events to be processed (default: all)" << std::endl;
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
            // convert to integers...
            nEvt = atoi( optarg ); 
            break;
        case 'd':
            // convert to integers...
            firstEvent = atoi( optarg );
            break;

        default:
            return 0;
        }
    }

    // Display options
   std::cout << "Options "           << std::endl;
   std::cout << "  Verbose: "        << verbose        << std::endl;
   std::cout << "  File List Name: " << fFileListName  << std::endl;
   std::cout << "  InputFile: "      << inputFileName  << std::endl;
   std::cout << "  firstEvent: "     << firstEvent     << std::endl;
   std::cout << "  nEvts: "          << nEvt           << std::endl;
   std::cout << "  OutputFile: "     << outputFileName << std::endl;

    /****************/
    /* OPEN fileOUT */

    TFile* fileOut = new TFile( outputFileName, "recreate" ); 


    /************************************/
    /* Chain input files, or input file */

    TList *fList = new TList();

    if( fFileListName != "" ) {
        std::ifstream fFileList( fFileListName );    
        std::string line;
        while( getline( fFileList, line ) ){
            fList->Add( new TObjString( TString(line) ) );
        }
    }
    else {
        fList->Add( new TObjString( inputFileName ) );
    }

	/**********************/
    /* build the detector */

    std::cout << " MAIN >> building HGC\n";
    HGC detector( fList, 
                  flagTCs, flagC2D, flagC3D, flagGen, flagGenPart, 
                  true, HGCverboselevel 
        );   
   std::cout << " MAIN >> HGC built\n"; 
    
	// - Create a class for storing statistics per event + endcap, for every radius 
	TTree *tStats = new TTree("tstats","tstats"); 	
//	TTree *ttcStats = new TTree("tcstats","tcstats"); 
	
	//Deprecating following loop, because it *may* be making everything not work!	
//	for (int iendcap=0; iendcap != 2; ++iendcap) {
//		for (int iRad=0; iRad != nR; ++iRad) {
//		/*	tgeStats->Branch(Form("radius_%d.endcap_%d", iRad, iendcap), &gestats[iendcap][iRad] ,64000,1);
//			ttcStats->Branch(Form("radius_%d.endcap_%d", iRad, iendcap), &tcstats[iendcap][iRad] ,64000,1); */
//			tgeStats->Branch(Form("radius_%d.endcap_%d", iRad, iendcap), &gestats[iendcap][iRad]);// ,64000,1);
//			ttcStats->Branch(Form("radius_%d.endcap_%d", iRad, iendcap), &tcstats[iendcap][iRad]);// ,64000,1);
//		}}

	//No more pre-save sorting!
    std::vector<ResolutionStats> gen_stats; 
    std::vector<ResolutionStats> tc_stats;

	//Add branches for difference schemes...
	tStats->Branch( "gen_clusters", &gen_stats, 64000,1);
	tStats->Branch( "tc_clusters", &tc_stats, 64000,1);


    /********************/
	/* Loop Over Events */
    unsigned totalEvt = detector.getEvents();
    nEvt = (nEvt==-1) ? totalEvt : nEvt;
    std::cout << " MAIN << totalEvt "<< totalEvt << "\t events selected " << nEvt << std::endl;

	/**********************************/
	/* Output datastructures for C3Ds */
    std::vector<HGCC3D> tcC3Ds[2][nR];
    std::vector<HGCC3D> geC3Ds[2][nR];
    
	/// Loop over events
    for( int ievt=firstEvent; ievt<(firstEvent+nEvt); ievt++ ){


		/******BUILD DIR HIERARCHY******/
        /* make a directory for this event and the phi sector in iFile
		 * IF saveEventByEvent flag is set 
		 */
        TDirectory* eventDir;
        if( saveEventByEvent ){
            eventDir = fileOut->mkdir( Form("event_%d", ievt) );
            
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
			// Return to root dir
            eventDir->cd();
        }

        /* Get Entry */
        std::cout << " MAIN >> getting event " << ievt <<std::endl;
        
		/// get event into 'detector' 
		detector.getEvent( ievt );

		/// get truth data (index is endcap) 
        std::vector<HGCgen*> gens  = detector.getGenAll();

		/// endcap loop
        for(unsigned iendcap=0; iendcap<HGCgeom::instance()->nEndcaps(); iendcap++) {
			// 
			HGCgen* gen = gens[iendcap]; 

			// For each section in iendcap, perhaps remove this (unnecessary) loop
		for(unsigned isection=0; isection<nLongitudinalSections; isection++){
	
			/* point the correct location */ 
			if( saveEventByEvent )  fileOut->cd( Form("event_%d/endcap_%d/section_%d", ievt, iendcap, isection) );

			// Routine here below resembles HGCsubdet::getGenC3D, but for TC not C2D
			/* polarFWtc routine */
			if (isection == 3) { // only full system

				/*** Loop over R ***/
				for (unsigned iRad=0; iRad!=c3dRadii.size() ;++iRad) {
					const float c3dRadius = c3dRadii[iRad];
					if (verbose) {std::cout << ">>> iRad:" << iRad <<"\tRad:" << c3dRadius <<" <<<"<< std::endl;}
		
					// Bin sizes for eventbyevent histograms.	
					unsigned binSums[36] = { 
						13,                                           // 0
						11, 11, 11,                                   // 1 - 3
						9, 9, 9,                                      // 4 - 6
						7, 7, 7, 7, 7, 7,                             // 7 - 12
						5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,  //13 - 27
						3, 3, 3, 3, 3, 3, 3, 3                        //28 - 35
					};
			
			// Trigger from gen loc only
			HGCC3Dgen C3Dgen = detector.getSubdet(iendcap, isection)->getGenC3D( c3dRadius );
            geC3Ds[iendcap][iRad] = C3Dgen.getNewC3Ds();
			
			if (verbose) {
				// Print all found clusters gen method
				for(unsigned ic3d=0; ic3d<geC3Ds[iendcap][iRad].size(); ++ic3d) {
						
                    std::cout << "iC3D:"<< ic3d << "  ngeC3D:" << geC3Ds[iendcap][iRad].size() << std::endl;
				    geC3Ds[iendcap][iRad].at(ic3d).print();	
				}}
			
			/*******************************/
			/**** Trigger from TCs ********/
			HGCpolarHisto<HGCTC> grid = detector.getSubdet(iendcap, isection)->getPolarFwC3D<HGCTC>( c3dRadius );
			//newC3Ds[iendcap] = grid.getNewC3Ds( c3dRadius, binSums );
			tcC3Ds[iendcap][iRad] = grid.getNewC3Ds( c3dRadius, binSums );
			/// If detailed view is needed
			if(  saveEventByEvent  ) {
				grid.getHisto()											->Write( 
						"polarFWtc_gridTcH"  );
				grid.getHistoSums( binSums, true )						->Write( 
						"polarFWtc_gridTcHS" );
				grid.getHistoMaxima( binSums, "defaultMaximum" ,true )	->Write( 
						"polarFWtc_gridTcM"  );
				grid.getGraph()											->Write( 
						"polarFWtc_gridTcG"  );
			}
			
			if (verbose) {
				cout << "********************\n";	
				cout << "truth info:\t" << gen->Pt() << " "<< gen->xNorm() <<" " << gen->yNorm() <<std::endl;
			}

			// Obtain the closest cluster to truth	
			auto bestClusterTC = min_element(tcC3Ds[iendcap][iRad].begin(), tcC3Ds[iendcap][iRad].end(), 
					[gen](HGCC3D& lhs, HGCC3D& rhs) { return getDist(lhs,*gen) < getDist(rhs,*gen);} ) ;   
			
			auto bestClusterGen = min_element(geC3Ds[iendcap][iRad].begin(), geC3Ds[iendcap][iRad].end(), 	
					[gen](HGCC3D& lhs, HGCC3D& rhs) { return getDist(lhs,*gen) < getDist(rhs,*gen);} ) ; 

            if (bestClusterGen == geC3Ds[iendcap][iRad].end() || bestClusterTC == tcC3Ds[iendcap][iRad].end() )
                {
                    cout << "Best cluster FAILED!"  << endl;
                    continue;
                }

            
            if (verbose) {
				cout << "+++++++++++++++++++++++++++++++++++\n";
				cout << "TC best cluster; pt:\t"	<< bestClusterTC->Pt()	<< " xNorm/yNorm:  " 
					<< bestClusterTC->xNorm()	<< "/" << bestClusterTC->yNorm()	<< "\n";

				cout << "Gen best cluster; pt:\t"	<< bestClusterGen->Pt() << " xNorm/yNorm:  " 
					<< bestClusterGen->xNorm()	<< "/" << bestClusterGen->yNorm()	<< "\n";
				cout << "+++++++++++++++++++++++++++++++++++\n";
			}
	
			// Calc stats and put into tcstats
			tc_stats.push_back	(CalculateStats( *bestClusterTC,	gen, c3dRadii[iRad]));					
			gen_stats.push_back	(CalculateStats( *bestClusterGen,	gen, c3dRadii[iRad]));			
						
			/// Loop over TC-generated C3Ds
			// Print out all C3Ds generated by tc-method
			if (verbose) {
				for(unsigned ic3d=0; ic3d<tcC3Ds[iendcap][iRad].size(); ++ic3d) {
					
                    std::cout << "iC3D:"<< ic3d << " out of " 
						<< tcC3Ds[iendcap][iRad].size() << std::endl;
					tcC3Ds[iendcap][iRad].at(ic3d).print();		
				}
			}

				} /*** End radius loop ***/

			} // END if section==3 loop
		
		} // END Section Loop

		} // END Endcap Loop
	
		// Save event output to root
		tStats->Fill();

		// Clear vectors to store event output
		gen_stats.clear(); tc_stats.clear();	

		/* CLEANUP: LOOP over generated clusters clears the HGCC3D vectors */
		for (unsigned iendcap=0; iendcap !=2; ++iendcap) {
			for (unsigned iRad=0; iRad != nR; ++iRad) {
				/// Delete data, at the end of every event loop
				tcC3Ds[iendcap][iRad].clear();
				geC3Ds[iendcap][iRad].clear();
			}
		}

       std::cout << " MAIN >> finished event " << ievt << std::endl;
    } // END Event loop


	/*Writing Output File*/
	fileOut->cd("/");
	
	// New stats storage to hold resolution imformation 
	tStats->Write();

    std::cout << " MAIN >>> The loop over events ended. " << std::endl;

    /* close the out file */
    fileOut->Close();

    std::cout << " MAIN >>> Output file closed." << std::endl;

    return 0;

} // End of main

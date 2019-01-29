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

	vector<float> c3dRadii;	
	// Radius increment (step)
	float incR = 0.05;
	// Number of radii to be analysed
	unsigned nR = 2;
	// Create vector of radii
	for (unsigned i=1; i != nR+1; ++i) {c3dRadii.push_back(i*incR);} 

	
	// Command Line Output Options
	bool verbose = true; 
	bool saveEventByEvent=false; 

	/****************************/
	/*** Command line options ***/

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
	cout << " MAIN >> building HGC\n";
    HGC detector( fList, 
                  flagTCs, flagC2D, flagC3D, flagGen, flagGenPart, 
                  true, HGCverboselevel 
        );   
    cout << " MAIN >> HGC built\n"; 
    // gen 
    
	
//	TGraph gGenProjXY[HGCgeom::instance()->		nEndcaps()][nLongitudinalSections][nPhiSectors];
//    TGraph gGenProjXYnorm[HGCgeom::instance()->	nEndcaps()][nLongitudinalSections][nPhiSectors];
 
	
	// C3D
//    double nC3D[nEvt][HGCgeom::instance()->nEndcaps()]; // [events][endcaps (f/b)]  

//    TGraph gC3DProjXYnorm[HGCgeom::instance()->nEndcaps()][nLongitudinalSections][nPhiSectors];

    /*********/
    /* trees */
//    TTree *tNewC3Ds = new TTree( "newC3Ds", "newC3Ds" );	
//    TTree *tGenC3Ds = new TTree( "genC3Ds", "genC3Ds" );
//    TTree *tForestC3Ds = new TTree( "forestC3Ds", "forestC3Ds" );
//    TTree *tC3DsSingle = new TTree( "C3DsSingle", "C3DsSingle" );

//    vector<HGCC3D> newC3Ds[2];
//    vector<HGCC3D> genC3Ds[2];
//    vector<HGCC3D> forestC3Ds[2];
//    vector<HGCC3D> C3DsSingle[2];

//    tNewC3Ds->Branch( "endcap0", &newC3Ds[0], 64000, 1);
//    tNewC3Ds->Branch( "endcap1", &newC3Ds[1], 64000, 1);
//    tGenC3Ds->Branch( "endcap0", &genC3Ds[0], 64000, 1);
//    tGenC3Ds->Branch( "endcap1", &genC3Ds[1], 64000, 1);

	
	//ResolutionStats gestats[2][nR]; // 2 Endcaps, nR radii tested
	//ResolutionStats tcstats[2][nR]; // 2 Endcaps, nR radii tested

	/// Current working HERE
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
	vector<ResolutionStats> gen_stats; 
	vector<ResolutionStats> tc_stats;

	//Add branches for difference schemes...
	tStats->Branch( "gen_clusters", &gen_stats, 64000,1);
	tStats->Branch( "tc_clusters", &tc_stats, 64000,1);


    /********************/
	/* Loop Over Events */
    unsigned totalEvt = detector.getEvents();
    nEvt = (nEvt==-1) ? totalEvt : nEvt;

	/*******************************/
	/* Loop over radius structures */
	vector<HGCC3D> tcC3Ds[2][nR];
	vector<HGCC3D> geC3Ds[2][nR];
    

	///
    for( int ievt=firstEvent; ievt<(firstEvent+nEvt); ievt++ ){
		
		/******BUILD DIR HIERARCHY******/
        /* make a directory for this event and the phi sector in iFile */
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
            
            eventDir->cd();
            
        }

        /* Get Entry */
        std::cout << " MAIN >> getting event " << ievt << std::endl;
        
		/// get event into 'detector' 
		detector.getEvent( ievt );

		/// get truth data (index is endcap) 
		vector<HGCgen*> gens  = detector.getGenAll();

		/// endcap loop
        for(unsigned iendcap=0; iendcap<HGCgeom::instance()->nEndcaps(); iendcap++) {
			// 
			HGCgen* gen = gens[iendcap]; 

			// For each section in iendcap
		for(unsigned isection=0; isection<nLongitudinalSections; isection++){
	

			/* point the correct location */ 
			if( saveEventByEvent )  fileOut->cd( Form("event_%d/endcap_%d/section_%d", ievt, iendcap, isection) );

	
			// Routine here below resembles HGCsubdet::getGenC3D, but for TC not C2D
			/* polarFWtc routine */
			if (isection == 3) { // only full system

				/*** Loop over R ***/
				for (unsigned iRad=0; iRad!=c3dRadii.size() ;++iRad) {
					const float c3dRadius = c3dRadii[iRad];
					if (verbose) { cout << ">>> iRad:" << iRad <<"\tRad:" << c3dRadius <<" <<<"<< endl;}

				//TEST gen print
				//cout << "****TEST****";
				//cout << "Pt" << gen->Pt() << "\txNorm" << gen->xNorm(); 
					
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
//            genC3Ds[iendcap] = C3Dgen.getNewC3Ds();

            geC3Ds[iendcap][iRad] = C3Dgen.getNewC3Ds();
			
			if (verbose) {

				for(unsigned ic3d=0; ic3d<geC3Ds[iendcap][iRad].size(); ++ic3d) {
						
				cout << "iC3D:"<< ic3d << "\|ngeC3D:" << geC3Ds[iendcap][iRad].size() << endl;
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
			
			cout << "********************\n";
			
			cout << "truth info:\t" << gen->Pt() << " "<< gen->xNorm() <<" " << gen->yNorm() <<endl;
			
			// Obtain the closest cluster to truth	
			auto bestClusterTC = min_element(tcC3Ds[iendcap][iRad].begin(), tcC3Ds[iendcap][iRad].end(), 
					[gen](HGCC3D& lhs, HGCC3D& rhs) { return getDist(lhs,*gen) < getDist(rhs,*gen);} ) ;   
			
			
			auto bestClusterGen = min_element(geC3Ds[iendcap][iRad].begin(), geC3Ds[iendcap][iRad].end(), 	
					[gen](HGCC3D& lhs, HGCC3D& rhs) { return getDist(lhs,*gen) < getDist(rhs,*gen);} ) ; 


			//Testing
			if (verbose) {
				cout << "+++++++++++++++++++++++++++++++++++\n";
				cout << "TC best cluster; pt:\t"	<< bestClusterTC->Pt()	<< " xNorm/yNorm:  " 
					<< bestClusterTC->xNorm()	<< "/" << bestClusterTC->yNorm()	<< "\n";
				cout << "Gen best cluster; pt:\t"	<< bestClusterGen->Pt() << " xNorm/yNorm:  " 
					<< bestClusterGen->xNorm()	<< "/" << bestClusterGen->yNorm()	<< "\n";
				cout << "+++++++++++++++++++++++++++++++++++\n";
			}

			/*
			cout << "+++++++++++++++++++++++++\n";
			auto best_pt_tc = min_element( tcC3Ds[iendcap][iRad].begin(), tcC3Ds[iendcap][iRad].end(),
					[gen] (HGCC3D& lhs, HGCC3D& rhs) {return abs_diff_pt(lhs,*gen) < abs_diff_pt(rhs, *gen);});
			cout << "best pt: " << best_pt_tc->Pt() << " xnorm "<< best_pt_tc->xNorm() << " ynorm "<< best_pt_tc->yNorm() << endl;
			cout << "+++++++++++++++++++++++++\n";
			*/
	
			// Calc stats and put into tcstats
			tc_stats.push_back	(CalculateStats( *bestClusterTC,	gen, c3dRadii[iRad]));					
			gen_stats.push_back	(CalculateStats( *bestClusterGen,	gen, c3dRadii[iRad]));			
						
			/// Loop over TC-generated C3Ds
			for(unsigned ic3d=0; ic3d<tcC3Ds[iendcap][iRad].size(); ++ic3d) {
				/*	TODO:
				 *		- discard c3d which are not pertinent to the event
				 *		- Energy calculations
				 */
				// For each C3D find distance to gen
					
				/*
				C3D_gen_test = geC3D[iendcap][iRad].at(ic3d);
				C3D_tc_test = tcC3D[iendcap][iRad].at(ic3d); 
				x_s = C3D_gen_test.xNorm()*C3D_gen_test.xNorm();
				y_s = C3D_gen_test.yNorm()*C3D_gen_test.yNorm();

				//newC3Ds[iendcap].at(ic3d).setNearestGen( detector.getGenAll() );	
				// Find best c3d to compare with truth! 
				// Find radial distance to truth... 
				x_s = tcC3D[iendcap][iRad].at(ic3d).xNorm()   
				y_s = tcC3D[iendcap][iRad].at(ic3d).yNorm() 
				*/
				if (verbose) {
					cout << "iC3D:"<< ic3d << " out of " 
						<< tcC3Ds[iendcap][iRad].size() << endl;
				tcC3Ds[iendcap][iRad].at(ic3d).print();	
				}	
			/************* END of polarFWtc routines************/
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

				} /*** End radius loop ***/

			} // END if section==3 loop
		
		} // END Section Loop

		} // END Endcap Loop

		// Please fill root from here!?
		//ttcStats->Fill();
		//tgeStats->Fill();	
		tStats->Fill();

		gen_stats.clear(); tc_stats.clear();	


				// Fill root variables
//		tNewC3Ds->Fill();
//		tGenC3Ds->Fill();
		// Cleanup after root files is filled. 
//		newC3Ds[0].clear();
//		newC3Ds[1].clear();
//		genC3Ds[0].clear();
//		genC3Ds[1].clear(); 

		/* LOOP over generated clusters [Calcs here?] 
		 *	Also clears the HGCC3D vectors */
		/*for (unsigned iendcap=0; iendcap !=2; ++iendcap) {
			for (unsigned iRad=0; iRad != nR; ++iRad) {

				/// Delete data, at the end of every event loop
				tcC3Ds[iendcap][iRad].clear();
				geC3Ds[iendcap][iRad].clear();
			}
		} */

        cout << " MAIN >> finished event " << ievt << endl;
    } // END Event loop


	/*Writing Output File*/
	fileOut->cd("/");

	// Deprecated C3D storage-> perhaps implement for a single radius.
	//tNewC3Ds->Write(); 
	//tGenC3Ds->Write(); 

	// New stats storage to hold resolution imformation 
	//tgeStats->Write();
	//ttcStats->Write(); 
	tStats->Write();
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



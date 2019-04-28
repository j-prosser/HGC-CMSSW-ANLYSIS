
#include "HGCpolarHisto_T.h"

template<class T>
HGCpolarHisto<T>::HGCpolarHisto() {

}

//template<class T>
//HGCpolarHisto<T>::HGCpolarHisto( unsigned rzNbins , double rzMin , double rzMax, 
//                                 unsigned phiNbins, double phiMin, double phiMax 
//    ){
//
//    _rzNbins = rzNbins; 
//    _phiNbins = phiNbins; 
//
//    _rzMin = rzMin; 
//    _phiMin = phiMin; 
//    _rzMax = rzMax; 
//    _phiMax = phiMax; 
//
//    _rzBinWidth  = (_rzMax-_rzMin) / _rzNbins; 
//    _phiBinWidth = (_phiMax-_phiMin) / _phiNbins; 
//
//    _histo = new TH2D("histo", "histo", 
//                      _phiNbins, _phiMin, _phiMax,
//                      _rzNbins , _rzMin , _rzMax
//        );
//
//    _histoSums = new TH2D("histoSums", "histoSums", 
//                          _phiNbins, _phiMin, _phiMax,
//                          _rzNbins , _rzMin , _rzMax
//        );
//
//    _histoMaxima = new TH2D("histoMaxima", "histoMaxima", 
//                            _phiNbins, _phiMin, _phiMax,
//                            _rzNbins , _rzMin , _rzMax
//        );
//    
//    _graph = new TGraph();
//
//    _grid = new HGCbin*[_phiNbins];
//
//    for (unsigned i=0; i<_phiNbins ; i++)
//        _grid[i] = new HGCbin[_rzNbins];
//
//    _binArea = new double[_rzNbins];
//
//
//    double dR = (_rzMax-_rzMin)/_rzNbins;
//    for(unsigned i=0; i<_rzNbins; i++){
//        double r1 = _rzMin+ i   *dR;
//        double r2 = _rzMin+(i+1)*dR;
//        _binArea[i] = ( (phiMax-phiMin)/(phiNbins*2.) ) * ( pow(r2,2) - pow(r1,2) )  ;
//    }
//
//}


//template<class T>
//HGCpolarHisto<T>::~HGCpolarHisto() { 
//    
//    delete _histo;
//    delete _histoSums;
//    delete _histoMaxima;
//    delete _graph;
//
//    for (unsigned i=0; i<_phiNbins ; i++)
//        delete[] _grid[i];
//
//    delete[] _grid;
//    delete[] _binArea;
//
//}

//template<class T>
//void HGCpolarHisto<T>::addPoint(const T hit) {
//
//    double phi = hit.Phi();
//    double r   = hit.r();
//    double z   = hit.z();
//    double rz  = r/abs(z);
//
//    unsigned rzBinId  = floor( ( rz - _rzMin ) / _rzBinWidth );
//    unsigned phiBinId = floor( ( phi - _phiMin ) / _phiBinWidth );
//
////    cout << "r/z  "   << r/z     << " - p " << phi << endl;
////    cout << "br/z "   << rzBinId << " - p " << phiBinId << endl;
////    cout << phiBinId  << " "     << rzBinId << endl;
////
//    if( phiBinId < _phiNbins && rzBinId < _rzNbins){
//        //_histo->Fill( phi, rz, hit.Energy());
//        _grid[phiBinId][rzBinId].addContent( hit.Energy(), hit.id() );
//    }
//    else
//        cout << " >>> HGCpolarHisto: bin Id out of range." << endl;
//    _graph->SetPoint( _graph->GetN(), phi, rz);
//
//    _hitsMap[hit.id()] = hit;
//    _hits.push_back( &(_hitsMap[hit.id()]) );
// 
//}
//
//template<class T>
//TH2D* HGCpolarHisto<T>::getHisto() {
//
//    for (unsigned iphi=0; iphi<_phiNbins; iphi++)
//        for (unsigned irz=0; irz<_rzNbins; irz++)
//            _histo->SetBinContent( iphi+1, irz+1, _grid[iphi][irz].getContent() );
//
//    return _histo;
//
//}

template<class T>
TH2D* HGCpolarHisto<T>::getHistoSums( unsigned *nBinsToSum, bool smear ) {
    
    for (unsigned irz=0; irz<_rzNbins; irz++) {
        int nBinsSide = (nBinsToSum[irz]-1)/2;
        
        for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
            
            double content = _grid[iphi][irz].getContent();
            double weight  = 1;
            for(int isbin=1; isbin<=nBinsSide; isbin++ ){
                
                int binToSumLeft = iphi;                 
                binToSumLeft = binToSumLeft-isbin; 
                if( binToSumLeft<0 ) binToSumLeft = _phiNbins+binToSumLeft;
                
                int binToSumRight = iphi;   
                binToSumRight = binToSumRight+isbin;
                if( binToSumRight>_phiNbins-1 ) binToSumRight = binToSumRight-_phiNbins;                
                
                content += ( _grid[binToSumLeft][irz].getContent()  / pow( 2, isbin) ); // quadratic kernel
                content += ( _grid[binToSumRight][irz].getContent() / pow( 2, isbin) ); // quadratic kernel
                
                weight += 2*(1/pow( 2, isbin));

            }
            
            double area = _binArea[irz]*weight;

	    if ( smear )   _histoSums->SetBinContent(iphi+1, irz+1, content/area);
	    if ( !smear ) _histoSums->SetBinContent(iphi+1, irz+1, _grid[iphi][irz].getContent());

        }
    }
    
    TH2D *histoSums = (TH2D*) _histoSums->Clone("histoSumsClone");
    
    for (unsigned irz=1; irz<=_rzNbins; irz++) {
        
        for (unsigned iphi=1; iphi<=_phiNbins; iphi++) {

            double content   = 0.;
            double contentUp = 0.;
            double contentDw = 0.;
            
            content = histoSums->GetBinContent(iphi, irz);
            if( irz < _rzNbins ) contentUp = histoSums->GetBinContent(iphi, irz+1) * .5;
            if( irz > 0 )        contentDw = histoSums->GetBinContent(iphi, irz-1) * .5;
            
            _histoSums->SetBinContent(iphi, irz, content+contentUp+contentDw);

        }
    }

    return _histoSums;

}


template<class T>
void HGCpolarHisto<T>::getDefaultMaximum( unsigned *nBinsToSum ) {


  /* searching for maxima */
  for (unsigned irz=0; irz<_rzNbins; irz++) {
    
        double rows[_phiNbins][3];
        
        for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
            
            if ( irz == 0 ) {
                rows[iphi][2] = _histoSums->GetBinContent(iphi+1, irz+2);
                rows[iphi][1] = _histoSums->GetBinContent(iphi+1, irz+1);
                rows[iphi][0] = 0.;
            }
            else if ( irz == _rzNbins-1 ) {
                rows[iphi][2] = 0.;
                rows[iphi][1] = _histoSums->GetBinContent(iphi+1, irz+1);
                rows[iphi][0] = _histoSums->GetBinContent(iphi+1, irz);
            }
            else {
                rows[iphi][2] = _histoSums->GetBinContent(iphi+1, irz+2);
                rows[iphi][1] = _histoSums->GetBinContent(iphi+1, irz+1);
                rows[iphi][0] = _histoSums->GetBinContent(iphi+1, irz);
            }
    
        }

        int nBinsSide = nBinsToSum[irz]-1/2;
  
        for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
            
            bool isMaxima = true;
	    
            double centralValue = rows[iphi][1];	    

            if( !( centralValue > rows[iphi][2] ) || !( centralValue >= rows[iphi][0] ) ) 
                isMaxima = false;

            if( isMaxima ) {
                for( int isphi=1; isphi<=nBinsSide; isphi++ ) {
                    
                    int binToSearchLeft = iphi;                 
                    binToSearchLeft = binToSearchLeft-isphi; 
                    if( binToSearchLeft<0 ) binToSearchLeft = _phiNbins+binToSearchLeft;
                    
                    int binToSearchRight = iphi;   
                    binToSearchRight = binToSearchRight+isphi;
                    if( binToSearchRight>_phiNbins-1 ) binToSearchRight = binToSearchRight-_phiNbins;                
                    
                    if( !( centralValue >= rows[binToSearchRight][0] ) ||
                        !( centralValue >= rows[binToSearchRight][1] ) ||
                        !( centralValue >= rows[binToSearchRight][2] ) )
                        isMaxima = false;
                    
                    if( !( centralValue >  rows[binToSearchLeft][0] )  ||
                        !( centralValue >  rows[binToSearchLeft][1] )  ||
                        !( centralValue >  rows[binToSearchLeft][2] )  )
                        isMaxima = false;
                   
                    if( !isMaxima )
                        break;
                }
            }
                        
	


	
	
	    
	    if(  isMaxima  ){

	      
	      _histoMaxima->SetBinContent(iphi+1, irz+1, rows[iphi][1]);
	      
	      vector<unsigned> idsBin = _grid[iphi][irz].getIds();
	      
	      maximaT maxima(0.,0.);
	      
	      for( auto id : idsBin ){
		T *hit = &(_hitsMap[id]);
		
		maxima.first = maxima.first + hit->xNorm(); 
		maxima.second = maxima.second + hit->yNorm();
		
	      }
	      
	      if( idsBin.size() == 0 ) continue;
	      maxima.first = maxima.first / idsBin.size(); 
	      maxima.second = maxima.second / idsBin.size(); 
	      
	      _maxima.push_back( maxima );
	      
	    }
	    
	}
  }
  

}

template<class T>
void HGCpolarHisto<T>::getMaximumEnergy( unsigned *nBinsToSum ) {
    /* Gets the maximas, and the value associated witht eh energy of each maximum*/

    /* What does this do? 
     *  Populates _maxima with x,y coords of maximas
     *  Populates _maxima_energies with respective histogram energy values for possible use in seed assoc stage
     *
     * */
  /* searching for maxima */
  for (unsigned irz=0; irz<_rzNbins; irz++) {
    
        double rows[_phiNbins][3];
        
        for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
           
            /*  2 - position to right
             *  1 - central value
             *  0 - position to left
             * */
            if ( irz == 0 ) {
                rows[iphi][2] = _histoSums->GetBinContent(iphi+1, irz+2);
                rows[iphi][1] = _histoSums->GetBinContent(iphi+1, irz+1);
                rows[iphi][0] = 0.;
            }
            else if ( irz == _rzNbins-1 ) {
                rows[iphi][2] = 0.;
                rows[iphi][1] = _histoSums->GetBinContent(iphi+1, irz+1);
                rows[iphi][0] = _histoSums->GetBinContent(iphi+1, irz);
            }
            else {
                rows[iphi][2] = _histoSums->GetBinContent(iphi+1, irz+2);
                rows[iphi][1] = _histoSums->GetBinContent(iphi+1, irz+1);
                rows[iphi][0] = _histoSums->GetBinContent(iphi+1, irz);
            }
    
        }

        int nBinsSide = nBinsToSum[irz]-1/2;
  
        for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
            
            bool isMaxima = true;
	    
            double centralValue = rows[iphi][1];	    

            if( !( centralValue > rows[iphi][2] ) || !( centralValue >= rows[iphi][0] ) ) 
                isMaxima = false;

            if( isMaxima ) {
                for( int isphi=1; isphi<=nBinsSide; isphi++ ) {
                    
                    int binToSearchLeft = iphi;                 
                    binToSearchLeft = binToSearchLeft-isphi; 
                    if( binToSearchLeft<0 ) binToSearchLeft = _phiNbins+binToSearchLeft;
                    
                    int binToSearchRight = iphi;   
                    binToSearchRight = binToSearchRight+isphi;
                    if( binToSearchRight>_phiNbins-1 ) binToSearchRight = binToSearchRight-_phiNbins;                
                    
                    if( !( centralValue >= rows[binToSearchRight][0] ) ||
                        !( centralValue >= rows[binToSearchRight][1] ) ||
                        !( centralValue >= rows[binToSearchRight][2] ) )
                        isMaxima = false;
                    
                    if( !( centralValue >  rows[binToSearchLeft][0] )  ||
                        !( centralValue >  rows[binToSearchLeft][1] )  ||
                        !( centralValue >  rows[binToSearchLeft][2] )  )
                        isMaxima = false;
                    
                    if( !isMaxima )
                        break;
                }
            }
                        
	    
            if(  isMaxima  ){
	      
                _histoMaxima->SetBinContent(iphi+1, irz+1, rows[iphi][1]);
	      
	            vector<unsigned> idsBin = _grid[iphi][irz].getIds();
	      
	            maximaT maxima(0.,0.);
	      
	            for( auto id : idsBin ){
		            T *hit = &(_hitsMap[id]);
		    
		            maxima.first = maxima.first + hit->xNorm(); 
		            maxima.second = maxima.second + hit->yNorm();
                }
	      
	        
                if( idsBin.size() == 0 ) continue;
	            maxima.first = maxima.first / idsBin.size(); 
	            maxima.second = maxima.second / idsBin.size(); 
	      
	            _maxima.push_back( maxima );
	     
                /*Add maxima energies to vector*/
                _maxima_energies.push_back( centralValue );
            }
	    
	
        }

  }
  

}



template<class T>
void HGCpolarHisto<T>::getInterpolationSeeds( unsigned *nBinsToSum, double thres_MIPT ) {
    /* Gets the maximas, and the value associated witht eh energy of each maximum*/

    /* What does this do? 
     *  Populates _maxima with x,y coords of maximas
     *  Populates _maxima_energies with respective histogram energy values for possible use in seed assoc stage
     *
     * */
  /* searching for maxima */
  
    /* INTERPOLATION
     *  Implementing: https://github.com/PFCal-dev/cmssw/blob/0f335e7a794cdb59da49175e818929466e0d24e9/L1Trigger/L1THGCal/src/backend/HGCalHistoSeedingImpl.cc#L217
     *
     * */
   
    //first order interpolation here
    
    std::vector<double> neighbour_weights_{0    , 0.25, 0   ,
                                           0.25 , 0   , 0.25,
                                           0    , 0.25, 0}; 
    
    
    /*
    std::vector<double> neighbour_weights_{ -0.25, 0.5, -0.25,
                                            0.5 , 0  ,  0.5 ,
                                            -0.25, 0.5, -0.25};
    */
    
    
    //std::cout << " INT ";
   
    //cout << "_rzNbins "<< _rzNbins << " _phiNbins " <<_phiNbins << endl;

    double centralValue, MIPT_E, MIPT_N, MIPT_S, MIPT_W, MIPT_NE, MIPT_NW, MIPT_SE, MIPT_SW, MIPT_pred; 


    double curr_hist_max =0.;

    bool isMax = false;
    for (unsigned irz=0; irz<_rzNbins; irz++) {
    
        for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
            
            centralValue = _histoSums->GetBinContent(iphi+1,irz+1);

            MIPT_S = irz<(int(_rzNbins)-1) ? _histoSums->GetBinContent(iphi+1,irz+2) : 0;
            MIPT_N = irz>0 ? _histoSums->GetBinContent(iphi+1,irz) : 0;

            int binLeft = iphi;
            if( binLeft<0 ) binLeft += _phiNbins;
            int binRight = iphi + 2;
            if( binRight>=int(_phiNbins) ) binRight -= _phiNbins;

            MIPT_W = _histoSums->GetBinContent(binLeft,irz+1);
            MIPT_E = _histoSums->GetBinContent(binRight,irz+1);

            MIPT_NW = irz>0 ? _histoSums->GetBinContent(binLeft,irz) : 0;
            MIPT_NE = irz>0 ? _histoSums->GetBinContent(binRight,irz) : 0;
            
            MIPT_SW = irz<(int(_rzNbins)-1) ? _histoSums->GetBinContent(binLeft,irz+2) : 0;
            MIPT_SE = irz<(int(_rzNbins)-1) ? _histoSums->GetBinContent(binRight,irz+2) : 0;
            
                
            MIPT_pred = neighbour_weights_[0] * MIPT_NW + neighbour_weights_[1] * MIPT_N + neighbour_weights_[2] * MIPT_NE
                  + neighbour_weights_[3] * MIPT_W + neighbour_weights_[5] * MIPT_E + neighbour_weights_[6] * MIPT_SW
                  + neighbour_weights_[7] * MIPT_S + neighbour_weights_[8] * MIPT_SE;

            isMax = false; 
            isMax = centralValue>=(MIPT_pred+thres_MIPT);
            
            if(isMax && (centralValue > curr_hist_max) ){
                curr_hist_max = centralValue;
                if (_verboselevel)
                    cout << "UPDATE: "; 
            }   
      
            if ((isMax) && (curr_hist_max*0.5 > centralValue)) {
                isMax = false;
            }

            if(isMax){
	    

               // if (_verboselevel)
               //     cout << " seed e " << centralValue << endl;   

                /*Add maxima energies to vector*/
                _maxima_energies.push_back( centralValue );
                
                
                _histoMaxima->SetBinContent(iphi+1, irz+1,_histoSums->GetBinContent(iphi+1, irz+1));
	      
	            vector<unsigned> idsBin = _grid[iphi][irz].getIds();
	      
	            maximaT maxima(0.,0.);
	      
	            for( auto id : idsBin ){
		            T *hit = &(_hitsMap[id]);
		    
		            maxima.first = maxima.first + hit->xNorm(); 
		            maxima.second = maxima.second + hit->yNorm();
                }
	      
	        
                if( idsBin.size() == 0 ) continue;
	            maxima.first = maxima.first / idsBin.size(); 
	            maxima.second = maxima.second / idsBin.size(); 
	      
	            //if (_verboselevel)
                    //cout << maxima.first << " " << maxima.second <<endl;

                _maxima.push_back( maxima );
	     
            }
	    
	
        }


    }
    //cout << " seeds " << _maxima.size() << endl; 
    
    
}


template<class T>
void HGCpolarHisto<T>::getThreshold( unsigned *nBinsToSum, double threshold ) {//in MIPT

  for (unsigned irz=0; irz<_rzNbins; irz++) {
    for (unsigned iphi=0; iphi<_phiNbins; iphi++) {
      
      bool isThreshold = false;
      double centralValue = _histoSums->GetBinContent(iphi+1, irz+1);
      
      if ( centralValue > threshold ) isThreshold = true;
      
      if ( isThreshold ){
	
	_histoMaxima->SetBinContent(iphi+1, irz+1, centralValue);
	
	vector<unsigned> idsBin = _grid[iphi][irz].getIds();
	
	maximaT maxima(0.,0.);
	
	for( auto id : idsBin ){
	  T *hit = &(_hitsMap[id]);
	  
	  maxima.first = maxima.first + hit->xNorm(); 
	  maxima.second = maxima.second + hit->yNorm();
	
	}
	
	if( idsBin.size() == 0 ) continue;
	maxima.first = maxima.first / idsBin.size(); 
	maxima.second = maxima.second / idsBin.size(); 
	
	_maxima.push_back( maxima );
	
      }
      
    }
  
  }
  


}


template<class T>
TH2D * HGCpolarHisto<T>::getHistoMaxima( unsigned *nBinsToSum, TString strategy, bool smear ) {

    //decides seeding strategy
 
    /* filling _histoSums */
  this->getHistoSums( nBinsToSum, smear );


  if ( strategy == "defaultMaximum" ){


    this->getDefaultMaximum( nBinsToSum );    

  }



  if ( strategy == "threshold" ){

    // 2nd argument is the cut
    this->getThreshold( nBinsToSum, 2 );


  }

  if ( strategy == "MaximumEnergy" ) {
    // new 
    this->getMaximumEnergy( nBinsToSum );
  
  }

  if ( strategy == "Interpolation" ) { 

    this->getInterpolationSeeds(nBinsToSum, 10.0); 
  }   


  //TODO 
  // implement histo maximum method using first order / second order interpolation
  // https://github.com/PFCal-dev/cmssw/blob/0f335e7a794cdb59da49175e818929466e0d24e9/L1Trigger/L1THGCal/src/backend/HGCalHistoSeedingImpl.cc#L217
  // https://github.com/PFCal-dev/cmssw/blob/0f335e7a794cdb59da49175e818929466e0d24e9/L1Trigger/L1THGCal/python/customClustering.py#L150



  return _histoMaxima;
  
}


template<class T>
vector<maximaT> HGCpolarHisto<T>::getMaxima( unsigned *nBinsToSum, TString strategy, bool smear ){

    _maxima.clear();
    
    this->getHistoMaxima( nBinsToSum, strategy, smear );
    
    return _maxima;

}


template<class T>
vector<HGCC3D> HGCpolarHisto<T>::getNewC3Ds( double radius, unsigned *nBinsToSum, TString seed_strategy, TString assoc_strategy, bool smear ) {
    // method that performs seeding and hit association

    //TODO Implement energy dividing scheme corrosponding to the seed energy
    // https://github.com/PFCal-dev/cmssw/blob/0f335e7a794cdb59da49175e818929466e0d24e9/L1Trigger/L1THGCal/src/backend/HGCalHistoClusteringImpl.cc#L45 
   
  //  _verboselevel
        
    this->getHistoMaxima( nBinsToSum, seed_strategy, smear );

    /* _maxima is a vector of pairs of doubles corrosponding to the x and y coordinates of the maxima in the grid. */

    if (_verboselevel)
        cout << "  getNewC3Ds: _maxima.size() " << _maxima.size() << endl;  

    HGCC3D c3ds[_maxima.size()];

    //used for debugging
    double tmpf=0.;  


    if (assoc_strategy== "euclidean" ){ 
        // Loop over hits fro hit association,
        //  Loops over all 'hits' then (nested) c3ds 
        for(unsigned ihit=0; ihit<_hits.size(); ihit++){
        
            const T* hit = _hits.at( ihit );
        
            unsigned c3dIdToAdd=0;
            double distance=1000;
            unsigned i=0;

            for(const auto& c3d : c3ds ) {
       
                // uses simple euclidean distance to determine wether part of cluster or not
                double dist = sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                // minimises distance wrt c3d euclid distance 
                if( distance>dist ) {
                    distance = dist; 
                    c3dIdToAdd = i;
                }
             
                i++;
            }
        
       
            /* check if the distance works for every hit */
            if( distance<=radius ){
                this->addHitToC3D( c3ds, c3dIdToAdd, &(_hitsMap[hit->id()]) );
                //c3ds[c3dIdToAdd].addC2D( _hitsMap[hit->id()] );
            }
        }
    } else if (assoc_strategy == "energyWeight" ){
        //ASSUME seed_strategy = "MaximumEnergy" !

        // use R as a proxy for k (?) 

        
        for(unsigned ihit=0; ihit<_hits.size(); ihit++){
        
            const T* hit = _hits.at( ihit );
        
            unsigned c3dIdToAdd=0;
            double distance=1000;
            unsigned i=0;

            for(const auto& c3d : c3ds ) {
       
                // SCALE BY ENERGY HERE
                
                // uses simple euclidean distance to determine wether part of cluster or not
                //double dist =  sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                // constant 200,000 is fairly arbiary
                double dist_e_weight = (1000000 / _maxima_energies[i] )  * sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                //cout << " Euclidean Dist: " << dist << "\tE Weighted: " << dist_e_weight << endl; 
                
                // minimises distance wrt c3d euclid distance 
                if( distance>dist_e_weight) {
                    distance = dist_e_weight;
                    //tmpf = dist; //debug 
                    c3dIdToAdd = i;
                }
             
                i++;
            }
        
            /* check if the distance works for every hit */
            if( distance<=radius ){
                //debug
                //cout << " checkRadius: "<< radius <<" weightedDist: " << distance << "\teuclideanDist: " << tmpf << endl;   
                this->addHitToC3D( c3ds, c3dIdToAdd, &(_hitsMap[hit->id()]) );
                //c3ds[c3dIdToAdd].addC2D( _hitsMap[hit->id()] );
            } 
        }

    } else if (assoc_strategy == "logenergyWeight" ){
        //ASSUME seed_strategy = "MaximumEnergy" !

        // use R as a proxy for k (?) 

        
        for(unsigned ihit=0; ihit<_hits.size(); ihit++){
        
            const T* hit = _hits.at( ihit );
        
            unsigned c3dIdToAdd=0;
            double distance=1000;
            unsigned i=0;

            for(const auto& c3d : c3ds ) {
       
                // SCALE BY ENERGY HERE
                
                // uses simple euclidean distance to determine wether part of cluster or not
                //
                //
                //double dist =  sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                // constant 200,000 is fairly arbiary
                //double dist_e_weight = (1. / log( (1.+_maxima_energies[i] ) ) )  * sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
                double dist_e_weight =(100./(4.0* log( (1.+_maxima_energies[i] ) )))  * sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                //cout << " Euclidean Dist: " << dist << "\tE Weighted: " << dist_e_weight << endl; 
                //cout << " debug " << dist << " " << dist_e_weight << endl;  

                // minimises distance wrt c3d euclid distance 
                if( distance>dist_e_weight) {
                    distance = dist_e_weight;
                 //   tmpf = dist; //debug 
                    c3dIdToAdd = i;
                }
             
                i++;
            }
        
            /* check if the distance works for every hit */
            if( distance<=radius ){
                //debug
               // cout << " checkRadius: "<< radius <<" weightedDist: " << distance << "\teuclideanDist: " << tmpf << endl;   
                this->addHitToC3D( c3ds, c3dIdToAdd, &(_hitsMap[hit->id()]) );
                //c3ds[c3dIdToAdd].addC2D( _hitsMap[hit->id()] );
            } 
        }

    } else if (assoc_strategy == "energyWeight2" ){
        //ASSUME seed_strategy = "MaximumEnergy" !

        // use R as a proxy for k (?) 

        
        for(unsigned ihit=0; ihit<_hits.size(); ihit++){
        
            const T* hit = _hits.at( ihit );
        
            unsigned c3dIdToAdd=0;
            double distance=1000;
            unsigned i=0;

            for(const auto& c3d : c3ds ) {
       
                // SCALE BY ENERGY HERE
                
                // uses simple euclidean distance to determine wether part of cluster or not
                //double dist =  sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                // constant 200,000 is fairly arbiary
                double dist_e_weight = ( _maxima_energies[i] /200000)  * sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
       
                //cout << " Euclidean Dist: " << dist << "\tE Weighted: " << dist_e_weight << endl; 
                
                // minimises distance wrt c3d euclid distance 
                if( distance>dist_e_weight) {
                    distance = dist_e_weight;
                    //tmpf = dist; //debug 
                    c3dIdToAdd = i;
                }
             
                i++;
            }
        
            /* check if the distance works for every hit */
            if( distance<=radius ){
                //debug
                //cout << " checkRadius: "<< radius <<" weightedDist: " << distance << "\teuclideanDist: " << tmpf << endl;   
                this->addHitToC3D( c3ds, c3dIdToAdd, &(_hitsMap[hit->id()]) );
                //c3ds[c3dIdToAdd].addC2D( _hitsMap[hit->id()] );
            } 
        }

    } else if(assoc_strategy == "EnergySplit"){
        // implement Energy Split here   
        int i=0;
        // declare vector to store targetEnergies
        std::vector<pair<int,double> > targetSeeds;
        for(unsigned ihit=0; ihit<_hits.size(); ihit++){

            const T* hit = _hits.at( ihit );
            
            targetSeeds.clear(); 

            //Loop over Seeds/Maximas etc
            for(int iseed=0; iseed < _maxima.size(); ++iseed){
                double dist = sqrt( pow( _maxima.at(i).first-hit->xNorm() , 2 ) + pow( _maxima.at(i).second-hit->yNorm(), 2 ) );
               
                // minimises distance wrt c3d euclid distance 
                if(dist<radius) {
                    //append seed idx and seed energy to container
                    targetSeeds.emplace_back(iseed, _maxima_energies[iseed]);
                }
            } 
   
         
            if(targetSeeds.empty()) continue;//check if any results
            double totalSeedEnergy = 0; 
            for (auto energy : targetSeeds){
                totalSeedEnergy += energy.second;
            }
            for (auto energy: targetSeeds){

                double seedWeight = 1;
                seedWeight = energy.second/totalSeedEnergy;
               
                //now have the seed weight for each TC
                
                /* CMSSW method 
                if( mapSeedMulticluster[energy.first].size()==0) {
                    mapSeedMulticluster[energy.first] = l1t::HGCalMulticluster(clu, seedWeight) ;
                }
                mapSeedMulticluster[energy.first].addConstituent(clu, true, seedWeight);
                */

                this->addHitToC3D( c3ds, energy.first, &(_hitsMap[hit->id()]), seedWeight);

      
            }
        }
    }

    for( auto c3d : c3ds ) {
        if(c3d.nclusters()>0 || c3d.ncells()>0)
            this->addNewC3D( c3d );
    }
   
    // return vector of c3ds
    return HGCC3DbuildBase<T>::getNewC3Ds();
    
}



template<class T>
void HGCpolarHisto<T>::addHitToC3D( HGCC3D *c3ds, unsigned c3dId, const T *hit, double weight ) {
    
    cout << " !!! WARNING !!! HGCpolarHisto<T>::addHitToC3D(HGCC3D *c3ds, unsigned c3dId, const T *hit) is implemented only for Classes HGCC2D and HGCTC. " << endl; 

}


template<>
void HGCpolarHisto<HGCC2D>::addHitToC3D( HGCC3D *c3ds, unsigned c3dId, const HGCC2D *hit, double weight ) {
    
    c3ds[c3dId].addC2D( hit );

}


template<>
void HGCpolarHisto<HGCTC>::addHitToC3D( HGCC3D *c3ds, unsigned c3dId, const HGCTC *hit, double weight ) {

    c3ds[c3dId].addTC( hit );

}


// hmmmm
//template<>
//void HGCpolarHisto<HGCTC>::addHitToC3D( HGCC3D *c3ds, unsigned c3dId, const HGCTC *hit, double weight) {
//    c3ds[c3dId].addTC_weight( hit, weight); 
//}

template<class T>
TGraph* HGCpolarHisto<T>::getGraph() {

    return _graph;

}


template<class T>
void HGCpolarHisto<T>::clear() {

    _histo->Reset();
    _histoSums->Reset();
    _histoMaxima->Reset();
    _maxima.clear();
    _hits.clear();
    _graph->Clear();

    /*NEW*/
    _maxima_energies.clear();

     for (unsigned iphi=0; iphi<_phiNbins; iphi++)
         for (unsigned irz=0; irz<_phiNbins; irz++)
             _grid[iphi][irz].clear();

}


template class HGCpolarHisto<HGCC2D>;
template class HGCpolarHisto<HGCTC>;


/* mylibs */
#include "HGC.h"


HGC::HGC( TList *fileList, bool flagTCs, bool flagC2D, int verboselevel ) {
    
    /* init */
    _evt = 0;
    _verboselevel = verboselevel;
    _flagTCs = flagTCs;
    _flagC2D = flagC2D;
    
    for(unsigned i=0; i<Nlayers; i++) {
        _TD[i]  = new vector<HGCROC> ;
        _TD[i] ->reserve(5000);
    }
    
    /* Get the Chain */
    _chain = new TChain("hgcalTriggerNtuplizer/HGCalTriggerNtuple");
    TIter next(fileList);
    while ( TObject *file = next() ){
      _chain->Add( ((TObjString*)file)->GetString() );
    }
    
    if( _flagTCs ){
      //_chain->SetBranchAddress( "tc_n"        , &_tc_n         );
        _chain->SetBranchAddress( "tc_id"       , &_tc_id        );
        _chain->SetBranchAddress( "tc_subdet"   , &_tc_subdet    );
        _chain->SetBranchAddress( "tc_zside"    , &_tc_zside     );
        _chain->SetBranchAddress( "tc_layer"    , &_tc_layer     );
        _chain->SetBranchAddress( "tc_wafer"    , &_tc_wafer     );
        _chain->SetBranchAddress( "tc_wafertype", &_tc_wafertype );
        _chain->SetBranchAddress( "tc_cell"     , &_tc_cell      );
        _chain->SetBranchAddress( "tc_data"     , &_tc_data      );
        _chain->SetBranchAddress( "tc_energy"   , &_tc_energy    );
        _chain->SetBranchAddress( "tc_eta"      , &_tc_eta       );
        _chain->SetBranchAddress( "tc_phi"      , &_tc_phi       );
        _chain->SetBranchAddress( "tc_z"        , &_tc_z         );
    }
    // C2D
    if( _flagC2D ) {
        _chain->SetBranchAddress("cl_n"      , &_cl_n      );
        _chain->SetBranchAddress("cl_pt"     , &_cl_pt     );
        _chain->SetBranchAddress("cl_energy" , &_cl_energy );
        _chain->SetBranchAddress("cl_eta"    , &_cl_eta    );
        _chain->SetBranchAddress("cl_phi"    , &_cl_phi    );
        /*_chain->SetBranchAddress("cl_x"      , &_cl_x      );
        _chain->SetBranchAddress("cl_y"      , &_cl_y      );
        _chain->SetBranchAddress("cl_z"      , &_cl_z      );*/
        _chain->SetBranchAddress("cl_layer"  , &_cl_layer  );
        _chain->SetBranchAddress("cl_ncells" , &_cl_ncells );
        _chain->SetBranchAddress("cl_cells"  , &_cl_cells  );
    }
}

HGC::~HGC() {
    
    for(unsigned i=0; i<Nlayers; i++) {
        delete _TD[i];
    }

};
    
unsigned HGC::getEvents(){

    return _chain->GetEntries();

}

void HGC::getEvent(int evt){
        
    /* clear detector */
    this->clear();

    /* Get Entry */
    _chain->GetEntry( evt );        
    
    /* looping over TCs */
    if( _flagTCs ){
     
        /* LOOP */
        unsigned nTC = _tc_id->size();
        for( unsigned itc=0; itc<nTC; itc++ ){
            
	  HGCTC tc;
	  tc.setId(         _tc_id->at( itc )       );
	  tc.setSubdet(     _tc_subdet->at( itc )   );            
	  tc.setZSide(      _tc_zside->at( itc )    );
	  tc.setLayer(      _tc_layer->at( itc )    );
	  tc.setWafer(      _tc_wafer->at( itc )    );
	  tc.setWaferType(  _tc_wafertype->at( itc ));
	  tc.setCell(       _tc_cell->at( itc )     );
	  tc.setData(       _tc_data->at( itc )     );
	  tc.setEnergy(     _tc_energy->at( itc )   );
	  tc.setEta(        _tc_eta->at( itc )      );
	  tc.setPhi(        _tc_phi->at( itc )      );
	  tc.setZ(          _tc_z->at( itc )        );
          
	  /* fill detector data */
	  this->addTC( tc );
                    
        }// end TCs LOOP
        
    }// end TCs

            
    /* Loop over C2D */
    if( _flagC2D ) {
                
        for(int iclu=0; iclu<_cl_n; iclu++){

            HGCC2D c2d;
            c2d.setPt(       _cl_pt->at(iclu)     );
	    c2d.setEnergy(   _cl_energy->at(iclu) );
	    c2d.setEta(      _cl_eta->at(iclu)    );
	    c2d.setPhi(      _cl_phi->at(iclu)    );
	    c2d.setLayer(    _cl_layer->at(iclu)  );
	    c2d.setCells(    _cl_cells->at(iclu)  );	    
	    /*c2d._x      =  _cl_x->at(iclu);
            c2d._y      =  _cl_y->at(iclu);
            c2d._z      =  _cl_z->at(iclu);*/

	    int subdet = -1;
	    if(_flagTCs){
	      HGCTC tc0 = this->getTC(c2d.cells()[0]);
	      subdet = tc0.subdet();
	    }	
	    c2d.setSubdet( subdet );
	    

            /* fill the detector */
            this->addC2D( c2d );

            
        }
    }// end C2D



}

void HGC::addTC( HGCTC tc ) { 

    const unsigned tcLayer = tc.correctedLayer();
    _TC.emplace_back(tc);    
    _TC_map[tc.id()] = _TC.size()-1;
    _TC_layer[tcLayer].emplace_back( _TC.size()-1 );

    HGCROC TD( tc );

    /* add to the correct HGCROC */
    bool found = false;
    for(unsigned int ihgcroc=0; ihgcroc<_TD[tcLayer]->size(); ihgcroc++ ){ 
        if( _TD[tcLayer]->at(ihgcroc).tcIsContained( tc ) ){
            found = true;
            _TD[tcLayer]->at(ihgcroc).addTC( tc );
            break;
        }
    }

    if( !found ) _TD[tcLayer]->push_back( TD );
        
}

void HGC::addC2D(HGCC2D c2d) { 

  _C2D.emplace_back(c2d);    
  _C2D_map[c2d.id()] = _C2D.size()-1;
  const unsigned c2dLayer = c2d.correctedLayer();
  _C2D_layer[c2dLayer].emplace_back( _C2D.size()-1 );

}


HGCTC HGC::getTC(unsigned int ID){

  return _TC[_TC_map[ID]];

}

HGCC2D HGC::getC2D(unsigned int ID){

  return _C2D[_C2D_map[ID]];

}


vector<HGCTC>  HGC::getTC_layer(unsigned layer)  { 

  vector<HGCTC> TCs;
  for(auto i : _TC_layer[layer])
    TCs.emplace_back(_TC[i]);
  return TCs;  

}

vector<HGCC2D> HGC::getC2D_layer(unsigned layer) { 

  vector<HGCC2D> C2Ds;
  for(auto i : _C2D_layer[layer])
    C2Ds.emplace_back(_C2D[i]);
  return C2Ds;  

}

vector<HGCROC> *HGC::getTD(unsigned layer) { 
    
    return _TD[layer];  

}

void HGC::getTCall( vector<HGCTC> &data ) {  

  data = _TC;

}

void HGC::getC2Dall( vector<HGCC2D> &data ) {  

  data = _C2D;

}

void HGC::getTDall( vector<HGCROC> &data ) {

    for(unsigned i=0; i<Nlayers; i++)
        data.insert(data.end(), _TD[i]->begin(), _TD[i]->end() );

}

void HGC::clear() {

    for(unsigned i=0; i<Nlayers; i++){
        _TD[i]->clear();
    }    
    
    _TC.clear();
    _C2D.clear();
    _TC_map.clear();
    _C2D_map.clear();
    _TC_layer.clear();
    _C2D_layer.clear();


}


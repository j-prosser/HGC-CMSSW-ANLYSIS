#include "ResolutionStats.h"
#include "TMath.h"

ClassImp(ResolutionStats)

// Default constructor
ResolutionStats::ResolutionStats() {
	this->init();
} 

ResolutionStats::~ResolutionStats() {} 


/* Set method declarations */
void ResolutionStats::setRadius(float radius) {_radius = radius;}
void ResolutionStats::setEta(float eta) {_eta = eta;}
void ResolutionStats::setPtGen(float PtGen) {_pt_gen = PtGen;}
void ResolutionStats::setPtReco(float PtReco) {_pt_reco = PtReco;}
void ResolutionStats::setPtReco_Gen(float PtReco_Gen) {_pt_reco_gen = PtReco_Gen;}
void ResolutionStats::setXRes(float XRes) {_xnorm_res = XRes;}
void ResolutionStats::setYRes(float YRes) {_ynorm_res = YRes;}
void ResolutionStats::setRRes(float RRes) {_rnorm_res = RRes;}

/* Get method declarations */
float ResolutionStats::Radius() const {return _radius;}
float ResolutionStats::Eta() const {return _eta;}
float ResolutionStats::PtGen() const {return _pt_gen;} 
float ResolutionStats::PtReco() const {return _pt_reco;} 
float ResolutionStats::PtReco_Gen() const {return _pt_reco_gen;} 
float ResolutionStats::XRes() const {return _xnorm_res;} 
float ResolutionStats::YRes() const {return _ynorm_res;} 
float ResolutionStats::RRes() const {return _rnorm_res;}

void ResolutionStats::init() {
	_radius = 0.;
	_eta = 0.; 
	_pt_gen = 0.;
	_pt_reco = 0.;
	_pt_reco_gen = 0.;
	_xnorm_res=0.;
	_ynorm_res=0.;
	_rnorm_res=0.;
}

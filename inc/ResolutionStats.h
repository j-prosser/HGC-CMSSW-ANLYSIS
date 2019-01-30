#ifndef RESOLUTIONSTATS_H
#define RESOLUTIONSTATS_H 1

/* c/c++ */
#include <iostream>
#include <map>     // needed to correctly generate dictionary
#include <vector>
#include <utility> // pair

/* program */
#include "HGCgen.h"
#include "HGCC3D.h"

/* ROOT */
#include "TObject.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class ResolutionStats : public TObject {

	public: 

		ResolutionStats();
		virtual ~ResolutionStats();

		ResolutionStats(HGCC3D* cluster, HGCgen* truth);

		/* set data methods*/
		void setRadius(float radius); 
		void setEta(float Eta);
		void setPtRes(float PtRes); 
		void setXRes(float XRes);
		void setYRes(float YRes); 
		void setRRes(float RRes); 

		/* get data methods*/
		float Radius() const;
		float Eta() const;
		float PtRes() const;
		float XRes() const;
		float YRes() const; 
		float RRes() const; 

		void init();

	ClassDef(ResolutionStats, 1)//Moved to public
	private:
		/* direct */
		Float_t _radius;
		Float_t _eta;
		Float_t _pt_res;
		Float_t _xnorm_res;
		Float_t _ynorm_res;
		Float_t _rnorm_res;
		/* derived */
};
#endif

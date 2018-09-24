#ifndef HGCGEN_H
#define HGCGEN_H 1

/* c/c++ */
#include <iostream>
#include <map>     // needed to correctly genreate dictionary
#include <vector>
#include <utility> // pair

/* mylibs */
#include "detId.h"

/* ROOT */
#include "TObject.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "Math/Point3D.h"
#include "TF1.h"
#include "TDatabasePDG.h"

using namespace std;


class HGCgen : public TObject {


public:

    HGCgen();
    ~HGCgen();

    static int charge(int i);

    void setPDGid   ( int   PDGid  );
    void setId      ( int   id     );
    void setStatus  ( float Status );
    void setEnergy  ( float Energy );
    void setPt      ( float Pt     );
    void setEta     ( float Eta    );
    void setPhi     ( float Phi    );
    void setGenjetId( int   genjetId );

    int   PDGid ();
    int   id    ();
    float Status();
    float Energy();
    float Pt    ();
    float Eta   ();
    float Phi   ();
    int   genjetId();
    
    float xNorm ();
    float yNorm ();
    
    ROOT::Math::RhoEtaPhiPoint getZprojection( double z );
    
    float distanceNorm(HGCgen*);
    float distanceEtaPhi(HGCgen*);

    // which endcap?
    int getEndcapId();

    // return the phi sector of the projection in z
    int getPhiSectorProj(unsigned nPhi, double* minPhi, double* maxPhi, double z);

    // get hough transform func
    TF1 getHT(double z, double zOffset, double zWeight=1);

   
private:

    //int myCharge();

    int   _genjetId;
    int   _PDGid   ;
    int   _id      ;
    float _Status;
    float _Energy; // GeV
    float _Pt    ; // GeV
    float _Eta   ;
    float _Phi   ;
    
    ClassDef(HGCgen, 1);

};

#endif


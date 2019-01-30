#include "utils.h"
#include <cmath> 

float getDist(HGCC3D& cluster, HGCgen& truth) {
	float result = 0.;	
	float xs = cluster.xNorm() - truth.xNorm();
	float ys = cluster.yNorm() - truth.yNorm();
	result =  xs*xs + ys*ys;
	return sqrt(result); 
}

float abs_diff_pt(HGCC3D& cluster, HGCgen& truth) { 
	return abs( truth.Pt() -  cluster.Pt() ); 
}


ResolutionStats CalculateStats(HGCC3D& cluster, HGCgen* truth, float radius) {
	ResolutionStats result = ResolutionStats(); 
	result.setRadius(radius);
	result.setEta(truth->Eta());
	// Pt res: Pt^cl / Pt^gen
	result.setPtRes( cluster.Pt() / truth->Pt() );
	result.setXRes( cluster.xNorm() - truth->xNorm()  );
	result.setYRes( cluster.yNorm() - truth->yNorm() ); 
	result.setRRes( sqrt(result.XRes()*result.XRes() + result.YRes()*result.YRes()) );
	return result;
} 

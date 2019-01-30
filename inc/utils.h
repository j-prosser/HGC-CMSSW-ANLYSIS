#include "HGCC3D.h"
#include "HGCgen.h"
#include "ResolutionStats.h"

/// Get x_diff**2 +y_diff**2
float getDist(HGCC3D& cluster, HGCgen& truth);  

// pt diff
float abs_diff_pt(HGCC3D& cluster, HGCgen& truth); 

ResolutionStats CalculateStats(HGCC3D& cluster, HGCgen* truth, float radius);

/* ----------------------------------------------------------------------
   PDPS - Particle Dynamics Parallel Simulator
   
   Copyright (2012) reserved by Lingqi Yang. 
   Email: ly2282@columbia.edu

   See the README file in the PDPS directory.
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

FixStyle(sphfloat,FixSphfloat)

#else

#ifndef PS_FIX_SPHFLOAT_H
#define PS_FIX_SPHFLOAT_H

#include "fix.h"

namespace PDPS_NS {

class FixSphfloat : public Fix {

public:
	FixSphfloat(class PDPS *, int, char **);
	~FixSphfloat();
	int setmask();
	void init();
	void setup();
	virtual void post_force();
	
protected:
	int rid, tid, newgid, refgid;           // region id, type id, new group id, reference group id
	double rho_ref, acc_ref;				//  frequency to do deletion, reference density, reference velocity, for pressure_flag

};
}

#endif
#endif

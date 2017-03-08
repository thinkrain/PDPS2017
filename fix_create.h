/* ----------------------------------------------------------------------
   PDPS - Particle Dynamics Parallel Simulator
   
   Copyright (2012) reserved by Lingqi Yang. 
   Email: ly2282@columbia.edu

   See the README file in the PDPS directory.
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

FixStyle(create,FixCreate)

#else

#ifndef PS_FIX_CREATE_H
#define PS_FIX_CREATE_H

#include "fix.h"

namespace PDPS_NS {

	class FixCreate : public Fix {

public:
	FixCreate(class PDPS *, int, char **);
	~FixCreate();
	int setmask();
	void init();
	void setup();
	virtual void post_force();
	
protected:
	int rid, tid, newgid, gengid;					 // region id, type id, new group id, group of place to generation
	double ratio;
	class RanMars *random;
	int seed;
	double radius_bubble;
	double mass_bubble;
	double rho_bubble;
	int fixed_flag;
	int random_flag;
	double eps;
};
}

#endif
#endif

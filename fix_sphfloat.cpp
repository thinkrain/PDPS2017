/* ----------------------------------------------------------------------
   PDPS - Particle Dynamics Parallel Simulator
   
   Copyright (2012) reserved by Lingqi Yang. 
   Email: ly2282@columbia.edu

   See the README file in the PDPS directory.
------------------------------------------------------------------------- */

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "create_particle.h"
#include "neighbor.h"
#include "neigh_list.h"
#include "domain.h"
#include "error.h"
#include "fix_sphfloat.h"
#include "particle.h"
#include "particle_type.h"
#include "region.h"
#include "random_park.h"
#include "update.h"
#include "group.h"
#include "update.h"
#include "compute.h"
#include "modify.h"

using namespace PDPS_NS;
using namespace FixConst;
enum{UP, DOWN, FRONT, BACK, LEFT, RIGHT};

/* ---------------------------------------------------------------------- */

FixSphfloat::FixSphfloat(PDPS *ps, int narg, char **arg) : Fix(ps, narg, arg)
{
	if (narg < 7) {
		error->all(FLERR,"Illegal fix Sphfloat command");
	}

	newgid = group->find_group(arg[3]);
	refgid = group->bitmask[newgid];
	rho_ref = atof(arg[4]);
	acc_ref = atof(arg[5]);
	
}

/* ---------------------------------------------------------------------- */

FixSphfloat::~FixSphfloat()
{

}

/* ---------------------------------------------------------------------- */

int FixSphfloat::setmask()
{
	int mask = 0;
	mask |= POST_FORCE;
	return mask;
}

/* ---------------------------------------------------------------------- */

void FixSphfloat::init()
{

}

/* ---------------------------------------------------------------------- */

void FixSphfloat::setup()
{
	post_force();
}

/* ---------------------------------------------------------------------- */

void FixSphfloat::post_force()
{
	double **x = particle->x;
	double **f = particle->f;
	int *mask = particle->mask;
	int *bitmask = group->bitmask;
	int *type = particle->type;
	int nlocal = particle->nlocal;
	double *poro = particle->poro;
	double *rho = particle->rho;
	double *mass = particle->mass; 

	//		judge particle's position to decide how much force subjected
	for (int i = 0; i < nlocal; i++) {
		if (mask[i] & groupbit) {
			int itype = type[i];
			f[i][2] += mass[itype]*acc_ref * poro[i] * rho_ref / rho[i];
		
		}
	}
	
	
}

/*
 * Hexapod.h
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#ifndef HEXAPOD_H_
#define HEXAPOD_H_

#ifndef LEG_H
#include "Limb.h"
#endif

class Hexapod {
private:
	Limb	Limbs[NUM_LIMBS_ON_BODY];
	char	command[NUM_LIMBS_ON_BODY*NUM_JOINTS_ON_LIMB*SIZE_COMMAND];
public:
	Hexapod();
	~Hexapod();
};

#endif /* HEXAPOD_H_ */

/*
 * Limb.h
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#ifndef Limb_H_
#define Limb_H_

#ifndef JOINT_H
#include "Joint.h"
#endif

#ifndef DEFINES_H
#include "defines.h"
#endif

#ifndef LIB_H
#include "lib.h"
#endif

class Limb {
private:
	int		number;
	Joint	Joints[NUM_JOINTS_ON_LIMB];
	char	command[NUM_JOINTS*SIZE_COMMAND];

public:
	Limb();
	~Limb();

	int		init(int, Joint *);
	int		startMotion(int);
	int		nextPhase(void);
	int		isInMotion(void);
	int		isStopped(void);
	void	reset(void);
	char*	getCommand(void);
};

#endif /* Limb_H_ */

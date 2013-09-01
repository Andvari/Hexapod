/*
 * Servo.h
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#ifndef JOINT_H_
#define JOINT_H_

#ifndef DEFINES_H
#include "defines.h"
#endif

#ifndef LIB_H
#include "lib.h"
#endif

class Joint {

private:
	JOINT	joint;
	int		motion;
	int		phase;
	char	command[SIZE_COMMAND];

	int		isInverse(void);
public:
	Joint(void);
	~Joint();

	int		init(Joint *);
	int		startMotion(int);
	int		nextPhase(void);
	int		isInMotion(void);
	int		isStopped(void);
	void	reset(void);
	char*	getCommand(void);
};

#endif /* JOINT_H_ */

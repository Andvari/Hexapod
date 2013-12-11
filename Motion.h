/*
 * Motion.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef MOTION_H_
#define MOTION_H_

#include "define.h"
#include "Phase.h"

class Motion {
public:
	Motion();
	Motion(int, int);								// id, num
	virtual ~Motion();

	void 	setPhase(int, Phase&);
	void	addPhase(Phase&);

	Phase&	getPhase(int);

	int		isReady();
	void	clear();
	int		lenght();
	void	print();

private:
	int id;
	int max_phases;
	int num_phases;
	Phase *phases;
};

#endif /* MOTION_H_ */

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
	Motion(int, Phase *);
	virtual ~Motion();

	int		setPhase(int, Phase);
	int		addPhase(Phase);

	Phase*	getPhase(int);

	int		isReady(void);
	void	clear(void);
	int		lenght(void);
	void	print(void);

private:
	int num_phases;
	Phase phases[MAX_PHASES];
};

#endif /* MOTION_H_ */

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
	int     addPhase(Phase);
	Phase	getPhase(int);
	int		isReady(void);
	void	clear(void);
	void	copy(Motion);
	int		lenght(void);

private:
	int num_phases;
	Phase *phases;
};

#endif /* MOTION_H_ */

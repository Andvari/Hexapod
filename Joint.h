/*
 * Joint.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef JOINT_H_
#define JOINT_H_

#include "define.h"

#include "Motion.h"

class Joint {
public:
	Joint();
	virtual ~Joint();

	int		setMotion(int, Motion);
	Motion	getMotion(int);
	int		isReady(void);
	void	clear(void);
	void	copy(Joint);
	int		lenght(void);

private:
	int		num_motions;
	Motion	*motions;
};

#endif /* JOINT_H_ */

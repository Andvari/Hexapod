/*
 * Limb.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef LIMB_H_
#define LIMB_H_

#include "define.h"
#include "Joint.h"

class Limb {
public:
	Limb();
	virtual ~Limb();

	int		setJoint(int, Joint);
	Joint	getJoint(int);
	int		isReady(void);
	void	clear(void);
	void	copy(Limb);
	int		lenght(void);

private:
	int		num_joints;
	Joint	*joints;
};

#endif /* LIMB_H_ */

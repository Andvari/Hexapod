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
	Limb(int, int, int, Joint *);
	virtual ~Limb();

	int		setJoint(int, Joint);
	int		setSide(int);
	int		setType(int);
	int		getSide();
	int		getType();
	Joint	getJoint(int);
	int		isReady(void);
	void	clear(void);
	void	copy(Limb);
	int		lenght(void);

private:
	int		num_joints;
	Joint	*joints;
	int		side;
	int		type;
};

#endif /* LIMB_H_ */

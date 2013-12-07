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
	int		addJoint(Joint);
	int		setSide(int);
	int		setType(int);

	void	updateState(int, int, char *);

	Joint*	getJoint(int);
	int		getSide(void);
	int		getType(void);

	int		isReady(void);
	void	clear(void);
	int		lenght(void);
	void	print(void);

private:
	int		num_joints;
	Joint	joints[MAX_JOINTS_ON_LIMB];
	int		side;
	int		type;
};

#endif /* LIMB_H_ */

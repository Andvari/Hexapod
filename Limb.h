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

	void	addJoint(Joint*);
	void	setId(int);

	void	updateState(int, int, char *);

	Joint*	getJoint(int);
	int		getId();

	int		isReady();
	void	clear();
	int		lenght();
	void	print();

private:
	int		id;
	int		num_joints;
	Joint	**joints;
};

#endif /* LIMB_H_ */

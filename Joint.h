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
	int		addMotion(Motion);
	int		setType(int);
	int		setBias(int);
	int		getType();
	Motion	getMotion(int);
	int		getBias(void);
	int		getType(void);
	int		isReady(void);
	void	clear(void);
	void	copy(Joint);
	int		lenght(void);

private:
	int		num_motions;
	Motion	*motions;
	int		bias;
	int		type;

};

#endif /* JOINT_H_ */

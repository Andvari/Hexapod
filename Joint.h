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
	Joint(int, int, int, int, Motion *);			// type, bias, channel, num, motions
	virtual ~Joint();

	int		setMotion(int, Motion);
	int		setChannel(int);
	int		setBias(int);
	int		setType(int);

	void	updateState(int, int, char *);

	Motion	getMotion(int);
	int		getChannel(void);
	int		getBias(void);
	int		getType(void);


	int		isReady(void);
	void	clear(void);
	int		lenght(void);

private:
	int		num_motions;
	Motion	*motions;
	int		bias;
	int		type;
	int		channel;

};

#endif /* JOINT_H_ */

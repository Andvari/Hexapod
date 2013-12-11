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

	void	addMotion(Motion*);
	void	setId(int);
	void	setType(int);
	void	setChannel(int);
	void	setBias(int);

	void	updateState(int, int, char *);

	Motion*	getMotion(int);
	int		getId();
	int		getType();
	int		getChannel();
	int		getBias();

	int		isReady();
	void	clear();
	int		lenght();
	void	print();

private:
	int		id;
	int		type;
	int		channel;
	int		bias;
	int		num_motions;
	Motion	**motions;
};

#endif /* JOINT_H_ */

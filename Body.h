/*
 * Body.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef BODY_H_
#define BODY_H_

#include "define.h"
#include "Limb.h"

class Body {
public:
	Body();
	virtual ~Body();

	void	addLimb(Limb*);
	void    setId(int);
	void	updateState(int, int, char*);

	Limb*	getLimb(int);
	int		getId();

	int		isReady();
	void	clear();
	int		lenght();
	void	print();

private:
	int id;
	int num_limbs;
	Limb **limbs;
};

#endif /* BODY_H_ */

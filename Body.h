/*
 * Body.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef BODY_H_
#define BODY_H_

#include "Limb.h"

class Body {
public:
	Body();
	Body(int, int, Limb *);
	virtual ~Body();

	int		setLimb(int, Limb);
	int		setTime(int);
	void	updateState(int, int, char*);

	Limb	getLimb(int);
	int		getTime(void);

	int		isReady(void);
	void	clear(void);
	int		lenght(void);

private:
	int num_limbs;
	Limb *limbs;
	int time;
};

#endif /* BODY_H_ */

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
	virtual ~Body();

	int		setLimb(int, Limb);
	Limb	getLimb(int);
	int		isReady(void);
	void	clear(void);
	void	copy(Body);
	int		lenght(void);

private:
	int num_limbs;
	Limb *limbs;
};

#endif /* BODY_H_ */

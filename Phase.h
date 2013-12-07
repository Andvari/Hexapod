/*
 * Phase.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef PHASE_H_
#define PHASE_H_

#include "define.h"

class Phase {
public:
	Phase();
	Phase(int);
	virtual ~Phase();

	int  setValue(int);
	void setPWM(void);

	int  getValue(void);
	int  getValueAsPWM(int);

	int  isReady(void);
	void clear(void);
	int  lenght(void);
	void print(void);

private:
	int value;
	int *pwm;
};

#endif /* PHASE_H_ */

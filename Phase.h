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
	int  getValue(void);
	int  isReady(void);
	void clear(void);
	void copy(Phase);
private:
	int value;
};

#endif /* PHASE_H_ */

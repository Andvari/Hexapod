/*
 * Phase.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Phase.h"

Phase::Phase() {
	value = NO_VALUE;
}

Phase::Phase(int n) {
	value = n;

	if((n < MIN_VALUE) || (n > MAX_VALUE)){ value = NO_VALUE; }
}

Phase::~Phase() {
}

int Phase :: setValue(int n){
	if((n < MIN_VALUE) || (n > MAX_VALUE)){ return ERROR; }

	value = n;

	return OK;
}

int Phase :: getValue(void){
	return value;
}

int Phase :: isReady(void){
	if (value == NO_VALUE) return ERROR;
	else return OK;
}

void Phase :: clear(void){
	value = NO_VALUE;
}

void Phase :: copy(Phase ph){
	value = ph.getValue();
}


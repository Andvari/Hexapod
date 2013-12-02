/*
 * Phase.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Phase.h"

Phase::Phase() {
	value = -1;
}

Phase::~Phase() {
}

void Phase :: setValue(int n){
	value = n;
}

int Phase :: getValue(void){
	return value;
}

int Phase :: isReady(void){
	if (value == -1) return FALSE;
	else return TRUE;
}

void Phase :: clear(void){
	value = -1;
}

void Phase :: copy(Phase ph){
	this->value = ph.getValue();
}


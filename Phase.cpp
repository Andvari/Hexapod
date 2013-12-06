/*
 * Phase.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Phase.h"

Phase::Phase() {

	pwm = new int[MAX_POSITIONS];
	value = NO_VALUE;

	setPWM();
}

Phase::Phase(int v) {
	value = v;

	if((v < MIN_VALUE) || (v > MAX_VALUE)){ value = NO_VALUE; }

	setPWM();
}

Phase::~Phase() {
}

int Phase :: setValue(int v){
	if((v < MIN_VALUE) || (v > MAX_VALUE)){ return ERROR; }

	value = v;

	return OK;
}

int Phase :: getValue(void){
	return value;
}

int Phase :: getValueAsPWM(void){
	return pwm[value];
}

int Phase :: isReady(void){
	if (value == NO_VALUE) return ERROR;
	else return OK;
}

void Phase :: clear(void){
	value = NO_VALUE;
}

int Phase :: lenght(void){
	return (1);
}

void Phase :: setPWM(void){

	int p=MIN_PWM;
	int i=0;

	while(p <= MAX_PWM){
		pwm[i++] = p;
		p += (MAX_PWM - MIN_PWM)/(MAX_POSITIONS-1);
	}
}

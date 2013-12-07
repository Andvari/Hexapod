/*
 * Motion.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Motion.h"
#include "stdio.h"

Motion::Motion() {
	num_phases = 0;
}

Motion::Motion(int n, Phase *p){
	num_phases = 0;

	for(int i=0; i<n; i++){
		phases[i] = p[i];
	}

	num_phases = n;
}

Motion::~Motion() {
}

int Motion :: setPhase(int n, Phase p){
	if (( n < MIN_NUM_PHASE ) || ( n > num_phases - 1 )) { return ERROR; }

	phases[n] = p;
	return OK;
}

int Motion :: addPhase(Phase p){
	if (( num_phases < MIN_NUM_PHASE ) || ( num_phases > MAX_NUM_PHASE)) { return ERROR; }

	phases[num_phases++] = p;
	return OK;
}

Phase* Motion :: getPhase(int n){
	Phase *p = new Phase();

	if(n < num_phases){
		return &phases[n];
	}

	return p;
}

int Motion :: isReady(void){
	if(num_phases == 0){ return ERROR; }

	for(int i=0; i<num_phases; i++){
		if(phases[i].isReady() != OK) return ERROR;
	}

	return OK;
}

void Motion :: clear(void){
	num_phases = 0;
}

int Motion :: lenght(void){
	return num_phases;
}

void Motion :: print(void){
	printf("\t\t\t\tnum_phases: %d\n", num_phases);

	for(int i=0; i<num_phases; i++){
		printf("\t\t\t\tphase %d:\n", i);
		this->getPhase(i)->print();
	}
}

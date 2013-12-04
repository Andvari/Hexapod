/*
 * Motion.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Motion.h"

Motion::Motion() {
	phases = new Phase[MAX_PHASES];
	num_phases = 0;
}

Motion::Motion(int n, Phase *p){
	phases = new Phase[MAX_PHASES];
	num_phases = 0;

	for(int i; i<n; i++){
		phases[i].copy(p[i]);
	}

	num_phases = n;
}

Motion::~Motion() {
}

int Motion :: setPhase(int n, Phase p){
	if (( n < MIN_NUM_PHASE ) || ( n > num_phases - 1 )) { return ERROR; }

	phases[n].copy(p);
	return OK;
}

int Motion :: addPhase(Phase p){

	if(num_phases == MAX_NUM_PHASE){ return ERROR; }

	phases[num_phases++].copy(p);

	return OK;
}

Phase Motion :: getPhase(int n){
	Phase p;

	if(n < num_phases){
		return phases[n];
	}

	return p;
}

int Motion :: isReady(void){
	if(num_phases == 0){ return WARNING; }

	for(int i=0; i<num_phases; i++){
		if(phases[i].isReady() != OK) return ERROR;
	}

	return OK;
}

void Motion :: clear(void){
	num_phases = 0;
}

void Motion :: copy(Motion m){

	for(int i = 0; i<m.lenght(); i++){
		phases[i].copy(m.getPhase(i));
	}

	num_phases = m.lenght();
}

int Motion :: lenght(void){
	return num_phases;
}

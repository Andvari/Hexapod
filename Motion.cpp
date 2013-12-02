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

Motion::~Motion() {
}

int Motion :: setPhase(int n, Phase p){
	if (n < num_phases){
		phases[n].copy(p);
		return OK;
	}
	else{
		return ERROR;
	}
}

Phase Motion :: getPhase(int n){
	Phase p;

	if(n < num_phases){
		return phases[n];
	}

	return p;
}

int Motion :: isReady(void){
	if(num_phases == 0){ return FALSE; }

	for(int i=0; i<num_phases; i++){
		if(phases[i].isReady() != TRUE) return FALSE;
	}

	return TRUE;
}

void Motion :: clear(void){
	num_phases = 0;
}

void Motion :: copy(Motion m){

	for(int i = 0; i<m.num_phases; i++){
		phases[i].copy(m.phases[i]);
	}

	num_phases = m.num_phases;
}

int Motion :: lenght(void){
	return num_phases;
}

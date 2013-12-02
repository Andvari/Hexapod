/*
 * Joint.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Joint.h"

Joint::Joint() {
	motions = new Motion[MAX_MOTIONS];
	num_motions = 0;
}

Joint::~Joint() {
}

int Joint :: setMotion(int n, Motion m){
	if(n < num_motions){
		motions[n].copy(m);
		return OK;
	}
	else{
		return FALSE;
	}
}

Motion Joint :: getMotion(int n){
	Motion m;

	if(n < num_motions){
		return motions[n];
	}

	return m;
}

int Joint :: isReady(void){
	if(num_motions == 0){ return FALSE; }

	for(int i=0; i<num_motions; i++){
		if(motions[i].isReady() != TRUE) return FALSE;
	}

	return TRUE;
}

void Joint :: clear(void){
	num_motions = 0;
}

void Joint :: copy(Joint j){
	for(int i=0; i<num_motions; i++){
		motions[i].copy(j.motions[i]);
	}
}


int Joint :: lenght(void){
	return num_motions;
}

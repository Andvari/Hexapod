/*
 * Body.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Body.h"

#include "define.h"
#include "Limb.h"

Body::Body() {
	limbs = new Limb[MAX_LIMBS];
	num_limbs = 0;
}

Body::~Body() {
}

int Body :: setLimb(int n, Limb l){
	if(n < num_limbs){
		limbs[n].copy(l);
		return OK;
	}
	else{
		return FALSE;
	}
}

Limb Body :: getLimb(int n){
	Limb l;

	if(n < num_limbs){
		return limbs[n];
	}

	return l;
}

int Body :: isReady(void){
	for(int i=0; i<num_limbs; i++){
		if(limbs[i].isReady() != TRUE) return FALSE;
	}

	return TRUE;
}

void Body :: clear(void){
	num_limbs = 0;
}

void Body :: copy(Body b){
	for(int i=0; i<num_limbs; i++){
		limbs[i].copy(b.getLimb(i));
	}

	num_limbs = b.lenght();
}

int Body :: lenght(void){
	return num_limbs;
}

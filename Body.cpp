/*
 * Body.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Body.h"
#include "define.h"
#include "Limb.h"
#include "string.h"
#include "stdio.h"

Body::Body() {
	limbs = new Limb[MAX_LIMBS];
	num_limbs = NO_LIMBS;
	//time = NO_TIME;
	time = 1234;
}

Body::Body(int t, int n, Limb *l){

	setTime(t);

	num_limbs = n;

	for(int i=0; i<n; i++){
		limbs[i] = l[i];
	}
}

Body::~Body() {
}

int Body :: setLimb(int n, Limb l){
	if(n < num_limbs){
		limbs[n] = l;
		return OK;
	}
	else{
		return ERROR;
	}
}

int Body::setTime(int t){

	if( (t < MIN_TIME) || (t > MAX_TIME) ) { return ERROR; }

	time = t;
	return OK;
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
		if(limbs[i].isReady() != OK) return ERROR;
	}

	return OK;
}

void Body :: clear(void){
	num_limbs = 0;
	time = NO_TIME;
}

int Body :: lenght(void){
	return num_limbs;
}

void Body :: updateState(int m, int p, char *line){
	int i;
	char c;

	line[0] = 0;

	for(int i=0; i<lenght(); i++){
		limbs[i].updateState(m, p, &line[strlen(line)]);
	}

	i = strlen(line);

	line[i++] = 'T';

	if((c = (int)(time%100000/10000)) != 0) { line[i++] = 48 + c; }
	if((c = (int)(time%10000/1000)) != 0) { line[i++] = 48 + c; }
	if((c = (int)(time%1000/100)) != 0) { line[i++] = 48 + c; }
	if((c = (int)(time%100/10)) != 0) { line[i++] = 48 + c; }
	if((c = (int)(time%10/1)) != 0) { line[i++] = 48 + c; }

	line[i++] = 0;

}

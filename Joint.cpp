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
	type = NO_TYPE;
	bias = NO_BIAS;
	side = NO_SIDE;
}

Joint::~Joint() {
}

int Joint :: setMotion(int n, Motion m){
	if((n < MIN_NUM_MOTION) || ( n > MAX_NUM_MOTION )){ return ERROR; }

	motions[n].copy(m);
	return OK;
}

int Joint :: addMotion(Motion m){
	if(num_motions  ==  MAX_NUM_MOTION){ return ERROR; }

	motions[num_motions++].copy(m);
	return OK;
}

int Limb :: setSide(int s){
	if(s == LEFT) { side = LEFT; return OK; }
	if(s == RIGHT) { side = RIGHT; return OK; }

	return ERROR;
}

int Limb :: setType(int t){
	if(t == TOP) { type = TOP; return OK; }
	if(t == MID) { type = MID; return OK; }
	if(t == BOT) { type = BOT; return OK; }

	return ERROR;
}


int Limb :: getSide(){
	return side;
}

int Limb :: getType(){
	return type;
}


int Joint :: setBias(int b){
	bias = b;
	return OK;
}

Motion Joint :: getMotion(int n){
	Motion m;

	if(n < num_motions){
		return motions[n];
	}

	return m;
}

int Joint :: getBias(void){
	return bias;
}

int	Joint :: getType(void){
	return type;
}

int Joint :: isReady(void){
	if(num_motions == 0){ return ERROR; }

	for(int i=0; i<num_motions; i++){
		if(motions[i].isReady() != OK) return ERROR;
	}

	if (bias == NO_BIAS) return ERROR;

	if(type == NO_TYPE) return ERROR;

	return OK;
}

void Joint :: clear(void){
	num_motions = 0;
	bias = NO_BIAS;
	type = NO_TYPE;
}

void Joint :: copy(Joint j){
	for(int i=0; i<j.lenght(); i++){
		motions[i].copy(j.motions[i]);
	}

	num_motions = j.lenght();
	bias = j.getBias();
	type = j.getType();
}


int Joint :: lenght(void){
	return num_motions;
}

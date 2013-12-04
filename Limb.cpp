/*
 * Limb.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Limb.h"

Limb::Limb() {
	joints = new Joint[MAX_JOINTS_ON_LIMB];
	num_joints = 0;
	side = NO_SIDE;
	type = NO_LIMB_TYPE;
}

Limb::Limb(int s, int t, int n, Joint *j) {
	joints = new Joint[MAX_JOINTS_ON_LIMB];

	setSide(s);
	setType(t);

	if ((n >= MIN_NUM_JOINT) && (n <= MAX_NUM_JOINT)){
		num_joints = n;
		for(int i=0; i<n; i++){
			setJoint(i, j[i]);
		}
	}
}

Limb::~Limb() {
}

int Limb :: setJoint(int n, Joint j){
	if((n < MIN_NUM_JOINT)||(n > MAX_NUM_JOINT)) { return ERROR; }

	joints[n].copy(j);
	return OK;
}

Joint Limb :: getJoint(int n){
	Joint j;

	if(n < num_joints){
		return joints[n];
	}

	return j;
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

int Limb :: isReady(void){
	if(num_joints == NO_JOINTS) { return ERROR; }
	if(side == NO_SIDE) { return ERROR; }
	if(type == NO_TYPE) { return ERROR; }

	for(int i=0; i<num_joints; i++){
		if(joints[i].isReady() != OK) return ERROR;
	}

	return OK;
}

void Limb :: clear(void){
	num_joints = NO_JOINTS;
	side = NO_SIDE;
	type = NO_LIMB_TYPE;
}

void Limb :: copy(Limb l){
	for(int i=0; i<l.lenght(); i++){
		joints[i].copy(l.getJoint(i));
	}

	num_joints = l.lenght();
	side = l.getSide();
	type = l.getType();
}

int Limb :: lenght(void){
	return num_joints;
}

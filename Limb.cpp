/*
 * Limb.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Limb.h"
#include "string.h"
#include "stdio.h"

Limb::Limb() {
	num_joints = NO_JOINTS;
	side = NO_SIDE;
	type = NO_LIMB_TYPE;
}

Limb::Limb(int s, int t, int n, Joint *j) {

	setSide(s);
	setType(t);

	if ((n >= MIN_NUM_JOINT) && (n <= MAX_NUM_JOINT)){
		num_joints = n;
		for(int i=0; i<n; i++){
			setJoint(i, j[i]);
			if(getSide() == LEFT){
				joints[i].setType(FORWARD);
			}
			else{
				joints[i].setType(BACKWARD);
			}
		}
	}
}

Limb::~Limb() {
}

int Limb :: setJoint(int n, Joint j){
	if((n < MIN_NUM_JOINT)||(n > MAX_NUM_JOINT)) { return ERROR; }

	joints[n] = j;

	return OK;
}

int Limb :: addJoint(Joint j){
	if((num_joints < MIN_NUM_JOINT)||(num_joints > MAX_NUM_JOINT)) { return ERROR; }

	joints[num_joints++] = j;

	return OK;
}

Joint* Limb :: getJoint(int n){
	Joint *j = new Joint();

	if(n < num_joints){
		return &joints[n];
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

int Limb :: lenght(void){
	return num_joints;
}

void Limb :: updateState(int m, int p, char *line){
	int i;

	line[0] = 0;

	for(i=0; i<lenght(); i++){
		this->getJoint(i)->updateState(m, p, &line[strlen(line)]);
	}
}

void Limb :: print(void){
	printf("\t\tside: %d type: %d\n", side, type);
	printf("\t\tnum_joints: %d\n", num_joints);
	for(int i=0; i<num_joints; i++){
		printf("\t\tjoint: %d\n", i);
		this->getJoint(i)->print();
	}
}

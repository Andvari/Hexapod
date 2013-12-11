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
	id = NO_ID;
	num_joints = NO_JOINTS_DEFINED;
	joints = NULL;
}

Limb::~Limb() {
}

void Limb :: addJoint(Joint *j){
	Joint **tmp;

	tmp = new Joint*[num_joints];

	for(int i=0; i<num_joints; i++){ tmp[i] = joints[i]; }

	delete joints;

	joints = new Limb*[num_joints+1];

	for(int i=0; i<num_joints; i++){ joints[i] = tmp[i]; }

	joints[num_joints++] = j;

	delete tmp;
}

void Limb :: setId(int id){ this->id = id; }

Joint* Limb :: getJoint(int n){

	if(n >= num_joints){
		printf("Limb id: %d, getJoint(%d) error\n", id, n);
		_exit(ERROR);
	}

	return joints[n];
}

int Limb :: getId() { return id; }

int Limb :: isReady(void){
	if(id == NO_ID) {
		printf("Limb isReady() error (NO_ID)\n");
		return ERROR;
	}
	if(num_joints == NO_JOINTS_DEFINED) {
		printf("Limb id: %d, isReady() error (NO_JOINTS_DEFINED)\n", id);
		return ERROR;
	}

	for(int i=0; i<num_joints; i++){
		if(joints[i]->isReady() != OK){
			printf("Limb id: %d, isReady() error (joint: %d)\n", id, i);
			return ERROR;
		}
	}

	return OK;
}

void Limb :: clear(){
	id = NO_ID;
	num_joints = NO_JOINTS_DEFINED;
	delete joints;
}

int Limb :: lenght(){ return num_joints; }

void Limb :: updateState(int m, int p, char *line){
	int i;

	line[0] = 0;

	for(i=0; i<lenght(); i++){
		getJoint(i)->updateState(m, p, &line[strlen(line)]);
	}
}

void Limb :: print(){
	printf("\t\tnum_joints: %d\n", num_joints);
	for(int i=0; i<num_joints; i++){
		printf("\t\tjoint: %d\n", i);
		getJoint(i)->print();
	}
}

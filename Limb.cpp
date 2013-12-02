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
}

Limb::~Limb() {
}

int Limb :: setJoint(int n, Joint j){
	if(n < num_joints){
		joints[n].copy(j);
		return OK;
	}
	else{
		return FALSE;
	}
}

Joint Limb :: getJoint(int n){
	Joint j;

	if(n < num_joints){
		return joints[n];
	}

	return j;
}

int Limb :: isReady(void){
	if(num_joints == 0){ return FALSE; }

	for(int i=0; i<num_joints; i++){
		if(joints[i].isReady() != TRUE) return FALSE;
	}

	return TRUE;
}

void Limb :: clear(void){
	num_joints = 0;
}

void Limb :: copy(Limb l){
	for(int i=0; i<num_joints; i++){
		joints[i].copy(l.getJoint(i));
	}

	num_joints = l.lenght();
}

int Limb :: lenght(void){
	return num_joints;
}

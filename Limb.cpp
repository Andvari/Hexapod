/*
 * Limb.cpp
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#include "Limb.h"

Limb :: Limb(){
	this->number = -1;
	this->command[0] = 0;
}

Limb :: ~Limb(){

}

int Limb :: init(int number, Joint *joints){

	if(isInRange(number, 0, NUM_LIMBS_ON_BODY)){
		this->number = number;
	}
	else{
		return FALSE;
	}

	for(int i=0; i<NUM_JOINTS_ON_LIMB; i++){
		if(!this->Joints[i].init(&joints[i]))return FALSE;
	}

	return TRUE;
}

int Limb :: startMotion(int new_motion){

	if (this->isInMotion()) return FALSE;

	for(int i=0; i<NUM_JOINTS_ON_LIMB; i++){
		if(!this->Joints[i].startMotion(new_motion)) return FALSE;
	}

	return TRUE;
}

int Limb :: nextPhase(void){

	for(int i=0; i<NUM_JOINTS; i++){
		if(!this->Joints[i].nextPhase()) return FALSE;
	}

	return TRUE;
}

int Limb :: isInMotion(void){

	for(int i=0; i<NUM_JOINTS; i++){
		if(this->Joints[i].isInMotion()) return TRUE;
	}

	return FALSE;
}

int Limb :: isStopped(void){

	for(int i=0; i<NUM_JOINTS; i++){
		if(this->Joints[i].isInMotion()) return FALSE;
	}

	return TRUE;
}

void Limb :: reset(void){

	for(int i=0; i<NUM_JOINTS; i++){
		this->Joints[i].reset();
	}
}

char* Limb :: getCommand(void){

	this->command[0] = 0;
	for(int i=0; i<NUM_JOINTS; i++){
		strcpy(&this->command[strlen(this->command)], (char *)"#");
		itoa((this->number*NUM_JOINTS_ON_LIMB+i)+1, &this->command[strlen(this->command)]);
		strcpy(&this->command[strlen(this->command)], this->Joints[i].getCommand());
	}

	return this->command;
}

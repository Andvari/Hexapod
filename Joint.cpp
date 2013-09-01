/*
 * Joint.cpp
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#include "Joint.h"

Joint :: Joint(){

	this->joint.number = -1;
	this->joint.base = -1;
	this->joint.bias = -1;
	this->joint.inverse = -1;

	this->phase = -1;
	this->motion = -1;

	for(int i=0; i<NUM_MOTIONS; i++){
		for(int j=0; j<NUM_PHASES; j++){
			this->joint.motion[i].phase[j] = -1;
		}
	}

	this->command[0] = 0;
}

Joint :: ~Joint(){

}

int Joint :: init(Joint *joint){

	if(isInRange(joint->joint.number, 0, NUM_JOINTS_ON_LIMB-1)){
		this->joint.number = joint->joint.number;
	}
	else{
		return FALSE;
	}

	if(isInRange(joint->joint.base, 0, NUM_POSITIONS-1)){
		this->joint.base = joint->joint.base;
	}
	else{
		return FALSE;
	}

	if(isInRange(joint->joint.bias, 0, MAX_BIAS)){
		this->joint.bias = joint->joint.bias;
	}
	else{
		return FALSE;
	}

	if(isInRange(joint->joint.inverse, 0, 1)){
		this->joint.inverse = joint->joint.inverse;
	}
	else{
		return FALSE;
	}

	this->phase = -1;
	this->motion = -1;

	for(int i=0; i<NUM_MOTIONS; i++){
		for(int j=0; j<NUM_PHASES; j++){
			if(isInRange(joint->joint.motion[i].phase[j], 0, NUM_POSITIONS-1)){
				this->joint.motion[i].phase[j] = joint->joint.motion[i].phase[j];
			}
			else{
				return FALSE;
			}
		}
	}

	return TRUE;
}

int Joint :: startMotion(int new_motion){
	if (this->isInMotion()) return FALSE;
	if((new_motion < 0)||(new_motion > NUM_MOTIONS - 1)) return FALSE;
	this->motion = new_motion;
	this->phase = 0;
	return TRUE;
}

int Joint :: nextPhase(void){
	if (this->phase == NUM_PHASES - 1) return FALSE;
	this->phase ++;
	return TRUE;
}

int Joint :: isInMotion(void){
	if (this->phase == NUM_PHASES-1){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

int Joint :: isStopped(void){
	if (this->phase == NUM_PHASES-1){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

int Joint :: isInverse(void){
	if (this->joint.inverse == INVERSE){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

void Joint :: reset(void){
	this->motion = -1;
	this->phase = -1;
}

char* Joint :: getCommand(void){
	int cmd;
	int pulse;

	if((this->motion == -1)||(this->phase == -1)){
		cmd = this->joint.base;
	}
	else{
		cmd = this->joint.motion[this->motion].phase[this->phase];
	}

	if(isInverse()){
		pulse = MAX_PULSE_WIDTH - cmd*(MAX_PULSE_WIDTH - MIN_PULSE_WIDTH)/NUM_POSITIONS - this->joint.bias;
	}
	else{
		pulse = MIN_PULSE_WIDTH + cmd*(MAX_PULSE_WIDTH - MIN_PULSE_WIDTH)/NUM_POSITIONS + this->joint.bias;
	}

	if(pulse < MIN_PULSE_WIDTH) pulse = MIN_PULSE_WIDTH;
	if(pulse > MAX_PULSE_WIDTH) pulse = MAX_PULSE_WIDTH;

	itoa(pulse, this->command);

	return this->command;
}

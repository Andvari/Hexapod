/*
 * Servo.cpp
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#include "Servo.h"
#include "stdring.h"

void Servo::Servo(int new_base, int new_bias, int *p[]){
	this->base = new_base;
	this_bias = new_bias;

	for(int i=0; i<NUM_MOTIONS; i++){
		for(int j=0; j<NUM_PHASES; j++){
			this->phases[i][j] = p[i][j];
		}
	}

	for(i=0; i<sizeof(this->command); i++){
		this->command[i] = 0;
	}

	this->command[0] = "P";
}

int Servo :: startMotion(int new_motion){
	if (this->isInMotion()) return FALSE;
	if((new_motion < 0)||(new_motion > NUM_MOTIONS - 1)) return FALSE;
	this->motion = new_motion;
	this->phase = 0;
	return TRUE;
}

int Servo :: nextPhase(void){
	if (this->phase == NUM_PHASES - 1) return FALSE;
	this->phase ++;
	return TRUE;
}

int Servo :: isInMotion(void){
	if (this->phase == NUM_PHASES-1){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

int Servo :: isStopped(void){
	if (this->phase == NUM_PHASES-1){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

void reset(void){
	this->motion = -1;
	this->phase = -1;
}

char* getCommand(void){
	return this->command;
}

/*
 * Joint.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Joint.h"
#include "stdlib.h"
#include "string.h"

Joint::Joint() {
	motions = new Motion[MAX_MOTIONS];
	num_motions = 0;
	setType(NO_TYPE);
	setBias(NO_BIAS);
}

Joint::Joint(int t, int b, int c, int n, Motion *m){
	motions = new Motion[MAX_MOTIONS];

	setType(t);
	setBias(b);
	setChannel(c);

	num_motions = n;

	for(int i=0; i<n; i++){
		motions[i] = m[i];
	}
}

Joint::~Joint() {
}

int Joint :: setMotion(int n, Motion m){
	if((n < MIN_NUM_MOTION) || ( n > MAX_NUM_MOTION )){ return ERROR; }

	motions[n] = m;
	return OK;
}

int Joint :: setChannel(int c){
	if((c<MIN_NUM_CHANNEL)||(c>MAX_NUM_CHANNEL)) { return ERROR; }
	channel = c;
	return OK;
}

int Joint :: setType(int t){
	if(t == FORWARD)  { type = FORWARD; return OK; }
	if(t == BACKWARD) { type = BACKWARD; return OK; }

	return ERROR;
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

int Joint :: getChannel(void){
	return channel;
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

int Joint :: lenght(void){
	return num_motions;
}

void Joint :: updateState(int m, int p, char *line){
	int pwm;
	int i;
	char c;

	if(this->type == FORWARD){
		pwm = getMotion(m).getPhase(p).getValueAsPWM() + this->getBias();
	}
	else{
		pwm = getMotion(m).getPhase(MAX_PHASES - p).getValueAsPWM() + this->getBias();
	}

	if(pwm < MIN_PWM){ pwm = MIN_PWM; }
	if(pwm > MAX_PWM){ pwm = MAX_PWM; }

	i=0;

	if(channel >= 10){
		line[i++] = 48 + (int)(channel/10);
	}

	line[i++] = 48 + channel%10;

	line[i++] = 'P';

	if ((c = (int)(pwm%10000/1000)) != 0) { line[i++] = 48 + c; }
	if ((c = (int)(pwm%1000/100)) != 0) { line[i++] = 48 + c; }
	if ((c = (int)(pwm%100/10)) != 0) { line[i++] = 48 + c; }
	if ((c = (int)(pwm%10/1)) != 0) { line[i++] = 48 + c; }

	line[i++] = 0;

}

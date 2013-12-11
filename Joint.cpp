/*
 * Joint.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Joint.h"

Joint::Joint() {
	id = NO_ID;
	channel = NO_CHANNEL_DEFINED;
	type = NO_TYPE_DEFINED;
	bias = NO_BIAS_DEFINED;
	num_motions = NO_MOTIONS_DEFINED;
	motions = NULL;
}

Joint::~Joint() {
}

void Joint :: addMotion(Motion *m){
	Motion **tmp;

	tmp = new Motion*[num_motions];

	for(int i=0; i<num_motions; i++){ tmp[i] = motions[i]; }

	delete motions;

	motions = new Motion*[num_motions+1];

	for(int i=0; i<num_motions; i++){ motions[i] = tmp[i]; }

	motions[num_motions++] = m;

	delete tmp;
}

void Joint :: setId(int id){ this->id = id; }

void Joint :: setChannel(int c){

	if((c >= MIN_NUM_CHANNEL)&&(c <= MAX_NUM_CHANNEL)){ channel = c; }
	else{
		printf("Joint id: %d, setChannel(%d) error\n", id, c);
		_exit(ERROR);
	}
}

void Joint :: setType(int t){
	if((t == TYPE_FORWARD) || (t == TYPE_BACKWARD))  { type = t; }
	else{
		printf("Joint id: %d, setType(%d) error\n", id, t);
		_exit(ERROR);
	}
}

void Joint :: setBias(int b){
	if((b>=MIN_BIAS)&&(b<=MAX_BIAS)){ bias = b; }
	else{
		printf("Joint id: %d, setBias(%d) error\n", id, b);
		_exit(ERROR);
	}
}

Motion* Joint :: getMotion(int n){

	if(n >= num_motions){
		printf("Joints id: %d, getMotion(%d) error\n", id, n);
		_exit(ERROR);
	}

	return motions[n];
}

int Joint :: getId() { return id; }

int Joint :: getChannel(){ return channel; }

int Joint :: getBias(){ return bias; }

int	Joint :: getType(){ return type; }

int Joint :: isReady(void){
	if(id == NO_ID) { printf("Joint isReady() error (NO_ID)\n"); return ERROR; }
	if(type == NO_TYPE_DEFINED) { printf("Joint id: %d, isReady() error (NO_TYPE_DEFINED)\n", id); return ERROR; }
	if(bias == NO_BIAS_DEFINED) { printf("Joint id, %d, isReady() error (NO_BIAS_DEFINED)\n", id); return ERROR; }
	if(channel == NO_CHANNEL_DEFINED){ printf("Joint id: %d, isReady() error (NO_CHANNEL_DEFINED)\n", id); return ERROR; }
	if(num_motions == NO_MOTIONS_DEFINED){ printf("Joint id: %d, isReady() error (NO_MOTIONS_DEFINED)\n", id); return ERROR; }

	for(int i=0; i<num_motions; i++){
		if(motions[i]->isReady() != OK) return ERROR;
	}

	return OK;
}

void Joint :: clear(){
	id = NO_ID;
	type = NO_TYPE_DEFINED;
	channel = NO_CHANNEL_DEFINED;
	bias = NO_BIAS_DEFINED;;
	num_motions = NO_MOTIONS_DEFINED;
	delete motions;
}

int Joint :: lenght(void){ return num_motions; }

void Joint :: updateState(int m, int p, char *line){
	int pwm;
	int i;
	int flag;
	int c;

	pwm = getMotion(m)->getPhase(p)->getValueAsPWM(this->getType()) + this->getBias();

	if(pwm < MIN_PWM){ pwm = MIN_PWM; }
	if(pwm > MAX_PWM){ pwm = MAX_PWM; }

	i=0;

	if(getMotion(m)->getPhase(p)->getValue() == Z_VALUE) return;

	line[i++] = '#';

	if(channel >= 10){
		line[i++] = 48 + (int)(channel/10);
	}

	line[i++] = 48 + channel%10;

	line[i++] = 'P';

	flag = 1;
	if(((c = (int)(pwm%100000/10000)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(pwm%10000/1000)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(pwm%1000/100)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(pwm%100/10)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(pwm%10/1)) != 0)||(flag == 0)) { line[i++] = 48 + c; flag = 0; }


	line[i++] = 0;

}

void Joint :: print(void){
	printf("\t\t\tbias: %d type: %d channel: %d\n", bias, type, channel);
	printf("\t\t\tnum_motions: %d\n", num_motions);
	for(int i=0; i<num_motions; i++){
		printf("\t\t\tmotion: %d\n", i);
		getMotion(i)->print();
	}
}

/*
 * Body.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Body.h"
#include "define.h"
#include "Limb.h"
#include "string.h"
#include "stdio.h"

Body::Body() {
	num_limbs = NO_LIMBS;
	time = NO_TIME;
}

Body::Body(int t, int n, Limb *l){

	setTime(t);

	num_limbs = n;

	for(int i=0; i<n; i++){
		limbs[i] = l[i];
	}
}

Body::~Body() {
}

int Body :: setLimb(int n, Limb l){
	if(n < num_limbs){
		limbs[n] = l;
		return OK;
	}
	else{
		return ERROR;
	}
}

int Body :: addLimb(Limb l){
	if((num_limbs < MIN_NUM_LIMBS) || (num_limbs > MAX_NUM_LIMBS)){ return ERROR; }
	limbs[num_limbs++] = l;
	return OK;
}

int Body::setTime(int t){

	if( (t < MIN_TIME) || (t > MAX_TIME) ) { return ERROR; }

	time = t;
	return OK;
}

Limb* Body :: getLimb(int n){
	Limb *l = new Limb();

	if(n < num_limbs){
		return &limbs[n];
	}

	return l;
}

int Body :: isReady(void){
	if(time == NO_TIME) { return ERROR; }

	for(int i=0; i<num_limbs; i++){
		if(limbs[i].isReady() != OK) return ERROR;
	}

	return OK;
}

void Body :: clear(void){
	num_limbs = 0;
	time = NO_TIME;
}

int Body :: lenght(void){
	return num_limbs;
}

void Body :: updateState(int m, int p, char *line){
	int i;
	char c;
	int flag;

	line[0] = 0;
/*
	for(i=0; i<lenght(); i++){
		this->getLimb(i)->updateState(m, p, &line[strlen(line)]);
	}
*/

	this->getLimb(3)->updateState(m, p, &line[strlen(line)]);
	this->getLimb(4)->updateState(m, p, &line[strlen(line)]);
	this->getLimb(5)->updateState(m, p, &line[strlen(line)]);
	this->getLimb(0)->updateState(m, p, &line[strlen(line)]);
	this->getLimb(1)->updateState(m, p, &line[strlen(line)]);
	this->getLimb(2)->updateState(m, p, &line[strlen(line)]);

	i = strlen(line);

	line[i++] = 'T';

	flag = 1;

	if(((c = (int)(time%100000/10000)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%10000/1000)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%1000/100)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%100/10)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%10/1)) != 0)||(flag == 0)) { line[i++] = 48 + c; flag = 0; }

	//line[i++] = '\r';
	//line[i++] = '\n';
	line[i++] = '\x0d';
	line[i++] = '\x0a';
	line[i++] = 0;

	printf("%s", line);
}

void Body :: print(void){
	printf("\ttime: %d\n", time);
	printf("\tnum_limbs: %d\n", num_limbs);
	for(int i=0; i<num_limbs; i++){
		printf("\tlimb: %d\n", i);
		this->getLimb(i)->print();
	}
}

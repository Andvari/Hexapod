/*
 * Body.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#include "Body.h"

Body::Body() {
	id = NO_ID;
	num_limbs = NO_LIMBS_DEFINED;
	limbs = NULL;
}

Body::~Body() {
}

void Body :: addLimb(Limb *l){
	Limb **tmp;

	tmp = new Limb*[num_limbs];

	for(int i=0; i<num_limbs; i++){ tmp[i] = limbs[i]; }

	delete limbs;

	limbs = new Limb*[num_limbs+1];

	for(int i=0; i<num_limbs; i++){
		limbs[i] = tmp[i];
	}

	limbs[num_limbs++] = l;

	delete tmp;
}

void Body::setId(int id){ this->id = id; }

Limb* Body :: getLimb(int n){

	if(n >= num_limbs){
		printf("Body id: %d, getLimb(%d) error\n", id, n);
		_exit(ERROR);
	}

	return limbs[n];
}

int Body :: getId(){ return id; }

int Body :: isReady(){
	if(id == NO_ID) {
		printf("Body isReady() error (NO_ID)\n");
		return ERROR;
	}

	for(int i=0; i<num_limbs; i++){
		if(limbs[i]->isReady() != OK){
			printf("Body id: %d, isReady() error (limb: %d)\n", id, i);
			return ERROR;
		}
	}

	return OK;
}

void Body :: clear(){
	id = NO_ID;
	num_limbs = NO_LIMBS_DEFINED;
	delete limbs;
}

int Body :: lenght(){ return num_limbs; }

void Body :: updateState(int m, int p, char *line){
	int i;
	char c;
	int flag;

	line[0] = 0;

	for(i=0; i<lenght(); i++){
		getLimb(i)->updateState(m, p, &line[strlen(line)]);
	}

	i = strlen(line);

	line[i++] = 'T';

	flag = 1;
/*
	if(((c = (int)(time%100000/10000)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%10000/1000)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%1000/100)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%100/10)) != 0) || (flag == 0)) { line[i++] = 48 + c; flag = 0; }
	if(((c = (int)(time%10/1)) != 0)||(flag == 0)) { line[i++] = 48 + c; flag = 0; }
*/
	line[i++] = '\r';
	line[i++] = '\n';
	line[i++] = 0;

	printf("%s", line);
}

void Body :: print(){
	printf("\tnum_limbs: %d\n", num_limbs);
	for(int i=0; i<num_limbs; i++){
		printf("\tlimb: %d\n", i);
		getLimb(i)->print();
	}
}

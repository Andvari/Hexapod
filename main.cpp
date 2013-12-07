/*
 * main.cpp
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

/*
 * SATOR
 * AREPO
 * TENET
 * OPERA
 * ROTAS
 */

#include "define.h"
#include "stdio.h"
#include "Body.h"


int main(void){
	FILE *f;
	char *line = new char[MAX_LEN_STATE*MAX_LIMBS*MAX_JOINTS_ON_LIMB];
	char str[80];

	int num_phases;

	f = fopen("motions.txt", "r");

	int i=0;
	int j=0;
	int k=0;
	int ph;

	Body hex;
	Limb limb;
	Joint joint;
	Motion motion;
	Phase phase;

	for(i=0; i<6; i++){
		hex.addLimb(limb);
		for(j=0; j<3; j++){
			hex.getLimb(i)->addJoint(joint);
		}
	}

	while(!feof(f)){
		fgets(str, sizeof(str), f);
		if(str[0] == '#') continue;
		sscanf(str, "%d", &num_phases);
		for(k = 0; k<3; k++){
			for(i = 0; i<6; i++){
				motion.clear();
				for(j=0; j<num_phases; j++){
					fscanf(f, "%d", &ph);
					phase.setValue(ph);
					motion.addPhase(phase);
				}
				hex.getLimb(i)->getJoint(k)->addMotion(motion);
				hex.getLimb(i)->getJoint(k)->setBias(0);
				if(i<3){
					hex.getLimb(i)->getJoint(k)->setType(FORWARD);
				}
				else{
					hex.getLimb(i)->getJoint(k)->setType(BACKWARD);
				}
				if(i<3){
					hex.getLimb(i)->setSide(LEFT);
				}
				else{
					hex.getLimb(i)->setSide(RIGHT);
				}
				if(i%3 == 0){
					hex.getLimb(i)->setType(TOP);
				}
				else{
					if(i%3 == 1){
						hex.getLimb(i)->setType(MID);
					}
					else{
						hex.getLimb(i)->setType(BOT);
					}
				}
			}
		}
	}


	int v=1;
	for(i=0; i<6; i++){
		for(j=0; j<3; j++){
			hex.getLimb(i)->getJoint(j)->setChannel(v++);
		}
	}

	//hex.print();

	hex.setTime(505);

	if(hex.isReady() != OK) { printf("ERROR\n"); return 0; }

	hex.updateState(0, 0, line);
	printf("%s\n", line);
	hex.updateState(0, 1, line);
	printf("%s\n", line);
	hex.updateState(0, 2, line);
	printf("%s\n", line);

	return 0;
}

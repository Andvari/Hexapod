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

	for(int i = 0; i<MAX_LIMBS; i++){

	}

	Body	hexa;

	hexa.updateState(0, 0, line);

	if(hexa.isReady() == OK){
		printf("Ready: OK\n");
	}
	else{
		printf("Ready: ERROR\n");
	}

	printf("-->%s<--\n", line);

	return 0;
}

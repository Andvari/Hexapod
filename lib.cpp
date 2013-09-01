/*
 * lib.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: nemo
 */

#ifndef DEFINES_H
#include "defines.h"
#endif

int isInRange(int val, int min, int max){

	if(val < min) return FALSE;

	if(val>max) return FALSE;

	return TRUE;
}

int isOutOfRange(int val, int min, int max){

	if(val < min) return TRUE;

	if(val>max) return TRUE;

	return FALSE;
}

int strlen(char *str){
	int i=0;

	while(str[i]!=0)i++;

	return i;
}


void itoa(int pulse, char *buf){
	int i=0, j=0;;
	char a;

	while(pulse > 0){
		a = pulse%10 + 48;
		if(a>57){
			a+=7;
		}
		buf[i++] = a;
		pulse /= 10;
	}

	buf[i++] = 'P';
	buf[i] = 0;

	for(j=0; j<i/2; j++){
		a = buf[j];
		buf[j] = buf[i-j-1];
		buf[i-j-1] = a;
	}

	return;
}


void strcpy(char *dst, char *src){
	int i;

	for(i=0; i<strlen(src); i++){
		dst[i] = src[i];
	}

	dst[i] = 0;
}

/*
 * UART.cpp
 *
 *  Created on: Dec 8, 2013
 *      Author: nemo
 */

#include "UART.h"
#include "stdio.h"
#include "string.h"
#include "fcntl.h"
#include "unistd.h"
#include "termios.h"
#include "sys/stat.h"

UART::UART() {
	struct termios options;

	fd = open("/dev/ttyACM0", O_RDWR);

	if(fd == -1) { printf("Port opening error\n"); }
	else { printf("Port opening ok\n"); }

	fcntl(fd, F_SETFL, 0);
	tcgetattr(fd, &options);

	cfsetospeed(&options, B115200);

	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_lflag &= ~ICANON;

	options.c_cc[VMIN]  = 1;
	options.c_cc[VTIME] = 0;

	tcsetattr(fd, TCSANOW, &options);
}

UART::UART(char *dev) {
	struct termios options;

	fd = open(dev, O_RDWR);

	if(fd == -1) { printf("Port opening error\n"); }
	else { printf("Port opening ok\n"); }

	fcntl(fd, F_SETFL, 0);
	tcgetattr(fd, &options);

	cfsetospeed(&options, B115200);

	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_lflag &= ~ICANON;

	options.c_cc[VMIN]  = 1;
	options.c_cc[VTIME] = 0;

	tcsetattr(fd, TCSANOW, &options);
}

UART::~UART() {
}


void UART :: sendByte(char byte){
	write(fd, &byte, 1);
	tcdrain(fd);
}

char UART :: recvByte(char *byte){
	read(fd, byte, 1);
	return (byte[0]);
}

void UART :: sendLine(char *line){

	for(unsigned int i=0; i<strlen(line); i++){
		sendByte(line[i]);
	}
}

void UART :: sendLine(char *line, int delay){

	for(unsigned int i=0; i<strlen(line); i++){
		sendByte(line[i]);
	}

	sleep(delay);
}

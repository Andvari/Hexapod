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
#include "UART.h"


int main(void){
	FILE *f;
	char *line = new char[MAX_LEN_STATE*MAX_LIMBS*MAX_JOINTS_ON_LIMB];
	char str[80];
	int time;

	int i, j, k, ph;

	int num_limbs;
	int num_joints;
	int num_phases;

	int type;
	int channel;
	int bias;

	Body hex;
	Limb limb;
	Joint joint;
	Motion motion;
	Phase phase;

	UART port;

	if((f = fopen("robot.txt", "r")) == NULL) { printf("No file \"robot.txt\" not found"); return 1; }

	fscanf(f, "%d", &num_limbs);

	for(i=0; i<num_limbs; i++){
		hex.addLimb(limb);
		fscanf(f, "%d", &num_joints);
		for(j=0; j<num_joints; j++){
			fscanf(f, "%d%d%d", &type, &channel, &bias);
			joint.setType(type);
			joint.setChannel(channel);
			joint.setBias(bias);
			hex.getLimb(i)->addJoint(joint);
			//hex.getBoardPWM()->setMode(channel, CHANNEL_USED);
		}
	}

	if((f = fopen("motions.txt", "r")) == NULL) { printf("No file \"motions.txt\" not found"); return 1; }

	while(!feof(f)){
		fgets(str, sizeof(str), f);
		if(str[0] == '#') continue;
		sscanf(str, "%d", &num_phases);
		for(k = 0; k<num_joints; k++){
			for(i = 0; i<num_limbs; i++){
				motion.clear();
				for(j=0; j<num_phases; j++){
					fscanf(f, "%d", &ph);
					phase.setValue(ph);
					motion.addPhase(phase);
				}
				hex.getLimb(i)->getJoint(k)->addMotion(motion);
			}
		}
	}

	//hex.print();

	time = 2;

	hex.setTime(time * 1000);

	if(hex.isReady()) { printf("ERROR\n"); return 0; }

	//char cmd[] = "#1P500#2P1500#3P1500#5P1800#6P1350#7P1500#10P1500#11P1350#12P1200#21P1500#22P1150#23P1500#25P1500#26P1150#27P1500#30P1500#31P1150#32P1500#4P1500#8P1500#9P1500#24P1500#28P1500#29P1500#13P500#14P1500#15P1500#16P1500#17P1500#18P1500#19P500#20P1500T1000\r\n";
	//char cmd[] = "3P15007P150012P150023P150027P150032P1500T2000\r\n";
	//char cmd[] = "#1P1500T1000\r\n";
	//port.sendLine(cmd, time);

	hex.updateState(0, 0, line);
	port.sendLine(line, time);
	//hex.updateState(0, 1, line);
	//port.sendLine(line, time);
	//hex.updateState(0, 2, line);
	//port.sendLine(line, time);


	printf("Stopped\n");
	fclose(f);

	return 0;
}

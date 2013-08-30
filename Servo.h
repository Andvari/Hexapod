/*
 * Servo.h
 *
 *  Created on: Aug 26, 2013
 *      Author: nemo
 */

#ifndef SERVO_H_
#define SERVO_H_

class Servo {

private:
	int		base	=	-1;
	int		bias	=	-1;
	int		motion	=	-1;
	int		phase	=	-1;
	int		phases[NUM_MOTIONS][NUM_PHASES];
	char	command[8];

public:
	void	Servo(int, int, int *[]);
	virtual	~Servo();

	int		startMotion(int);
	int		nextPhase(void);
	int		isInMotion(void);
	int		isStopped(void);
	void	reset(void);
	char*	getCommand(void);
};

#endif /* SERVO_H_ */

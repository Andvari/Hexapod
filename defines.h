/*
 * defines.h
 *
 *  Created on: Aug 31, 2013
 *      Author: nemo
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define	SIZE_COMMAND		10

#define	NUM_LIMBS_ON_BODY	6
#define	NUM_JOINTS_ON_LIMB	3

#define	NUM_MOTIONS			5
#define	NUM_PHASES			5

#define	TRUE				1
#define	FALSE				0

#define	DIRECT				0
#define	INVERSE				1
#define	MIXED				2

#define	NUM_POSITIONS		5
#define	MIN_PULSE_WIDTH		500
#define	MAX_PULSE_WIDTH		2500

#define NUM_JOINTS			3
#define	MAX_BIAS			20

#define	MOTION_STOP			0
#define	MOTION_FORWARD		1
#define	MOTION_REAR			2
#define	MOTION_LEFT			3
#define	MOTION_RIGHT		4
#define	MOTION_UP			5
#define	MOTION_DOWN			6

typedef struct{
	int	phase[NUM_PHASES];
}MOTION;

typedef struct{
	MOTION	motion[NUM_MOTIONS];
	int		base;
	int		bias;
	int		number;
	int		inverse;
}JOINT;

#endif /* DEFINES_H_ */

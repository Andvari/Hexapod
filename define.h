/*
 * define.h
 *
 *  Created on: Dec 2, 2013
 *      Author: nemo
 */

#ifndef DEFINE_H_
#define DEFINE_H_

#define OK		0
#define	ERROR	-1
#define	WARNING	-2

#define	LEFT	0
#define	RIGHT	1

#define	TOP			0
#define	MID			1
#define	BOT			2

#define	NULL	0

#define	MAX_POSITIONS		9
#define	MAX_PHASES			5
#define	MAX_MOTIONS			10
#define	MAX_JOINTS_ON_LIMB	3
#define	MAX_LIMBS			6

/*
 * Phase
 */
#define	NO_VALUE	(-1)
#define	MIN_VALUE	(0)
#define	MAX_VALUE	(MAX_POSITIONS-1)

/*
 * Motion
 */
#define	NO_PHASES		0
#define MIN_NUM_PHASE	0
#define	MAX_NUM_PHASE	(MAX_PHASES-1)

/*
 * Joint
 */
#define	NO_TYPE		(-1)

#define	MIN_NUM_MOTION	0
#define MAX_NUM_MOTION	(MAX_MOTIONS-1)

#define	NO_BIAS		(0x80000000)
#define	MAX_PWM		2500
#define	MIN_PWM		500

/*
 * Limb
 */
#define	NO_JOINTS		0

#define	NO_SIDE			(-1)
#define	NO_LIMB_TYPE	(-1)

#define	MIN_NUM_JOINT	0
#define	MAX_NUM_JOINT	(MAX_JOINTS_ON_LIMB-1)

#endif /* DEFINE_H_ */

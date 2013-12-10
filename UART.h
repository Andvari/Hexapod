/*
 * UART.h
 *
 *  Created on: Dec 8, 2013
 *      Author: nemo
 */

#ifndef UART_H_
#define UART_H_

class UART {
public:
	UART();
	UART(char *);
	virtual ~UART();

	void sendByte(char);
	char recvByte(char*);
	void sendLine(char*);
	void sendLine(char*, int);

private:
	int	fd;
};

#endif /* UART_H_ */

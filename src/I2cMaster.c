#include <samc21.h>
#include <I2cMaster.h>

void sercomI2cWriteAddress (Sercom *sercom, const uint8_t addr);
void sercomI2cWriteRestartAddress (Sercom *sercom, const uint8_t addr);
void sercomI2cWriteByte (Sercom *sercom, const uint8_t data);
void sercomI2cCmd (Sercom *sercom, uint8_t cmd);
void sercomI2cWait (Sercom *sercom);
uint8_t sercomI2cGetNack (Sercom *sercom);
void sercomI2cStop (Sercom *sercom);

//i2c master isr
void sercomI2cHandler (Sercom *sercom) {
	if (sercom->I2CM.INTFLAG.bit.MB) { //Master on Bus (Master transmitting)
		if (sercom->I2CM.STATUS.bit.RXNACK) { //nack
			//nack received
		} else { //ack
			//ok
		}

		sercom->I2CM.INTFLAG.reg = 0x01;
	}

	if (sercom->I2CM.INTFLAG.bit.SB) { //Slave on Bus (slave transmitting)
		sercom->I2CM.INTFLAG.reg = 0x02;
	}

	if (sercom->I2CM.INTFLAG.bit.ERROR) {
		if (sercom->I2CM.STATUS.bit.LENERR) {
			sercom->I2CM.STATUS.bit.LENERR = 1;
		}

		if (sercom->I2CM.STATUS.bit.BUSERR) {
			sercomI2cStop (sercom);
			//sys.isI2cFault = 1;
			sercom->I2CM.STATUS.bit.BUSERR = 1;
		}

		if (sercom->I2CM.STATUS.bit.SEXTTOUT) {
			sercom->I2CM.STATUS.bit.SEXTTOUT = 1;
		}

		if (sercom->I2CM.STATUS.bit.MEXTTOUT) {
			sercom->I2CM.STATUS.bit.MEXTTOUT = 1;
		}

		if (sercom->I2CM.STATUS.bit.LOWTOUT) {
			sercom->I2CM.STATUS.bit.LOWTOUT = 1;
		}

		if (sercom->I2CM.STATUS.bit.ARBLOST) {
			sercom->I2CM.STATUS.bit.ARBLOST = 1;
		}

		sercom->I2CM.INTFLAG.reg = 0x80;
	}
}

void sercomI2cReset (Sercom *sercom) {
	sercom->I2CM.CTRLA.bit.SWRST = 1;
	while (sercom->I2CM.CTRLA.bit.SWRST);
}

void initI2cMaster (Sercom *sercom) {
	sercom->I2CM.CTRLA.bit.SWRST = 1;
	while (sercom->I2CM.CTRLA.bit.SWRST);

	sercom->I2CM.CTRLA.bit.LOWTOUTEN = 1;
	sercom->I2CM.CTRLA.bit.SPEED = 0;
	sercom->I2CM.CTRLA.bit.SDAHOLD = 2;
	sercom->I2CM.CTRLA.bit.MODE = 5; //MUST BE 5 = I2C MASTER MODE
	//sercom->I2CM.CTRLA.bit.SCLSM = 1;

	//sercom->I2CM.CTRLB.bit.SMEN = 1;
	//sercom->I2CM.CTRLB.bit.QCEN = 1;

	//sercom->I2CM.BAUD.bit.BAUD = 48;
	//sercom->I2CM.BAUD.bit.BAUDLOW = 36;

	sercom->I2CM.BAUD.bit.BAUD = 64;
	sercom->I2CM.BAUD.bit.BAUDLOW = 48;

	sercom->I2CM.INTENSET.bit.ERROR = 1;
	//sercom->I2CM.INTENSET.bit.MB = 1;
	//sercom->I2CM.INTENSET.bit.SB = 1;

	sercom->I2CM.CTRLA.bit.ENABLE = 1;
	sercomI2cWait (sercom);

	sercom->I2CM.STATUS.bit.BUSSTATE = 1;
	sercomI2cWait (sercom);

	sercomI2cStop (sercom);
};

//
//SERCOM I2C MASTER
//
void sercomI2cWrite (Sercom *sercom, const uint8_t addr, const uint8_t *data, const uint8_t size) {
	uint8_t index = 0;

	sercomI2cWriteAddress (sercom, addr);
	if (sercomI2cGetNack (sercom)) {
		//printf ("i2c address 0x%02X no response\n", addr);
		sercomI2cStop (sercom);
		return;
	}

	for (index = 0; index < size; index++) {
		sercomI2cWriteByte (sercom, *(data + index));
		if (sercomI2cGetNack (sercom)) {
			break; //意外中斷
		}
	}

	sercomI2cStop (sercom);
}

void sercomI2cRead (Sercom *sercom, const uint8_t addr, const uint8_t reg, uint8_t *buf, uint8_t size) {
	uint8_t index = 0;

	//address
	sercomI2cWriteAddress (sercom, addr);
	if (sercomI2cGetNack (sercom)) {
		//printf ("i2c address 0x%02X no response\n", addr);
		sercomI2cStop (sercom);
		return;
	}

	//reg
	sercomI2cWriteByte (sercom, reg);
	if (sercomI2cGetNack (sercom)) {
		sercomI2cStop (sercom);
		return;
	}

	//re-start

	sercomI2cWriteRestartAddress (sercom, addr | 0x01);
	if (sercomI2cGetNack (sercom)) {
		sercomI2cStop (sercom);
		return;
	}

	for (index = 0; index < size; index++) {
		*(buf + index) = sercom->I2CM.DATA.bit.DATA;
		while (sercom->I2CM.INTFLAG.bit.SB == 0);

		if ((index + 1) == size) {
			sercom->I2CM.CTRLB.bit.ACKACT = 1; //FINAL BYTE, SEND NACK
		} else {
			sercom->I2CM.CTRLB.bit.ACKACT = 0; //SEND ACK
			sercomI2cCmd (sercom, 0x02); //TRIGGER READ
		}
	}

	sercomI2cStop (sercom);
}

void sercomI2cWriteAddress (Sercom *sercom, const uint8_t addr) {
	sercom->I2CM.ADDR.bit.ADDR = addr;
	while (sercom->I2CM.INTFLAG.bit.MB == 0);
}

void sercomI2cWriteRestartAddress (Sercom *sercom, const uint8_t addr) {
	sercom->I2CM.ADDR.bit.ADDR = addr;
	while (sercom->I2CM.INTFLAG.bit.SB == 0);
}

void sercomI2cWriteByte (Sercom *sercom, const uint8_t data) {
	sercom->I2CM.DATA.bit.DATA = data;
	while (sercom->I2CM.INTFLAG.bit.MB == 0);
}

void sercomI2cWait (Sercom *sercom) {
	while (sercom->I2CM.SYNCBUSY.bit.SYSOP);
}

void sercomI2cCmd (Sercom *sercom, uint8_t cmd) {
	sercom->I2CM.CTRLB.bit.CMD = cmd;
	sercomI2cWait (sercom);
}

//1:nack, 0:ack
uint8_t sercomI2cGetNack (Sercom *sercom) {
	while (sercom->I2CM.STATUS.bit.CLKHOLD == 0);
	return sercom->I2CM.STATUS.bit.RXNACK;
}

void sercomI2cStop (Sercom *sercom) {
	sercom->I2CM.CTRLB.bit.CMD = 0x03;
	sercomI2cWait (sercom);
}

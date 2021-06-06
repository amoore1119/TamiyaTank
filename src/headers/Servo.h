//
//TP-S3003
//Neutro:1520uS
//+-45 degree => +-400us
//@resolution 10us => 1.125 degree
//

typedef struct _servo {
	uint16_t neutro;
	
	uint16_t target;
	uint16_t output;
} Servo;

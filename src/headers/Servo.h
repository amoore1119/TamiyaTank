//
//TP-S3003
//Neutro:1520uS
//+-45 degree => +-400us
//@resolution 10us => 1.125 degree
//

typedef struct _servo_parameters {
	uint16_t neutro;
	uint16_t resolution; // 10us
	uint16_t rps; //range per side (400us)
	float dpr; //dgree per resolution (1.125)
} ServoParameter;

typedef struct _servo {
	ServoParameter para;
	float degree; //current degree
	
	uint16_t target;
	uint16_t output;
} Servo;

void ctrlServo (void );
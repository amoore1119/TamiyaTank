//
//
//
typedef struct _motor_dc_parameters {
	uint16_t min; //pwm starts
	uint16_t max; //pwm limits
	
	float stickRes;
} MotorParameters;

typedef struct _motor_dc_output {
	uint16_t target;
	uint16_t present;
} MotorOutput;

typedef struct _motor_dc {
	MotorParameters para;
	MotorOutput output;
	
	//hardware not support (yet)
	//uint32_t rpm;
	//uint32_t amps;
} Motor;

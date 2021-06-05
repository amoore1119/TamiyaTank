//
//
//

typedef struct _motor_dc_output {
	uint16_t min; //pwm starts
	uint16_t max; //pwm limits
	
	uint16_t target;
	uint16_t present;
	
} MotorOutput;

typedef struct _motor_dc {
	MotorOutput output;
	
	//curcuit not support (yet)
	uint32_t rpm;
	uint32_t amps;
} Motor;

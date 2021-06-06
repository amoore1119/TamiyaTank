//
//FUTABA R2008SB
//

#define RECEIVER_MODEL "R2008SB"
#define RECEIVER_CHANNLS_COUNT 8

#define RECEIVER_PPM_NEUTRO 1520
#define RECEIVER_PPM_MIN 1120
#define RECEIVER_PPM_MAX 1920

typedef struct _receiver {
	uint8_t isRunning; //
	uint16_t value[RECEIVER_CHANNLS_COUNT];
} RadioReceiver;

void receiverParser (void );

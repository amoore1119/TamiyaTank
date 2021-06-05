//
//
//

#define RECEIVER_MODEL "R2008SB"
#define RECEIVER_CHANNLS_COUNT 8

typedef struct _receiver {
	uint16_t value[RECEIVER_CHANNLS_COUNT];
} RadioReceiver;

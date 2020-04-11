#ifndef __CONTROLLER_H
#define __CONTROLLER_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "FreeRTOS.h"
#include "timers.h"
#include "dataDefs.h"

#define STATE_BLINK_PERIOD_TICKS	500
#define RESET_BLINK_PERIOD_TICKS	40
#define NUMBER_RESET_BLINKS			10
#define TIMER_INIT_TICKS			40

// called from lower down areas of the code (controller)
typedef enum { 
	CONTROLLER_SUCCESS = 0u,
	CONTROLLER_PARAMETER_ERROR = 0x10u,
	CONTROLLER_PARAMETER_END   = 0x11u,
	CONTROLLER_ERROR =0xFFu 
} eControllerResult_t;

struct state;
typedef eControllerResult_t state_function(struct state *);

struct state {
	state_function * next;
	uint32_t eventId;
};


void controllerBlinkLedCallback(TimerHandle_t xTimer);
void controllerProcess(struct state * state);

typedef eControllerResult_t(*ControllerState_t)(struct state *);

typedef struct sControllerStateStruct
{
    const uint32_t state;
    ControllerState_t execute;
} sControllerStateTable_t;

#define CONTROLLER_STATE_TABLE_END {NULL, NULL}

const sControllerStateTable_t* ControllerStateGetTable(void);

uint32_t controllerCurrentState;

#ifdef __cplusplus
}
#endif
#endif /*__CONTROLLER_H */
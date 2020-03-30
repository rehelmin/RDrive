#ifndef __CONTROLLER_H
#define __CONTROLLER_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "FreeRTOS.h"
#include "timers.h"

/*
static const uint32_t STATE_BLINK_PERIOD_TICKS = 1000;
static const uint32_t RESET_BLINK_PERIOD_TICKS = 40;
static const uint32_t NUMBER_RESET_BLINKS = 10;
*/

#define STATE_BLINK_PERIOD_TICKS	500
#define RESET_BLINK_PERIOD_TICKS	40
#define NUMBER_RESET_BLINKS			10
#define TIMER_INIT_TICKS			40

typedef enum {
	kStartupState = 1,
	kNotReadyToSwitchOnState = 2,
	kSwitchOnDisabledState = 3,
	kReadytoSwitchOnState = 4,
	kSwitchedOnState = 5,
	kOperationEnabledState = 6,
	kQuickStopActiveState = 7,
	kFaultReactionState = 8,
	kFaultState = 9,
	kLastState = 10
} eControllerState;

struct sStateTableEntry {
	eControllerState gotoNotReadytoSwitchOnEvent;
	eControllerState gotoSwitchOnDisabledEvent;
	eControllerState gotoReadyEvent;
	eControllerState gotoOnEvent;
	eControllerState gotoOperationEnabledEvent;
	eControllerState FaultEvent;
	eControllerState DisableEvent;
	eControllerState ResetEvent;
};

struct state;
typedef void state_function(struct state *);

struct state {
	state_function * next;
	uint32_t i;
};

state_function handleStartup;
state_function handleNotReadyToSwitchOn;
state_function handleSwitchOnDisabled;
state_function handleReadyToSwitchOn;
state_function handleSwitchedOn;
state_function handleOperationEnabled;
state_function handleFaultReaction;
state_function handleFault;

void controllerBlinkLedCallback(TimerHandle_t xTimer);
void controllerProcess(void);

#ifdef __cplusplus
}
#endif
#endif /*__CONTROLLER_H */
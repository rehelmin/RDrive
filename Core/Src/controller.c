#include "main.h"
#include "controller.h"

state_function controllerHandleStartup;
state_function controllerHandleNotReadyToSwitchOn;
state_function controllerHandleSwitchOnDisabled;
state_function controllerHandleReadyToSwitchOn;
state_function controllerHandleSwitchedOn;
state_function controllerHandleOperationEnabled;
state_function controllerHandleFaultReaction;
state_function controllerHandleFault;

static const sControllerStateTable_t mControllerStateTable[] =
{
	{1, &controllerHandleStartup},
	{2, &controllerHandleNotReadyToSwitchOn},
	{3, &controllerHandleSwitchOnDisabled},

	CONTROLLER_STATE_TABLE_END // must be LAST
};

void controllerBlinkLedCallback( TimerHandle_t xTimer )
{

	static uint32_t blinkCount = 0;

	if (blinkCount > (2*NUMBER_RESET_BLINKS + 2*controllerCurrentState))
	{
		blinkCount = 0;
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
		xTimerChangePeriod(xTimer, RESET_BLINK_PERIOD_TICKS, 0);
	}
	else if (blinkCount == 2*NUMBER_RESET_BLINKS)
	{
		xTimerChangePeriod(xTimer, STATE_BLINK_PERIOD_TICKS, 0);
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
	}
	else
	{
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
	}

	
	blinkCount = blinkCount + 1;

}

void controllerProcess(struct state * state)
{
	uint32_t receiveStatus;
	ControllerData_t receiveData;

	receiveStatus = xQueueReceive(controllerQueue, &receiveData, 50);
    if (receiveStatus == pdPASS) {
    	state->eventId = receiveData.event;
    }

	state->next(state); 

}

eControllerResult_t controllerHandleStartup(struct state * state)
{
	controllerCurrentState = kStartupState;
	//ConsoleData_t data;
	//data.messageBuffer = "Starting up...";

	//xQueueSend(consoleQueue, &data, 10);

	state->next = controllerHandleNotReadyToSwitchOn;

	return CONTROLLER_SUCCESS;
}

eControllerResult_t controllerHandleNotReadyToSwitchOn(struct state * state)
{
	controllerCurrentState = kNotReadyToSwitchOnState;

	if (kReqSwitchOnDisabled == state->eventId)
	{
		state->next = controllerHandleSwitchOnDisabled;
	}
	else
	{
		state->next = controllerHandleNotReadyToSwitchOn;
	}
	

	return CONTROLLER_SUCCESS;
}

eControllerResult_t controllerHandleSwitchOnDisabled(struct state * state)
{
	controllerCurrentState = kSwitchOnDisabledState;

	state->next = controllerHandleSwitchOnDisabled;

	return CONTROLLER_SUCCESS;
}


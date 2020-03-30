#include "main.h"
#include "controller.h"

uint32_t controllerCurrentState = 0;

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

void controllerProcess(void)
{
	struct state state = { handleStartup, 0 };

}

void handleStartup(struct state * state)
{
	controllerCurrentState = kStartupState;

	state->next = handleNotReadyToSwitchOn;
}

void handleNotReadyToSwitchOn(struct state * state)
{
	controllerCurrentState = kNotReadyToSwitchOnState;

	state->next = handleNotReadyToSwitchOn;
}


#include "logging.h"
#include "main.h"

uint32_t LogGlobal = 1;
LogSettings_t subsystemSettings = {
	.controllerLogLevel = eInfo,
	.motionLogLevel = eInfo,
	.communicationLogLevel = eInfo,
};

void Log(LogLevel_t levelId, LogSource_t source, char* message)
{
	if (LogGlobal)
	{
		uint32_t sendMessage = 0;
		sendMessage = (eController == source && levelId <= subsystemSettings.controllerLogLevel);
		sendMessage |= (eMotion == source && levelId <= subsystemSettings.motionLogLevel);
		sendMessage |= (eCommunication == source && levelId <= subsystemSettings.communicationLogLevel);

		if (sendMessage)
		{
			LogData_t data = {
				.levelId = levelId,
				.source = source,
				.message = message
			};
			xQueueSend(consoleQueue, &data, 10);
		}
	}
	
}

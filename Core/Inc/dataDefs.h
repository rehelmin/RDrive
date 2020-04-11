#ifndef __DATADEFS_H
#define __DATADEFS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  eStateChangeRequest = 0u
} eControllerMessageID_t;

typedef enum {
  eDebugMessage = 0u,
  eInfoMessage = 1u,
  eWarningMessage = 2u,
  eErrorMessage = 3u
} ConsoleMessageID_t;

typedef enum {
	eController = 0u,
	eMotion = 1u,
	eCommunication = 2u
} ConsoleMessageSource_t;

typedef enum {
	kStartupState = 0x1u,
	kNotReadyToSwitchOnState = 0x2u,
	kSwitchOnDisabledState = 0x3u,
	kReadytoSwitchOnState = 0x4u,
	kSwitchedOnState = 0x5u,
	kOperationEnabledState = 0x6u,
	kQuickStopActiveState = 0x7u,
	kFaultReactionState = 0x8u,
	kFaultState = 0x9u,
	kLastState = 0xAu
} eControllerState;


typedef enum {
	kReqSwitchOnDisabled = 0x3u,

} eControllerEventId_t;


typedef struct
{
  eControllerMessageID_t messageId;
  eControllerEventId_t event;
} ControllerData_t;

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
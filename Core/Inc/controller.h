#ifndef __CONTROLLER_H
#define __CONTROLLER_H
#ifdef __cplusplus
 extern "C" {
#endif

typedef enum {
	kStartupState,
	kNotReadyToSwitchOnState,
	kSwitchOnDisabledState,
	kReadytoSwitchOnState,
	kSwitchedOnState,
	kOperationEnabledState,
	kQuickStopActiveState,
	kFaultReactionState,
	kFaultState
} tState;


#ifdef __cplusplus
}
#endif
#endif /*__CONTROLLER_H */
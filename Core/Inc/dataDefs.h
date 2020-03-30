#ifndef __DATADEFS_H
#define __DATADEFS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  eStateChangeRequest = 0u
} ControllerMessageID_t;

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

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
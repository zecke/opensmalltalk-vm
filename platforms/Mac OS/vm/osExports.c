/* note: this file is only a backward compatible wrapper
   for the old-style "platform.exports" definitions.
   If your platform has migrated to the new exports
   style you may as well insert the exports right here */

#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#include <stdio.h>
#include "sqMacUIEvents.h"
#if !NewspeakVM
# include "SerialPlugin.h"
#endif

/* duh ... this is ugly */
#define XFN(export) {"", #export, (void*)export},
#define XFND(export,depth) {"", #export "\000" depth, (void*)export},

WindowPtr getSTWindow(void);
void setMessageHook(eventMessageHook theHook);
void setPostMessageHook(eventMessageHook theHook);
char * GetAttributeString(int id);
#if !NewspeakVM
int serialPortSetControl(int portNum,int control, char *data);
int serialPortIsOpen(int portNum);
int serialPortNames(int portNum, char *portName, char *inName, char *outName);
#endif
Boolean IsKeyDown(void);
int primitivePluginBrowserReady(void);

void *os_exports[][3] = {
	XFN(getSTWindow)
	XFN(setMessageHook)
	XFN(setPostMessageHook)
	XFN(GetAttributeString)
	XFN(recordDragDropEvent)
#if !NewspeakVM
	XFN(serialPortSetControl)
	XFN(serialPortIsOpen)
	XFN(serialPortClose)
	XFN(serialPortCount)
	XFN(serialPortNames)
	XFN(serialPortOpen)
	XFN(serialPortReadInto)
	XFN(serialPortWriteFrom)
#endif
	XFN(IsKeyDown)
	XFN(getUIToLock)
	{NULL, NULL, NULL}
};

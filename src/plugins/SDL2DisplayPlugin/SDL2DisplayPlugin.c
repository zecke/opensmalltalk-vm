/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.1950 uuid: b4089b49-1494-49d2-8966-57cba5c92194
   from
	SDL2DisplayPlugin SDL2DisplayPlugin-RonieSalgado.1 uuid: c606cec6-dc4b-4a7a-b88b-23bae31b229f
 */
static char __buildInfo[] = "SDL2DisplayPlugin SDL2DisplayPlugin-RonieSalgado.1 uuid: c606cec6-dc4b-4a7a-b88b-23bae31b229f " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "SDL2DisplayPlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveHasDisplayPlugin(void);
EXPORT(sqInt) primitiveSetSDL2Input(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*argumentCountOf)(sqInt methodPointer);
static sqInt (*failed)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveMethod)(void);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt argumentCountOf(sqInt methodPointer);
extern sqInt failed(void);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveMethod(void);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SDL2DisplayPlugin SDL2DisplayPlugin-RonieSalgado.1 (i)"
#else
	"SDL2DisplayPlugin SDL2DisplayPlugin-RonieSalgado.1 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}


/*	Just answer true, letting image know we're here
	 */

	/* SDL2DisplayPlugin>>#primitiveHasDisplayPlugin */
EXPORT(sqInt)
primitiveHasDisplayPlugin(void)
{
	popthenPush(1 + (argumentCountOf(primitiveMethod())), trueObject());
	return 0;
}

	/* SDL2DisplayPlugin>>#primitiveSetSDL2Input */
EXPORT(sqInt)
primitiveSetSDL2Input(void)
{
    sqInt sema;

	sema = stackIntegerValue(0);
	setSDL2InputSemaphoreIndex(sema);
	if (!(failed())) {
		pop(1);
	}
	return 0;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {

#if !defined(SQUEAK_BUILTIN_PLUGIN)
		argumentCountOf = interpreterProxy->argumentCountOf;
		failed = interpreterProxy->failed;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveMethod = interpreterProxy->primitiveMethod;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		trueObject = interpreterProxy->trueObject;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "SDL2DisplayPlugin";
void* SDL2DisplayPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveHasDisplayPlugin\000\377", (void*)primitiveHasDisplayPlugin},
	{(void*)_m, "primitiveSetSDL2Input\000\000", (void*)primitiveSetSDL2Input},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveSetSDL2InputAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
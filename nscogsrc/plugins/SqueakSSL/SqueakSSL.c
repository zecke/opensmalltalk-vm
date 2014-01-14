/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.584 uuid: f8e3994b-6462-4df0-bc8e-c71034adf6aa
   from
	SqueakSSLPlugin VMMaker.oscog-eem.584 uuid: f8e3994b-6462-4df0-bc8e-c71034adf6aa
 */
static char __buildInfo[] = "SqueakSSLPlugin VMMaker.oscog-eem.584 uuid: f8e3994b-6462-4df0-bc8e-c71034adf6aa " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "SqueakSSL.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveAccept(void);
EXPORT(sqInt) primitiveConnect(void);
EXPORT(sqInt) primitiveCreate(void);
EXPORT(sqInt) primitiveDecrypt(void);
EXPORT(sqInt) primitiveDestroy(void);
EXPORT(sqInt) primitiveEncrypt(void);
EXPORT(sqInt) primitiveGetIntProperty(void);
EXPORT(sqInt) primitiveGetStringProperty(void);
EXPORT(sqInt) primitiveSetIntProperty(void);
EXPORT(sqInt) primitiveSetStringProperty(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*nilObject)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*pushInteger)(sqInt integerValue);
static sqInt (*signed32BitIntegerFor)(sqInt integerValue);
static int (*signed32BitValueOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackObjectValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt nilObject(void);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt pushInteger(sqInt integerValue);
extern sqInt signed32BitIntegerFor(sqInt integerValue);
extern int signed32BitValueOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackObjectValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SqueakSSL VMMaker.oscog-eem.584 (i)"
#else
	"SqueakSSL VMMaker.oscog-eem.584 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

static sqInt
halt(void)
{
	;
	return 0;
}

static sqInt
msg(char *s)
{
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}


/*	Primitive. Starts or continues a server handshake using the current
	session. Will eventually produce output to be sent to the client. Requires
	the host
	and cert name to be set for the session. Returns a code indicating the
	sate of the connection:
	> 0	 - Number of bytes to be sent to the client.
	0	 - Success. The connection is established.
	-1 - More input is required.
	< -1 - Other errors.
	 */

EXPORT(sqInt)
primitiveAccept(void)
{
    sqInt dstLen;
    sqInt dstOop;
    char *dstPtr;
    sqInt handle;
    sqInt result;
    sqInt srcLen;
    sqInt srcOop;
    char *srcPtr;
    sqInt start;

	if (!((methodArgumentCount()) == 5)) {
		return primitiveFail();
	}
	dstOop = stackObjectValue(0);
	srcLen = stackIntegerValue(1);
	start = stackIntegerValue(2);
	srcOop = stackObjectValue(3);
	handle = stackIntegerValue(4);
	if (failed()) {
		return null;
	}
	if (!(((start > 0)
 && (srcLen >= 0))
		 && ((isBytes(srcOop))
		 && ((isBytes(dstOop))
		 && ((byteSizeOf(srcOop)) >= ((start + srcLen) - 1)))))) {
		return primitiveFail();
	}
	srcPtr = firstIndexableField(srcOop);
	dstPtr = firstIndexableField(dstOop);
	srcPtr = (srcPtr + start) - 1;
	dstLen = byteSizeOf(dstOop);
	result = sqAcceptSSL(handle, srcPtr, srcLen, dstPtr, dstLen);
	if (failed()) {
		return null;
	}
	pop((methodArgumentCount()) + 1);
	pushInteger(result);
}


/*	Primitive. Starts or continues a client handshake using the provided data.
	Will eventually produce output to be sent to the server. Requires the host
	name to be set for the session. 
	Returns:
	> 0	 - Number of bytes to be sent to the server
	0	 - Success. The connection is established.
	-1 - More input is required.
	< -1 - Other errors.
	 */

EXPORT(sqInt)
primitiveConnect(void)
{
    sqInt dstLen;
    sqInt dstOop;
    char *dstPtr;
    sqInt handle;
    sqInt result;
    sqInt srcLen;
    sqInt srcOop;
    char *srcPtr;
    sqInt start;

	if (!((methodArgumentCount()) == 5)) {
		return primitiveFail();
	}
	dstOop = stackObjectValue(0);
	srcLen = stackIntegerValue(1);
	start = stackIntegerValue(2);
	srcOop = stackObjectValue(3);
	handle = stackIntegerValue(4);
	if (failed()) {
		return null;
	}
	if (!(((start > 0)
 && (srcLen >= 0))
		 && ((isBytes(srcOop))
		 && ((isBytes(dstOop))
		 && ((byteSizeOf(srcOop)) >= ((start + srcLen) - 1)))))) {
		return primitiveFail();
	}
	srcPtr = firstIndexableField(srcOop);
	dstPtr = firstIndexableField(dstOop);
	srcPtr = (srcPtr + start) - 1;
	dstLen = byteSizeOf(dstOop);
	result = sqConnectSSL(handle, srcPtr, srcLen, dstPtr, dstLen);
	if (failed()) {
		return null;
	}
	pop((methodArgumentCount()) + 1);
	pushInteger(result);
}


/*	Primitive. Creates a new SSL session and returns its handle. */

EXPORT(sqInt)
primitiveCreate(void)
{
    sqInt handle;

	if (!((methodArgumentCount()) == 0)) {
		return primitiveFail();
	}
	handle = sqCreateSSL();
	if (handle == 0) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushInteger(handle);
}


/*	Primitive. Decrypts a buffer sent via the connection.
	Requires the session to be established.
	Returns:
	>=0 - Number of bytes decrypted in the result buffer
	< -1 - Other errors.
	 */

EXPORT(sqInt)
primitiveDecrypt(void)
{
    sqInt dstLen;
    sqInt dstOop;
    char *dstPtr;
    sqInt handle;
    sqInt result;
    sqInt srcLen;
    sqInt srcOop;
    char *srcPtr;
    sqInt start;

	if (!((methodArgumentCount()) == 5)) {
		return primitiveFail();
	}
	dstOop = stackObjectValue(0);
	srcLen = stackIntegerValue(1);
	start = stackIntegerValue(2);
	srcOop = stackObjectValue(3);
	handle = stackIntegerValue(4);
	if (failed()) {
		return null;
	}
	if (!(((start > 0)
 && (srcLen >= 0))
		 && ((isBytes(srcOop))
		 && ((isBytes(dstOop))
		 && ((byteSizeOf(srcOop)) >= ((start + srcLen) - 1)))))) {
		return primitiveFail();
	}
	srcPtr = firstIndexableField(srcOop);
	dstPtr = firstIndexableField(dstOop);
	srcPtr = (srcPtr + start) - 1;
	dstLen = byteSizeOf(dstOop);
	result = sqDecryptSSL(handle, srcPtr, srcLen, dstPtr, dstLen);
	if (failed()) {
		return null;
	}
	pop((methodArgumentCount()) + 1);
	pushInteger(result);
}


/*	Primitive. Destroys an SSL session. */

EXPORT(sqInt)
primitiveDestroy(void)
{
    sqInt handle;
    sqInt result;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	handle = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	result = sqDestroySSL(handle);
	if (result == 0) {
		return primitiveFail();
	}
	pop(methodArgumentCount());
}


/*	Primitive. Encrypts a buffer to be sent to the via the connection.
	Requires the session to be established.
	Returns:
	>=0 - Number of bytes encrypted in the result buffer
	< -1 - Other errors.
	 */

EXPORT(sqInt)
primitiveEncrypt(void)
{
    sqInt dstLen;
    sqInt dstOop;
    char *dstPtr;
    sqInt handle;
    sqInt result;
    sqInt srcLen;
    sqInt srcOop;
    char *srcPtr;
    sqInt start;

	if (!((methodArgumentCount()) == 5)) {
		return primitiveFail();
	}
	dstOop = stackObjectValue(0);
	srcLen = stackIntegerValue(1);
	start = stackIntegerValue(2);
	srcOop = stackObjectValue(3);
	handle = stackIntegerValue(4);
	if (failed()) {
		return null;
	}
	if (!(((start > 0)
 && (srcLen >= 0))
		 && ((isBytes(srcOop))
		 && ((isBytes(dstOop))
		 && ((byteSizeOf(srcOop)) >= ((start + srcLen) - 1)))))) {
		return primitiveFail();
	}
	srcPtr = firstIndexableField(srcOop);
	dstPtr = firstIndexableField(dstOop);
	srcPtr = (srcPtr + start) - 1;
	dstLen = byteSizeOf(dstOop);
	result = sqEncryptSSL(handle, srcPtr, srcLen, dstPtr, dstLen);
	if (failed()) {
		return null;
	}
	pop((methodArgumentCount()) + 1);
	pushInteger(result);
}


/*	Primitive. Returns an integer property for the session */

EXPORT(sqInt)
primitiveGetIntProperty(void)
{
    sqInt handle;
    sqInt propID;
    sqInt value;

	if (!((methodArgumentCount()) == 2)) {
		return primitiveFail();
	}
	propID = stackIntegerValue(0);
	handle = stackIntegerValue(1);
	if (failed()) {
		return null;
	}
	value = sqGetIntPropertySSL(handle, propID);
	if (failed()) {
		return null;
	}
	popthenPush((methodArgumentCount()) + 1, signed32BitIntegerFor(value));
}


/*	Primitive. Returns a string property for the session */

EXPORT(sqInt)
primitiveGetStringProperty(void)
{
    sqInt handle;
    sqInt i;
    char *oopPtr;
    sqInt propID;
    sqInt stringLen;
    sqInt stringOop;
    char *stringPtr;

	if (!((methodArgumentCount()) == 2)) {
		return primitiveFail();
	}
	propID = stackIntegerValue(0);
	handle = stackIntegerValue(1);
	if (failed()) {
		return null;
	}
	stringPtr = sqGetStringPropertySSL(handle, propID);
	if (failed()) {
		return null;
	}
	if (stringPtr == null) {
		stringOop = nilObject();
	}
	else {
		stringLen = strlen(stringPtr);
		stringOop = instantiateClassindexableSize(classString(), stringLen);
		oopPtr = firstIndexableField(stringOop);
		for (i = 0; i < stringLen; i += 1) {
			oopPtr[i] = (stringPtr[i]);
		}
	}
	popthenPush((methodArgumentCount()) + 1, stringOop);
}


/*	Primitive. Sets a integer property for the session */

EXPORT(sqInt)
primitiveSetIntProperty(void)
{
    sqInt handle;
    sqInt propID;
    sqInt result;
    sqInt value;

	if (!((methodArgumentCount()) == 3)) {
		return primitiveFail();
	}
	value = signed32BitValueOf(stackValue(0));
	propID = stackIntegerValue(1);
	handle = stackIntegerValue(2);
	if (failed()) {
		return null;
	}
	result = sqSetIntPropertySSL(handle, propID, value);
	if (!result) {
		return primitiveFail();
	}
	if (failed()) {
		return null;
	}
	pop(methodArgumentCount());
}


/*	Primitive. Sets a string property for the session */

EXPORT(sqInt)
primitiveSetStringProperty(void)
{
    sqInt handle;
    sqInt propID;
    sqInt result;
    sqInt srcLen;
    sqInt srcOop;
    char *srcPtr;

	if (!((methodArgumentCount()) == 3)) {
		return primitiveFail();
	}
	srcOop = stackObjectValue(0);
	propID = stackIntegerValue(1);
	handle = stackIntegerValue(2);
	if (failed()) {
		return null;
	}
	if (!(isBytes(srcOop))) {
		return primitiveFail();
	}
	srcPtr = firstIndexableField(srcOop);
	srcLen = byteSizeOf(srcOop);
	result = sqSetStringPropertySSL(handle, propID, srcPtr, srcLen);
	if (!result) {
		return primitiveFail();
	}
	if (failed()) {
		return null;
	}
	pop(methodArgumentCount());
}


/*	Note: This is coded so that it can be run in Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		nilObject = interpreterProxy->nilObject;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		pushInteger = interpreterProxy->pushInteger;
		signed32BitIntegerFor = interpreterProxy->signed32BitIntegerFor;
		signed32BitValueOf = interpreterProxy->signed32BitValueOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackObjectValue = interpreterProxy->stackObjectValue;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* SqueakSSL_exports[][3] = {
	{"SqueakSSL", "getModuleName", (void*)getModuleName},
	{"SqueakSSL", "primitiveAccept\000\001", (void*)primitiveAccept},
	{"SqueakSSL", "primitiveConnect\000\001", (void*)primitiveConnect},
	{"SqueakSSL", "primitiveCreate\000\377", (void*)primitiveCreate},
	{"SqueakSSL", "primitiveDecrypt\000\001", (void*)primitiveDecrypt},
	{"SqueakSSL", "primitiveDestroy\000\000", (void*)primitiveDestroy},
	{"SqueakSSL", "primitiveEncrypt\000\001", (void*)primitiveEncrypt},
	{"SqueakSSL", "primitiveGetIntProperty\000\000", (void*)primitiveGetIntProperty},
	{"SqueakSSL", "primitiveGetStringProperty\000\000", (void*)primitiveGetStringProperty},
	{"SqueakSSL", "primitiveSetIntProperty\000\000", (void*)primitiveSetIntProperty},
	{"SqueakSSL", "primitiveSetStringProperty\000\001", (void*)primitiveSetStringProperty},
	{"SqueakSSL", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveAcceptAccessorDepth = 1;
signed char primitiveConnectAccessorDepth = 1;
signed char primitiveDecryptAccessorDepth = 1;
signed char primitiveDestroyAccessorDepth = 0;
signed char primitiveEncryptAccessorDepth = 1;
signed char primitiveGetIntPropertyAccessorDepth = 0;
signed char primitiveGetStringPropertyAccessorDepth = 0;
signed char primitiveSetIntPropertyAccessorDepth = 0;
signed char primitiveSetStringPropertyAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */

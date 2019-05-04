#define XFN(export) {"", #export, (void*)export},
#define XFND(export,depth) {"", #export "\000" depth, (void*)export},

char * GetAttributeString(int id);
#if !defined(HEADLESS)
void *ioGetDisplay(void);
void *ioGetWindow(void);
#endif

void *os_exports[][3]=
{
  XFN(GetAttributeString)
#if !defined(HEADLESS)
	XFN(ioGetDisplay)
	XFN(ioGetWindow)
#endif
  { 0, 0, 0 }
};

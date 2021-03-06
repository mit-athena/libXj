/*
 * Various stuff stolen from the X Toolkit...
 *
 * $Id: Jets.h,v 1.4 2004-02-25 21:21:37 rbasch Exp $
 *
 * Copyright 1990, 1991 by the Massachusetts Institute of Technology. 
 *
 * For copying and distribution information, please see the file
 * <mit-copyright.h>. 
 *
 */

#ifndef _Xj_Jets_h
#define _Xj_Jets_h

#include <string.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>

#define Boolean int

typedef void (*XjInitializeProc)();
typedef void (*XjPreRealizeProc)();
typedef void (*XjRealizeProc)();
typedef Boolean (*XjEventProc)();
typedef void (*XjExposeProc)();
typedef void (*XjQuerySizeProc)();
typedef void (*XjMoveProc)();
typedef void (*XjResizeProc)();
typedef void (*XjDestroyProc)();
typedef int (*XjCallbackProc)();
typedef void (*XjProc)();

#ifdef __STDC__
typedef void*           XjPointer;
#else
typedef char*           XjPointer;
#endif

typedef struct _XjCallbackRec
{
    char *name;
    XjCallbackProc proc;
} XjCallbackRec;

#define argInt 0
#define argString 1
#define argPtr 2

typedef struct _XjCallback
{
  struct _XjCallback *next;
  int argType;
  void *passPtr;
  char *passString;
  int passInt;
  XjCallbackProc proc;
} XjCallback;

typedef struct _XjPixmap
{
  unsigned int width, height;
  int hot_x, hot_y;
  Pixmap pixmap;
} XjPixmap;

typedef struct _XjSize
{
  int width, height;
} XjSize;

typedef struct _XjResource {
    char *      resource_name;  /* Resource name                            */
    char *      resource_class; /* Resource class                           */
    char *      resource_type;  /* Representation type desired              */
    int         resource_size;  /* Size in bytes of representation          */
    int         resource_offset;/* Offset from base to put resource value   */
    char *      default_type;   /* representation type of specified default */
    caddr_t     default_addr;   /* Address of default resource              */
} XjResource;

typedef struct _CoreClassPart {
  char			*className;	/* name of this jet class */
  int			jetSize;
  XjInitializeProc	classInitialize;
  int			classInitialized;
  XjInitializeProc	initialize;
  XjPreRealizeProc	preRealize;
  XjRealizeProc		realize;
  XjEventProc		event;		/* proc to pass jet's events to */
  XjExposeProc		expose;		/* proc to pass exposes to; this
					   is for jets without windows */
  XjQuerySizeProc	querySize;
  XjMoveProc		move;
  XjResizeProc		resize;
  XjDestroyProc		destroy;
  XjResource		*resources;	/* location of resource table */
  int			num_resources;
} CoreClassPart;

typedef struct _JetClassRec {
  CoreClassPart core_class;
} JetClassRec, CoreClassRec;

typedef struct _JetClassRec *JetClass;

#define XjNumber(n) ((sizeof(n) / sizeof(n[0])))

typedef struct _CorePart {
  JetClass		classRec;	/* class record for this jet inst */
  char			*name;		/* instance name */
  Display		*display;	/* display */
  Window		window;		/* this instance's window (if any) */
  int			x, y;
  int			width, height;
  int			borderWidth;
  struct _JetRec	*parent;	/* parent of this jet */
  struct _JetRec	*sibling;	/* next sibling */
  struct _JetRec	*child;		/* first child */
  Boolean		need_expose;	/* need an expose? (set by parent) */
} CorePart;

typedef struct _JetRec {
    CorePart    core;
} JetRec, CoreRec;

typedef struct _JetRec *Jet;

#define XjParent(jet)	((jet)->core.parent)
#define XjChild(jet)	((jet)->core.child)
#define XjSibling(jet)	((jet)->core.sibling)
#define XjWindow(jet)	((jet)->core.window)
#define XjDisplay(jet)	((jet)->core.display)
#define XjName(jet)	((jet)->core.name)

typedef long XjArgVal;

extern int global_argc;
extern int malloced;
extern char **global_argv;
extern char *programName;
extern char *programClass;
extern char *displayName;
extern XrmDatabase rdb;
extern unsigned long writecolors[];
extern Colormap xjcolormap;

#define XjColormap(j) xjcolormap
#define XjGetColor(c) (writecolors[c])
#define XjNoColor -1

extern char *XjMalloc(), *XjRealloc();
extern Jet XjCreateRoot();
extern void XjVaGetValues(Jet jet, char *valName, ...);
extern Jet XjVaCreateJet(char *name, JetClass class, Jet parent,
			 char *valName, ...);
extern Jet XjFindJet();
extern void XjReadCallback();
extern void XjLoadFromResources();
extern void XjSetSignalChecker();
extern void XjRealizeJet();
extern void XjDestroyJet();
extern void XjRegisterWindow();
extern void XjUnregisterWindow();
extern void XjSelectInput();
extern void XjEventLoop();
extern void XjFatalError();
extern void XjWarning();
extern void XjUsage();
extern int XjAddWakeup();
extern unsigned long XjRemoveWakeup();
extern void XjRegisterCallback();
extern void XjRegisterCallbacks();
extern void XjCallCallbacks();
extern void XjQuerySize();
extern void XjMove();
extern void XjResize();
extern XjCallbackProc XjGetCallback();
extern XjCallback *XjConvertStringToCallback();
extern void XjStdinCallback();
extern void XjExit();

#define XjNwidth "width"
#define XjCWidth "Width"
#define XjNheight "height"
#define XjCHeight "Height"
#define XjNx "x"
#define XjCX "X"
#define XjNy "y"
#define XjCY "Y"
#define XjNfont "font"
#define XjCFont "Font"
#define XjNforeground "foreground"
#define XjCForeground "Foreground"
#define XjNbackground "background"
#define XjCBackground "Background"
#define XjCCenter "Center"
#define XjNcenterX "centerX"
#define XjNcenterY "centerY"
#define XjCJustify "Justify"
#define XjNjustify "justify"
#define XjNjustifyX "justifyX"
#define XjNjustifyY "justifyY"
#define XjCPixmap "Pixmap"
#define XjNpixmap "pixmap"
#define XjCPadding "Padding"
#define XjNpadding "padding"
#define XjCReverseVideo "ReverseVideo"
#define XjNreverseVideo "reverseVideo"
#define XjCHighlightProc "HighlightProc"
#define XjNhighlightProc "highlightProc"
#define XjNunHighlightProc "unHighlightProc"

#define XjRInt "Int"
#define XjRJustify "Justify"
#define XjROrientation "Orientation"
#define XjRDirection "Direction"
#define XjRBoolean "Boolean"
#define XjRString "String"
#define XjRFontStruct "FontStruct"
#define XjRFont "Font"
#define XjRColor "Color"
#define XjRCallback "Callback"
#define XjRPixmap "Pixmap"
#define XjRJet "Jet"

#define XjDefaultFont "XjDefaultFont"
#define XjNone "none"
#define XjDefaultValue "-1"
#define XjDefaultForeground "XjDefaultForeground"
#define XjDefaultBackground "XjDefaultBackground"
#define XjColor "color"
#define XjLeftJustify "left"
#define XjRightJustify "right"
#define XjTopJustify "top"
#define XjBottomJustify "bottom"
#define XjCenterJustify "center"
#define XjVertical "vertical"
#define XjHorizontal "horizontal"
#define XjNorth "north"
#define XjNorthEast "northeast"
#define XjEast "east"
#define XjSouthEast "southeast"
#define XjSouth "south"
#define XjSouthWest "southwest"
#define XjWest "west"
#define XjNorthWest "northwest"

#define Top        -1
#define Bottom      1
#define Left       -1
#define Right       1
#define Center      0
#define Vertical    0
#define Horizontal  1

#define North		0
#define NorthEast	1
#define East		2
#define SouthEast	3
#define South		4
#define SouthWest	5
#define West		6
#define NorthWest	7

#define XjCActivateProc "ActivateProc"
#define XjNactivateProc "activateProc"

#define XjInheritValue "-1"

#define XjOffset(type,field) \
        ((int) (((char *) (&(((type)NULL)->field))) - ((char *) NULL)))

/* #define XjFree(ptr) free(ptr) */
#define XjCreatePixmap(d, r, w, h, p)  XCreatePixmap((d), (r), (w), (h), (p))
#define XjFreePixmap(d, p)  XFreePixmap((d), (p))
#define XjCreateGC(d, r, m, v)  XCreateGC((d), (r), (m), (v))
#define XjFreeGC(d, gc)  XFreeGC((d), (gc))
#define XjCreateFontCursor(d, s)  XCreateFontCursor((d), (s))
#define XjFreeCursor(d, c)  XFreeCursor((d), (c))
#define XjFreeStringList(p)  XFreeStringList((p))

#define XjNewString(str) \
    ((str) != NULL ? (strcpy(XjMalloc((unsigned)strlen(str) + 1), str)) : NULL)

#ifndef MIN
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif

/*
 * Root specific records...
 */
extern JetClass rootJetClass;

typedef struct {int littlefoo;} RootClassPart;

typedef struct _RootClassRec {
  CoreClassPart		core_class;
  RootClassPart		root_class;
} RootClassRec;

extern RootClassRec rootClassRec;

typedef struct _RootRec {
  CorePart	core;
} RootRec;

typedef struct _RootRec *RootJet;
typedef struct _RootClassRec *RootJetClass;

#define XjCRoot "Root"

#endif				/* _Xj_Jets_h */

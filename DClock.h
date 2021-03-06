/*
 * $Id: DClock.h,v 1.2 1999-01-22 23:16:50 ghudson Exp $
 *
 * Copyright 1990, 1991 by the Massachusetts Institute of Technology. 
 *
 * For copying and distribution information, please see the file
 * <mit-copyright.h>. 
 *
 */

#ifndef _Xj_DClock_h
#define _Xj_DClock_h

#include "Jets.h"

extern JetClass dClockJetClass;

typedef struct {int littlefoo;} DClockClassPart;

typedef struct _DClockClassRec {
  CoreClassPart		core_class;
  DClockClassPart	dClock_class;
} DClockClassRec;

extern DClockClassRec dClockClassRec;

#define MAX_FMTS 32

typedef struct {
  GC gc, gc_bkgnd;
  int foreground;
  int background;
  Boolean reverseVideo;
  XFontStruct *font;
  Boolean centerY;
  int justify;
  int padding;
  Pixmap pmap;
  int pmap_ht;
  int timerid;
  int update;
  char *format[2];
  int current_fmt;
  Boolean blink_colons;
  Boolean colons_on;
  int timeOffset;
} DClockPart;

typedef struct _DClockRec {
  CorePart	core;
  DClockPart	dClock;
} DClockRec;

typedef struct _DClockRec *DClockJet;
typedef struct _DClockClassRec *DClockJetClass;

#define XjCFormat "Format"
#define XjNformat "format"
#define XjNformat2 "format2"
#define XjCUpdate "Update"
#define XjNupdate "update"
#define XjCInterval "Interval"
#define XjNinterval "interval"
#define XjCBlink "Blink"
#define XjNblinkColons "blinkColons"
#define XjCTimeOffset "TimeOffset"
#define XjNtimeOffset "timeOffset"

#endif /* _Xj_DClock_h */

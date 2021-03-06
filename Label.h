/*
 * $Id: Label.h,v 1.2 1999-01-22 23:16:55 ghudson Exp $
 *
 * Copyright 1990, 1991 by the Massachusetts Institute of Technology. 
 *
 * For copying and distribution information, please see the file
 * <mit-copyright.h>. 
 *
 */

#ifndef _Xj_Label_h
#define _Xj_Label_h

#include "Jets.h"

extern JetClass labelJetClass;
extern void setLabel();
extern void setPixmap();
extern void setState();

#define setIcon setState	/* backward compatibility -- do not use... */

typedef struct {int littlefoo;} LabelClassPart;

typedef struct _LabelClassRec {
  CoreClassPart		core_class;
  LabelClassPart	label_class;
} LabelClassRec;

extern LabelClassRec labelClassRec;

typedef struct _LabelPart {
  int foreground, background;
  Boolean reverseVideo;
  XFontStruct *font;
  int justifyX, justifyY;
  int x, y, leftX, leftY, rightX, rightY;
  char *label;
  GC gc, gc_reverse;
  XjPixmap *pixmap, *leftPixmap, *rightPixmap;
  int inverted, padding;
} LabelPart;

typedef struct _LabelRec {
  CorePart	core;
  LabelPart	label;
} LabelRec;

typedef struct _LabelRec *LabelJet;
typedef struct _LabelClassRec *LabelJetClass;

#define XjCLabel "Label"
#define XjNlabel "label"

#define XjCIcon "Icon"
#define XjNicon "icon"
#define XjNleftIcon "leftIcon"
#define XjNrightIcon "rightIcon"

#endif /* _Xj_Label_h */

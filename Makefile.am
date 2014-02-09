ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libXj.la
libXj_la_SOURCES = \
	AClock.c \
	AClock.h \
	Arrow.c \
	Arrow.h \
	Button.c \
	Button.h \
	DClock.c \
	DClock.h \
	Drawing.c \
	Drawing.h \
	Form.c \
	Form.h \
	hash.c \
	hash.h \
	Jets.c \
	Jets.h \
	Label.c \
	Label.h \
	Menu.c \
	Menu.h \
	mit-copyright.h \
	registerCB.c \
	ScrollBar.c \
	ScrollBar.h \
	sintable.h \
	StrToBool.c \
	StrToDirect.c \
	StrToJust.c \
	StrToOrient.c \
	StrToPixmap.c \
	StrToXColor.c \
	StrToXFont.c \
	TextDisplay.c \
	TextDisplay.h \
	Tree.c \
	Tree.h \
	VaCreateJet.c \
	warn.c \
	warn.h \
	Window.c \
	Window.h \
	xselect.c \
	xselect.h
libXj_la_LIBADD = @x_libraries@

appdefdir=${sysconfdir}/X11/app-defaults
bitmapdir=${includedir}/X11/bitmaps
libXj_la_CFLAGS = @x_includes@ -DSHAPE -DHOSTTYPE=\"${HOSTTYPE}\" \
	-DAPPDEFDIR=\"${appdefdir}\" -DBITMAPDIR=\"${bitmapdir}\"

jetsdir = $(includedir)/Jets
jets_HEADERS = \
	AClock.h \
	Arrow.h \
	Button.h \
	DClock.h \
	Drawing.h \
	Form.h \
	hash.h \
	Jets.h \
	Label.h \
	Menu.h \
	ScrollBar.h \
	TextDisplay.h \
	Tree.h \
	warn.h \
	Window.h

noinst_PROGRAMS = sintable
sintable_SOURCES = sintable.c

BUILT_SOURCES = sintable.h
CLEANFILES = sintable.h

# Generate sintable.h
sintable.h: sintable$(EXEEXT)
	./sintable$(EXEEXT) >$@

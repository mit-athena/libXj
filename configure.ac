#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([libxj], [10.0.2], [debathena@mit.edu])
AM_INIT_AUTOMAKE([foreign -Wall])
AM_MAINTAINER_MODE([enable])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([Jets.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
# automake 1.12 seems to require this, but automake 1.11 doesn't recognize it
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT

# Checks for libraries.
AC_CHECK_LIB([m], [sin])

# Checks for header files.
AC_PATH_X
AC_SUBST([x_includes])
AC_SUBST([x_libraries])
AC_CHECK_HEADERS([stdlib.h string.h sys/file.h sys/ioctl.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_STRUCT_TIMEZONE

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([gettimeofday memset select strcasecmp strchr strerror strncasecmp strrchr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

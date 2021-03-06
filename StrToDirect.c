/*
 * $Id: StrToDirect.c,v 1.2 1999-01-22 23:16:59 ghudson Exp $
 *
 * Copyright 1990, 1991 by the Massachusetts Institute of Technology. 
 *
 * For copying and distribution information, please see the file
 * <mit-copyright.h>. 
 *
 */

#if  (!defined(lint))  &&  (!defined(SABER))
static char *rcsid =
"$Id: StrToDirect.c,v 1.2 1999-01-22 23:16:59 ghudson Exp $";
#endif

#include "mit-copyright.h"
#include "Jets.h"

/*
 * String to Direction conversion
 */
int StrToDirection(display, window, where, resource, type, address)
     Display *display;
     Window window;
     caddr_t where;
     XjResource *resource;
     char *type;
     caddr_t address;
{
  int retval = -1;
  int direction = North;

  if (strcasecmp(address, XjNorth) == 0)
    {
      direction = North;
      retval = 0;
    }

  if (strcasecmp(address, XjNorthEast) == 0)
    {
      direction = NorthEast;
      retval = 0;
    }

  if (strcasecmp(address, XjEast) == 0)
    {
      direction = East;
      retval = 0;
    }

  if (strcasecmp(address, XjSouthEast) == 0)
    {
      direction = SouthEast;
      retval = 0;
    }

  if (strcasecmp(address, XjSouth) == 0)
    {
      direction = South;
      retval = 0;
    }

  if (strcasecmp(address, XjSouthWest) == 0)
    {
      direction = SouthWest;
      retval = 0;
    }

  if (strcasecmp(address, XjWest) == 0)
    {
      direction = West;
      retval = 0;
    }

  if (strcasecmp(address, XjNorthWest) == 0)
    {
      direction = NorthWest;
      retval = 0;
    }

  if (retval)
    {
      char errtext[100];
      sprintf(errtext, "bad direction value `%s', using `North'", address);
      XjWarning(errtext);
    }

  *((int *)((char *)where + resource->resource_offset)) = direction;
  return retval;
}

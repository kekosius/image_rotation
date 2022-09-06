#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

_Noreturn void err( const char* msg, ... ) {
  va_list args;
  va_start (args, msg);
  vfprintf(stderr, msg, args);
  va_end (args);
  exit(1);
}

const size_t find_padding(const size_t w, const size_t h)
{
	return (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;
}


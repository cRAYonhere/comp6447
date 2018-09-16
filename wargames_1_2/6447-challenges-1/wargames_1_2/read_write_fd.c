#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  FILE *test_file;
  char buf[4096];
  if ( (test_file = fopen ("/var/log/Xorg.0.log", "r")) != NULL)
    {
      while (!feof (test_file))
	{
	  fgets (buf, sizeof (buf), test_file);
	  puts (buf);
	}
    }
  else
    {
      printf ("Error opening file: %s\n", strerror (errno));
      exit (EXIT_FAILURE);
    }

  return 0;


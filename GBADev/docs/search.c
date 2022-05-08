#include <stdio.h>
#include <stdlib.h>
#include <process.h>

const char *DOXYSEARCH = "\\usr\\local\\bin\\\\doxysearch.exe";
const char *DOXYPATH = ".\\output\\html";

int main(void)
{
  char buf[1024];
  sprintf(buf,"%s %s",DOXYSEARCH,DOXYPATH);
  if (system(buf))
  {
    printf("Content-Type: text/html\n\n");
    printf("<h2>Error: failed to execute %s</h2>\n",DOXYSEARCH);
    exit(1);
  }
  return 0;
}

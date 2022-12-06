#include <stdio.h>
#include <stdlib.h>
int main() {
  char buf[256];
  printf("input characters:\n");
  fgets(buf, sizeof(buf), stdin);
  fputs(buf, stdout);
  fprintf(stdout, "What you wrote is %s\n",buf);
}

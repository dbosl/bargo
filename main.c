#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "bargo.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: bargo new <project_name>");
    exit(1);
  }

  int fd = init_bargo();

  if (fd == 1) {
    fprintf(stdout, "<project_name> ready.");
  }

  return 0;
}

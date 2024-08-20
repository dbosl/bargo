#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "bargo.h"

// TODO: getopt to build better UX
// TODO: add makefile

int copy_files();

void handle_error(char *str) {
  perror(str);
  exit(1);
}

// TODO: refactor to use this for general file creation
FILE *create_file(char *filename) {
  FILE *fd = fopen(filename, "w+");

  if (fd == NULL) {
    fprintf(stderr, "Error creating %s\n", filename);
    exit(1);
  }

  return fd;
}

int create_init_files() {
  int fd = mkdir("./src", 0777);

  if (fd == -1) {
    handle_error("mkdir");
  }

  int main_file_fd = open("./src/main.c", O_CREAT, 0644);
  if (main_file_fd == -1) {
    handle_error("open");
  }

  int header_file_fd = open("./src/header.h", O_CREAT, 0644);
  if (header_file_fd == -1) {
    handle_error("open");
  }

  return 1;
}

int init_bargo() { 
  int res = create_init_files();
  int cp_res = copy_files();
  if (res == 1 && cp_res == 1) return 1;
  return 0; 
}

int copy_files() {
  FILE *input, *output;
  int c;

  input = fopen("./init/main.txt", "r");
  if (input == NULL) {
    fprintf(stderr, "Error reading %s\n", "./init/main.txt");
    fclose(input);
    exit(1);
  }

  output = fopen("./src/main.c", "w");
  if (output == NULL) {
    fprintf(stderr, "Error reading %s\n", "./src/main.c");
    fclose(output);
    exit(1);
  }

  while ((c = getc(input)) != EOF) {
    printf("%c", c);
    putc(c, output);
  }

  fclose(input);
  fclose(output);
  return 1;
}

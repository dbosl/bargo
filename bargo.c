#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "bargo.h"

// TODO: add makefile

int copy_files();

void print_usage(const char *prog_name) {
    printf("Usage: %s [-i] [-c] [-h]\n", prog_name);
    printf("  -i, --init   Initialize the project\n");
    printf("  -c, --copy   Copy files\n");
    printf("  -h, --help   Display this help message\n");
}

void handle_error(const char *str, FILE *fd) {
  perror(str);
  fclose(fd);
  exit(EXIT_FAILURE);
}

FILE *create_file(const char *filename) {
  FILE *fd = fopen(filename, "w+");

  if (fd == NULL) {
    handle_error("Error creating file", fd);
  }

  return fd;
}

int create_init_files(const char *prog_name) {
  char project_dir[MAX_PATH_LENGTH];
  char src_dir[MAX_PATH_LENGTH];
  char main_file_path[MAX_PATH_LENGTH];
  char header_file_path[MAX_PATH_LENGTH];

  snprintf(project_dir, sizeof(project_dir), "./%s", prog_name);
  if (mkdir(project_dir, 0777) == -1) {
    handle_error("mkdir", NULL);
  }

  snprintf(src_dir, sizeof(src_dir), "%s/src", project_dir);
  if (mkdir(src_dir, 0777) == -1) {
    handle_error("mkdir src", NULL);
  }

  snprintf(main_file_path, sizeof(main_file_path), "%s/main.c", src_dir);
  FILE *main_file = create_file(main_file_path);
  fclose(main_file);

  snprintf(header_file_path, sizeof(header_file_path), "%s/header.c", src_dir);
  FILE *header_file = create_file(header_file_path);
  fclose(header_file);

  return SUCCESS;
}

int init_bargo(const char *project_name) { 
  int res = create_init_files(project_name);
  int cp_res = copy_files();
  if (res == SUCCESS && cp_res == SUCCESS) return SUCCESS;
  return FAILURE; 
}

int copy_files() {
  FILE *input, *output;
  int c;

  input = fopen("./init/main.txt", "r");
  if (input == NULL) {
   handle_error("open", input); 
  }

  output = fopen("./src/main.c", "w");
  if (output == NULL) {
   handle_error("open", input); 
  }

  while ((c = getc(input)) != EOF) {
    putc(c, output);
  }

  fclose(input);
  fclose(output);
  return SUCCESS;
}

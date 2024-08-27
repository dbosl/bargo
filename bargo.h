#ifndef BARGO_H
#define BARGO_H

#include <stdio.h>

#define SUCCESS 0
#define FAILURE  1
#define MAX_PATH_LENGTH 256

int copy_files();

void print_usage(const char *prog_name);

void handle_error(const char *str, FILE *fd);

FILE *create_file(const char *filename);

int create_init_files(const char *prog_name);

int init_bargo(const char* project_name);
int copy_files();
#endif



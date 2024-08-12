#ifndef BARGO_H
#define BARGO_H

#include <stdio.h>

int copy_files();

void handle_error(char *str);

FILE *create_file(char *filename);

int create_init_files();

int init_bargo();
int copy_files();
#endif



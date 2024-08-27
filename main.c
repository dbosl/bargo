#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "bargo.h"

int main(int argc, char *argv[]) {
        if (argc < 2) {
	        print_usage("<project_name>");
               return EXIT_FAILURE;
	}

	const char *project_name = argv[1];

        if (init_bargo(project_name) == EXIT_SUCCESS) {
	    printf("Project '%s' initialized successfully.\n", project_name);
	    return EXIT_SUCCESS;
	} else {
	    printf("Failed to initialize project '%s'.\n", project_name);
	    return EXIT_FAILURE;
	}
 }    

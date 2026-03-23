#include <stdio.h>
#include <stdlib.h>

#define Error__outOfBoundsUpper()\
       	perror("Exception: Index exceeds upper bound.");\
	exit();

#define Error_outOfBoundsLower()\
	perror("Exception: Index exceeds lower bound.");\
	exit();

#define Error_dereffrence()\
	perror("Error: pointer points to NULL");\
	exit();

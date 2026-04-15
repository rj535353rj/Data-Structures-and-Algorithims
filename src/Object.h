#ifndef OBJECT_H
	#define OBJECT_H
	
	#include <stdlib.h>

	typedef struct object *Object;
	extern Object Object_Copy(Object this);
	extern void Object_Destructor(Object this);
	extern Object new_Object();

#endif

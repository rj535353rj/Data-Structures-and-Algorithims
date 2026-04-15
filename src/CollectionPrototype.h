#include "Collection.h"
#include "ObjectPrototype.h"

typedef struct Collection_Data_Struct{
	unsigned int (*size) ( Collection this );
	int (*isEmpty) ( Collection this );
	void (*clear) ( Collection this );
	void* (*toArray) ( Collection this );
} *Collection_Data;

struct Collection_Struct {
	Class class;
	Collection_Data data;
}

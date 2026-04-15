#include "Object.h"

typedef Class_Struct *Class;
typedef Object (*Copy_Function)( Object this );
typedef void (*Destructor_Function)( Object this );
typedef void (*Constructor_Function)( Object this );

struct object{
	Class class;
};

Typedef struct Class_Struct {
	unsigned int byte_size;
	Class parent;
	Constructor_Function constructor;
	Copy_Function copy;
	Destructor_Function destructor;
};





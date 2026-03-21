#include "AbstractList.h"
#include <stdio.h>

#define list( type ) ArrayList__ ## type 

#define ArrayList_interface( type )\
	typedef struct arrayList__ ## type list( type ) ;\
	AbstractListInterface( ArrayList, type )\
	void list( type ) ## __push_back ( list( type ) *this, type element );\
	void list( type ) ## __pop_back ( list( type ) *this );\
\
	struct arrayList__ ## type {\
		type *data;\
		int capacity;\
		int size;\
	};
	
//increaseCapacity is a helper method and is not in the interface

#define ArrayList_methods( type )\
	AbstractList_equals( ArrayList, type )\
	AbstractList_isEmpty( ArrayList, type )\
	AbstractList_contains( ArrayList, type )\
\
	void list( type ) ## __constructor ( list( type ) *this ) {\
		this->data = NULL;\
		this->capacity = 0;\
		this->size = 0;\
	}\
\
	void list( type ) ## __increaseCapacity ( list( type ) *this ) {\
		if( this->size == 0){\
			this->data = malloc( sizeof( type ) );\
			this->capacity = 1;\
		} else {\
			this->capacity *= 2;\
			type *temp = realloc( this->data, sizeof( type ) * this->capacity);\
			this->data = temp;\
		}\
	}\
\
	void list( type ) ## __insert ( list( type ) *this, type element, int index) {\
		if( this->size > index ){\
			perror("list index exeeds upper bounds");\
			return;\
		}\
		if( this->size < 0 ){\
			perror("list index exeeds lower bounds. AKA fucked up big time");\
				return;\
		}\
		if( this->size == this->capacity ){\
			list( type ) ## __increaseCapacity( this );\
		}\
		if( index == this->size ){\
			this->data[size] = element;\
			(this->size)++;\
		} else {\
			type current = this->data[ index ];\
			for(int i = index + 1; i < this->size; i++){\
				type temp = (this->data)[ i ];\
				( thisi->data )[ i ] = ( this->data )[ i ];\
				current = temp;\
			}\
			( this->data )[ index ] = element;\
			(this->size)++;\
		}\
	}

	





#undef list

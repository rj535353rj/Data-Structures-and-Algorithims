#include "AbstractList.h"
#include <stdio.h>

// #define list( type ) ArrayList__ ## type // this doesent work so i got rid of it

#define ArrayList_interface( type )\
	typedef struct arrayList__ ## type ArrayList__ ## type ;\
	AbstractListInterface( ArrayList__ ## type , type )\
	void ArrayList__## type ## __pushBack ( ArrayList__ ## type *this, type element );\
	void ArrayList__ ## type ## __popBack ( ArrayList__ ## type *this );\
\
	struct arrayList__ ## type {\
		type *data;\
		int capacity;\
		int size;\
	};
	
//increaseCapacity is a helper method and is not in the interface

#define ArrayList_methods( type )\
	AbstractList_equals( ArrayList ## __ ## type, type )\
	AbstractList_isEmpty( ArrayList ## __ ## type, type )\
	AbstractList_contains( ArrayList ## __ ## type, type )\
\
	void ArrayList__ ## type ## __constructor ( ArrayList__ ## type *this ) {\
		this->data = NULL;\
		this->capacity = 0;\
		this->size = 0;\
	}\
\
	void ArrayList__ ## type ## __increaseCapacity ( ArrayList__ ## type *this ) {\
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
	void ArrayList__ ## type ## __decreaseCapacity ( ArrayList__ ## type *this ) {\
		if(this->size == 0){\
			this->data = NULL;\
		} else {\
			if(this->capacity > this->size *2){\
				this->capacity >>= 1;\
				type *temp = realloc( this->data, sizeof( type ) * this->capacity );\
				this->data = temp;\
			}\
		}\
	}\
\
	void ArrayList__ ## type ## __insert ( ArrayList__ ## type *this, type element, int index) {\
		if( index > this->size ){\
			perror("list index exeeds upper bounds");\
			return;\
		}\
		if( this->size < 0 ){\
			perror("list index exeeds lower bounds. AKA fucked up big time");\
				return;\
		}\
		if( this->size == this->capacity ){\
			ArrayList__ ## type ## __increaseCapacity( this );\
		}\
		if( index == this->size ){\
			this->data[this->size] = element;\
			(this->size)++;\
		} else {\
			type current = ( this->data )[ index ];\
			for(int i = index + 1; i < this->size + 1; i++){\
				type temp = ( this->data )[ i ];\
				( this->data )[ i ] = current;\
				current = temp;\
			}\
			( this->data )[ index ] = element;\
			(this->size)++;\
		}\
	}\
\
	int ArrayList__ ## type ## __indexOf( ArrayList__ ## type *this, type element){\
		for ( int i  = 0; i < this->size; i++ ){\
			if ( ( this->data )[i] == element ){\
				return i;\
			}\
		}\
		return -1;\
	}\
\
	int ArrayList__ ## type ## __size( ArrayList__ ## type *this){\
		return this->size;\
	}\
\
	type ArrayList__ ## type ## __get( ArrayList__ ## type * this, int index){\
		return ( this->data )[ index ];\
	}\
\
	void ArrayList__ ## type ## __pushBack ( ArrayList__ ## type *this, type element ) {\
		ArrayList__ ## type ## __insert( this, element, this->size );\
	}\
\
	void ArrayList__ ## type ## __remove ( ArrayList__ ## type *this, int index ) {\
		--(this->size);\
		if( index < this->size ) {\
			for( int i = index; i < this->size; i++ ){\
				( this->data )[ i ] = ( this->data )[i + 1];\
			}\
		}\
		ArrayList__ ## type ## __decreaseCapacity( this );\
	}\
\
	void ArrayList__ ## type ## __popBack ( ArrayList__ ## type *this ) {\
		--(this->size);\
		ArrayList__ ## type ## __decreaseCapacity( this );\
	}

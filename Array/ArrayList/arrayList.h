#include <stdlib.h>

//this is gonna contain the macro to define arraylist
//this macro can define arraylist for anytype

#define ArrayList(type) \
	 struct arrayList__ ## type ##__ {\
		type *data;\
		int capacity;\
		int size;\
		void ( *constructor )( struct arrayList__ ## type ## __* );\
		void ( *push_back )( struct arrayList__ ## type ##__*, type );\
		void ( *pop_back )( struct arrayList__ ## type ## __*);\
		void ( *insert )( type, int );\
		void ( *remove )( int );\
		type ( *get )( int );\
	}; \
\
	typedef struct arrayList__ ## type ## __ ArrayList__ ## type ## __  ;\
\
	void ArrayList__ ## type ## __push_back ( ArrayList__ ## type ## __ *list, type n ) {\
		if ( list->size == 0 ) {\
			list->data = malloc( sizeof( type  ) );\
			list->data[0] = n;\
			list->size = 1;\
			list->capacity = 1;\
		} else {\
			if ( list->size == list->capacity ) {\
				type *temp = realloc( list->data , sizeof( type ) * list->capacity * 2 );\
				list->data = temp;\
				list->capacity *= 2;\
				list->data[ list->size ] = n;\
				++( list->size );\
			} else {\
				list->data[ list->size ] = n;\
				++( list->size );\
			}\
		}\
	}\
\
	void ArrayList__ ## type ## __pop_back ( ArrayList__ ## type ## __ *list ){\
		if( list->size <= 1 ){\
			if(list->size == 1){\
				free(list->data);\
				list->size = 0;\
				list->capacity = 0;\
			} else { /* list->size must = 0 */\
				/* we do nothing, the arrayList has no elements */\
			}\
		} else {\
			--(list->size);\
			if(list->size <= list->capacity / 2){\
				list->capacity /= 2;\
				type *temp = realloc( list->data, sizeof( type ) * list->capacity );\
				list->data = temp;\
			}\
		}\
	}\
\
	void ArrayList__ ## type ## __constructor ( ArrayList__ ## type ## __ *list ) {\
		list->constructor = ArrayList__ ## type ## __constructor;\
		list->push_back = ArrayList__ ## type ## __push_back;\
		list->pop_back = ArrayList__ ## type ## __pop_back;\
		list->capacity = 0;\
		list->size = 0;\
	}


#include "AbstractList.h"
#include <stddef.h>
#include <stdlib.h>

#define LinkedList_interface( type )\
	typedef struct linkedList__ ## type LinkedList__ ## type ;\
	typedef struct LinkedList__ ## type ## __node LinkedList__ ## type ## __Node;\
	AbstractListInterface( LinkedList__ ## type , type );\
	void LinkedList__ ## type ## __constructor( LinkedList__ ## type *this );\
\
	struct LinkedList__ ## type ## __node {\
		LinkedList__ ## type ## __Node *next;\
		type value;\
	};\
\
	struct linkedList__ ## type {\
		LinkedList__ ## type ## __Node *root;\
		int size;\
	};

#define LinkedList_methods( type )\
	AbstractList_equals( LinkedList__ ## type, type );\
	AbstractList_isEmpty( LinkedList__ ## type, type );\
	AbstractList_contains( LinkedList__ ## type, type );\
\
	void LinkedList__ ## type ## __constructor ( LinkedList__ ## type *this ) {\
		this->root = NULL;\
		this->size = 0;\
	}\
\
	void LinkedList__ ## type ## __Node__constructor ( LinkedList__ ## type ## __Node *this, type value ) {\
		this->next = NULL;\
		this->value = value;\
	}\
\
	void LinkedList__ ## type ## __insert ( LinkedList__ ## type *this, type element, int index ) {\
		if ( index == 0 ) {\
			LinkedList__ ## type ## __Node *temp = malloc( sizeof( LinkedList__ ## type ## __Node ) );\
			LinkedList__ ## type ## __Node__constructor( temp, element );\
			temp->next = this->root;\
			this->root = temp;\
			return;\
		}\
		LinkedList__ ## type ## __Node *current = this->root;\
		for ( int i = 0; i < index-1; i++ ) {\
			current = current->next;\
		}\
		LinkedList__ ## type ## __Node *temp = malloc( sizeof( LinkedList__ ## type ## __Node ) );\
		LinkedList__ ## type ## __Node__constructor( temp, element );\
		temp->next = current->next;\
		current->next = temp;\
	}\
\
	void LinkedList__ ## type ## __remove ( LinkedList__ ## type *this, int index ) {\
		if ( index == 0 ) {\
			LinkedList__ ## type ## __Node *temp = this->root;\
			this->root = this->root->next;\
			free( temp );\
			return;\
		}\
		LinkedList__ ## type ## __Node *current = this->root;\
		for ( int i = 0; i < index-1; i++ ) {\
			current = current->next;\
		}\
		LinkedList__ ## type ## __Node *temp = current->next;\
		current->next = temp->next;\
		free( temp );\
	}\
\
	type LinkedList__ ## type ## __get ( LinkedList__ ## type *this, int index ) {\
		LinkedList__ ## type ## __Node *current = this->root;\
		for ( int i = 0; i < index; i++ ) {\
			current = current->next;\
		}\
		return current->value;\
	}\
\
	int LinkedList__ ## type ## __indexOf ( LinkedList__ ## type * this, type element ) {\
		LinkedList__ ## type ## __Node *current;\
		for ( int i = 0; i < this->size; i++ ){\
			if ( current->value == element ) {\
				return i;\
			}\
			current = current->next;\
		}\
		return -1;\
	}\
\
	int LinkedList__ ## type ## __size ( LinkedList__ ## type * this ) {\
		return this->size;\
	}

	


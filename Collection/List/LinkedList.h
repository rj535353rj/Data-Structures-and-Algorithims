#include "AbstractList.h"

#define LinkedList_interface( type )\
	typedef struct linkedList__ ## type LinkedList__ ## type ;
	AbstractListInterface( LinkedList__ ## type , type );
	AbstractList_equals( LinkedList__ ## type, type );
	AbstractList_isEmpty( LinkedList__ ## type, type );
	AbstractList_contains( LinkedList__ ## type, type );

	typedef struct LinkedList__ ## type ## __node {
		struct LinkedList __ ## type ## __ node *next;
		type value;
	} LinkedList__ ## type ## __Node;

	struct linkedList__ ## type {
		linkedList__ ## type ## __Node *root;
		int size;
	};

	void LinkedList__ ## type ## __constructor ( LinkedList__ ## type *this ) {
		this->root = NULL;
		this->size = 0;
	}

	void LinkedList__ ## type ## __Node__constructor ( LinkedList__ ## type ## __Node *this, type value ) {
		this->next = NULL;
		this.value = value;
	}

	void LinkedList__ ## type ## __insert ( LinkedList__ ## type *this, type element, int index ) {
		if ( index == 0 ) {
			LinkedList__ ## type ## __Node *temp = malloc( sizeof( LinkedList__ ## type ## __Node ) );
			LinkedList__ ## type ## __Node__constructor( temp, element );
			temp->next = this->root;
			this->root = temp;
			return;
		}
		LinkedList__ ## type ## __Node *current = this->root;
		for ( int i = 0; i < index-1; i++ ) {
			current = current->next;
		}
		LinkedList__ ## type ## __Node *temp = malloc( sizeof( LinkedList__ ## type ## __Node ) );
		LinkedList__ ## type ## __Node__constructor( temp, element );
		temp->next = current->next;
		current->next = temp;
	}

	void LinkedList__ ## type ## __remove ( LinkedList__ ## type *this, int index ) {
		if ( index == 0 ) {
			LinkedList__ ## type ## __Node *temp = this->root;
			this->root = this->root->next;
			free( temp );
			return;
		}
		LinkedList__ ## type ## __Node *current = this->root;
		for ( int i = 0; i < index-1; i++ ) {
			current = current->next;
		}
		LinkedList__ ## type ## __Node *temp = current->next;
		current->next = temp->next;
		free( temp );
	}

	

	


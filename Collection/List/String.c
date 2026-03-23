#include "String.h"

void String__constructor ( String * this ) {
	ArrayList__Char__constructor( &(this->characters) );
}

void String__append ( String * this, char c) {
	ArrayList__Char__pushBack( &(this->characters), c);
}

void String__concatenate ( String *this, String *other ) {
	for( int i = 0; i < (other->characters).size; i++ ){

	}
}

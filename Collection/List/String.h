#include "../../Number/AbstractNumber.h"
#include "ArrayList.h"

typedef struct string String;

ArrayList_interface( Char )

struct string {
	ArrayList__Char characters;
}

void String__constructor( String *this );
void String__append( String *this, Char c );
void String__concatnate( String *this, String *other);


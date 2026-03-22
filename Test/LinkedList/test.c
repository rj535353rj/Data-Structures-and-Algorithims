#include <stdio.h>
#include "LinkedListInt.h"

int main () {
	LinkedList__Integer list;
	LinkedList__Integer *plist = &list;
	LinkedList__Integer__constructor( plist );
	LinkedList__Integer__insert( plist, 100, 0 );
	LinkedList__Integer__insert( plist, 200, 0 );
	LinkedList__Integer__insert( plist, 300, 0 );

	LinkedList__Integer__remove( plist, 1 );

	printf( "%d\n", LinkedList__Integer__get( plist, 0 ));	
	printf( "%d\n", LinkedList__Integer__get( plist, 1 ));	
}

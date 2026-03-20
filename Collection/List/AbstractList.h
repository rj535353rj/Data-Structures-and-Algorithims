#include "../AbstractCollection.h"

//pretty much all the operations a list needs, most other operations are just combinations of these.

#define AbstractListInterface( type, subtype )\
	AbstractCollectionInterface( type, subtype )\
	void type ## __ ## subtype ## __insert( type *this, subtype element, int position );\
	void type ## __ ## subtype ##__remove( type *this, int position );\
	subtype type ## __ ## subtype ## __get( type *this, int position );\
	subtype type ## __ ## subtype ## __indexOf( type *this, subtype element );\
	int type ## __ ## subtype ## __size( type *this );\

#include "../AbstractCollection.h"

//pretty much all the operations a list needs, most other operations are just combinations of these.

#define AbstractListInterface( type, subtype )\
	AbstractCollectionInterface( type, subtype )\
	void type ## __insert( type *this, subtype element, int index );\
	void type ##__remove( type *this, int index );\
	subtype type ## __get( type *this, int index );\
	int type ## __indexOf( type *this, subtype element );\
	int type ## __size( type *this );\

// #define list( type, subtype ) type ## __ ## subtype this didnt work so i have to manually remove all of the instances of it

#define AbstractList_equals( type, subtype )\
	Boolean type ## __equals (type *this, type *collection ){\
		int size1 = type ## __size( this );\
		int size2 = type ## __size( collection );\
		if( size1 != size2 ){\
			return false;\
		}\
		for( int i = 0; i < size1; i++ ){\
			if( type ## __get( this, i ) != type ## __get( collection, i ) ){\
				return false;\
			}\
		}\
		return true;\
	}

#define AbstractList_isEmpty( type, subtype )\
	Boolean type ## __isEmpty ( type *this ){\
		if( type ## __size( this ) == 0){\
			return true;\
		} else {\
			return false;\
		}\
	}\

#define AbstractList_contains( type, subtype )\
	Boolean type ## __contains ( type *this, subtype element){\
		if( type ## __indexOf( this, element ) == -1 ){\
			return false;\
		} else {\
			return true;\
		}\
	}

//I hope this works

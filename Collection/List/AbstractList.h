#include "../AbstractCollection.h"

//pretty much all the operations a list needs, most other operations are just combinations of these.

#define AbstractListInterface( type, subtype )\
	AbstractCollectionInterface( type, subtype )\
	void type ## __ ## subtype ## __insert( type *this, subtype element, int position );\
	void type ## __ ## subtype ##__remove( type *this, int position );\
	subtype type ## __ ## subtype ## __get( type *this, int position );\
	subtype type ## __ ## subtype ## __indexOf( type *this, subtype element );\
	int type ## __ ## subtype ## __size( type *this );\

#define list( type, subtype ) type ## __ ## subtype

#define AbstractList_equals( type, subtype )\
	Boolean list( type, subtype) ## __equals (type *this, type *collection ){\
		int size1 = list( type, subtype ) ## __size( this );\
		int size2 = list( type, subtype ) ## __size( collection );\
		if( size1 != size2 ){\
			return false;\
		}\
		for( int i = 0; i < size1; i++ ){\
			if( list( type, subtype ) ## __get( this, i ) != list( type, subtype) ## __get( collection, i ) ){\
				return false;\
			}\
		}\
		return true;\
	}

#define AbstractList_isEmpty( type, subtype )\
	Boolean list( type, subtype ) ## __isEmpty ( type *this ){\
		if( list( type, subtype ) ## __size( this ) == 0){\
			return true;\
		} else {\
			return false;\
		}\
	}\

#define AbstractList_contains( type, subtype )\
	Boolean list( type, subtype ) ## __contains ( type *this, subtype element){\
		if( list( type, subtype ) ## __indexOf( element) == -1 ){\
			return false;\
		} else {\
			return true;\
		}\
	}

#undef list
//I hope this works

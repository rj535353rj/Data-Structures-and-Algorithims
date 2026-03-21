
//defining an abstract collection, the subype is the type of the elements
//pretty much the only operations that all collections will have
//Size was not included because of non-finite sets (i might implnetn non-finite sets, idk)

#define AbstractCollectionInterface( type, subtype )\
	Boolean type ## __ ## subtype ## __equals( type *this, type *collection);\
	Boolean type ## __ ## subtype ## __isEmpty( type *this );\
	Boolean type ## __ ## subtype ## __contains ( type *this, subtype element );\


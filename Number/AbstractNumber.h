#include <stdint.h>

typedef int Integer;
typedef uint32_t Natural;
typedef float Float;
typedef double Double;
typedef char Char;
typedef long Long;
struct bignum;
typedef struct bignum Bignum;
typedef int Boolean;

//this helps us to declare a bunch of funcitons for each number
//acts similar to an abstract interface, ei it only defines functions, and the implementation
#define AbstractNumber_interface( type )\
	Integer type ## __Integer__conversion( type val );\
	Natural type ## __Natural__conversion( type val );\
	Float type ## __Float__conversion( type val );\
	Double type ## __Double__conversion( type val );\
	Char type ## __Char__conversion( type val );\
	Long type ## __Long__conversion( type val );\
	Bignum type ## __Bignum__conversion( type val );\
	type type ## __add( type val1, type val2 );\
	type type ## __sub( type val1, type val2 );\
	type type ## __mul( type val1, type val2 );\
	type type ## __div( type val1, type val2 );\
	void type ## __assign( type *this, type val);\
	Boolean type ## __equality( type val1, type val2);\
	Boolean type ## __lessThan( type val1, type val2);\

//a helper macro, lots of conversions will be similar so this allows us to define them really fast
#define AbstractNumber_conversion( type1, type2 )\
	type2 type1 ## __ ## type2 ##__conversion( type1 val ){\
		return ( type2 ) val ;\
	}
//another helper macro, lots of the operation will be defined similarly, so this removes unessasary code
#define AbstractNumber_operation( type, name, operator )\
	type type ## __ ## name ( type val1, type val2 ){\
		return ( val1 ) operator ( val2 );\
	}

//as above
#define AbstractNumber_comparison( type, name, operator )\
	Boolean type ## __ ## name ( type val1, type val2 ){\
		return ( val1 ) operator ( val2 );\
	}



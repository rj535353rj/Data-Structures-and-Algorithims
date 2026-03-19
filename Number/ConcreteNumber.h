//A macro for implementing numbers, eg Integer and float, note, this dosent implement bignum conversions, so that must be defiend seperatly
#define ConcreteNumber_implementor( type )\
	AbstractNumber_conversion( type, Integer )\
\
	AbstractNumber_conversion( type, Natural )\
\
	AbstractNumber_conversion( type, Float )\
\
	AbstractNumber_conversion( type, Double )\
\
	AbstractNumber_conversion( type, Char )\
\
	AbstractNumber_Operation( type, add, + )\
\
	AbstractNumber_Operation( type, sub, - )\
\
	AbstractNumber_Operation( type, mul, * )\
\
	AbstractNumber_Operation( type, div, / )\
\
	AbstractNumber_Comparison( type, equality, == )\
\
	AbstractNumber_Comparison( type, lessThan, < )

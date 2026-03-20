//A macro for implementing numbers, eg Integer and float, note, this dosent implement bignum conversions, so that must be defiend seperatly
#define ConcreteNumber_implementor( type )\
	AbstractNumber_conversion( type , Integer )\
\
	AbstractNumber_conversion( type , Natural )\
\
	AbstractNumber_conversion( type , Float )\
\
	AbstractNumber_conversion( type , Double )\
\
	AbstractNumber_conversion( type , Char )\
\
	AbstractNumber_operation( type , add, + )\
\
	AbstractNumber_operation( type , sub, - )\
\
	AbstractNumber_operation( type , mul, * )\
\
	AbstractNumber_operation( type , div, / )\
\
	AbstractNumber_comparison( type , equality, == )\
\
	AbstractNumber_comparison( type , lessThan, < )

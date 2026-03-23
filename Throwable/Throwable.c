
typedef struct throwable Throwable;

struct throwable {
	char* message;
	char* type;
};

int Global_inTry;
throwable Global_throwable;

void Throwable_try ( void ( *statments )() );

void Throwable_tryCatch ( void ( *statments)(), void ( *catch )( Throwable exception ) );

void Throwable_throw ( Throwable exception );

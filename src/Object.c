#inlcude "ObjectPrototype.h"

Class_Struct object_class;

static
Object base_copy( Object this, Class ansestor ) { //note this function is recursive;
	if ( ancestor->copy ) {
		return ancestor->copy(this);
	} else {
		if ( ancestor->parent ) {
			return base_copy(this, ansestor->parent);
		} else {
			Object new = (Object) malloc(this->class->byte_size);
			char *byte = (char*) this;
			char *target = (char*) new;
			for( unsigned int i = 0; i < this->class->byte_size; i++ ){
				target + i = byte + i; //we copy all the data from the original to the copy
			}
			return new;
		}
	}
}

Object Object_Copy( Object this ){
	return base_copy(this, this->class);
}

/*
static 
Object base_constructor( Object this, Class ansestor ) {
	if ( ancestor->constructor ){
		return ancestor->constructor;
	} else {
		if ( ancestor->parent ) {
			return base_constructor(this, ancestor->parent);
		} else {
			new = (Object) malloc(this->class->byte_size);
			new->class = object_class;
			return new;
		}	
}

static
Object_Constructor( Object this ) {
	return base_constructor( this, this->class );
}
*/

static
void base_destructor( Object this, Class ancestor) {
	if ( ancestor->destructor ) {
		ancestor->destructor(this);
		return;
	} else {
		if ( ancestor->parent ) {
			base_destrucotr(this, ancestor->parent);
			return;
		} else {
			free(this);
		}
	}
}

void Object_Destructor( Object this ){
	base_destructor( this, this->class );
}

Object new_Object(){
	Object new = (Object) malloc(object_class.byte_size);
	new.class = &object_class;
}

object_class = { sizeof(Object_Struct), NULL, NULL, NULL, NULL};

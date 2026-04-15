#include "CollectionPrototype.h"

struct Collection_Data_Struct collection_struct;

static
unsigned int base_size( Collection this, Class ancestor ){
	if ( ancestor->size ) {
		return ancestor->size(this);
	} else {
		if ( ancestor->parent ) {
			return base_size( this, ancestor->parent );
		} else {
			return 0;
		}
	}
}

Collection_Size( Collection this ) {
	return base_size( this, this->class );
}

static
int base_is_empty( Collection this, Class ancestor ){
	if( ancestor->is_empty ) {
		return ancestor->is_empty(this);
	} else {
		if( ancestor->parent ) {
			return base_is_empty(this, ancestor->parent);
		} else {
			return 1;
		}
	}
}

static void 



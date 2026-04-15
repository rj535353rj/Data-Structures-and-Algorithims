#include "Object.h"

int main(){
	Object a = new_Object();
	Object b = Object_Copy(a);
	Object_Destructor(a);
	Object_Destructor(b);
}

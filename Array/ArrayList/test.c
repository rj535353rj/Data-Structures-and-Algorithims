#include <stdio.h>
#include "arrayList.h"

ArrayList( int )

int main(){
	ArrayList__int__ list;
	ArrayList__int__constructor(&list);
	(list.push_back)(&list, 1);
	list.push_back(&list, 20);
	list.push_back(&list, 4);
	list.pop_back(&list);
	printf("number = %d\n", list.data[0]);
	printf("number = %d\n", list.data[1]);
	printf("number = %d\n", list.size);
}

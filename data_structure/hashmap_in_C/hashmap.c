#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashmap.h"
int main(){
	hashmap map = newhashmap();
	set(map, "john",1);
	set(map, "cena",2);
	set(map, "aaron",4);
	set(map, "arson",6);
	printf("john->%d\n",get(map,"john"));
	printf("cena->%d\n",get(map,"cena"));
	printf("aaron->%d\n",get(map,"aaron"));
	printf("arson->%d\n",get(map,"arson"));

	set(map,"aaron",99);
	printf("aaron->%d\n",get(map,"aaron"));
	return 0;
}

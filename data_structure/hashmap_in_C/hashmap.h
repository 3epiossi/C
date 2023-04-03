#ifndef __HASHMAP__
#define __HASHMAP__

typedef struct PAIR{
	char *key;
	int val;
	struct PAIR* next;
}Pair;
typedef Pair* pair;

typedef struct HASHMAP{
	pair* list;
	unsigned int cap;
	unsigned int len;
}Hashmap;
typedef Hashmap* hashmap;

hashmap newhashmap();
unsigned int SHA_2266(hashmap, char*);
int get(hashmap, char*);
void set(hashmap, char*, int);
#endif

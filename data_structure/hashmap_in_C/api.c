#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashmap.h"
hashmap newhashmap(){
	hashmap self;
	self = (hashmap)malloc(sizeof(self));
	self->cap = 26;
	self->len = 0;
	self->list = calloc((self->cap), sizeof(pair)); 
	return self;
}
unsigned int SHA_2266(hashmap self, char* key){
	int code;
	for(code = 0; (*key)!='\0'; key+=1){
		code +=((int)(*key)) *2266 + 62;
	}
	return code % (self->cap);
}
void set(hashmap self, char* key, int val){
		/*優化算法:next指針都被初始化為NULL,即可這樣做
		 unsigned index = hashcode(this, key);
      		 Pair* current;
  		  for (current = this->list[index]; current;
      		   current = current->next) {
      		    // if key has been already in hashmap
      		  if (!strcmp(current->key, key)) {
      		      current->val = val;
      		      return;
      		  }
  		  }
  		    // key is not in the hashmap
  		  Pair* p = malloc(sizeof(*p));
  		  p->key = key;
 		   p->val = val;
 		   p->next = this->list[index];
 		   this->list[index] = p;
 		   this->len++;
		   */

	pair track;
	pair p = (pair)malloc(sizeof(Pair));
	unsigned int index = SHA_2266(self, key);
	if(self->list[index]){
		for(track = self->list[index] ; strcmp(track->key, key)&&track->next!=NULL ; track = track->next);
		if(!strcmp(track->key, key)){
            track->val = val;
        }
		if(track->next == NULL){
			p->key = key;
			p->val = val;
			p->next = NULL;
			track->next = p;
			self->len+=1;
			/*優化算法:把後加上的掛在頭那, 比較容易搜尋
			  p->next = self->list[index];
			  self->list[index] = p
			*/
		}
	}
	else{
            p->key = key;
            p->val = val;
            p->next = NULL;
            self->list[index]=p;
	}
	return;

}
int get(hashmap self, char* key){
	pair current;
	for(current = self->list[SHA_2266(self, key)];current!= NULL;current=current->next){
		if(!strcmp(current->key, key))
			return current->val;
	}
	fprintf(stderr,"%s is not found",key);
	exit(EXIT_FAILURE);
} 

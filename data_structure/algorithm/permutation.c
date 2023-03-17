#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LEN 80
int to_number(char* temp,int* arr);
bool in_range(char);
char* s_gets(char* temp, int n);
void permutation(int a[],int left, int right );
void swap(int* left, int* right);
int main(){
	char temp[100]={};
	int arr[100]={};
	char store[100][10]={};
	int i=0;;
	s_gets(temp, LEN);
	i = to_number(temp,arr);
	permutation(arr,0,i-1);
}
char* s_gets(char*temp, int len){
	char* ret_val;
	char* find;
	ret_val = fgets(temp,len,stdin);
	if(ret_val){
		for(find = temp;(*find)!='\n' && (*find)!='\0';find+=1);
		if((*find)=='\n'){
			*find = '\0';
		}
		else{
			while(getchar() != '\n');			
		}
		return ret_val;
	}
	else{
		return NULL;
	}
}


bool in_range(char ch){
	switch(ch){
		case'0':
				return true;
				break;
		case '1':
				return true;
				break;
		case '2':
				return true;
				break;
		case '3':
				return true;
				break;
		case '4':
				return true;
				break;
		case '5':
				return true;
				break;
		case '6':
				return true;
				break;
		case '7':
				return true;
				break;
		case '8':
				return true;
				break;
		case '9':
				return true;
				break;
		case'-':
				return true;
				break;
		default:
				return false;
				break;
	}
}
void swap(int* left, int* right){
	int temp = (*right);
	(*right) = (*left);
	(*left) = temp;
}
void permutation(int a[],int left, int right){
	int count = 0;
	if(left == right){
		for(count=0;count<=right;count++){
			printf("%d ",a[count]);
		}
		printf("\n");
		return;
	}
	for(count=left;count<=right;count++){
		swap(&(a[left]),&(a[count]));
		permutation(a,left+1,right);
		swap(&(a[count]),&(a[left]));
	}

}
int to_number(char* temp,int* arr){
	int count=0,i=0,j=0;
	char store[100][10]={};
	while(temp[count]!='\0'){
		if(!in_range(temp[count])){
			count++;
			continue;
		}
		for(j = 0;in_range(temp[count]);j++,count++){
				store[i][j]=temp[count];
		}
		i++;
	}
	for(count=0;count<i;count++){
		arr[count] = atoi(store[count]);
	}
	return i;

}

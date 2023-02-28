#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define QUAN 52
int main(void){
	int poker[QUAN];
	int count = 0;
	for(count = 0;count<QUAN;count++){
		poker[count] = count;
	}
	
	int exch,temp;
	srand((unsigned)time(NULL));
	for(count=0;count<QUAN;count++){
		exch = rand() % 52+ 1;
		temp = poker[exch];
		poker[exch] = poker[count];
		poker[count] = temp;
	}
	int j;
	for(count=0;count<QUAN;count++){
		if(count%4 == 0)
			printf("\n");	
		switch(poker[count]%4){
			case 0:
				printf("♤%d ",poker[count]%13+1);
				break;
			case 1:
				printf("♡%d ",poker[count]%13+1);
				break;
			case 2:
				printf("♢%d ",poker[count]%13+1);
				break;
			case 3:
				printf("♧%d ",poker[count]%13+1);
				break;
			}
		

	}
	return 0;
}

#include <stdio.h>
#include "define.h"//分段計價的費率
void count_c(void);
void count_r(void);
void count_j(void);
void count_s(void);
void dollar(void);
int main (void)
{
  char choose,
       clear;//等一下清緩存時會用到的變數
  int quit=0;
  int test_git;
 do
{
  printf("If the condition is commercial pricing and is not in June,July,Augest,September. Please input C.\n"
         "If the condition is residental pricing and is not in June,July,Augest,September. Please input R.\n"
         "If the condition is commercial pricing and is in June,July,Augest,September. Please input J.\n"
         "If the condition is residental pricing and is in June,July,Augest,September. Please input S.\n"
         "If you want to quit. Please input Q\n>>");
  
  scanf("%c",&choose);
  
  switch (choose)
  {
   case'C':
    count_c();
    break;
  
   case'R':
    count_r();
    break;
   
   case 'J':
     count_j();
     break;
     
   case 'S':
     count_s ();
     break;

   case 'Q':
    quit = 1;
    printf("Thanks for using.\n");
    break;
    
   default:
    printf("your input cannot be identified. Please follow the following instruction.\n");
    
    while((clear=getchar())!='\n') continue;//清緩存用，在這裡，當getchar()讀取stdin並返回值給clear之後，stdin中便會清除相應的char字符。所以，在這裡的例子，相當於fflush(stdin); 
    //getchar()函數，是一個讀取stdin的函數，回傳值是char類型，所以如果你輸入10,它的類型不是int的10,而是char類型的 '1' '0'
    break;
  }
 
  if(quit)//退出do while 迴圈的程式
   break;

}while(choose!='C'||choose !='R'||choose!='J'||choose!='S');
  dollar();
  
  return 0;
}


void count_r(void)
{
  double electr,total=0.;
  int sum=0;
  char clear;
  printf("Please input how much the electricity used.\n>>");
  while(scanf("%lf",&electr))
  {
    if(electr<=120.&& electr>=0.)
    {
      total = S1*electr;
      if((total-(int)total)>=0.5)//四捨五入的函數
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<330.&& electr >=120.)
    {
      total = S1*120+S2*(electr-120.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=500.&&electr>330.)
    {
      total = S1*120+S2*210+S3*(electr-330.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=700.&&electr>500.)
    {
      total = S1*120+S2*210+S3*170+S4*(electr-500.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=1000.&&electr>700.)
    {
      total = S1*120+S2*210+S3*170+S4*200+S5*(electr-700.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr>1000.)
    {
      total = S1*120+S2*210+S3*170+S4*200+S5*300+S6*(electr-1000.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else//違法輸入，例如輸入負數
    {
      printf("Your input is not reasonable. Please input again.\n");
    }
    
  }
  
  while((clear=getchar())!='\n')
      continue;
 
}

void count_c(void)
{
  double electr,total=0.;
  int sum =0;
  char clear;
  printf("Please input how much the electricity used.\n>>");
  while(scanf("%lf",&electr))
  {
    if(electr<=330.&& electr>=0.)
    {
      total = CS1*electr; 
       if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<700.&& electr >=300.)
    {
      total = CS1*330+CS2*(electr-330.);
       if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=1500.&&electr>700.)
    {
      total = CS1*330+CS2*400+CS3*(electr-700.);
       if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    
    else if(electr>1500.)
    {
      total = CS1*330+CS2*400+CS3*800+CS4*(electr-1500.);
       if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else
    {
      printf("Your input is not reasonable. Please input again.\n");
    }
   
  }
  while((clear=getchar())!='\n')
     continue;
 
}

void dollar (void)
{
  int i,j,k;
  for (i=1;i<=6;i++)//上面的六層結構
  {
    for(j=5;j>=i;j--)//空格數量
    {
      printf(" ");
    }
    for(k=1;k<=2*i-1;k++)//＄的數量
    {
      printf("$");
    }
    printf("\n");
  }
  for(i=1;i<=5;i++)//下面的五層結構
  {
    for(j=0;j<i;j++)//空格數量
    {
      printf(" ");
    }
    for(k=9;k>=2*i-1;k--)//＄的數量
    {
      printf("$");
    }
    printf("\n");
  }
}
void count_j(void)
{
   double electr,total=0.;
   int sum=0;
  char clear;
  printf("Please input how much the electricity used.\n>>");
  while(scanf("%lf",&electr))
  {
    if(electr<=330.&& electr>=0.)
    {
      total = CW1*electr; 
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<700.&& electr >=300.)
    {
      total = CW1*330+CW2*(electr-330.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=1500.&&electr>700.)
    {
      total = CW1*330+CW2*400+CW3*(electr-700.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    
    else if(electr>1500.)
    {
      total = CW1*330+CW2*400+CW3*800+CW4*(electr-1500.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else
    {
      printf("Your input is not reasonable. Please input again.\n");
    }
   
  }
  while((clear=getchar())!='\n')
     continue;
 
}
void count_s(void)
{
  double electr,total=0.;
  int sum=0;
  char clear;
  printf("Please input how much the electricity used.\n>>");
  while(scanf("%lf",&electr))
  {
    if(electr<=120.&& electr>=0.)
    {
      total = W1*electr; 
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<330.&& electr >=120.)
    {
      total = W1*120+W2*(electr-120.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=500.&&electr>330.)
    {
      total = W1*120+W2*210+W3*(electr-330.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=700.&&electr>500.)
    {
      total = W1*120+W2*210+W3*170+W4*(total-500.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr<=1000.&&electr>700.)
    {
      total = W1*120+W2*210+W3*170+W4*200+W5*(electr-700.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else if(electr>1000.)
    {
      total = W1*120+W2*210+W3*170+W4*200+W5*300+W6*(electr-1000.);
      if((total-(int)total)>=0.5)
        sum=(int)total+1;
      else
        sum=(int)total;
      printf("your must pay $%d to Taiwan Power Company\n",sum);
      break;
    }
    else
    {
      printf("Your input is not reasonable. Please input again.\n");
    }
    
  }
  while((clear=getchar())!='\n')
      continue;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include "dataframe.h"
/*
    函式名稱: get_string
    參數: 無
    return value: string結構指標
    目的: return 的值, 是擷取stdin(使用者輸入), 再轉為string結構, 方便進行後面的操作 
                                                        (我真的試過直接用使用者輸入來操作, 但失敗了)
    反正這個函式, 大家未來在用自己的函式時, 應該使用不太到, 我就先介紹到這了
*/
String* get_string(){
    String* res = (String*) malloc(sizeof(String));
    String* left = res;
    String* right = res;
    char now, cur;
    int i = 0;
    if((now = getchar())=='\n'){   
        res->cnum = now;
        res->next = NULL;
        res->row = 0;
        return res;
    }
    i++;
    res->cnum = now;
    res->next = NULL;
    res->row = i;
    left = res;
    now = getchar();
    
    for(;1;){
        for(; now != '\n';){
            
            right = (String*) malloc(sizeof(String));
            right->cnum = now;
            right->row = i;
            right->next = NULL; 

            left->next = right;
            left = right;
            now = getchar();
        }
        if((cur = getchar())=='\n' && now == '\n'){
            right = (String*) malloc(sizeof(String));
            if(right == NULL)
                fprintf(stderr, "right is not assigned");
            right->cnum = '\n';
            right->next = NULL;
            right->row = i;
            left->next = right;
            left = right;
            return res;
        }
        else{
            right = (String*) malloc(sizeof(String));
            right->cnum = now;
            right->next = NULL;
            right->row = i;
            left->next = right;
            left = right;
            now = cur;
        }
        
        i++;
    }
} 
/*
    名稱: print_String
    輸入: String 結構指標
    輸出: 在螢幕上顯示string結構指標所指向的列表(就是助教課剛上的List, 列表)
*/
void print_String(String* lt){
    for(; lt != NULL; lt = lt->next){
        printf("%c:", lt->cnum);
        printf("%d ", lt->row);
    }
}
/*
    名稱: create_list
    輸入: String結構指標
    return value: List結構指標
    簡介: List結構也是列表(就是助教課剛上過的). 與String列表的區別在於:
        1. String 結構裡的cnum還沒轉化成數字(就是它只是字符), 而List就是將String裡的數字字符
        轉成真的數字(int), 在進行儲存
        2. 這個函式可以將String的其他內容進行轉化, 儲存在這個List中. 像是row, 就是矩陣中, 
        一個element在第幾行, col就是第幾列.
    目的: 創造並回傳List結構指標. 不過要注意, 此時這個List也是列表結構(就是我還沒真正讓他變成矩陣)
        我只是在這個List中, 處理每一個element的資訊而已, 千萬不要List dataframe[1][2], 絕對出錯
*/
List* create_list(String* st){
    String* l;          
    String* r;             
    l = st;
    List* res;
    for(; l->cnum == ' '; l = l->next);    
    if(l->row == 0){ 
        //printf("in create_list; success");   
        return NULL;
    }
    
    List* old;
    for(int i = 1; 1; i++){
        if(l->next == NULL)
            break;
        for(int j = 1; 1; j++){
            List* new = (List*) malloc(sizeof(List));
            for(; l->cnum == ' ' || l->cnum == '\n'; l = l->next);
            for(r = l; r->cnum != '\n' && r->cnum != ' '; r = r->next);
            String* slash = l;
            for(; slash->cnum != '/' && slash != r; slash = slash->next);
            if(slash == r){
                char buffer1[100] = {};
                int numerator;
                String* m = l;
                for(int count = 0; m != r; m = m->next, count++){
                    buffer1[count] = m->cnum;
                }
                numerator = atoi(buffer1);
                new->numerator = numerator;
                new->denominator = 1;
                new->row = i;
                new->col = j;
                new->sign = (new->numerator / abs(new->numerator)); 
                new->next = NULL;
                if(i == 1 && j == 1){
                    res = new;
                    old = new;
                }
                else{
                    old->next = new;
                    old = new;
                }
            }
            else{
                char buffer1[100] = {};
                int denominator;
                int numerator;
                String* m = l;
                for(int count = 0; m != slash; m = m->next, count++){
                    buffer1[count] = m->cnum;
                }
                numerator = atoi(buffer1);
                m = slash->next;
                char buffer2[100] = {};
                for(int count = 0; m != r; m = m->next, count++){
                    buffer2[count] = m->cnum;
                }
                denominator = atoi(buffer2);
                new->numerator = numerator;
                new->denominator = denominator;
                new->row = i;
                new->col = j;
                new->sign = (new->numerator / abs(new->numerator)) * (new->denominator / abs(new->denominator));
                new->next = NULL;
                if(i == 1 && j == 1){
                    res = new;
                    old = new;
                }
                else{
                    old->next = new;
                    old = new;
                }
            }
            l = r;
            for(; l->cnum == ' '; l = l->next);
            if(l->cnum == '\n')
                break;
        }
    }
    return res;
}
/*
    名稱: print_list
    人如其名, 我就不多做介紹了
*/
void print_list(List* lt){
    if(lt == NULL)
        return;
    for(; lt!=NULL; lt = lt->next){
        if(lt->denominator!=1){
            printf("%d/%d -> %d:%d\n", lt->numerator, lt->denominator, lt->row, lt->col);
        }
        else
            printf("%d -> %d:%d\n", lt->numerator, lt->row, lt->col);
        if(lt == NULL)
            return;
    }
}
/*
    名稱: get_size
    輸入: 尚未轉化成矩陣結構的 List*結構指標, 矩陣結構需要的m列, n行
    輸出: m列n行
    簡介: 雖然我們在終端機上執行程式, 可以不用輸入幾乘幾, 但是在創造矩陣時, 還是要知道這個矩陣是幾列幾行
*/
void get_size(List* lt, int* m, int* n){
    int row_max = 0;
    int col_max = 0;
    for(;lt != NULL; lt = lt->next){
        if(row_max < lt->row)
            row_max = lt->row;
        if(col_max < lt->col)
            col_max = lt->col;
    }
    *m = row_max;
    *n = col_max;
}
/*
    名稱: init_dataframe
    輸入: 一個儲存矩陣結構, 以及關於此矩陣的各種資訊的Df結構指標
    輸出: 已經經過處理, 擁有完整資訊的Df結構指標
    簡介: 先來講一下為什麼我要把這個結構的名稱叫Df(dataframe), 因為這個結構不止存放array
        (就是最我們之後打程式經常會用到的矩陣), 還存放著其他的資訊, 所以才叫它dataframe(資料框架)
        如果你們以後還想加一些屬性在你們說創造的矩陣中, 就去dataframe.h中, 找到Df結構的定義那, 加上你們要的 
        屬性即可. 這個函式集中了上面的get_string, create_list的函式, 所以之後如果沒必要, 
        你們應該是不會用到get_string, create_list. 所以未來我們用Df結構時, 這個init_dataframe就是大家的好朋友
        只要像這樣 Df* dataframe = (Df*) malloc(sizeof(Df)); init_dataframe(dataframe); 就可以獲得一個香香的矩陣.
        之後要進行像array一樣的操作, 只要dataframe->array[i][j]即可(記得一定要dataframe->, 不然會報錯)
*/
Df* init_dataframe(Df* dataframe){
    puts("\nPlease enter your array(empty line to finish)");
    fflush(stdin);
    String* st = get_string();
    List* lt = create_list(st);
    //if(lt == NULL) printf("init_dataframe; success");
    if(lt == NULL) return NULL;
    int m, n;
    get_size(lt, &m, &n);
    int count = 0;
    (dataframe)->array = (Num**) malloc(m * sizeof(Num*));
    dataframe->row = m;
    dataframe->col = n;
    for(int i = 0; i < m; i++){
        (dataframe)->array[i] =(Num*) malloc(n * sizeof(Num));
        count = 0;
        for(int j = 0; j < n; j++){
            if(lt == NULL){
               fprintf(stderr, "你的矩陣要%d列%d行, 你目啾嘎我貝卡金欸", m, n);
               exit(EXIT_FAILURE); 
            }
            dataframe->array[i][j].numerator = lt->numerator;
            dataframe->array[i][j].denominator = lt->denominator;
            strcat(dataframe->array[i][j].color, "yellow");
            lt =lt->next;
            count++;
        }
    }
    return dataframe;           
}
/*
    名稱: print_array
    輸入輸出就不多做介紹, 不過我想向大家特別介紹一下, 就是這個print_array是可以印出帶有顏色的字體的. 未來我會創造get_color的函式,
        它可以讓使用者在終端指定它想要在矩陣的那些元素上著色. 方便使用者觀察.
*/
void print_array(Df* dataframe){
    for(int i = 0; i<dataframe->row; i++){
        for(int j = 0; j<dataframe->col; j++){
            if(dataframe->array[i][j].denominator != 1){
                if(!strcmp(dataframe->array[i][j].color, "red") )
                    printf("\033[41;37;1m%d/%d \033[0m", dataframe->array[i][j].numerator, dataframe->array[i][j].denominator);
                else if(!strcmp(dataframe->array[i][j].color, "yellow") )
                    printf("\033[43;37;1m%d/%d \033[0m", dataframe->array[i][j].numerator, dataframe->array[i][j].denominator);
                else if(!strcmp(dataframe->array[i][j].color, "blue") )
                    printf("\033[44;37;1m%d/%d \033[0m", dataframe->array[i][j].numerator, dataframe->array[i][j].denominator);
                else
                    printf("%d/%d ", dataframe->array[i][j].numerator, dataframe->array[i][j].denominator); 
            }
            else{
                if(!strcmp(dataframe->array[i][j].color, "red") )
                    printf("\033[41;37;1m%d \033[0m", dataframe->array[i][j].numerator);
                else if(!strcmp(dataframe->array[i][j].color, "yellow") )
                    printf("\033[43;37;1m%d \033[0m", dataframe->array[i][j].numerator);
                else if(!strcmp(dataframe->array[i][j].color, "blue") )
                    printf("\033[44;37;1m%d \033[0m", dataframe->array[i][j].numerator);
                else
                    printf("%d ", dataframe->array[i][j].numerator);
            }
        }
        puts("");
    }
    printf("Row(dataframe) = %d\n", dataframe->row);
    printf("Col(dataframe) = %d\n", dataframe->col);
}
/*
    名稱: m_n_init_dataframe
    輸入: 一個確定指向一個Df物件的Df*指標, 你要的矩陣的列數m,你要的矩陣的行數n
    結果: 你的Df*指標-->Df物件.array, 為一個大小為mXn的0矩陣
*/
void m_n_init_dataframe(Df* dataframe, int m, int n){
    (dataframe)->array = (Num**) malloc(m * sizeof(Num*));
    dataframe->row = m;
    dataframe->col = n;
    for(int i = 0; i < m; i++){
        (dataframe)->array[i] =(Num*) malloc(n * sizeof(Num));
        for(int j = 0; j < n; j++){
            dataframe->array[i][j].numerator = 0;
            dataframe->array[i][j].denominator = 1;
            strcat(dataframe->array[i][j].color, "yellow");
        }
    }
}
/*
    名稱: case1
        顧名思義就是處理case1要執行的動作
*/
void case1(){
    Df* dataframe = (Df*) malloc(sizeof(Df));
    init_dataframe(dataframe);
    print_array(dataframe);
    Df* aa = (Df*) malloc(sizeof(Df));
    m_n_init_dataframe(aa, dataframe->row, dataframe->col);
    Num d;
    if((dataframe->row)!=(dataframe->col)){
        printf("This matrix is not square\n");
    }
    else{
        d=det(dataframe);
        aa=adj(dataframe);
        if(d.denominator==1){
            printf("\ndetminant: %d\n",d.numerator);
        }
        else{
            printf("\ndetminant: %d/%d\n",d.numerator,d.denominator);
        }
        if(d.numerator!=0){
            printf("\nadjoint:\n\n");
            for(int i=0;i<dataframe->row;i++){
                for(int j=0;j<dataframe->col;j++){
                    if(aa->array[i][j].denominator==1){
                        printf("%d ",aa->array[i][j].numerator);
                    }
                    else{
                        printf("%d/%d ",aa->array[i][j].numerator,aa->array[i][j].denominator);
                    }
                }
                printf("\n");
            }
            aa=inverse(dataframe);
            printf("\ninverse:\n\n");
            for(int i=0;i<dataframe->row;i++){
                for(int j=0;j<dataframe->col;j++){
                    if(aa->array[i][j].denominator==1){
                        printf("%d ",aa->array[i][j].numerator);
                    }
                    else{
                        printf("%d/%d ",aa->array[i][j].numerator,aa->array[i][j].denominator);
                    }
                }
                printf("\n\n");
            }
        }
    }
}

/*  
    名稱: case2
    簡介：矩陣乘法
    執行輸入:gcc main.c dataframe.c -o main
            ./main
        2023/5/27 談晋東
*/
void case2(){
    Df* dataframeA = (Df*) malloc(sizeof(Df));
    init_dataframe(dataframeA);
    Df* dataframeB = (Df*) malloc(sizeof(Df));
    init_dataframe(dataframeB);
    Df* dataframeT = (Df*) malloc(sizeof(Df));
    m_n_init_dataframe(dataframeT, dataframeA->row, dataframeB->col);
    if(dataframeA->col != dataframeB->row){
        printf("Error: The number of columns in matrix A must be equal to the number of rows in matrix B.\n");
        return ;
    }
    for(int i=0;i<dataframeA->row;i++){
        for(int j=0;j<dataframeB->col;j++){
            Num not_sim;
            not_sim.numerator = 0;
            not_sim.denominator = 1;
            for (int k = 0; k < dataframeA->col; k++){
                not_sim.numerator = not_sim.numerator * dataframeA->array[i][k].denominator * dataframeB->array[k][j].denominator 
                + not_sim.denominator * dataframeA->array[i][k].numerator * dataframeB->array[k][j].numerator;
                not_sim.denominator = not_sim.denominator * dataframeA->array[i][k].denominator * dataframeB->array[k][j].denominator;
            }
            Num sim = simplify(not_sim);
            dataframeT->array[i][j].numerator = sim.numerator;
            dataframeT->array[i][j].denominator = sim.denominator;
        }
    }
    print_array(dataframeT);
}            
/*
    名稱: case4
        修正中
        補能帶入分數跟檢查矩陣大小
        2023/5/21 沈義軒
        分數功能加入~
        係數也能輸入分數但會多印出plaese enter your array
        因為我使用init_dataframe輸入係數
        我太菜了只能先這樣
        2023/6/12 沈義軒
        感覺修改完成了吧!
        2023/6/12 張冠麒
        稍微優化 主要功能不變 防止容易爆int
        2023/6/15 沈義軒
*/
void case4(){
    int allmatrices = 1;
    char operator;
    Num notsim, sim;
    Df* dataframe1 = (Df*) malloc(sizeof(Df));
    Df* dataframe2 = (Df*) malloc(sizeof(Df));
    List* coeff; String* st;
    for(int n = 1; n <= allmatrices; n++){
        if(n==1){
            printf("Enter coefficient or input 0 to end\n");
            st = get_string();
            coeff = create_list(st);
            if(!(coeff->denominator && coeff->numerator))break;
            init_dataframe(dataframe1);
            for(int i = 0; i < dataframe1->row; i++)
                for(int j = 0; j < dataframe1->col; j++){
                    dataframe1->array[i][j].numerator *= coeff->numerator;
                    dataframe1->array[i][j].denominator *= coeff->denominator;
                    notsim.numerator = dataframe1->array[i][j].numerator;
                    notsim.denominator = dataframe1->array[i][j].denominator;
                    sim = simplify(notsim);
                    dataframe1->array[i][j].numerator = sim.numerator;
                    dataframe1->array[i][j].denominator = sim.denominator;
                }
        }
        printf("Enter operator or press any key to end\n");
        char operator = getchar();
        while(getchar() != '\n');
        switch(operator){
            case '+':
                printf("Enter coefficient or input 0 to end\n");
                st = get_string();
                coeff = create_list(st);
                if(!(coeff->numerator || coeff->denominator))break;
                init_dataframe(dataframe2);
                if(dataframe1->col != dataframe2->col || dataframe1->row != dataframe2->row){
                    printf("Error: The number of columns and rows in this matrix must equal to the former matrix.\n");
                    return ;
                }
                for(int i = 0; i < dataframe1->row; i++)
                    for(int j = 0; j < dataframe1->col; j++){
                        dataframe2->array[i][j].numerator *= coeff->numerator;
                        dataframe2->array[i][j].denominator *= coeff->denominator;
                        dataframe1->array[i][j].numerator = 
        dataframe2->array[i][j].numerator * dataframe1->array[i][j].denominator + dataframe1->array[i][j].numerator * dataframe2->array[i][j].denominator;
                        dataframe1->array[i][j].denominator = dataframe1->array[i][j].denominator * dataframe2->array[i][j].denominator;
                        notsim.numerator = dataframe1->array[i][j].numerator;
                        notsim.denominator = dataframe1->array[i][j].denominator;
                        sim = simplify(notsim);
                        dataframe1->array[i][j].numerator = sim.numerator;
                        dataframe1->array[i][j].denominator = sim.denominator;
                    }
                allmatrices++;
                break;
            case '-':
                printf("Enter coefficient or input 0 to end\n");
                st = get_string();
                coeff = create_list(st);
                if(!(coeff->numerator || coeff->denominator))break;
                init_dataframe(dataframe2);
                if(dataframe1->col != dataframe2->col || dataframe1->row != dataframe2->row){
                    printf("Error: The number of columns and rows in this matrix must equal to the former matrix.\n");
                    return ;
                }
                for(int i = 0; i < dataframe1->row; i++)
                    for(int j = 0; j < dataframe1->col; j++){
                        dataframe2->array[i][j].numerator *= coeff->numerator;
                        dataframe2->array[i][j].denominator *= coeff->denominator;
                        dataframe1->array[i][j].numerator = 
        dataframe1->array[i][j].numerator * dataframe2->array[i][j].denominator - dataframe2->array[i][j].numerator * dataframe1->array[i][j].denominator;
                        dataframe1->array[i][j].denominator = dataframe1->array[i][j].denominator * dataframe2->array[i][j].denominator;
                        notsim.numerator = dataframe1->array[i][j].numerator;
                        notsim.denominator = dataframe1->array[i][j].denominator;
                        sim = simplify(notsim);
                        dataframe1->array[i][j].numerator = sim.numerator;
                        dataframe1->array[i][j].denominator = sim.denominator;
                    }
                allmatrices++;
                break;
            default :
                break;
        }   
    }
    print_array(dataframe1);
}

/*
    名稱: cal_cof
    輸入: 原本的矩陣以及你要算的cofactor所在的row跟column(row跟column是從0開始算，要特別注意)
    輸出: cofactor的值
*/
Num cal_cof(Df* dataframe,int r,int c){
    Num cof;
    Df* aa = (Df*) malloc(sizeof(Df));
    m_n_init_dataframe(aa, (dataframe->row)-1, (dataframe->col)-1);
    int rr=0;
    int cc=0;
    for(int k=0;k<dataframe->row;k++){
        for(int l=0;l<dataframe->col;l++){
            if((l!=c)&&(k!=r)){
                aa->array[rr][cc].numerator=dataframe->array[k][l].numerator;
                aa->array[rr][cc].denominator=dataframe->array[k][l].denominator;
                cc++;
                if(cc==(dataframe->col-1)){
                    cc=0;
                }
            }
        }
        if(k!=r){
            rr++;
            if(rr==(dataframe->row-1)){
                rr=0;
            }
        }
    }
    aa->row=dataframe->row-1;
    aa->col=dataframe->col-1;
    cof=det(aa);
    if((r+c)%2==1){
        cof.numerator*=(-1);
        return simplify(cof);
    }
    else{
        return simplify(cof);
    }
}
/*
    名稱: det
        顧名思義就是計算行列式值，只需輸入你要算的矩陣
*/
Num det(Df* dataframe){
    Num d;
    Num t;
    if(dataframe->row>2){
        for(int i=0;i<dataframe->row;i++){
            t.numerator=dataframe->array[i][0].numerator*cal_cof(dataframe,i,0).numerator;
            t.denominator=dataframe->array[i][0].denominator*cal_cof(dataframe,i,0).denominator;
            if(i==0){
                d.numerator=t.numerator;
                d.denominator=t.denominator;
            }
            else{
                d.numerator=d.numerator*t.denominator+t.numerator*d.denominator;
                d.denominator=d.denominator*t.denominator;
            }
        }
        return simplify(d);
    }
    else if(dataframe->row==2){
        d.numerator=dataframe->array[0][0].numerator*dataframe->array[1][1].numerator*dataframe->array[0][1].denominator*dataframe->array[1][0].denominator-dataframe->array[0][1].numerator*dataframe->array[1][0].numerator*dataframe->array[0][0].denominator*dataframe->array[1][1].denominator;
        d.denominator=dataframe->array[0][0].denominator*dataframe->array[1][1].denominator*dataframe->array[0][1].denominator*dataframe->array[1][0].denominator;
        return simplify(d);
    }
    else{
        d.numerator=dataframe->array[0][0].numerator;
        d.denominator=dataframe->array[0][0].denominator;
        return simplify(d);
    }
}
/*
    名稱: adj
    輸入: 你想要處理的矩陣
    輸出: 轉換過的adjoint
*/
Df* adj(Df* dataframe){
    Df* aa = (Df*) malloc(sizeof(Df));
    m_n_init_dataframe(aa, dataframe->row, dataframe->col);
    for(int i=0;i<dataframe->row;i++){
        for(int j=0;j<dataframe->col;j++){
            aa->array[i][j].numerator=cal_cof(dataframe,j ,i).numerator;
            aa->array[i][j].denominator=cal_cof(dataframe,j ,i).denominator;
            aa->array[i][j]=simplify(aa->array[i][j]);
        }
    }
    return aa;
}
/*
    名稱: inverse
        顧名思義就是將你輸入的矩陣轉換為反矩陣
*/
Df* inverse(Df* dataframe){
    Num d=det(dataframe);
    dataframe=adj(dataframe);
    for(int i=0;i<dataframe->row;i++){
        for(int j=0;j<dataframe->col;j++){
            dataframe->array[i][j].numerator*=d.denominator;
            dataframe->array[i][j].denominator*=d.numerator;
            dataframe->array[i][j]=simplify(dataframe->array[i][j]);
        }
    }
    return dataframe;
}
/*
    名稱: simplify
    輸入: 你想要化簡的分數(要是Num)
    輸出: 最簡分數
*/
Num simplify(Num a){
    int t;
    Num b;
    int j=a.numerator;
    int k=a.denominator;
    while(k!=0){
        t=j%k;
        j=k;
        k=t;
    }
    b.numerator=a.numerator/j;
    b.denominator=a.denominator/j;
    return b;
}
/*
    名稱: case3
        解Ax=b 並輸出結果b
        2023/05/24 黃翊宸
        成功解決
        2023 6/9 張冠麒
*/
void case3(){
    Df* dataframe = (Df*) malloc(sizeof(Df));
    init_dataframe(dataframe);
    if (dataframe->col != dataframe->row){
        printf("A is not square");
        return;
    }
    
    /*Df* dataframe1 = (Df*) malloc(sizeof(Df));   //dataframe1=A[i][j]
    m_n_init_dataframe(dataframe1, dataframe->row, dataframe->col);*/
    
    Df* dataframei = (Df*) malloc(sizeof(Df));   //dataframei=A[i][j]之反矩陣
    //m_n_init_dataframe(dataframei, dataframe->row, dataframe->col);
    dataframei=inverse(dataframe);              //使用inverse得A_inv[i][j]

    Df* dataframe2 = (Df*) malloc(sizeof(Df));   //dataframe2=B[i][j]
    init_dataframe(dataframe2);
    if(dataframe2->row != dataframe->col){
        printf("x's row can not fit with A_inv's col");
        return;
    }
    Df* dataframex = (Df*) malloc(sizeof(Df));   //dataframex=x[j]
    m_n_init_dataframe(dataframex, dataframei->row, dataframe2->col);
    
    int i,j;
    //使A的反矩陣與X相乘後,結果儲存於b
    
    for(i=0;i<dataframei->row;i++){               //for(i=0;i<N;i++)
        for(j=0;j<dataframe2->col;j++){           //for(j=0;j<N;i++)
            Num not_sim;
            not_sim.numerator = 0;
            not_sim.denominator = 1;
            for (int k = 0; k < dataframei->col; k++){
                not_sim.numerator = not_sim.numerator * dataframei->array[i][k].denominator*dataframe2->array[k][j].denominator + not_sim.denominator * dataframei->array[i][k].numerator * dataframe2->array[k][j].numerator;
                not_sim.denominator = not_sim.denominator * dataframei->array[i][k].denominator * dataframe2->array[k][j].denominator;
            }
            Num sim = simplify(not_sim);
            dataframex->array[i][j].numerator = sim.numerator;
            dataframex->array[i][j].denominator = sim.denominator;
        }
    }
    print_array(dataframex);
    
} 
#ifndef DATAFRAME
#define DATAFRAME
typedef struct Number{
    char color[10];
    int sign;
    int numerator;
    int denominator;
}Num;
typedef struct Dataframe{
    Num** array;
    int row;
    int col;
    char color[10];
}Df;
typedef struct String{
    struct String* next;
    int row;
    char cnum;
}String;
typedef struct List{
    struct List* next;
    int row;
    int col;
    int sign;
    int numerator;
    int denominator;
}List;

String* get_string();
void print_String(String* lt);
List* create_list(String* st);
void print_list(List* lt);
void get_size(List* lt, int* m, int* n);
Df* init_dataframe(Df* dataframe);
void print_array(Df* dataframe);
void m_n_init_dataframe(Df* dataframe, int m, int n);
void case1();
void case2();
void case3();
void case4();
Num cal_cof(Df* dataframe, int r, int c);
Num det(Df* dataframe);
Df* adj(Df* dataframe);
Num simplify(Num a);
Df* inverse(Df* dataframe);
#endif
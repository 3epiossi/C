#include<stdio.h>
#include<stdlib.h>
#include "dataframe.h"

/*
    我(張冠麒)對這個程式的構思: 
        競程電神已經將很多演算法想出來了,我看未來當我們在上特徵值時,他大概也把特徵值的演算法也打好了. 
        所以我們必須想一些點子, 否則就給他玩就好了😂 我想把這個程式變成是可以連續運算的計算機, 也可以儲存很多種不同的Df結構
        例如: 當使用者想要計算 cA + kB(c, k是常數, A,B是矩陣), 就可以先算出cA是什麼矩陣, 在儲存cA; 在計算kB是什麼矩陣,
        在儲存kB; 最後在創造新的矩陣, 儲存著cA+kB. 然後使用者還可以繼續進行運算, 像是求得cA+kB的行列式值, cofactor矩陣等等....

    如果有什麼新想法, 歡迎大家打在這裡, 方便大家了解. 對了, 這個平台最多只能容納5個人一起編輯程式, 在多就要課金了, 
        所以如果某一天, 你發現無法造訪此程式時, 就是5人名額已滿, 我把你先”暫時“移出名單而已. 記得在群組裡說, 我就會邀請你來了

    如果大家已經創造除了一個新函式, 記得就像競程電神說的: 記得加註釋. 我在這裡先建立一個標準寫注釋的格式
    ”“”
    函式名稱:
    參數 或 終端輸入:
    return value 或 終端輸出:
    簡介:
    目的:
    “”“ 
    可以不用完全寫出來, 只要你覺得意思到就好, 以上格式只是做參考. 對了, 記得創造新函式時, 也要來這裡說一下
    大家就一起加油吧! 💪 
    更新: 這裡的debuger, 我不知道怎麼用, 如果有人成功了, 麻煩教我. 如果想編譯檔案, 麻煩在終端輸入:
        gcc main.c dataframe.c (如果以後還有其他.c檔案, 記得在這裡加上) -o main
    張冠麒 2023/5/14
    
    我們每個人在修改這個程式時先匯出一份到群組當備份，以免到時候debug不出來，匯出時只需要下載.h和兩個.c檔就好
    袁嘉謙/5/14/5/14
    
    說的有道理. 還有, 如果大家寫出函式, 記得先在自己的電腦上試運行, 再來這裡運行, 
    一切都以這裡不要出bug為最高指導原則
    張冠麒 2023/5/14 二更

    bug解決: 解除掉get_string沒有fflush的問題
    張冠麒 2023/5/19

    case1完成
    袁嘉謙 2023/5/20

    只是把while(getchar != \n) 移到main函式而已, 但還是做個紀錄, 
    還有print_array那, 把if..if...if...改成if... else if... else...
    張冠麒 2023/5/20

    分數化簡優化
    袁嘉謙 2023/5/20

    把 void init_dataframe(...) 變成 Df* init_dataframe(...), 但是初始化dataframe的方式不受影響
    張冠麒 2023/5/20

*/
int main(){
    Df* dataframe = (Df*) malloc(sizeof(Df));
    char want;
    
    printf("What do you want to do?\n\n1: Find determinant & adjoint & inverse \n2: multiply matrices\n3: Solve Ax = B\n4: linear combination\n\nEnter a number: ");
    scanf("%c",&want);
    while(getchar() != '\n');
    switch(want){
        case '1':
            case1();
            break;
        case '2':
            case2();
            break;
        case '3':
            case3();
            break;
        case '4':
            case4();
            break;
        default:
            break;
    }
    return 0;
}
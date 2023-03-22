// #include<stdio.h>
// int main(){
// 	int a;
// 	scanf("%d", &a);
// 	if(a==4){
// 		printf("CHECK THE NUMBER AGAIN");}
// }
//devanshu was here
#include <stdio.h>
#include <stdbool.h>
//BY BD(dev)
int answerfinder(int *array1, int *array2, int len, int pointer, int sum) {
    //base
    if(len == pointer-1) {
        for(int v = 0; v < len; v++) {
            printf("%d ", *(array1+v));
        }
        printf("\n");
        return 0;
    }

    //process
    bool checker = true;
    for(int e = 0; e < len; e++) {
        if(*(array2+e) > 0 && (sum + *(array2+e)) % pointer != 0) {
            *(array1+pointer-1) = *(array2+e);
            sum = sum + *(array2+e);
            *(array2+e) = 0;
            checker = false;
            break;
        }
    }
    if(checker == true) {
        return -1;
    }
    
    //recurse
    return answerfinder(array1, array2, len, pointer+1, sum);
}

int main() {
    // your code goes here
    int _BD_;
    scanf("%d", &_BD_);
    while(_BD_--) {
        int len;
        scanf("%d", &len);
        int array1[len];
        int array2[len];
        for(int d = 1; d <= len; d++) {
            *(array2+d-1) = d;
        }
        *array2 = 0;
        *array1 = 1;
        int printnegitive1true = answerfinder(array1, array2, len, 2, 1);
        if(printnegitive1true == -1) {
            printf("-1\n");
        }
    }
    return 0;
}


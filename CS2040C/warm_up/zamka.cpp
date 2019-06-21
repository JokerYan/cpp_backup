#include <stdio.h>

int sumDigits(int number);

int main(){
    int L, M, X;
    scanf("%d %d %d", &L, &M, &X);

    for(int i = L; i <= M; i++){
        if(sumDigits(i) == X){
            printf("%d\n", i);
            break;
        }
    }
    for(int i = M; i >= L; i--){
        if(sumDigits(i) == X){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

int sumDigits(int number){
    int sum = 0;
    while(number > 0){
        sum += number % 10;
        number = number / 10;
    }
    return sum;
}
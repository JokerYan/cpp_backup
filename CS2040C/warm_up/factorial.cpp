#include <stdio.h>

int calLastFactorial(int N);

int main(){
    int T;
    scanf("%d", &T);
    int N;
    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        printf("%d\n", calLastFactorial(N));
    }
    return 0;
}

int calLastFactorial(int N){
    int lastDigit = 1;
    for(int i = 2; i <= N; i++){
        lastDigit = lastDigit * i % 10;
    }
    return lastDigit;
}
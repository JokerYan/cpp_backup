#include <stdio.h>

bool debug = false;

bool isHarshad(long n);
int main(){
    long n;
    scanf("%ld", &n);
    while(true){
        if(isHarshad(n)){
            printf("%ld", n);
            break;
        }
        else n++;
    }

    return 0;
}


bool isHarshad(long n){
    int digitSum = 0;
    long n_left = n;
    while(n_left > 0){
        digitSum += n_left % 10;
        n_left = n_left / 10;
    }
    if(debug) printf("%d\n", digitSum);
    return ((n % digitSum) == 0);
}
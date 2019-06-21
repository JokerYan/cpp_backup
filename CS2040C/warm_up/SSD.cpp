#include <stdio.h>
#include <math.h>

bool debug = false;
int main(){
    int P;
    scanf("%d", &P);

    int K, b, n;
    int SSD, cur_digit;
    for(int i = 0; i < P; i++){
        scanf("%d %d %d", &K, &b, &n);
        SSD = 0;
        while(n > 0){
            cur_digit = n % b;
            if(debug) printf("SSD:%d\t", SSD);
            // SSD += cur_digit * cur_digit;
            SSD += round(pow(cur_digit, 2));
            if(debug) printf("digit:%d\t SSD:%d\n", cur_digit, SSD);
            n = n / b;
        }
        printf("%d %d\n", K, SSD);
    }
    return 0;
}
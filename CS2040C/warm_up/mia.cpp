#include <stdio.h>

int calValue(int a, int b);
int main(){
    int s0, s1, r0, r1;
    int value1, value2;
    while(true){
        scanf("%d %d %d %d", &s0, &s1, &r0, &r1);
        if(s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0) break;
        value1 = calValue(s0, s1); value2 = calValue(r0, r1);
        if(value1 > value2) printf("Player 1 wins.\n");
        else if (value1 < value2) printf("Player 2 wins.\n");
        else printf("Tie.\n");
    }
    return 0;
}

int calValue(int a, int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    int value = 10 * a + b;
    if(value == 21) value = value * 100;
    if(a == b) value = value * 10;
    return value;
}

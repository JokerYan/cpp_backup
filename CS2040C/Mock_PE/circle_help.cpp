#include <stdio.h>
#include <math.h>

int main(){
    for(int i = 0; i <= 2018; i++){
        for(int j = 0; j <= 2018; j++){
            if((int)pow(i, 2) + (int)pow(j, 2) == (int)pow(2018, 2)) printf("%d %d\n", i, j);
        }
    }

    return 0;
}
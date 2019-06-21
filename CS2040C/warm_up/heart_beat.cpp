#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int b; float p;
    for(int i = 0; i < N; i++){
        scanf("%d %f", &b, &p);
        printf("%.4f %.4f %.4f\n", 60 * (b - 1) / p, 60 * b / p, 60 * (b + 1) / p);
    }
    return 0;
}
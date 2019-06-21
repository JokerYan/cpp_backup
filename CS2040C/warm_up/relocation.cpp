#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, Q;
    scanf("%d %d", &N, &Q);
    int* companies = new int[N+1];
    for(int i = 1; i < N + 1; i++){
        scanf("%d", &companies[i]);
    }
    int cmd, arg1, arg2;
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d", &cmd, &arg1, &arg2);
        if(cmd == 1){
            companies[arg1] = arg2;
        }else if(cmd == 2){
            printf("%d\n", abs(companies[arg1] - companies[arg2]));
        }
    }

    return 0;
}
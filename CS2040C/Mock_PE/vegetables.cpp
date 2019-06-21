#include <stdio.h>

int main(){
    float T; int N;
    scanf("%f %d", &T, &N);

    int vegs[N];

    for(int i = 0; i < N; i++){
        int temp;
        scanf("%d", &temp);
        vegs[i] = temp;
    }


    int segs[N];
    float weights[N];
    for(int i = 0; i < N; i++){
        weights[i] = vegs[i];
        segs[i] = 1;
    }

    for(int cut = 0; cut <= 500 ; cut++){
        
        int maxIndex = -1; float max = -1.0f;
        int minIndex = -1; float min = -1.0f;
        for(int i = 0; i < N; i++){
            if(max == -1.0f || max < weights[i]){
                max = weights[i];
                maxIndex = i;
            }
            if(min == -1.0f || min > weights[i]){
                min = weights[i];
                minIndex = i;
            }
        }
        
        if(min / max >= T){
            printf("%d", cut);
            break;
        }

        maxIndex = -1;
        max = -1.0f;
        for(int i = 0; i < N; i++){
            if(max == -1.0f || max < weights[i]){
                max = weights[i];
                maxIndex = i;
            }
        }
        weights[maxIndex] = vegs[maxIndex] / (++segs[maxIndex]);
    }

    return 0;
}
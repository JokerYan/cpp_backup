#include <stdio.h>

int calBox(int* data, int size, int volume){
    int count = 0;
    for(int i = 0; i < size; i++){
        count += (data[i] - 1) / volume + 1;
    }
    // printf("volume: %d; boxes needed: %d\n", volume, count);
    return count;

}

int calPop(int* data, int size, int volume){
    int boxes[size] = {0};
    for(int i = 0; i < size; i++){
        boxes[i] = (data[i] - 1) / volume + 1;
    }
    int maxPop = 0;
    for(int i = 0; i < size; i++){
        int pop = (data[i] - 1) / boxes[i] + 1;
        maxPop = (pop > maxPop) ? pop : maxPop;
    }
    return maxPop;
}


int main(){
    for(int test = 0; test < 3; test++){
        int N, B;
        scanf("%d %d", &N, &B);
        if(N == -1 && B == -1) break;

        int cities[N] = {0};
        for(int i = 0; i < N; i++){
            scanf("%d", &cities[i]);
        }

        //binary search
        int left = 1, right = 5000000, mid;
        while(left <= right){
            mid = (left + right) / 2;
            // printf("binary search ongoing: left: %d; mid: %d; right: %d\t", left, mid, right);
            int boxes = calBox(cities, N, mid);
            // printf("boxes: %d\n", boxes);
            if(boxes > B) left = mid + 1;
            else if(boxes < B){
                if(calBox(cities, N, mid - 1) > B) break;
                right = mid - 1;
            } 
            else{
                if(left == right) break;
                right = mid;
            }
        }
        printf("%d\n", mid);
        scanf("\n");

    }


    return 0;
}
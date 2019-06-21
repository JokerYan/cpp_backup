#include <stdio.h>
#include <stdlib.h>

void quick(int* list, int left, int right);

int main(){
    int N;
    scanf("%d", &N);
    int list[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &list[i]);
    }

    quick(list, 0, N);

    for(int i = 0; i < N; i++){
        printf("%d ", list[i]);
    }

    return 0;
}

void quick(int* list, int left, int right){
    if(left >= right) return;
    int pivot = left;
    int storeIndex = pivot + 1;
    for(int i = pivot + 1; i < right; i++){
        //random to beat the case where all or too many elements are the same
        if(list[i] < list[pivot] || (list[i] == list[pivot] && rand()%2 == 0)){ 
            int temp = list[i];
            list[i] = list[storeIndex];
            list[storeIndex] = temp;
            storeIndex++;
        }
    }
    int temp = list[pivot];
    list[pivot] = list[storeIndex - 1];
    list[storeIndex - 1] = temp;
    quick(list, left, storeIndex - 1);
    quick(list, storeIndex, right);
}
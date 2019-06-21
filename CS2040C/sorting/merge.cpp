#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

void merge(int* list, int low, int mid, int high);
void mergeSort(int* list, int low, int high);

int main(){
    srand(time(NULL));
    long N;
    scanf("%d", &N);
    int *list = new int[N];
    for(int i = 0; i < N; i++){
        list[i] = rand();
    }

    clock_t start = clock();
    mergeSort(list, 0, N);55
    // std::sort(list, list + N);
    clock_t stop = clock();
    printf("Time: %f\n", (double)(stop - start)/ CLOCKS_PER_SEC);

    // for(int i = 0; i < N; i++){
    //     printf("%d ", list[i]);
    // }

    return 0;
}

void merge(int* list, int low, int mid, int high){
    int* tempList = new int[high - low];
    int leftIndex = low, rightIndex = mid;
    int tempIndex = 0;
    while(leftIndex < mid && rightIndex < high)
        tempList[tempIndex++] = (list[leftIndex] <= list[rightIndex]) ? list[leftIndex++] : list[rightIndex++];
    while(leftIndex < mid) tempList[tempIndex++] = list[leftIndex++];
    while(rightIndex < high) tempList[tempIndex++] = list[rightIndex++];
    for(int i= 0; i < high - low; i++){
        list[i + low] = tempList[i];
    }
    delete[] tempList;
}

void mergeSort(int* list, int low, int high){
    if(low < high - 1){
        int mid = (low + high) / 2;
        mergeSort(list, low, mid);
        mergeSort(list, mid, high);
        merge(list, low, mid, high);
    }
}
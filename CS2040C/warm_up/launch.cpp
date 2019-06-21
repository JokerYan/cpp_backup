#include <stdio.h>

int main(){
    int days, min, minIndex = 0;
    scanf("%d %d", &days, &min);
    int temp;
    for(int i = 1; i < days; i++){
        scanf("%d", &temp);
        if(temp < min){
            min = temp;
            minIndex = i;
        }
    }
    printf("%d", minIndex);
    return 0;
}
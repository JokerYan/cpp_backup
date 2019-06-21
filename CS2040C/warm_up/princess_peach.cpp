#include <stdio.h>
#include <stdlib.h>

int main(){
    int total, found;
    scanf("%d %d", &total, &found);
    int obstacles[100] = {0};
    int cur_obstacle;
    for(int i = 0; i < found; i++){
        scanf("%d", &cur_obstacle);
        obstacles[cur_obstacle] = 1;
    }
    int found_count = 0;
    for(int i = 0; i < total; i++){
        if(obstacles[i] == 0) printf("%d\n", i);
        else found_count ++;
    }
    printf("Mario got %d of the dangerous obstacles.", found_count);
    return 0;
}
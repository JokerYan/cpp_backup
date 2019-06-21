#include <stdio.h>

int main(){
    int row, column;
    scanf("%d %d", &row, &column);
    char** map = new char*[row];
    for(int i = 0; i < row; i++){
        map[i] = new char[column];
        scanf("%s", map[i]);
    }
    int x = 0, y = 0, step = 0;
    int pre_x, pre_y;
    while(true){
        if(x < 0 || y < 0 || x >= row || y >= column){
            printf("Out");
            break;
        }
        if(map[x][y] == '-'){
            printf("Lost");
            break;
        }
        if(map[x][y] == 'T'){
            printf("%d", step);
            break;
        }
        pre_x = x; pre_y = y;
        switch(map[x][y]){
            case 'E':
                y++;
                break;
            case 'W':
                y--;
                break;
            case 'S':
                x++;
                break;
            case 'N':
                x--;
                break;
        }
        map[pre_x][pre_y] = '-';
        step++;
    }
    return 0;
}
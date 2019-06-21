#include <stdio.h>
#include <string.h>

int main(){
    // FILE* file;
    // file = fopen("interpreter.in","r");

    int registers[10], RAM[1000];
    memset(registers, 0, sizeof registers);
    memset(RAM, 0, sizeof RAM);
    for(int i = 0; i < 1000; i++){
        scanf("%d", &RAM[i]);
        // fscanf(file, "%d", &RAM[i]);
    }
    int cur_cmd = 0;
    int step = 0;
    int d1, d2, d3;
    while(step < 10000){
        step++;
        d1 = RAM[cur_cmd] / 100;
        d2 = RAM[cur_cmd] / 10 - 10 * d1;
        d3 = RAM[cur_cmd] % 10;
        // printf("%d %d %d %d\n", RAM[cur_cmd], d1, d2, d3);
        cur_cmd++;
        if(d1 == 1) break;
        switch(d1){
            case 2:
                registers[d2] = d3;
                break;
            case 3:
                registers[d2] = (registers[d2] + d3) % 1000;
                break;
            case 4:
                registers[d2] = (registers[d2] * d3) % 1000;
                break;
            case 5:
                registers[d2] = registers[d3];
                break;
            case 6:
                registers[d2] = (registers[d2] + registers[d3]) % 1000;
                break;
            case 7:
                registers[d2] = (registers[d2] * registers[d3]) % 1000;
                break;
            case 8:
                registers[d2] = RAM[registers[d3]];
                break;
            case 9:
                RAM[registers[d3]] = registers[d2];
                break;
            case 0:
                if(registers[d3] != 0) cur_cmd = registers[d2];
                break;
        }
    }
    printf("%d", step);
    return 0;
}
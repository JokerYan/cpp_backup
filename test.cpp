#include <iostream>
#include <string.h>
using namespace std;

int M = 2, N = 5;
char grid[200][200];

int main(){
    memset(grid, 0, sizeof(grid));
    cin >> grid[0];
    cin >> grid[1];
    for(int i = 0; i < M; i++){
        cout << grid[i] << endl;
    }
    return 0;
}
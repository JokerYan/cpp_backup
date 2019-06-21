#include <stdio.h>
#include <unordered_map>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    unordered_map<int, int> table;
    int awkardness = N;

    for(int i = 0; i < N; i++){
        int guest;
        scanf("%d", &guest);
        auto result = table.find(guest);
        if(result != table.end()){
            if(awkardness > i - table[guest])
                awkardness = i - table[guest];
            table[guest] = i;
        }else{
            table[guest] = i;
        }
    }

    printf("%d", awkardness);




    return 0;
}
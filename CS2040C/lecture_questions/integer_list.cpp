#include <stdio.h>
#include <deque>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int p = 0; p < N; p++){
        vector<char> command;
        char tempChar;
        scanf("\n");
        while(true){
            scanf("%c", &tempChar);
            if(tempChar == '\n') break;
            command.push_back(tempChar);
        }
        int n;
        scanf("%d", &n);
        printf("n = %d\n", n);
        deque<int> data;
        scanf("[");
        for(int i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            scanf(",");
            data.push_back(temp);
            printf("(%d) ", temp);
        }
        scanf("]");
        printf("input finished\n");

        queue<int> result;
        bool atFront = true;
        bool error = false;
        for(int i = 0; i < command.size(); i++){
            if(command[i] == 'R') atFront = !atFront;
            else if(command[i] == 'D'){
                if(data.empty()){
                    printf("error\n");
                    error = true;
                    break;
                }
                if(atFront){
                    result.push(data.front());
                    data.pop_front();
                }else{
                    result.push(data.back());
                    data.pop_back();
                }
            }
        }
        if(!error){
            printf("[");
            while(!result.empty()){
                printf("%d", result.front());
                result.pop();
                if(!result.empty()) printf(",");
                else printf("]\n");
            }
        }
    }
    return 0;
}
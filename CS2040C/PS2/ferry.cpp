#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        int n, t, m;
        scanf("%d %d %d", &n, &t, &m);

        queue<int> leftSide, rightSide, leftSideIndex, rightSideIndex;
        for(int j = 0; j < m; j++){
            int arrTime;
            char sideTemp[6];
            scanf("%d %s", &arrTime, sideTemp);
            string side = sideTemp;
            if(side == "left"){
                leftSide.push(arrTime);
                leftSideIndex.push(j);
            }else if(side == "right"){
                rightSide.push(arrTime);
                rightSideIndex.push(j);
            }
        }
        
        int time = 0;
        bool atLeft = true;
        int result[m] = {0};
        while(!leftSide.empty() || !rightSide.empty()){
            bool loaded = false;
            if(atLeft){
                for(int j = 0; j < n; j++){
                    if(!leftSide.empty() && leftSide.front() <= time){
                        leftSide.pop();
                        result[leftSideIndex.front()] = time + t;
                        leftSideIndex.pop();
                        loaded = true;
                    }else break;
                }
            }else{
                for(int j = 0; j < n; j++){
                    if(!rightSide.empty() && rightSide.front() <= time){
                        rightSide.pop();
                        result[rightSideIndex.front()] = time + t;
                        rightSideIndex.pop();
                        loaded = true;
                    }else break;
                }
            }
            if(loaded){
                time += t;
                atLeft = !atLeft;
            }
            else{
                if(atLeft){
                    if(!leftSide.empty() && leftSide.front() <= rightSide.front() || rightSide.empty()) time = leftSide.front();
                    else{
                        time = max(rightSide.front(), time) + t;
                        atLeft = !atLeft;
                    }
                }else{
                    if(!rightSide.empty() && rightSide.front() <= leftSide.front() || leftSide.empty()) time = rightSide.front();
                    else{
                        time = max(leftSide.front(), time) + t;
                        atLeft = !atLeft;
                    }
                }
            }
        }
        for(int j = 0; j < m; j++){
            printf("%d\n", result[j]);
        }
        printf("\n");
    }

    return 0;
}
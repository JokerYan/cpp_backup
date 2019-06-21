#include <stdio.h>
#include <math.h>

int main(){
    int N;
    scanf("%d", &N);
    int* problems = new int[N];
    int* timePenalty = new int[N];
    int* submitTime = new int[N];
    int* extra = new int[N];
    int* ranking = new int[N];
    int* scores = new int[N];
    int rules[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &problems[i], &timePenalty[i], &submitTime[i], &extra[i]);
        ranking[i] = i;
        scores[i] = 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i - 1; j++){
            bool swap = false;
            int index1 = ranking[j];
            int index2 = ranking[j + 1];
            if(problems[index1] < problems[index2]) swap = true;
            else if(problems[index1] == problems[index2]){
                if(timePenalty[index1] > timePenalty[index2]) swap = true;
                else if(timePenalty[index1] == timePenalty[index2]){
                    if(submitTime[index1] > submitTime[index2]) swap = true;
                }
            }
            if(swap){
                int temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }
    int curRanking = 0;
    while(curRanking < 30 && curRanking < N){
        int tieRanking = curRanking + 1;
        while(tieRanking < N){
            if(problems[ranking[tieRanking]] == problems[ranking[curRanking]] &&
                timePenalty[ranking[tieRanking]] == timePenalty[ranking[curRanking]] &&
                submitTime[ranking[tieRanking]] == submitTime[ranking[curRanking]]){
                    tieRanking ++;
                }
            else{
                break;
            }
        }
        float sum = 0;
        for(int i = curRanking; i < tieRanking && i < 30; i++){
            sum += rules[i];
        }
        for(int i = curRanking; i < tieRanking; i++){
            scores[ranking[i]] = ceil(sum / (tieRanking - curRanking));
        }
        curRanking = tieRanking;
    }
    for(int i = 0; i < N; i++){
        scores[i] += extra[i];
        printf("%d\n", scores[i]);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

using namespace std;

class obstacle_info {
    private:
        bool found[100];
    public:
        obstacle_info(){
            memset(found, false, sizeof(found));
        }

        void set(int k){
            this->found[k] = true;
        }

        bool get(int k){
            return found[k];
        }
};

int main(){
    int N, Y;
    scanf("%d %d", &N, &Y);
    obstacle_info obstacle;
    for(int i = 0; i < Y; i++){
        int k; scanf("%d", &k);
        obstacle.set(k);
    }
    int X = 0;
    for(int i = 0; i < N; i++){
        if(!obstacle.get(i)) printf("%d\n", i);
        else X++; 
    }
    printf("Mario got %d of te dangerous obstacles\n", X);
    return 0;
}
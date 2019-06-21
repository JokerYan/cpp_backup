#include <stdio.h>
#include <vector>

int main(){
    int N;
    scanf("%d", &N);

    std::vector<int> cards;
    for(int i = 0; i < N; i++){
        int temp;
        scanf("%d", &temp);
        cards.push_back(temp);
    }
    bool removed = true;
    while(removed){
        int index = 1;
        removed = false;
        while(index < cards.size()){
            if((cards[index] + cards[index - 1]) % 2 == 0){
                cards.erase(cards.begin() + index);
                cards.erase(cards.begin() + index - 1);
                removed = true;
            }else index++;
        }
    }
    
    printf("%d", cards.size());
    return 0;
}
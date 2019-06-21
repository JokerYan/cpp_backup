#include <iostream>
#include <string.h>
using namespace std;

void sort(int* list, int size);
int getSize(int* list, int maxLength);

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int S;
        cin >> S;
        int* blue = new int[S + 1];
        int* red = new int[S + 1];
        memset(blue, -1, sizeof(blue[0]) * (S+1));
        memset(red, -1, sizeof(red[0]) * (S+1));
        string temp;
        int blueIndex = 0, redIndex = 0;
        for(int j = 0; j < S; j++){
            cin >> temp;
            if(temp[temp.size() - 1] == 'B') {
                blue[blueIndex] = stoi(temp.substr(0, temp.size()-1));
                blueIndex++;
            }
            else if(temp[temp.size() - 1] == 'R'){
                red[redIndex] = stoi(temp.substr(0, temp.size()-1));
                redIndex++;
            }
        }
        sort(blue, S+1);
        sort(red, S+1);
        int sizeBlue = getSize(blue, S);
        int sizeRed = getSize(red, S);
        // for(int j = 0; j < S+1; j++){
        //     cout << red[j] << " ";
        // }
        int maxCount = min(sizeBlue, sizeRed);
        cout << "Case #" << i+1 << ": ";
        if(maxCount == 0){
            cout << 0 << endl;
            continue;
        } else{
            int length = 0;
            for(int j = 0; j < maxCount; j++){
                length += red[j];
                length += blue[j];
                length -= 2;
            }
            // if(red[maxCount + 1] != -1) length += red[maxCount + 1] - 1;
            // if(blue[maxCount + 1] != -1) length += blue[maxCount + 1] -1;
            cout << length <<endl;
        }
    }
    return 0;
}

void sort(int* list, int size){
    bool flag;
    for(int i = 0; i < size; i++){
        flag = false;
        for(int j = 0; j < size - i - 1; j++){
            if(list[j] < list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                flag = true;
            }
        }
        if(!flag) break;
    }
    return;
}

int getSize(int* list, int maxSize){
    int size = 0;
    for(int i = 0; i < maxSize; i++){
        if(list[i] == -1) break;
        size ++;
    }
    return size;
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string line;
    // ifstream cin("chartingProgress.txt");
    int length, count, total = 0;
    while(getline(cin, line)){
        if(line == ""){
            cout << endl;
            total = 0;
            continue;
        }
        length = line.length();
        count = 0;
        for(int i = 0; i < length; i++){
            if(line[i] == '*') count++;
        }
        for(int i = 0; i < length; i++){
            if(i < length - total - count) cout << ".";
            if(i >= length - total - count && i < length - total) cout << "*";
            if(i >= length - total) cout << ".";
        }
        cout << endl;
        total += count;
        if(cin.eof()) break;
    }
    return 0;
}
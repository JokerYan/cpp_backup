#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

bool beginWith(string beginning, string word){
    if(word.size() < beginning.size()) return false;
    for(int i = 0; i < beginning.size(); i++){
        if(beginning[i] != word[i]) return false;
    }
    return true;
}

bool exceedUpper(string beginning, string word){
    for(int i = 0; i < beginning.size() && i < word.size(); i++){
        if(beginning[i] < word[i]) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    while(cin >> N, !cin.eof()){
        map<string, int> words;
        for(int i = 0; i < N; i++){
            string thisWord;
            cin >> thisWord;
            if(words.size() == 0){
                words[thisWord] = 1;
                cout << 0 << endl;
                continue;
            }
            auto lower = words.lower_bound(thisWord);
            int count = 0;
            // if(lower != words.end()) cout << "lower: " << *lower << endl;
            bool found = false;
            while(lower != words.end()){
                if(exceedUpper(thisWord, (*lower).first)) break;
                if(beginWith(thisWord, (*lower).first)){
                    count += (*lower).second;
                    if((*lower).first.compare(thisWord) == 0) {
                        found = true;
                        (*lower).second += 1;
                    }
                }
                ++lower;
            }
            cout << count << endl;
            if(!found) words[thisWord] = 1;
        }
    }
    return 0;
}
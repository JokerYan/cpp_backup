#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct category{
    string name;
    int frequency;
    unordered_set<string> keywords;
};

bool comp(category a, category b){
    if(a.frequency > b.frequency) return true;
    if(a.frequency == b.frequency){
        if(a.name.compare(b.name) < 0){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    vector<category> allCategories;
    for(int i = 0; i < N; i++){
        string name; cin >> name;
        int k; cin >> k;
        category thisCat;
        thisCat.name = name;
        thisCat.frequency = 0;
        for(int j = 0; j < k; j++){
            string keyword; cin >> keyword;
            thisCat.keywords.insert(keyword);
        }
        allCategories.push_back(thisCat);
    }

    string word;
    while(cin >> word, !cin.eof()){
        for(auto &cat : allCategories){
            if(cat.keywords.find(word) != cat.keywords.end()) cat.frequency++;
        }
    }

    sort(allCategories.begin(), allCategories.end(), comp);
    int max = (*allCategories.begin()).frequency;
    for(auto& cat: allCategories){
        if(cat.frequency == max)
            cout << cat.name << endl;
        else break;
    }

    return 0;
}
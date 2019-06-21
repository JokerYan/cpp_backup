#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    map<string, int> forest;

    string thisTree;
    float total;
    while(getline(cin, thisTree), !cin.eof()){
        auto tree = forest.find(thisTree);
        if(tree == forest.end()){
            forest[thisTree] = 1;
        }
        else{
            tree->second++;
        }
        total += 1;
    }

    cout << fixed;
    for(auto &tree : forest){
        cout << tree.first << " " << setprecision(5) << tree.second * 100 / total << endl;
    }

    return 0;
}
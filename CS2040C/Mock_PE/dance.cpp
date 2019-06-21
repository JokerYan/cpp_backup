#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector<string> allLines;

    for(int i = 0; i < N; i++){
        string line;
        getline(cin, line);
        allLines.push_back(line);
    }

    int count = 1;
    for(int i = 0; i < M; i++){
        bool blank = true;
        for(int j = 0; j < N; j++){
            if(allLines[j][i] == '$'){
                blank = false;
                break;
            }
        }
        if(blank) count++;
    }
    cout << count << endl;

    return 0;
}
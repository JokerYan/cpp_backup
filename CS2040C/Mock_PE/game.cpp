#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> allCommands;

    for(int i = 0; i < k; i++){
        string command;
        cin >> command;
        if(command.compare("undo") != 0){
            allCommands.push_back(stoi(command));
        }else{
            int move;
            cin >> move;
            for(int j = 0; j < move; j++){
                allCommands.pop_back();
            }
        }
    }

    int totalMove = 0;
    for(int i = 0; i < allCommands.size(); i++){
        totalMove += allCommands[i];
    }

    totalMove = totalMove % n;
    if(totalMove < 0) totalMove += n;

    cout << totalMove << endl;

    return 0;
}
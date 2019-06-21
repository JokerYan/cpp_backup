#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    map<int, priority_queue<int>> quests;
    for(int com = 0; com < N; com++){
        string command;
        cin >> command;

        if(command.compare("add") == 0){
            int E, G; cin >> E >> G;
            auto found = quests.find(E);
            if(found == quests.end()){
                priority_queue<int> tempQueue;
                tempQueue.push(G);
                quests[E] = tempQueue;
            }else{
                (*found).second.push(G);
            }
        }else{
            int E; cin >> E;
            long long G = 0;
            while(true){
                if(quests.empty()) break;
                auto found = quests.upper_bound(E);
                if(found == quests.begin()) break;
                --found;
                E -= (*found).first;
                G += (*found).second.top();
                (*found).second.pop();
                if((*found).second.empty()){
                    quests.erase(found);
                }
            }
            cout << G << endl;
        }
    }

    return 0;
}
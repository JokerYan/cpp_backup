#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int testCase; cin >> testCase;
    while(testCase--){
        int n, t; cin >> n >> t;
        int buttons[n];
        for(int i = 0; i < n; i++){
            int button; cin >> button;
            buttons[i] = button;
        }

        if(t == 0){
            cout << 0 << " " << 0 << endl;
            continue;
        }

        queue<pair<int, int>> path; //step, total time
        set<int> visited;

        path.push(make_pair(0, 0));
        visited.insert(0);

        int minStep = -1; int minDistance = -1;

        while(!path.empty()){
            auto node = path.front();
            path.pop();

            int step = node.first;
            int total = node.second;

            for(int j = 0; j < n; j++){
                int new_step = step + 1;
                int new_total = total + buttons[j];
                if(new_total < 0) new_total = 0;
                if(new_total > 3600) new_total = 3600;

                if(visited.find(new_total) == visited.end()){
                    visited.insert(new_total);
                    path.push(make_pair(new_step, new_total));
                    if(new_total >= t){
                        if(new_total - t < minDistance || minDistance == -1){
                            minDistance = new_total - t;
                            minStep = new_step;
                        }
                    }
                }
                // cout << "-> step: " << new_step << " total: " << new_total << " last_step: " << step << " last_total: " << total << endl;
            }
        }

        cout << minStep << " " << minDistance << endl;

    }

    return 0;
}
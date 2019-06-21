#include <iostream>
#include <vector>
#include <tuple>

#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q, s;
    while(cin >> n >> m >> q >> s, (n || m || q || s)){
        vector<tuple<int, int, int>> edge_list; //u, v, weight
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge_list.push_back(make_tuple(u, v, w));
        }
        int costs[n];
        for(int i = 0; i < n; i++){
            costs[i] = INF;
        }
        costs[s] = 0;
        for(int i = 0; i < n - 1; i++){
            bool flag = true;
            for(int j = 0; j < edge_list.size(); j++){
                if(costs[get<0>(edge_list[j])] + get<2>(edge_list[j]) < costs[get<1>(edge_list[j])]){
                    costs[get<1>(edge_list[j])] = costs[get<0>(edge_list[j])] + get<2>(edge_list[j]);
                    flag = false;
                    // cout << "updated: " << get<0>(edge_list[j]) << endl;
                }
            }
            if(flag) break;
        }

        for(int i = 0 ; i < n; i++){
            cout << "vertex " << i << " " << costs[i] << endl;
        }

        bool negative[n];
        //query
        for(int i = 0; i < edge_list.size(); i++){
            if(costs[get<0>(edge_list[i])] + get<2>(edge_list[i]) < costs[get<1>(edge_list[i])]){
                negative[get<1>(edge_list[i])] = true;
                cout << "negative loop detected with  u: " << get<0>(edge_list[i]) << " -> v: " << get<1>(edge_list[i]) << endl;
            }else{
                negative[get<1>(edge_list[i])] = false;
            }
        }

        // cout << "neg inf assignment finished" << endl;

        for(int i = 0; i < q; i++){
            int v; cin >> v;
            if(costs[v] >= INF){
                cout << "Impossible" << endl;
            }else if(negative[v]){
                cout << "-Infinity" << endl;
            }
            else{
                cout << costs[v] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
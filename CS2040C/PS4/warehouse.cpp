#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Ware{
    string name;
    int count;
};

bool comp(Ware ware1, Ware ware2){
    if(ware1.count > ware2.count) return true;
    if(ware1.count < ware2.count) return false;
    int i = 0;
    while(i < ware1.name.length() && i < ware2.name.length()){
        if(ware1.name.at(i) < ware2.name.at(i)) return true;
        if(ware1.name.at(i) > ware2.name.at(i)) return false;
        i++;
    }
    return ware1.name.length() < ware2.name.length();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int cases;
    cin >> cases;

    for(int testCase = 0; testCase < cases; testCase++){
        int N;
        cin >> N;

        unordered_map<string, int> warehouse;

        for(int i = 0; i < N; i++){
            string wareName;
            int wareCount;
            cin >> wareName;
            cin >> wareCount;

            if(warehouse.find(wareName) != warehouse.end()){
                warehouse[wareName] += wareCount;
            }else{
                warehouse[wareName] = wareCount;
            }
        }

        vector<Ware> warehouse_sorted;
        for(auto &x : warehouse){
            warehouse_sorted.push_back(Ware{x.first, x.second});
        }
        sort(warehouse_sorted.begin(), warehouse_sorted.end(), comp);

        cout << warehouse_sorted.size() << endl;
        for(int i = 0; i < warehouse_sorted.size(); i ++){
            cout << warehouse_sorted[i].name << " " << warehouse_sorted[i].count << endl;
        }



    }

    return 0;
}
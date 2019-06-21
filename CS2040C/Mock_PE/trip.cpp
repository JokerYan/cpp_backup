#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    unordered_map<string, vector<int>> travelHistory;
    for(int i = 0; i < n; i++){
        string country; int year;
        cin >> country >> year;
        // cout << country << ":" << year << endl;
        travelHistory[country].push_back(year);
    }

    for(auto &country : travelHistory){
        sort(country.second.begin(), country.second.end());
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        string country; int k;
        cin >> country >> k;

        cout << travelHistory[country][k - 1] << endl;
        // auto visit = travelHistory[country].begin();
        // advance(visit, k - 1);
        // cout << *visit << endl;
    }

    return 0;
}
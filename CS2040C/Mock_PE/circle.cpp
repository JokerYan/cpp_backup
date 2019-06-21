#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    vector<pair<long long, long long>> points;
    set<string> pointString;
    vector<pair<int, int>> offsets;
    
    for(int i = 0; i <= 2018; i++){
        for(int j = 0; j <= 2018; j++){
            if(i * i + j * j == 2018 * 2018) {
                offsets.push_back(make_pair(i, j));
                // cout << i << j << endl;  
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < N; i++){
        long long x, y; cin >> x >> y;
        points.push_back(make_pair(x, y));
        pointString.insert(to_string(x) + " " + to_string(y));
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < offsets.size(); j++){
            string p1 = to_string(points[i].first + offsets[j].first) + " " + to_string(points[i].second + offsets[j].second);
            string p2 = to_string(points[i].first + offsets[j].first) + " " + to_string(points[i].second - offsets[j].second);
            string p3 = to_string(points[i].first - offsets[j].first) + " " + to_string(points[i].second + offsets[j].second);
            string p4 = to_string(points[i].first - offsets[j].first) + " " + to_string(points[i].second - offsets[j].second);
            if(pointString.find(p1) != pointString.end()) {
                // cout << "->" << p1 << ";" << offsets[j].first << "," << offsets[j].second << endl;
                count++;
            }
            if(pointString.find(p2) != pointString.end() && offsets[j].second != 0) {
                // cout << "->" << p2 << ";" << offsets[j].first << "," << -1 * offsets[j].second << endl;
                count++;
            }
            if(pointString.find(p3) != pointString.end() && offsets[j].first != 0) {
                // cout << "->" << p3 << ";" << -1 * offsets[j].first << "," << offsets[j].second << endl;
                count++;
            }
            if(pointString.find(p4) != pointString.end() && offsets[j].first != 0 && offsets[j].second != 0) {
                // cout << "->" << p4 << ";" << -1 * offsets[j].first << "," << -1 * offsets[j].second << endl;
                count++;
            }
        }
    }
    cout << count / 2 << endl;

    return 0;
}
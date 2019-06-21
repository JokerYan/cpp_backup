#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> my_map;
    my_map[1] = 1;
    my_map[2] = 2;
    my_map[3] = 3;

    for(auto &x : my_map){
        cout << x.first << ": " << x.second << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;
    stringstream ss(s);
    string token;

    while(getline(ss, token, '-')){
        cout << token[0];
    }
    return 0;
}
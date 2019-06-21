#include <iostream>
using namespace std;

int main(){
    int left, right;
    cin >> left;
    cin >> right;
    if (left == right){
        if (left == 0){
            cout << "Not a moose";
        }else{
            cout << "Even " << left * 2;
        }
    }else{
        cout << "Odd " << max(left, right) * 2;
    }
    return 0;
}

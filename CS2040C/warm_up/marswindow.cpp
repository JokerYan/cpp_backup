#include <iostream>
using namespace std;

int main(){
    int year, month;
    cin >> year;

    month = (year - 2018 + 1) * 12 - 4;
    if (month % 26 < 12) cout << "yes";
    else cout << "no";

    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // ifstream cin("statcintics.in");
    for (int i = 0; i < 50; i++){
        int count;
        cin >> count;
        if (cin.eof()){
            break;
        }
        int min, max, temp;
        cin >> temp;
        min = temp; max = temp;
        for (int j = 0; j < count - 1; j++){
            cin >> temp;
            if (temp > max) max = temp;
            if (temp < min) min = temp;
        }
        cout << "Case " << i + 1 << ": " << min << " " << max << " " << max - min << endl;
    }
    return 0;
}
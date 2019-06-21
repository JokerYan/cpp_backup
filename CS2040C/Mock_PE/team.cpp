#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    for(int t = 0; t < testCase; t++){
        int N;
        cin >> N;
        vector<int> students;
        for(int i = 0; i < 3 * N; i++){
            int score;
            cin >> score;
            students.push_back(score);
        }
        sort(students.begin(), students.end());
        int total = 0;
        auto thisStudent = students.begin();
        for(int i = 0; i < 3 * N; i++){
            if(((i - N) % 2 == 0) && i >= N) total += *thisStudent;
            ++thisStudent; 
        }
        cout << total << endl;
    }

    return 0;
}
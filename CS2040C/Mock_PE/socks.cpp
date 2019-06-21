#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    stack<int> mainStack;
    stack<int> auxStack;

    for(int i = 0; i < 2 * N; i++){
        int sock; cin >> sock;
        mainStack.push(sock);
    }

    bool paired = false;
    int count = 0;
    while(true){
        if(auxStack.empty() || auxStack.top() != mainStack.top()){
            // cout << "move" << endl;
            int sock = mainStack.top();
            auxStack.push(sock);
            mainStack.pop();
            count++;
        }else if(auxStack.top() == mainStack.top()){
            // cout << "pair" << endl;
            mainStack.pop();
            auxStack.pop();
            count++;
        }
        if(auxStack.empty() && mainStack.empty()){
            // cout << "finished" << endl;
            paired = true;
            break;
        }
        if(mainStack.empty() && !auxStack.empty()){
            break;
        }
    }
    if(paired) cout << count << endl;
    else cout << "impossible" << endl;

    return 0;
}
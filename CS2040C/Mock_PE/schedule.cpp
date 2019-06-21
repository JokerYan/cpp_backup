#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Event{
    string expression;
    int time;
};

bool comp(Event a, Event b){
    return a.time < b.time;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);

    int N;
    while(cin >> N, N != 0){
        vector<Event> allEvents;
        for(int i = 0; i < N; i++){
            string time1, time2;
            cin >> time1 >> time2;

            int found = time1.find(":");
            string hour = time1.substr(0, found);
            string minute = time1.substr(found + 1, 2);
            if(hour.compare("12") == 0) hour = "0";
            int time = stoi(hour) * 60 + stoi(minute);
            if(time2.compare("p.m.") == 0) time += 60 * 12;

            Event thisEvent = {time1 + " " + time2, time};
            allEvents.push_back(thisEvent);
        }
        sort(allEvents.begin(), allEvents.end(), comp);
        for(int i = 0; i < N; i++){
            cout << allEvents[i].expression << endl;
        }
        cout << endl;
    }

    return 0;
}
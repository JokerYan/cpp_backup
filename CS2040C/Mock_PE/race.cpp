#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Runner{
    string firstName, lastName, bib, s1String, s2String, finishString;
    int s1Time, s2Time, finishTime, rank1, rank2, rank3;
};

bool compTime(Runner a, Runner b){
    return a.finishTime < b.finishTime;
}

bool compS1Time(Runner a, Runner b){
    return a.s1Time < b.s1Time;
}

bool compS2Time(Runner a, Runner b){
    return a.s2Time < b.s2Time;
}

bool compName(Runner a, Runner b){
    if(a.lastName.compare(b.lastName) < 0){
        return true;
    }if(a.lastName.compare(b.lastName) == 0){
        return a.firstName.compare(b.firstName) < 0;
    } return false;
}

void printString(string input, int length, bool toLeft){
    if(!toLeft){
        cout << string((length - input.size()) , ' ');
    }
    cout << input;
    if(toLeft){
        cout << string((length - input.size()) , ' ');
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int testCase = 0; testCase < 10; testCase++){
        vector<Runner> allRunners;
        int N; cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++){
            Runner thisRunner;
            string firstName, lastName, bib;
            cin >> firstName >> lastName >> bib;
            thisRunner.firstName = firstName;
            thisRunner.lastName = lastName;
            thisRunner.bib = bib;
            allRunners.push_back(thisRunner);
        }
        for(int i = 0; i < 3 * N; i++){
            string bib, section, time;
            cin >> bib >> section >> time;
            int realTime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
            for(int j = 0; j < N; j++){
                if(allRunners[j].bib.compare(bib) == 0){
                    if(section.compare("S1") == 0){
                        allRunners[j].s1Time = realTime;
                        allRunners[j].s1String = time;
                        break;
                    }
                    if(section.compare("S2") == 0){
                        allRunners[j].s2Time = realTime;
                        allRunners[j].s2String = time;
                        // cout << allRunners[j].s2Time << "<---" << realTime << endl;
                        break;
                    }
                    if(section.compare("F") == 0){
                        allRunners[j].finishTime = realTime;
                        allRunners[j].finishString = time;
                        break;
                    }
                }
            }
        }

        sort(allRunners.begin(), allRunners.end(), compTime);
        int lastTime = 0; int lastRank = 1;
        for(int i = 0; i < N; i++){
            if(lastTime == allRunners[i].finishTime){
                allRunners[i].rank3 = lastRank;
            }else{
                lastRank = i + 1;
                lastTime = allRunners[i].finishTime;
                allRunners[i].rank3 = lastRank;
            }
        }
        
        sort(allRunners.begin(), allRunners.end(), compS1Time);
        lastTime = 0; lastRank = 1;
        for(int i = 0; i < N; i++){
            if(lastTime == allRunners[i].s1Time){
                allRunners[i].rank1 = lastRank;
            }else{
                lastRank = i + 1;
                lastTime = allRunners[i].s1Time;
                allRunners[i].rank1 = lastRank;
            }
        }
        
        sort(allRunners.begin(), allRunners.end(), compS2Time);
        lastTime = 0; lastRank = 1;
        for(int i = 0; i < N; i++){
            if(lastTime == allRunners[i].s2Time){
                allRunners[i].rank2 = lastRank;
            }else{
                lastRank = i + 1;
                lastTime = allRunners[i].s2Time;
                allRunners[i].rank2 = lastRank;
            }
        }


        sort(allRunners.begin(), allRunners.end(), compName);
        cout << "NAME                       BIB    SPLIT1      RANK    SPLIT2      RANK    FINISH      RANK" << endl;
        for(int i = 0; i < N; i++){
            Runner thisRunner = allRunners[i];
            string nameString = thisRunner.lastName + ", " + thisRunner.firstName;
            string bibString = thisRunner.bib;
            string s1String = allRunners[i].s1String;
            string s2String = allRunners[i].s2String;
            string finishString = allRunners[i].finishString;
            string rank1String = to_string(thisRunner.rank1);
            string rank2String = to_string(thisRunner.rank2);
            string rank3String = to_string(thisRunner.rank3);
            printString(nameString, 20, true);
            printString(bibString, 10, false);
            printString(s1String, 10, false);
            printString(rank1String, 10, false);
            printString(s2String, 10, false);
            printString(rank2String, 10, false);
            printString(finishString, 10, false);
            printString(rank3String, 10, false);
            cout << endl;
        }
        
        cout << endl;

    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Person{
    public:
        string name;
        string classLevel;
        Person(string line){
            int found = line.find(":");
            name = line.substr(0, found);
            string classSubstr = line.substr(found + 2, line.find(" ", found + 2) - found - 2);
            while(classSubstr.size() > 0){
                found = classSubstr.find("-");
                string subClass;
                if(found != -1){
                    subClass = classSubstr.substr(0, found);
                    classSubstr = classSubstr.substr(found + 1);
                }else{
                    subClass = classSubstr;
                    classSubstr = "";
                }
                if(subClass.compare("upper") == 0) classLevel = "3" + classLevel;
                if(subClass.compare("middle") == 0) classLevel = "2" + classLevel;
                if(subClass.compare("lower") == 0) classLevel = "1" + classLevel;
            }
            // cout << classLevel << endl;
        }
};


bool compPerson (Person a, Person b){
    string aLevelStr = a.classLevel;
    string bLevelStr = b.classLevel;
    long long aLevel, bLevel;
    while(aLevelStr.size() < bLevelStr.size()){
        aLevelStr += "2";
    }
    while(bLevelStr.size() < aLevelStr.size()){
        bLevelStr += "2";
    }
    aLevel = stoll(aLevelStr);
    bLevel = stoll(bLevelStr);
    // cout << a.name << ": " << aLevel << " - " << b.name << ": " << bLevel << endl;
    if(aLevel > bLevel) return true;
    if(aLevel < bLevel) return false;
    return a.name.compare(b.name) < 0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);

    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase; tc++){
        int N; cin >> N;
        // char dummy; cin >> dummy;
        cin.ignore();
        vector<Person> community;
        for(int i = 0; i < N; i++){
            string line;
            getline(cin, line);
            Person newPerson = Person(line);
            community.push_back(newPerson);
        }
        sort(community.begin(), community.end(), compPerson);
        for(int i = 0; i < N; i++){
            cout << community[i].name << endl;
        }
        cout << "==============================" << endl;
    }
}

//1. cin.ignore() is needed before the getline if anything is read before that
//2. substr the second parameter is length not the ending index
//3. use int found as helper index when slicing the string
//4. stoi is used to convert string to int; stoll is for long long

#include <sstream>

getline(cin, line);
stringstream ss(line);
ss >> word;
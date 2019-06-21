#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Line{
    int label;
    string command;
};

int variables[26] = {0};
vector<Line> lines;
int current_command = 0;

int getLabel(string line){
    return stoi(line);
}

int getVariable(char n){
    return variables[n - 'A'];
}

void setVariable(char n, int v){
    variables[n - 'A'] = v;
}

bool isArithmatics(string expression){
    return expression.find("+") != string::npos || expression.find("*") != string::npos || expression.find("/") != string::npos
        || (expression.find("-") != string::npos && (char)expression[expression.find("-") + 1] == ' ');
}

int getNumber(string expression){
    if((char)expression[0] >= 'A' && (char)expression[0] <= 'Z'){
        // cout << expression << " is variable" << endl;
        return getVariable((char)expression[0]);
    }else{
        // cout << stoi(expression) << " is number" << endl;
        return stoi(expression);
    }
}

int arithmatics(string expression){
    if(!isArithmatics(expression)){
        return getNumber(expression);
    }
    if(expression.find("+") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("+") - 1));
        int right = getNumber(expression.substr(expression.find("+") + 2));
        return left + right;
    }
    else if(expression.find("-") != string::npos && (char)expression[expression.find("-") + 1] == ' '){
        int left = getNumber(expression.substr(0, expression.find("-") - 1));
        int right = getNumber(expression.substr(expression.find("-") + 2));
        return left - right;
    }
    else if(expression.find("*") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("*") - 1));
        int right = getNumber(expression.substr(expression.find("*") + 2));
        return left * right;
    }
    else if(expression.find("/") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("/") - 1));
        int right = getNumber(expression.substr(expression.find("/") + 2));
        return left / right;
    }
}

bool isTrue(string expression){
    if(expression.find("<>") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("<") - 1));
        int right = getNumber(expression.substr(expression.find(">") + 2));
        return left != right;
    }
    else if(expression.find(">=") != string::npos){
        int left = getNumber(expression.substr(0, expression.find(">") - 1));
        int right = getNumber(expression.substr(expression.find("=") + 2));
        return left >= right;
    }
    else if(expression.find("<=") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("<") - 1));
        int right = getNumber(expression.substr(expression.find("=") + 2));
        return left <= right;
    }
    else if(expression.find("=") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("=") - 1));
        int right = getNumber(expression.substr(expression.find("=") + 2));
        return left == right;
    }
    else if(expression.find(">") != string::npos){
        int left = getNumber(expression.substr(0, expression.find(">") - 1));
        int right = getNumber(expression.substr(expression.find(">") + 2));
        return left > right;
    }
    else if(expression.find("<") != string::npos){
        int left = getNumber(expression.substr(0, expression.find("<") - 1));
        int right = getNumber(expression.substr(expression.find("<") + 2));
        return left < right;
    }
}

void letCommand(string command){
    char left = command[0];
    int ariStart = command.find("=") + 2;
    int ariResult = arithmatics(command.substr(ariStart));
    // cout << "ari string: " << command.substr(ariStart) << endl;
    setVariable(left, ariResult);
    // cout << "set variable: " << left << " to " << getVariable(left) << endl;
}

void printCommand(string command){
    if(command.find("\"") != string::npos){
        cout << command.substr(1, command.length() - 2);
    }else{
        cout << getVariable(command[0]);
    }
}

void printlnCommand(string command){
    printCommand(command);
    cout << endl;
}

void gotoCommand(string command){
    int label = stoi(command);
    for(int i = 0; i < lines.size(); i++){
        if(lines[i].label == label) {
            current_command = i - 1;
            // cout << "goto command: " << lines[i].command << " with label " << label << endl;
            break;
        }
    }
}

void ifCommand(string command){
    if(isTrue(command.substr(0, command.find("THEN GOTO ") - 1))){
        gotoCommand(command.substr(command.find("THEN GOTO ") + 10));
    }
}

void processCommand(string command){
    string keyword = command.substr(0, command.find(" "));

    if(keyword == "LET"){
        // cout << "let command" << endl;
        letCommand(command.substr(command.find(" ") + 1));
    }
    else if(keyword == "IF"){
        // cout << "if command" << endl;
        ifCommand(command.substr(command.find(" ") + 1));
    }
    else if(keyword == "PRINT"){
        // cout << "print command" << endl;
        printCommand(command.substr(command.find(" ") + 1));
    }
    else if(keyword == "PRINTLN"){
        // cout << "println command" << endl;
        printlnCommand(command.substr(command.find(" ") + 1));
    }
}

int main(){
    string tempLine;
    while(getline(cin, tempLine)){
        // if(tempLine == "end") break;
        int tempLabel = getLabel(tempLine);
        string tempCommand = tempLine.substr(tempLine.find(" ") + 1);
        Line curLine {tempLabel, tempCommand};
        // processCommand(tempCommand);
        if(lines.empty()){
            lines.push_back(curLine);
        }else{
            bool arranged = false;
            for(int i = 0; i < lines.size(); i++){
                if(tempLabel < lines[i].label){
                    lines.insert(lines.begin() + i, curLine);
                    arranged = true;
                    break;
                }
            }
            if(!arranged) lines.push_back(curLine);
        }
    }
    // for(int i = 0; i < lines.size(); i++) cout << lines[i].command << endl;
    while(current_command < lines.size()){
        // cout << "command (" << lines[current_command].command << ") executed ->";
        processCommand(lines[current_command].command);
        current_command++;
    }
    return 0;
}
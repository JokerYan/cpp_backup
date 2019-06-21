#include <iostream>
#include <string>
using namespace std;

bool debug = false;

bool reach(int* instructions, int X, int Y, int N);
int main(){
	int X, Y;
	cin >> X; cin >> Y;
	int N;
	cin >> N;
	
	int* instructions = new int[N]; //0 forward, -1 left, 1 right
	string tempInput;
	for(int i = 0; i < N; i ++){
		cin >> tempInput;
		if(tempInput == "Forward"){
			instructions[i] = 0;
		}else if(tempInput == "Left"){
			instructions[i] = -1;
		}else if(tempInput == "Right"){
 			instructions[i] = 1;
		}
	}
	if(debug) cout << reach(instructions, X, Y, N) << endl;
	
	int* correctedInstructions = new int[N];
	string commands[] = {"Left", "Forward", "Right"};
	bool flag = false;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			correctedInstructions[j] = instructions[j];
		}
		for(int j = -1; j <= 1; j++){
			correctedInstructions[i] = j;
			if(reach(correctedInstructions, X, Y, N)){
				flag = true;
				cout << i + 1 << " " << commands[j+1] << endl;
				break;
			}
		}
		if(flag) break;
	}
	if(!flag)cout << "path not found" << endl;
	
	return 0;
}

bool reach(int* instructions, int X, int Y, int N){
	int curX = 0, curY = 0, direction = 0; //0 to up, 1 to right, 2 to down, 3 to left
	for(int i = 0; i < N; i++){
		switch(instructions[i]){
			case 0:
				if(direction == 0) curY++;
				else if(direction == 1) curX++;
				else if(direction == 2) curY--;
				else if(direction == 3) curX--;
				break;
			case -1:
				direction = ((direction - 1) % 4 + 4) % 4;
				break;
			case 1:
				direction = ((direction + 1) % 4 + 4) % 4;
				break;
		}
	}
	if(debug) cout << curX << " " << curY << endl;
	return (curX == X && curY == Y);
}

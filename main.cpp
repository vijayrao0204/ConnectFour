#include<iostream>
#include"connectFour.h"

using namespace std;

int main(){
	Player p1;
	p1.printBoard();
	int nm = 0;
	int coordinates = 0;
	vector<pair<int,int>> p1Moves;
	vector<pair<int,int>> p2Moves;
	bool result = false;
	while(!result){
		if(nm%2 == 0){
			pair<int,int> temp = p1.move(p1.b1,nm);
			p1.b1[temp.first][temp.second] = "X";
			p1.printBoard();
			int won = p1.checkWin(p1Moves,temp);
			p1Moves.push_back(temp);
			for(int i=0;i<p1Moves.size();i++){
				cout << p1Moves[i].first << "," << p1Moves[i].second <<endl;
			}
			result = p1.gameOver(won);
			cout << "Won: " << won << " result: " << result << endl; 
			if(result == true)
				cout << "Player 1 won the game." << endl;
		}
		else{
			pair<int,int> temp = p1.move(p1.b1,nm);
			p1.b1[temp.first][temp.second] = "O";
			p1.printBoard();
			int won = p1.checkWin(p2Moves,temp);
			p2Moves.push_back(temp);
			for(int i=0;i<p2Moves.size();i++){
				cout << p2Moves[i].first << "," << p2Moves[i].second <<endl;
			}
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 2 won the game." << endl;
		}
		nm++;
		cout << "Result: " << result << endl;
	}
	return 0;
}
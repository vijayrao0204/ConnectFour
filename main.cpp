#include<iostream>
#include"connectFour.h"

using namespace std;

int main(){
	Player p1;
	p1.printBoard();
	int nm = 0;
	int coordinates = 0;
	vector<pair<int,int>> p1Moves = p1.player1Moves;
	vector<pair<int,int>> p2Moves = p1.player2Moves;
	p1Moves.push_back({0,0});
	p2Moves.push_back({0,1});
	p1.b1[0][0] = "X";
	p1.b1[0][1] = "O";
	bool result = false;
	//cout << result << endl;
	int d;
	cout << "Enter depth: ";
	cin >> d;
	cout << endl;
	while(!result){
		cout << "In While." << endl;
		if(nm%2 == 0){
			//pair<int,int> temp = p1.move(p1.b1);
			//pair<int,int> temp = p1.move();
			pair<int,int> temp = p1.getMinMaxAB(d,1,1,p1Moves.back());
			cout << "temp.first: " << temp.first << " ,temp.second: " << temp.second <<endl;
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
			//pair<int,int> temp = p1.move(p1.b1);
			//pair<int,int> temp = p1.move();
			//cout <<  d << endl;
			cout << "p2Moves.back().first: " << p2Moves.back().first << ", p2Moves.back().second: " << p2Moves.back().second << endl;
			pair<int,int> temp = p1.getMinMaxAB(d,1,2,p2Moves.back());
			//cout << "In Else" << endl;
			cout << "temp.first: " << temp.first << ", temp.second: " << temp.second << endl;			
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
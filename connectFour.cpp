#include "connectFour.h"
#include<vector>
using namespace std;

Player::Player(){
	turn = false;
	playerName = 1;
	n1 = n2 = 0;
	evalFunc1 = evalFunc2 = 0;
	tn1 = tn2 = 0;
	
	for(int i=0; i<6; i++){
		for(int j=0;j<7;j++){
			b1[i][j] = " ";
		}
	}
}

void Player::printBoard(){
	cout << " ----------------" << endl;
	cout << "|" << b1[5][0] << "|" << b1[5][1] << "|" << b1[5][2] << "|" << b1[5][3] << "|" << b1[5][4] << "|" << b1[5][5] << "|" << b1[5][6] << "|" << endl;
	cout << "|" << b1[4][0] << "|" << b1[4][1] << "|" << b1[4][2] << "|" << b1[4][3] << "|" << b1[4][4] << "|" << b1[4][5] << "|" << b1[4][6] << "|" << endl;
	cout << "|" << b1[3][0] << "|" << b1[3][1] << "|" << b1[3][2] << "|" << b1[3][3] << "|" << b1[3][4] << "|" << b1[3][5] << "|" << b1[3][6] << "|" << endl;
	cout << "|" << b1[2][0] << "|" << b1[2][1] << "|" << b1[2][2] << "|" << b1[2][3] << "|" << b1[2][4] << "|" << b1[2][5] << "|" << b1[2][6] << "|" << endl;
	cout << "|" << b1[1][0] << "|" << b1[1][1] << "|" << b1[1][2] << "|" << b1[1][3] << "|" << b1[1][4] << "|" << b1[1][5] << "|" << b1[1][6] << "|" << endl;
	cout << "|" << b1[0][0] << "|" << b1[0][1] << "|" << b1[0][2] << "|" << b1[0][3] << "|" << b1[0][4] << "|" << b1[0][5] << "|" << b1[0][6] << "|" << endl;
	cout << " ----------------" << endl;
}

void Player::resetBoard(){
	for(int i=0; i<6; i++){
		for(int j=0;j<7;j++){
			b1[i][j] = "";
		}
	}
}

bool Player::gameOver(int result){
	if(result == 1)
		return true;
	else
		return false;
}

int Player::checkWin(vector<pair<int,int>> player1, pair<int,int> m){
	int cr=0;
	int cd=0;
	int cc=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<player1.size(); j++){
			//cheching row
			if(m.first == player1[i].first){
				cout << "in checking row" << endl;
				if((m.second)+i+1 == player1[j].second){
					cr++;
				} 
				else if((m.second)-i-1 == player1[j].second){
					cr++;
				}
			}
			//cheching column
			if(m.second == player1[i].second){
				cout << "in checking column" << endl;
				if(((m.first)+i+1 == player1[j].first)){
					cc++;
				} 
				else if(((m.first)-i-1 == player1[j].first))
					cc++;
			}
			//check Diagnol
			else{
				cout << "in checking diagnol" << endl;
				if(player1[j].first == ((m.first)+i+1) && player1[j].second == ((m.second)+i+1)){
					cout << "m.first: " << m.first+i+1 << " player1[i].first: " <<player1[j].first <<endl;
					cout << "m.second: " << m.second+i+1 << " player1[i].second: " <<player1[j].second <<endl;
					cd++;
				}
				else if(player1[j].first == ((m.first)-i-1) && player1[j].second == ((m.second)-i-1)){
					cout << "m.first: " << m.first-i-1 << " player1[i].first: " <<player1[j].first <<endl;
					cout << "m.second: " << m.second-i-1 << " player1[i].second: " <<player1[j].second <<endl;
					cd++;
				}
			}
		}
	}
	cout << "cr: " << cr << " cc: " << cc << " cd: " << cd << endl;
	if(cr > 2 || cc > 2 || cd > 2)
		return 1;
	else 
		return 0;
}

//vector<pair<int,int>> Player::getValidMove(string board[6][7]){
vector<pair<int,int>> Player::getValidMove(){
	vector<pair<int,int>> validMoves;
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				//if(board[0][j] == " "){
				if(b1[0][j] == " "){
					validMoves.push_back({0,j});
				}
				//if(board[i][j] == "X" || board[i][j] == "O"){
					//if(board[i+1][j] == " ")
				if(b1[i][j] == "X" || b1[i][j] == "O"){
					if(b1[i+1][j] == " ")
						validMoves.push_back({i+1,j});
				}
			}
		}
	return validMoves;
}

//pair<int,int> Player::move(string board[6][7]){
pair<int,int> Player::move(){
	//vector<pair<int,int>> validMoves = getValidMove(board);
	vector<pair<int,int>> validMoves = getValidMove();
	return validMoves[0];
}

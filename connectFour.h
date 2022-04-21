#include<iostream>
#include<vector>
using namespace std;
class Player {
	public: 
		string b1[6][7];
		bool turn;
		int playerName;
		
		int evalFunc1,evalFunc2;
		int maxDepth;
		int n1,n2,tn1,tn2;
		int ne1,ne2,tne1,tne2;
		
		vector<pair<int,int>> player1Moves;
		vector<pair<int,int>> player2Moves;
	
		Player();
		void printBoard();
		void resetBoard();
		bool gameOver(int);
		int checkWin(vector<pair<int,int>>, pair<int,int>);
		int deepEnough(int);
		pair<int,int> move();
		vector<pair<int,int>> getValidMove();
		int opposite(int);
		pair<int, int> maxValue(int, int, int, int, int, pair<int,int>);
		pair<int, int> minValue(int, int, int, int, int, pair<int,int>);
		
		int compute(int, int, pair<int,int>);
		pair<int,vector<pair<int,int>>> minMaxAB(pair<int,int>, int, int, int, int, int);
		pair<int,int> getMinMaxAB(int, int, int, pair<int,int>);
		pair<int, int> alphaBetaSearch(int, int, int, int, int,pair<int,int>);
		pair<int,int> getAlphaBeta(int, int, int, pair<int,int>);
		
		int e1(int, pair<int,int>);
		//int e2(int);
		//int e3(int);
		
};
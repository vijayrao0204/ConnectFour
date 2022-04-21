#include<iostream>
#include<vector>
using namespace std;
class Player {
	public: 
		string b1[6][7];
		//char b2[6];
		bool turn;
		bool rev;
		int playerName;
		
		int tb1[6][7];
		//int tb2[6];
		
		int evalFunc1,evalFunc2;
		int maxDepth;
		int n1,n2,tn1,tn2;
		int ne1,ne2,tne1,tne2;
		
		vector<pair<int,int>> player1Moves;
		vector<pair<int,int>> player2Moves;
	
		Player();
		void printBoard();
		void resetBoard();
		//int gameOver();
		bool gameOver(int);
		//int checkWin();
		int checkWin(vector<pair<int,int>>, pair<int,int>);
		int deepEnough(int);
		//void move(int,int);
		//pair<int,int> move(string board[6][7]);
		pair<int,int> move();
		//vector<pair<int,int>> getValidMove(string [6][7]);
		vector<pair<int,int>> getValidMove();
		int opposite(int);
		/*bool isValidMove(int,int);
		void aiTMove(int,int,int [],int []);
		
		int getMinMaxAB(int [],int [], int , int,int, Player);
		pair<int,vector<pair<int,int>>>minMaxAB(int[], int[],int,int,int,int,int,int);
		int getAlphaBeta(int[], int[],int, int, int);
		pair<int, int> alphaBetaSearch(int[], int[], int, int, int, int, int);*/
		pair<int, int> maxValue(int, int, int, int, int, pair<int,int>);
		pair<int, int> minValue(int, int, int, int, int, pair<int,int>);
		
		int compute(int, int, pair<int,int>);
		pair<int,vector<pair<int,int>>> minMaxAB(pair<int,int>, int, int, int, int, int);
		pair<int,int> getMinMaxAB(int, int, int, pair<int,int>);
		pair<int, int> alphaBetaSearch(int, int, int, int, int,pair<int,int>);
		pair<int,int> getAlphaBeta(int, int, int, pair<int,int>);
		//int getAlphaBeta(int, int, int);

		int e1(int, pair<int,int>);
		//int e2(int);
		//int e3(int);
		
};
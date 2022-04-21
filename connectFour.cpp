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
	int cdl=0;
	int cdr=0;
	int cc=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<player1.size(); j++){
			//cheching row
			if(m.first == player1[j].first){
				if((m.second)+i+1 == player1[j].second){
					cr++;
				} 
				if((m.second)-i-1 == player1[j].second){
					cr++;
				}
			}
			//cheching column
			if(m.second == player1[j].second){
				if(((m.first)+i+1 == player1[j].first)){
					cc++;
				} 
				if(((m.first)-i-1 == player1[j].first)){
					cc++;
				}
			}
			//check Diagnol
			else{
				if(player1[j].first == ((m.first)+i+1) && player1[j].second == ((m.second)+i+1)){
					cdr++;
				}
				if(player1[j].first == ((m.first)-i-1) && player1[j].second == ((m.second)-i-1)){
					cdr++;
				}
				if(player1[j].first == ((m.first)+i+1) && player1[j].second == ((m.second)-i-1)){
					cdl++;
				}
				if(player1[j].first == ((m.first)-i-1) && player1[j].second == ((m.second)+i+1)){
					cdl++;
				}
			}
		}
	}
	//cout << "cr: " << cr << " cc: " << cc << " cdl: " << cdl << " cdr: " << cdr << endl;
	if(cr > 2 || cc > 2 || cdr > 2 || cdl > 2)
		return 1;
	else 
		return 0;
}

vector<pair<int,int>> Player::getValidMove(){
	vector<pair<int,int>> validMoves;
		for(int i=0;i<5;i++){
			for(int j=0;j<7;j++){
				if(b1[0][j] == " "){
					validMoves.push_back({0,j});
				}
				if(b1[i][j] == "X" || b1[i][j] == "O"){
					if(b1[i+1][j] == " ")
						validMoves.push_back({i+1,j});
				}
			}
		}
	return validMoves;
}

pair<int,int> Player::move(){
	vector<pair<int,int>> validMoves = getValidMove();
	return validMoves[0];
}

int Player::e1(int pname, pair<int,int> possibleMove){
	int score = 0;
	if(pname == 1){
		//chechking row
		for(int i=0; i<3; i++){
			//checking forward
			if(possibleMove.second < 4){
				if(b1[possibleMove.first][possibleMove.second+i+1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.second == 4 && i!=2){
				if(b1[possibleMove.first][possibleMove.second+i+1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.second == 5 && i<1){
				if(b1[possibleMove.first][possibleMove.second+i+1] == "X"){
					score += 25;
				}
			}
			//checking backward
			if(possibleMove.second > 2){
				if(b1[possibleMove.first][possibleMove.second-i-1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.second == 2 && i!=2){
				if(b1[possibleMove.first][possibleMove.second-i-1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.second == 1 && i<1){
				if(b1[possibleMove.first][possibleMove.second-i-1] == "X"){
					score += 25;
				}
			}
		}
		
		//checking column
		for(int i=0; i<3; i++){
			//checking forward
			if(possibleMove.first < 3){
				if(b1[possibleMove.first+i+1][possibleMove.second] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first == 3 && i!=2){
				if(b1[possibleMove.first+i+1][possibleMove.second] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first == 4 && i<1){
				if(b1[possibleMove.first+i+1][possibleMove.second] == "X"){
					score += 25;
				}
			}
			//checking backward
			if(possibleMove.first > 2){
				if(b1[possibleMove.first-i-1][possibleMove.second] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first == 2 && i!=2){
				if(b1[possibleMove.first-i-1][possibleMove.second] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first == 1 && i<1){
				if(b1[possibleMove.first-i-1][possibleMove.second] == "X"){
					score += 25;
				}
			}
		}
		
		//checking diagnol 
		for(int i=0; i<3; i++){
			//checking forward
			if(possibleMove.first > 2 && possibleMove.second < 4){
				if(b1[possibleMove.first-i-1][possibleMove.second+i+1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first < 3  && possibleMove.second < 4){
				if(b1[possibleMove.first+i+1][possibleMove.second+i+1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first > 2 && possibleMove.second > 3){
				if(b1[possibleMove.first-i-1][possibleMove.second-i-1] == "X"){
					score += 25;
				}
			}
			else if(possibleMove.first < 3 && possibleMove.second > 3){
				if(b1[possibleMove.first+i+1][possibleMove.second-i-1] == "X"){
					score += 25;
				}
			}
		}
	}
	else if(pname == 2){
		//chechking row
		//cout << "Evaluation for Player 2" << endl;
		for(int i=0; i<3; i++){
			//checking forward
			if(possibleMove.second < 4){
				if(b1[possibleMove.first][possibleMove.second+i+1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.second == 4 && i!=2){
				if(b1[possibleMove.first][possibleMove.second+i+1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.second == 5 && i<1){
				if(b1[possibleMove.first][possibleMove.second+i+1] == "O"){
					score += 25;
				}
			}
			//checking backward
			if(possibleMove.second > 2){
				if(b1[possibleMove.first][possibleMove.second-i-1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.second == 2 && i!=2){
				if(b1[possibleMove.first][possibleMove.second-i-1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.second == 1 && i<1){
				if(b1[possibleMove.first][possibleMove.second-i-1] == "O"){
					score += 25;
				}
			}
		}
		
		//checking column
		for(int i=0; i<3; i++){
			//checking forward
			if(possibleMove.first < 3){
				if(b1[possibleMove.first+i+1][possibleMove.second] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first == 3 && i!=2){
				if(b1[possibleMove.first+i+1][possibleMove.second] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first == 4 && i<1){
				if(b1[possibleMove.first+i+1][possibleMove.second] == "O"){
					score += 25;
				}
			}
			//checking backward
			if(possibleMove.first > 2){
				if(b1[possibleMove.first-i-1][possibleMove.second] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first == 2 && i!=2){
				if(b1[possibleMove.first-i-1][possibleMove.second] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first == 1 && i<1){
				if(b1[possibleMove.first-i-1][possibleMove.second] == "O"){
					score += 25;
				}
			}
		}
		
		//checking diagnol
		for(int i=0; i<3; i++){
			//checking forward
			if(possibleMove.first > 2 && possibleMove.second < 4){
				if(b1[possibleMove.first-i-1][possibleMove.second+i+1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first < 3  && possibleMove.second < 4){
				if(b1[possibleMove.first+i+1][possibleMove.second+i+1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first > 2 && possibleMove.second > 3){
				if(b1[possibleMove.first-i-1][possibleMove.second-i-1] == "O"){
					score += 25;
				}
			}
			else if(possibleMove.first < 3 && possibleMove.second > 3){
				if(b1[possibleMove.first+i+1][possibleMove.second-i-1] == "O"){
					score += 25;
				}
			}
		}
	}
	return score;
}

int Player::deepEnough(int d)
{
    if(d==maxDepth)
        return 0;
    else
		return 1;	
}

int Player::compute(int player, int eval, pair<int,int> pos){
	if(eval==1)
    {
        return e1(player,pos);
    }
    /*else if(eval==2)
    {
        return e2(player);
    }
    else
    {
        return e3(player);
    }*/
	return e1(player,pos); //remove later
}

int Player::opposite(int player){
	if(player == 0)
		return 1;
	else
		return 2;
}
//Algorithms
pair<int,vector<pair<int,int>>> Player::minMaxAB(pair<int,int> position, int depth, int player, int useThresh, int passThresh, int eFunc){
	vector<pair<int,int>> successors;
	
	if(player == 1){
		n1++;
		successors = getValidMove();
	}
	else{
		n2++;
		successors = getValidMove();
	}
	
	if(deepEnough(depth) || successors.size() == 0){
		vector<pair<int,int>> path = successors;
		if(player == 1)
			return make_pair(-compute(player,eFunc,position),path);
		else
			return make_pair(compute(player,eFunc,position),path);
	}
	
	vector<pair<int,int>> bPath;
	int newValue;
	for (int i=0; i<successors.size(); i++){
		pair<int,vector<pair<int,int>>> result = minMaxAB(successors[i],depth+1,opposite(player), -useThresh, -passThresh, eFunc);
		newValue = -result.first;
		if(newValue > passThresh){
			passThresh = newValue;
			bPath.push_back(successors[i]);
		}
		if(passThresh>=useThresh){
			return(make_pair(passThresh,bPath));
		}
		
	}
	return make_pair(passThresh,bPath);
}


pair<int,int> Player::getMinMaxAB(int depth, int evalFunc, int player, pair<int,int> position){
	maxDepth = depth;
	if(player == 1){
		n1=0;
		ne1=0;
		pair<int,vector<pair<int,int>>> mv = minMaxAB(position,0,player,INT_MAX,INT_MIN,evalFunc);
		tn1 += n1;
		tne1 += ne1;
		return mv.second.back();
	}
	else{
		n2=0;
		ne2=0;
		pair<int,vector<pair<int,int>>> mv = minMaxAB(position,0,player,INT_MAX,INT_MIN,evalFunc);
		tn2 += n2;
		tne2 += ne2;
		return mv.second.back();
	}
}

pair<int, int> Player::alphaBetaSearch(int depth, int playerName, int alpha, int beta, int evalFunc, pair<int,int> pos){
	return maxValue(depth, playerName, alpha, beta, evalFunc, pos);
}

pair<int, int> Player::maxValue(int depth, int playerName, int alpha, int beta, int evalFunc, pair<int,int> pos){
	vector<pair<int,int>> mv;
	if(playerName == 1){
		n1++;
		mv = getValidMove();
	}
	else{
		n2++;
		mv = getValidMove();
	}
	
	if(depth == 0 || mv.size() == 0){
		if(playerName == 1){
			return make_pair(-compute(playerName, evalFunc,pos),-1);
		}
		else{
			return make_pair(compute(playerName, evalFunc,pos),-1);
		}
	}
	
	int v = INT_MIN;
	pair<int,int> temp;
	pair<int,int> val;
	for(int i=0; i<mv.size(); i++){
		val = minValue(depth-1, opposite(playerName), alpha, beta, evalFunc, pos);
		v = max(v,val.first);
		if(val.first == v){
			temp = mv[i];
		}
		if(v >= beta){
			return temp;
		}
		alpha = max(alpha,v);
		if(alpha > v){
			temp = mv[i];
		}
	}
	return temp;
}

pair<int, int> Player::minValue(int depth, int playerName, int alpha, int beta, int evalFunc, pair<int,int> pos){
	vector<pair<int,int>> mv;
	if(playerName == 1){
		n1++;
		mv = getValidMove();
	}
	else{
		n2++;
		mv = getValidMove();
	}
	
	if(depth == 0 || mv.size() == 0){
		if(playerName == 1){
			return make_pair(-compute(playerName, evalFunc, pos),-1);
		}
		else{
			return make_pair(compute(playerName, evalFunc, pos),-1);
		}
	}
	
	int v = INT_MAX;
	pair<int,int> temp;
	pair<int,int> val;
	for(int i=0; i<mv.size(); i++){
		val = maxValue(depth-1, opposite(playerName), alpha, beta, evalFunc, pos);
		v = min(v,val.first);
		if(val.first == v){
			temp = mv[i];
		}
		if(v <= alpha){
			return make_pair(v,temp.first);
		}
		beta = min(beta,v);
		if(beta < v){
			temp = mv[i];
		}
	}
	return make_pair(v, temp.first);
}

pair<int,int> Player::getAlphaBeta(int depth, int playerName, int evalFunc, pair<int,int> pos){
	pair<int,int> mv;
	mv = alphaBetaSearch(depth, playerName, INT_MIN, INT_MAX, evalFunc, pos);
	return mv;	
}
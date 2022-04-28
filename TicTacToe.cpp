#include<bits/stdc++.h>
using namespace std;

struct move{
	int row;
	int coloumn;
};


int check(char board[3][3]){
	int i,j;
	//for rows
	for(i=0;i<3;i++){
		if(board[i][0]==board[i][1] && board[i][1] == board[i][2])
		{
			if(board[i][0]=='X')
				return -10;
			else if(board[i][0]=='O')
				return 10;
			
 		}
	}
	
	//for columns
	for(i=0;i<3;i++){
		if(board[0][i]==board[1][i] && board[1][i] == board[2][i])
		{
			if(board[0][i]=='X')
				return -10;
			else if(board[0][i]=='O')
				return 10;
			
 		}
	}
	
	//for diagnols
	if(board[0][0]==board[1][1] && board[1][1] == board[2][2])
		{
			if(board[0][0]=='X')
				return -10;
			else if(board[0][0]=='O')
				return 10;
			
 		}
		 	
 	if(board[0][2]==board[1][1] && board[1][1] == board[2][0])
		{
			if(board[0][2]=='X')
				return -10;
			else if(board[0][2]=='O')
				return 10;
			
 		}
	return 0;
}


bool isFull(char board[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j] == 45)
				return false;
		}
	}
	return true;
}

void player(char board[3][3]){
	int i,j;
	cout << "enter the location : ";
	cin >> i >> j;
	board[i][j] = 'X';
}

void display(char board[3][3]){
	cout << "\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << "\t" << board[i][j];
		}
		cout << "\n";
	}
	
	
}

int minimax(char board[3][3], bool isMax) 
{ 
    
    int score = check(board); 
  
    // If Maximizer has won the game return his
    // evaluated score 
    if (score == 10) 
        return score; 
  
    // If Minimizer has won the game return his 
    // evaluated score 
    if (score == -10) 
        return score; 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (isFull(board)==true) 
        return 0;
    
    // If this maximizer's move 
    if (isMax) 
    { 
        int best = -1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]==45) 
                { 
                    // Make the move 
                    board[i][j] = 'O'; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    best = max( best,minimax(board, !isMax) ); 
  
                    // Undo the move 
                    board[i][j] = 45; 
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else
    { 
        int best = 1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]==45) 
                { 
                    // Make the move 
                    board[i][j] = 'X'; 
  
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = min(best,minimax(board, !isMax));  
                    board[i][j] = 45; 
                } 
            } 
        } 
        return best; 
    } 
}

void machine(char board[3][3]){
	int bestVal = -1000; 
    move bestMove; 
    bestMove.row = -1; 
    bestMove.coloumn = -1; 
 
    for (int i = 0; i<3; i++) 
    { 
        for (int j = 0; j<3; j++) 
        { 
            if (board[i][j]==45) 
            { 
                board[i][j] = 'O'; 
                int moveVal = minimax(board, false);
                board[i][j] = 45; 
  
                if (moveVal > bestVal) 
                { 
                    bestMove.row = i; 
                    bestMove.coloumn = j; 
                    bestVal = moveVal; 
                } 
            } 
        } 
    } 
  
    printf("The value of the best Move is : %d\n",bestVal); 
  
    board[bestMove.row][bestMove.coloumn] = 'O';
	
}

int main(){
	char board[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			board[i][j] = 45;
		}
	}
	
	while(1){
		if(!isFull(board) && !check(board)){
			display(board);
			player(board);	
		}
		else
			break;

		
		if(!isFull(board) && !check(board)){
			display(board);
			machine(board);	
		}
		else
			break;
		
	}
	
	display(board);
	if(check(board) == -10)
		cout << "YOU WIN" << endl;
	else if (check(board) == 10)
		cout << "YOU LOSS" << endl;
	else if(isFull(board))
		cout << "GAME DRAW" << endl;
}









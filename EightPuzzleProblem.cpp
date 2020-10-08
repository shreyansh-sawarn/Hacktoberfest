#include<stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Board{
    int** board;
    int heuristicValue;
    int depth;

public:
    Board(){
        board = (int**) calloc(3, sizeof(int*));

        for(int i=0; i<3; i+=1)
            board[i] = (int*) calloc(3, sizeof(int));
    }

    Board(const Board &a){
        board = (int**) calloc(3, sizeof(int*));

        for(int i=0; i<3; i+=1)
            board[i] = (int*) calloc(3, sizeof(int));

        for(int i=0; i<3; i+=1)
            for(int j=0; j<3; j+=1)
                board[i][j] = a.board[i][j];
    }

    void input(){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                scanf("%d", &board[i][j]);
            }
        }
    }

    void show(){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

	// Move the empty block to the left
    void moveLeft(){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                if(j!=0 && board[i][j]==0){
                    board[i][j] = board[i][j-1];
                    board[i][j-1] = 0;
                    return;
                }
            }
        }
    }

	// Move the empty block to right
    void moveRight(){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                if(j!=2 && board[i][j]==0){
                    board[i][j] = board[i][j+1];
                    board[i][j+1] = 0;
                    return;
                }
            }
        }
    }

	// Move the empty block up
    void moveUp(){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                if(i!=0 && board[i][j]==0){
                    board[i][j] = board[i-1][j];
                    board[i-1][j] = 0;
                    return;
                }
            }
        }
    }

	// Move the empty block down
    void moveDown(){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                if(i!=2 && board[i][j]==0){
                    board[i][j] = board[i+1][j];
                    board[i+1][j] = 0;
                    return;
                }
            }
        }
    }

    friend class A_star_algorithm;
};

class A_star_algorithm{
    vector<Board> solutionList;
    Board goalState;
    int heuristicValues[4];
    int solutionSize;
    bool canBeSolved;

public:
    A_star_algorithm(){
        Board init;
        printf("Enter the initial configuration : : ");
        init.input();
        solutionList.push_back(init);

		printf("Enter the goal configuration : : ");
        goalState.input();

        printf("\nStart State : : \n");
        init.show();

        printf("\nGoal State : : \n");
        goalState.show();

        solutionSize = 1;
        canBeSolved = true;
    }

    // Calculate the heuristic value of the state by comparing it with the goal state
    int heuristicFunction(Board b){
        int count = 0;

        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                if(b.board[i][j] != goalState.board[i][j] && b.board[i][j] != 0)
                    count += 1;
            }
        }

        return count;
    }
    
    // Check the last 2 states in the list. If same, then it cannot be solved by this method.
    bool isSolvable(){
    	Board b = solutionList[solutionSize - 1];
    	Board b2 = solutionList[solutionSize - 2];
    	
    	bool flag = true;
    	
    	for(int i=0; i<3; i+=1){
    		for(int j=0; j<3; j+=1){
    			if(b.board[i][j] != b2.board[i][j]){
    				flag = false;
    				break;
    			}
    		}
    		if(flag==false)	break;
    	}
    	
    	if(flag==true) return false;
    	
    	return true;
    }

    // Check if the puzzle is solved
    bool isSolved(){
        Board b = solutionList[solutionSize - 1];

        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                if(b.board[i][j] != goalState.board[i][j])
                    return false;
            }
        }

        return true;
    }

    void algorithmStep(){
        // Heuristic value when the empty block is moved left
        Board bl = solutionList.at(solutionSize - 1);
        bl.moveLeft();
        heuristicValues[0] = heuristicFunction(bl);

        // Heuristic value when the empty block is moved right
        Board br = solutionList.at(solutionSize - 1);
        br.moveRight();
        heuristicValues[1] = heuristicFunction(br);
    
        // Heuristic value when the empty block is moved up
        Board bu = solutionList.at(solutionSize - 1);
        bu.moveUp();
        heuristicValues[2] = heuristicFunction(bu);
    
        // Heuristic value when the empty block is moved dowm
        Board bd = solutionList.at(solutionSize - 1);
        bd.moveDown();
        heuristicValues[3] = heuristicFunction(bd);

        int min = 0;
        
        // Search for the minimum heuristic value
        for(int i=0; i<4; i+=1){
            if(heuristicValues[min] > heuristicValues[i])
                min = i;
        }

        // Depending on the minimum heuristic value, add the corresponding solution to the list
        if(min==0){
            solutionList.push_back(bl);
        }
        else if(min==1){
            solutionList.push_back(br);
        }
        else if(min==2){
            solutionList.push_back(bu);
        }
        else{
            solutionList.push_back(bd);
        }
        
        solutionSize +=1;
    }

    // Initiating function
    void solve(){
        while(!isSolved()){
            algorithmStep();
            if(!isSolvable()){
           		printf("The Puzzle Cannot be Solved By This Method\n");
           		return;
            }
        }
        
        solutionList.push_back(goalState);
        
        for(int step=1; step<=solutionSize; step+=1){
        	printf("\n*** Iteration %d ***\n", step);
        	solutionList[step-1].show();
        }
    }
};

int main(){
    A_star_algorithm a;
    a.solve();
    return 0;
}

//============================================================================
// Name        : Project1.cpp
// Author      : Stephen Katz
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#define N 8

//function to run Knights Tour Problem
int KnightsTour();
//core function to solve
int solve(int x, int y, int moveI, int sol[N][N], int moveX[], int moveY[]);
//checks if move is a safe move
int safe(int x, int y, int solution[N][N]);
//prints solution to terminal
void printSolution(int solution[N][N]);

int main() {
	KnightsTour();
	return 0;
}

//
int KnightsTour() {

	//create solution matrix
	int solution[N][N];

	//fill matrix with -1
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < N; y++) {
			solution[x][y] = -1;
		}
	}

	//defines next moves in x and y direction
	int moveX[N] = {2, 1, -1, -2, -2, -1,  1,  2};
	int moveY[N] = {1, 2,  2,  1, -1, -2, -2, -1};

	//sets first space to 0
	solution[0][0] = 0;

	//condition to make sure that the moveX and moveY are safe solutions
	if(solve(0, 0, 1, solution, moveX, moveY) == 0) {
		std::cout << "No possible solution";
		return 0;
	} else {
		printSolution(solution);
	}

	return 1;
}

//simple print function for a 8x8 matrix
void printSolution(int solution[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++) {
        	std::cout << solution[x][y] << " ";
        }
        std::cout << "\n";
    }
}

//checks if the move is safe and in the bounds of the 8x8 matrix
int safe(int x, int y, int solution[N][N]) {
	return ( x >= 0 && x < N && y >= 0 && y < N && solution[x][y] == -1);
}

//recursive function that
int solve(int x, int y, int moveI, int solution[N][N], int moveX[], int moveY[]) {
	int nextX, nextY;
	if(moveI == N*N) {
		return 1;
	}

	for(int i = 0; i < N; i++) {
		nextX = x + moveX[i];
		nextY = y + moveY[i];
		if(safe(nextX, nextY, solution)) {
			solution[nextX][nextY] = moveI;
			if(solve(nextX, nextY, moveI+1, solution, moveX, moveY) == 1) {
				return 1;
			} else {
				solution[nextX][nextY] = -1;
			}
		}
	}

	return 0;
}

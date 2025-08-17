#include <iostream>
#include <vector>
#include "raylib.h"

using namespace std;

int main() {
	int height = 800;
	int width = 800;

	InitWindow(width, height, "Game of life");
	SetTargetFPS(10);


	bool board[120][120] = { false };
	bool newboard[120][120] = { false };

	//Put any starting combination
		board[10][10] = true;
		board[11][10] = true;
		board[12][10] = true;

		board[20][25] = true;
		board[21][26] = true;
		board[22][24] = true;
		board[22][25] = true;
		board[22][26] = true;

		board[50][50] = true;
		board[51][51] = true;
		board[51][52] = true;
		board[50][52] = true;
		board[49][51] = true;  

		board[80][80] = true;
		board[81][80] = true;
		board[82][80] = true;
		board[82][81] = true;
		board[81][82] = true;  

		board[100][30] = true;
		board[101][30] = true;
		board[102][30] = true;

		board[70][100] = true;
		board[71][100] = true;
		board[72][100] = true;
		board[73][101] = true;
		board[72][102] = true; 

	int moves[8][2] = {
		{1, 0}, 
		{1, 1}, 
		{0, 1},
		{-1, 1},
		{-1, 0},
		{-1, -1},
		{0, -1},
		{1, -1}
	};
	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		for (int i = 1; i < 119; i++) {
			DrawLine(i * 8, 0, i * 8, 800, GRAY);
			DrawLine(0, i * 8, 800, i * 8, GRAY);
			for (int j = 1; j < 119; j++) {
				if (board[i][j] == true) {
					DrawRectangle(i * 8, j * 8, 8, 8, WHITE);
				}
				newboard[i][j] = false;
			}
		}

		for (int i = 1; i < 119; i++) {
			for (int j = 1; j < 119; j++) {
				int neighbors = 0;
				for (int u = 0; u < 8; u++) {
					if (i + moves[u][0] >= 1 || i + moves[u][0] <= 11 || j + moves[u][1] >= 1 || j + moves[u][1] <= 11) {
						if (board[i + moves[u][0]][j + moves[u][1]] == true) {
							neighbors++;
						}
					}
					else {
						continue;
					}
				}
				if (board[i][j] == true) {
					if (neighbors < 2) {
						newboard[i][j] = false;
					}
					else if (neighbors > 3) {
						newboard[i][j] = false;
					}
					else {
						newboard[i][j] = true;
					}
				}
				else {
					if (neighbors == 3) {
						newboard[i][j] = true;
					}
				}
			}
		}

		for (int i = 1; i < 119; i++) {
			for (int j = 1; j < 119; j++) {
				board[i][j] = newboard[i][j];
			}
		}


		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}

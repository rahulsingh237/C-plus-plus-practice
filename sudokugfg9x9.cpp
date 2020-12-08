#include <bits/stdc++.h>
using namespace std;
#define NotAssign 0
#define N 9

bool findNALoc(int sudoku[N][N],int& row, int& col);

bool isSafe(int sudoku[N][N], int row,
			int col, int num);

bool SolveSudoku(int sudoku[N][N])
{
	int row, col;

	if (!findNALoc(sudoku, row, col))
		return true;

	for (int num = 1; num <= 9; num++) 
	{

		if (isSafe(sudoku, row, col, num)) 
		{
			

			sudoku[row][col] = num;

			if (SolveSudoku(sudoku))
				return true;
			sudoku[row][col] = NotAssign;
		}
	}
	
	return false;
}

bool findNALoc(int sudoku[N][N],int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (sudoku[row][col] == NotAssign)
				return true;
	return false;
}

bool UsedInRow(int sudoku[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (sudoku[row][col] == num)
			return true;
	return false;
}

bool UsedInCol(int sudoku[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (sudoku[row][col] == num)
			return true;
	return false;
}

bool UsedInBox(int sudoku[N][N], int boxStartRow,int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (sudoku[row + boxStartRow]
					[col + boxStartCol] ==
									num)
				return true;
	return false;
}

bool isSafe(int sudoku[N][N], int row,int col, int num)
{
	return !UsedInRow(sudoku, row, num)
		&& !UsedInCol(sudoku, col, num)
		&& !UsedInBox(sudoku, row - row % 3,
						col - col % 3, num)
		&& sudoku[row][col] == NotAssign;
}

void showSudoku(int sudoku[N][N])
{
	for (int row = 0; row < N; row++) 
	{
		for (int col = 0; col < N; col++)
			cout << sudoku[row][col] << " ";
		cout << endl;
	}
}

int main()
{

	int sudoku[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	if (SolveSudoku(sudoku) == true)
		showSudoku(sudoku);
	else
		cout << "No solution exists";

	return 0;
}


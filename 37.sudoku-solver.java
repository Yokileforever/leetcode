/*
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (31.46%)
 * Total Accepted:    86K
 * Total Submissions: 273.4K
 * Testcase Example:  '[[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * You may assume that there will be only one unique solution.
 * 
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 */
class Solution {
    public void solveSudoku(char[][] board) {
		if (board == null || board.length == 0) {
			return ;
		}
		int x[] = new int[105], y[] = new int[105];
		int cnt = 0;
		for (int i = 0; i < board.length; ++i) {
			for (int j = 0; j < board[i].length; ++j) {
				if (board[i][j] == '.'){
					x[cnt] = i;
					y[cnt++] = j;
				}
			}
		}
		solve(board, 0, cnt, x, y);
    }
	public boolean solve(char[][] board, int cnt, int tar, int []x, int []y) {
		if (cnt == tar)	return true;
		for (char c = '1'; c <= '9'; ++c) {
			if (isVaild(board, x[cnt], y[cnt], c)) {
				board[x[cnt]][y[cnt]] = c;
				if (solve(board, cnt + 1, tar, x, y))	return true;
				board[x[cnt]][y[cnt]] = '.';
			}
		}
		return false;
	}
	public boolean isVaild(char [][]board, int row, int col, char c) {
		for (int i = 0; i < 9; ++i) {
			if (board[row][i] != '.' && board[row][i] == c)	return false;
			if (board[i][col] != '.' && board[i][col] == c)	return false;
			int x = 3 * (row / 3) + i / 3, y = 3 * (col / 3) + i % 3;
			if (board[x][y] != '.' && board[x][y] == c)	return false;
		}
		return true;
	}
}

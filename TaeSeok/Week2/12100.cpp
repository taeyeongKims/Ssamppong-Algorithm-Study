#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_MOVES = 5;

enum Direction { UP, DOWN, LEFT, RIGHT };
int N = 0;

int getMaxTile(const vector<vector<int>>& board) {
    int max_tile = 0;
    for (const auto& row : board) {
        max_tile = max(max_tile, *max_element(row.begin(), row.end()));
    }
    return max_tile;
}

void inversionBoard(vector<vector<int>>& board)
{
    for (int i = 0; i < N; i++)
        reverse(board[i].begin(), board[i].end());
}

void transpositionBoard(vector<vector<int>>& board)
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            swap(board[i][j], board[j][i]);
}

void compressBoard(vector<vector<int>>& board)
{
    for (int i = 0; i < N; i++)
    {
        int pos = 0;
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 0)
            {
                if (pos != j)
                {
                    board[i][pos] = board[i][j];
                    board[i][j] = 0;
                }
                pos++;
            }
        }
    }
}

void mergeBoard(vector<vector<int>>& board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
            }
        }
    }
}

void moveBoard(vector<vector<int>>& board, Direction dir) {
    switch (dir) {
    case LEFT:
        break;
    case RIGHT:
        inversionBoard(board);
        break;
    case UP:
        transpositionBoard(board);
        break;
    case DOWN:
        transpositionBoard(board);
        inversionBoard(board);
        break;
    }

    compressBoard(board);
    mergeBoard(board);
    compressBoard(board);

    switch (dir) {
    case LEFT:
        break;
    case RIGHT:
        inversionBoard(board);
        break;
    case UP:
        transpositionBoard(board);
        break;
    case DOWN:
        inversionBoard(board);
        transpositionBoard(board);
        break;
    }
}


bool isBoardChanged(const vector<vector<int>>& before, const vector<vector<int>>& after) {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            if (before[i][j] != after[i][j]) return true;
        
    return false;
}

bool canMove(const vector<vector<int>>& board) {
    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> newBoard = board;
        moveBoard(newBoard, static_cast<Direction>(dir));
        if (isBoardChanged(board, newBoard)) return true; 
    }
    return false; 
}

int findMaxAfterMoves(vector<vector<int>> board, int moves) {
    if (moves == 0 || !canMove(board)) return getMaxTile(board);

    int max_tile = 0;

    for (int dir = 0; dir < 4; dir++)
    {
        vector<vector<int>> newBoard = board;
        moveBoard(newBoard, static_cast<Direction>(dir));

        if (!isBoardChanged(board, newBoard)) continue;

        max_tile = max(max_tile, findMaxAfterMoves(newBoard, moves - 1));
    }

    return max_tile;
}

int main()
{
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    cout << findMaxAfterMoves(board, MAX_MOVES);

    return 0;
}

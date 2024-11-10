#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotateSticker(const vector<vector<int>>& sticker)
{
    int rows = sticker.size();
    int cols = sticker[0].size();
    vector<vector<int>> rotated(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            rotated[j][rows - 1 - i] = sticker[i][j];
        }
    }
    return rotated;
}

bool canPlaceSticker(const vector<vector<int>>& notebook, const vector<vector<int>>& sticker, int x, int y)
{
    int stickerRows = sticker.size();
    int stickerCols = sticker[0].size();

    for (int i = 0; i < stickerRows; i++) 
    {
        for (int j = 0; j < stickerCols; j++) 
        {
            if (sticker[i][j] == 1 && notebook[x + i][y + j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

void placeSticker(vector<vector<int>>& notebook, const vector<vector<int>>& sticker, int x, int y)
{
    int stickerRows = sticker.size();
    int stickerCols = sticker[0].size();

    for (int i = 0; i < stickerRows; i++) 
    {
        for (int j = 0; j < stickerCols; j++) 
        {
            if (sticker[i][j] == 1) 
            {
                notebook[x + i][y + j] = 1;
            }
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> notebook(N, vector<int>(M, 0));

    for (int k = 0; k < K; k++)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> sticker(R, vector<int>(C));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> sticker[i][j];
            }
        }


        bool isPlaced = false;

        for (int rotation = 0; rotation < 4; rotation++)
        {
            int stickerRows = sticker.size();
            int stickerCols = sticker[0].size();

            for (int i = 0; i <= N - stickerRows; i++)
            {
                for (int j = 0; j <= M - stickerCols; j++)
                {
                    if (canPlaceSticker(notebook, sticker, i, j))
                    {
                        placeSticker(notebook, sticker, i, j);
                        isPlaced = true;
                        break;
                    }
                }
                if (isPlaced) break;
            }

            if (isPlaced)
                break;
            sticker = rotateSticker(sticker);
        }
    }

    int filledCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (notebook[i][j] == 1) {
                filledCount++;
            }
        }
    }

    cout << filledCount << endl;
    return 0;
}

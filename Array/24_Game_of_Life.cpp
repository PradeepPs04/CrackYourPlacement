#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m)
{
    if(i >= 0 && i < n && j >= 0 && j < m)  return true;
    return false;
}

void gameOfLife(vector<vector<int>>& board) 
{
    int n = board.size();
    int m = board[0].size();

    int rows[8] = {-1,-1,0,+1,+1,+1,0,-1};
    int cols[8] = {0,+1,+1,+1,0,-1,-1,-1};

    for(int cr = 0; cr < n; cr++)
    {
        for(int cc = 0; cc < m; cc++)
        {
            int neighbours = 0;
            for(int i = 0; i < 8; i++)
            {
                int nr = cr + rows[i];
                int nc = cc + cols[i];

                if(valid(nr, nc, n, m) && board[nr][nc] >= 1)   neighbours++;
            }
            if(neighbours < 2 || neighbours > 3)  
            {
                // if alive then it will die
                if(board[cr][cc] == 1)  board[cr][cc] = 2;
            }
            else if(neighbours == 3)    
            {
                // if dead then it will regen
                if(board[cr][cc] == 0)  board[cr][cc] = -2;
            }   
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)  
        {
            if(board[i][j] == 2)  board[i][j] = 0;
            else if(board[i][j] == -2)    board[i][j] = 1;
        }
    }
}

int main()
{
    vector<vector<int>>board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);

    cout<<"Updated board"<<endl;

    for(auto i:board)
    {
        for(auto j:i)   cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
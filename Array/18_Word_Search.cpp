#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>>& board, vector<vector<int>>& visited, int cr, int cc, int idx, int& n, int& m, string& word, int rows[], int cols[])
{
    if(idx == word.length())    return true;
    if(cr < 0 || cr == n || cc < 0 || cc == m)  return false;
    if(board[cr][cc] != word[idx])    return false;
    if(visited[cr][cc] == 1)  return false;

    visited[cr][cc] = 1;

    for(int i = 0; i < 4; i++)
    {
        int nr = cr + rows[i];
        int nc = cc + cols[i];
        if(solve(board, visited, nr, nc, idx+1, n, m, word, rows, cols))    return true;
    }

    visited[cr][cc] = 0;
    return false;
}

void wordExists(vector<vector<char>>& board, string word)
{
    int n = board.size();
    int m = board[0].size();
    int rows[4] = {-1, 0, +1, 0};
    int cols[4] = {0, +1, 0, -1};
    vector<vector<int>>visited(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == word[0])
            {
                if(solve(board, visited, i, j, 0, n, m, word, rows, cols))    
                {
                    cout<<"Word found"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"Word not found"<<endl;
}

int main()
{
    vector<vector<char>>board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCCED";
    wordExists(board, word);
    return 0;
}
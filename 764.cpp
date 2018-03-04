#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<algorithm>

using namespace std;
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines)
{
    vector<vector<int>> grid(N,vector<int>(N,N));
    
    for(int i =0; i < N; i++)
        for(int j =0; j< N; j++)
        {
            grid[i][j] = min(i-0+1,j-0+1);
            grid[i][j] = min(grid[i][j],N-i);
            grid[i][j] = min(grid[i][j],N-j);
        }
    
    for(auto v : mines)
    {
        int i = v[0];
        int j = v[1];
        
        for(int ii =0; ii< N;ii++)
            grid[ii][j] = min(grid[ii][j],abs(ii-i));
        
        for(int jj =0; jj< N;jj++)
            grid[i][jj] = min(grid[i][jj],abs(jj-j));
    }
    
    
    int result =0;
    
    for(int i =0; i < N; i++)
        for(int j =0; j< N; j++)
            result = max(result,grid[i][j]);

    return result;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
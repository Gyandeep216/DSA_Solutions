// https://leetcode.com/problems/rotting-oranges/

// Efficient Approach with BFS using queue
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int total = 0;
        int rotten = 0;
        int time = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int k = q.size();
            rotten+=k;
            while(k--){
                int dir = 4;
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<dir; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) time++;
        }
    
        if(rotten==total) return time;
        return -1;
    }
};
// TC : O(N*N)
// SC : O(N*N)
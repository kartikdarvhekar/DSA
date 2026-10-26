class Solution {
public:
    long long ans(vector<vector<int>>& grid,int r,int c){
            if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
                return 0;
            }
            long long sum=grid[r][c];
        
            grid[r][c]=0;
            sum+=ans(grid,r-1,c);
            sum+=ans(grid,r+1,c);
            sum+=ans(grid,r,c-1);
            sum+=ans(grid,r,c+1);
            return sum;
            
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
     
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    if(k!=0 && ans(grid,i,j)% (long long)(k)==0) count++;
                }
            }
        }
        return count;
    }
};
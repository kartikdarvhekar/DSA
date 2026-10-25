class Solution {
public:
    bool check(int r,int c,vector<vector<int>>& grid){
       if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()){
        return false;
       }
       if(grid[r][c]==1) return true;
       
       grid[r][c]=1;
       bool u=check(r-1,c,grid);
       bool d=check(r+1,c,grid);
       bool right=check(r,c+1,grid);
       bool l=check(r,c-1,grid);
       
       return u && d && l && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.size()==1 && grid[0].size()==1) return 0;
        int count=0;
       
        for(int i=1;i<grid.size()-1;i++){          
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==0){
                    if(check(i,j,grid)==true) count++;
                }
            }
        }
        
        return count;
    }
};
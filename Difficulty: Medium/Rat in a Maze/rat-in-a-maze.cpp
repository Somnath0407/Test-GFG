class Solution {
  public:
  void helper(vector<vector<int>>& maze,int r,int c,string path,vector<string>&ans){
    int n=maze.size();
    if(r<0||c<0||r>=n||c>=n||maze[r][c]==0){
        return ;
    }
    if(r==n-1 && c==n-1){
        ans.push_back(path);
        return ;
    }
    maze[r][c]=0;
    helper(maze, r + 1, c, path + "D", ans); 
    helper(maze, r - 1, c, path + "U", ans); 
    helper(maze, r, c - 1, path + "L", ans); 
    helper(maze, r, c + 1, path + "R", ans);
    maze[r][c]=1;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
         vector<string> ans;
        int n = maze.size();
        
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return ans;
        
        helper(maze, 0, 0, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};
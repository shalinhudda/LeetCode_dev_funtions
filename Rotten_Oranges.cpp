class Solution {
public:
    struct Data{
        int AllRotten;
        list<pair<int, int>> Coordinates;
        int NotPossible = 0;
    };
    
    int orangesRotting(vector<vector<int>>& grid) {
        Data CollectedData;
        int index = 0;
        int row, column;
        
        CollectedData = CheckIfAllRotten(grid);             
        
        while(CollectedData.AllRotten != 0) {
            
            while( CollectedData.Coordinates.size() != 0) {
                row = CollectedData.Coordinates.front().first;
                column = CollectedData.Coordinates.front().second;
                
                // same row boundary check
                if(!((column + 1) >= grid[row].size())) {
                    if(grid[row][column+1] == 1) 
                        grid[row][column+1] = 2;
                }
                
                // same row boundary check
                if((column - 1) >= 0) {
                    if(grid[row][column-1] == 1) 
                        grid[row][column-1] = 2;
                }
                
                // same column boundary check
                if(!((row + 1) >= grid.size())){
                    if(grid[row+1][column] == 1) 
                        grid[row+1][column] = 2;
                }
                
                // same column boundary ceck 
                if((row - 1) >= 0) {
                    if(grid[row-1][column] == 1) 
                        grid[row-1][column] = 2;  
                }
                
                grid[row][column] = 0;
                CollectedData.Coordinates.pop_front();
            }
            
            CollectedData = CheckIfAllRotten(grid);
            index++;
        }
        if(CollectedData.NotPossible == 1)
            return -1;
        else
            return index;
    }
    
    Data CheckIfAllRotten(vector<vector<int>> & grid);


    
};

// if everything is rotten AllRotten = 0; 
Solution::Data Solution::CheckIfAllRotten(vector<vector<int>> & grid) {
    Data ReturnData;
    ReturnData.AllRotten = 0;
    int TotalSpace = grid.size() * grid[0].size();
    int NumberOfZeroAndOne = 0;
    int AllZero =0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1){
                ReturnData.AllRotten = -1;
                NumberOfZeroAndOne++;
            }
            if(grid[i][j] == 0) {
                NumberOfZeroAndOne++;
                AllZero++;
            }
            if(grid[i][j] == 2){
                ReturnData.Coordinates.push_back(make_pair(i, j));
            }

        }

    }

    if(NumberOfZeroAndOne == TotalSpace && AllZero != TotalSpace){
        ReturnData.AllRotten = 0;
        ReturnData.NotPossible = 1;
    }
    return ReturnData;
}

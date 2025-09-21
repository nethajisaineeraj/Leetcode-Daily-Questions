// 3484 Design Spreadsheet
class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet = vector<vector<int>> (rows, vector<int>(26, 0));
    }

    pair<int, int> getIndex(string cell){
        int col=-1, row=0;
        for(auto ch: cell){
            if(isalpha(ch))
                col = ch-65;
            else{
                row = row*10 + (ch-'0');
            }
        }
        row = row-1;
        return {row,col};
    }
    
    void setCell(string cell, int value) {
        auto [row, col] = getIndex(cell);
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = getIndex(cell);
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = string(formula.begin()+1, formula.end());
        stringstream ss(formula);
        string cell;
        int result = 0;
        while(getline(ss, cell, '+')){
            auto [row, col] = getIndex(cell);
            if(col==-1)
                result+=(row+1);
            else
                result+=sheet[row][col];
        }
        return result;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
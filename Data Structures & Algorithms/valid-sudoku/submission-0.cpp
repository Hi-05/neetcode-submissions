class Solution {
public:
    bool row(int r,vector<vector<char>> &b){

        unordered_set<char> s;

        for(int c = 0; c < 9; c++){

            if(b[r][c] >= '1' && b[r][c] <= '9'){

                if(s.find(b[r][c]) != s.end()) return false;
                s.insert(b[r][c]);
            }
        }
        return true;
    }

    bool col(int c,vector<vector<char>> &b){

        unordered_set<char> s;

        for(int r = 0; r < 9; r++){

            if(b[r][c] >= '1' && b[r][c] <= '9'){

                if(s.find(b[r][c]) != s.end()) return false;
                s.insert(b[r][c]);
            }
        }
        return true;
    }

    bool block(int i ,vector<vector<char>> &b){

        int r = i - (i % 3);
        int c = (i % 3) * 3;

        unordered_set<char> s;

        for(int j = r; j < (r + 3) ; j++){
            for(int k = c ; k < (c + 3); k++){

                if(b[j][k] >= '1' && b[j][k] <= '9'){

                    if(s.find(b[j][k]) != s.end()) return false;
                    s.insert(b[j][k]);
                }

            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){

            if(!row(i,board)) return false;
            if(!(col(i,board))) return false;
            if(!block(i,board)) return false;
        }

        return true;
    }
};

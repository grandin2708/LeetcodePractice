class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::set<char> s;
        std::unordered_map<char, int> m;

        // Check 3x3 squares
        for (int k{0}; k < 3; ++k) {
            for (int p{0}; p < 3; ++p) {
                for (int i{3*k}; i < 3*(k+1); ++i) {
                    for (int j{3*p}; j < 3*(p+1); ++j) {
                        char c{board[i][j]};
                        if (c == '.') continue;
                        if (++m[c] > 1) return false;
                    }
                }
                m.clear();
            }
        }
        
        // Check horizontal lines
        for (const auto& v: board){
            for (auto c : v) {
                if (c == '.') continue;
                if (++m[c] > 1) return false;
            }
            m.clear();
        }

        // Check vertical lines
        for (size_t i{0}; i < board.size(); ++i) {
            for (size_t j{0}; j < board.size(); ++j) {
                char c{board[j][i]};
                if (c == '.') continue;
                if (++m[c] > 1) return false;
            }
            m.clear();
        }

        return true;
    }
};

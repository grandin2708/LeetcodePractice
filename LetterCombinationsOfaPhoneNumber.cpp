class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        unordered_map<char,string> m = {{'2', "abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

        // First generate all char combinations
        vector<string> c;
        for (int i{0}; i < digits.size(); ++i) c.push_back(m[digits[i]]);

        // Determine res size
        int sz{1}; 
        for (auto s : c) sz *= s.size();
        res.resize(sz);

        vector<size_t> strSz;
        for (auto s : c) strSz.push_back(s.size());

        int lastSize = strSz.back();
        size_t prevSize{1};

        // Then generate all possible combinations
        for (int i{0}; i < c.size(); ++i) {
            string s{m[digits[i]]};
            
            for (int j{0}; j < res.size(); ++j) {
                // For the first char
                size_t charIdx{j/(sz/s.size())};
                if (i == c.size()-1){
                    charIdx = j % s.size();
                } else if (i > 0) {
                    // Frequency updates for middle chars
                    size_t freq{sz/(prevSize*lastSize)};
                    assert(prevSize > 0);
                    assert(lastSize > 0);
                    if (c.size() > 3) {
                        //Update for 4 digit case
                        if (i == 1)
                            freq = strSz[i+1]*strSz[i+2];
                        else // i==2
                            freq = lastSize;
                    }
                    charIdx = (j/freq) % s.size();
                }
                
                res[j].push_back(s[charIdx]);
            }   
            prevSize *= s.size();
        }

        return res;
    }
};

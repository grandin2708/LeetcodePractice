class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
    
        vector<string> result;
        if (n <= 0) {
            return result;
        } else if (n == 1) {
            string s;
            s += '(';
            s.push_back(')');
            result.push_back(s);
            return result;
        }

        vector<int> intRep;
        intRep.push_back(1);

        vector<vector<int>> possibleVals;
        possibleVals.push_back(intRep);

        for (int i{1}; i < 2*n; ++i) {
            auto size{possibleVals.size()};
            
            for (auto k{0}; k < size; ++k) {

                if (possibleVals[k].empty()) continue;

                assert(possibleVals[k].size() == i);

                bool posFeas{checkFeas(possibleVals[k], i, 1, 2*n)};
                bool negFeas{checkFeas(possibleVals[k], i, -1, 2*n)};

                if (posFeas && negFeas) {
                    vector<int> vDup(possibleVals[k]);
                    possibleVals[k].push_back(-1);
                    vDup.push_back(1);
                    possibleVals.push_back(vDup);
                } else if(posFeas && !negFeas) {
                    possibleVals[k].push_back(1);
                } else if(!posFeas && negFeas) {
                    possibleVals[k].push_back(-1);
                } else possibleVals[k].clear();
            }
        }

        for (auto& v : possibleVals) {
            string s;
            //s.push_back(v[0]);
            //s.push_back(v[1]);
            for (size_t i{0}; i < v.size(); ++i) {
                if (v[i] > 0) s += '(';
                else s.push_back(')');
            }
            result.push_back(s);
        }
        return result;
    }

    bool checkFeas(const vector<int>& v, int curPos, int val, int totSz) {
        if (v.empty()) return false;

        int partialSum{0};
        for (auto i: v) {
            partialSum += i;
            if (partialSum < 0){
                return false;
            }
        }

        //Too many closing parentheses 
        if (partialSum + val < 0) return false;

        //Too many opening parentheses
        if (partialSum + val > totSz - curPos - 1) {
            return false;
        }

        return true;
    }
};

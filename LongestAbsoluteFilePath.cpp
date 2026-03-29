class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLength{0};
        if (input.empty()) return maxLength;

        stack<string> stk;
        string s;
        int tabLevel{0};
        int curSize{0};

        for (auto it = input.begin(); it != input.end(); ++it) {     
            if (*it == '.') {
                // Process file name
                while (it != input.end() && *it != '\n') {
                    s +=(*it);
                    ++it;
                }

                while (tabLevel < (int)stk.size()) {
                    string topStr{stk.top()};
                    curSize -= (int)topStr.length();
                    stk.pop();
                }
                int sz{curSize + (int)s.length() + (int)stk.size()};
                
                if (sz > maxLength) {
                    maxLength = sz;
                }
                s.clear();
                if (it == input.end()) break;
                //else --it;
                tabLevel = 0;

                continue;
            } else if (*it == '\n') {
                if (stk.empty()){
                    stk.push(s);
                    curSize += (int)s.length();
                    tabLevel = 0;
                    s.clear();
                } 
                else {
                    while (tabLevel < (int)stk.size()) {
                        string topStr{stk.top()};
                        curSize -= (int)topStr.length();
                        stk.pop();
                    }
               
                    curSize += (int)s.length();
                    stk.push(s);
                    s.clear(); 
                    tabLevel = 0;
                }
                continue;
            } else if (*it == '\t') {
                ++tabLevel;
                continue;
            }

            s+=(*it);
        }
        return maxLength;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        string s;

        vector<char> charNums;
        for (int i{1}; i <= n; ++i) charNums.push_back(i+'0');

        int digit{0};
        while (digit < n) {
            ++digit;
            int nextFact{getFactorial(n-digit)};
            int sum = 0;
            int num{0};
            while (sum < k) {
                sum += nextFact;
                ++num;
            } 
            --num;

            k -= num * nextFact;
            assert(num <= n - digit);
            s.push_back(charNums[num]);
            charNums.erase(charNums.begin() + num);
            charNums.shrink_to_fit();
        }

        return s;
        
    }

    int getFactorial(int m) {
        int res{1};
        for (int i{1}; i <= m; ++i) res *= i;
        return res;
    }
};

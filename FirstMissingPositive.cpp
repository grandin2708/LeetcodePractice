class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // First solution
        // unordered_map<uint32_t,uint8_t> m;
        // for (int i : nums) {
        //     if (i > 0) m[i] = 1;
        // }
        // uint32_t res{1};
        // for (int i{1}; i < INT_MAX; ++i) {
        //     if (m[i] == 0){
        //         res = i;
        //         break;
        //     } 
        // }
        // return res;

        // Second solution
        vector<uint8_t> v(nums.size()+1);
        for (int i : nums) {
            if (i <= 0 || i > (int)nums.size()) continue;
            v[i] = 1;
        }

        int r{(int)nums.size()+1};
        for (int k{1}; k < (int)v.size(); ++k){
            if (v[k] == 0){
                r = k;
                break;
            }
        }
        return r;
    }
};

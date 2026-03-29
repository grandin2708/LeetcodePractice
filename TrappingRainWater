class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() <= 2) return 0;

        // Check for height change
        size_t numDecr{0};
        for (int i{1}; i < height.size(); ++i) {
            if (height[i] - height[i-1] > 0) {
                ++numDecr;
            }
        }

        if (numDecr >= height.size() - 1) return 0;
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(),0);

        vector<int> inds(height.size());
        iota(inds.begin(), inds.end(), 0);
        std::sort(inds.begin(), inds.end(), [&height](int i, int j) {return height[i] > height[j];});

        int largestInd{inds[0]};

        for (int h{0}; h < height.size(); ++h){
        //for (auto& h: height) {
            int left{-1};
            if (largestInd < h) {
                left = height[largestInd];
            } else {
                left = *std::max_element(height.begin(), height.begin() + h);
            }
            int right{-1};
            if (largestInd > h){
                right = height[largestInd];
            } else {
                right = *std::max_element(height.begin() + h, height.end());
            } 
            maxLeft[h] = left;
            maxRight[h] = right;
        }
        
        int water{0};

        for (size_t i{1}; i < height.size() - 1; ++i) {
            int curHeight{std::min(maxLeft[i], maxRight[i])};
            water += std::max(0, curHeight - height[i]);
        }

       
        return water;
    }
};

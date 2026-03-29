class Solution {
public:
    int mirrorReflection(int p, int q) {
        assert(p>=q);

        if (p % q == 0){
            int r{p/q};
            if (r % 2 == 0) return 2;
            else return 1;

        } else {
            int l{lcm(p,q)};
            int s{l/q};
            if (s % 2 == 0) return 2;
            else {
                int k{l/p};
                if (k % 2 == 0) return 0;
                else return 1;
            } 
        }
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        if (points.size() <= 2)
            return points.size();

        int xCoef;
        int yCoef;
        int constant; // has to be integer

        std::set<pair<int,int>> noCheck; 
        //set of pairs no needing check (previosuly found to lie on the same line)
        int maxPoints = 2;

        for (int i = 0; i < points.size() - 1; ++i)
        {
            for (int j = i+1; j < points.size(); ++j)
            {
                auto setFinder = noCheck.find(std::make_pair(i,j));

                //Point (i,j) already on the line of the previously considered pair of points
                if (setFinder != noCheck.end()) continue; 

                xCoef = points[j][1] - points[i][1];
                yCoef = points[i][0] - points[j][0];
                constant = points[i][0]*(points[j][1] - points[i][1]) 
                - points[i][1]*(points[j][0] - points[i][0]); 

                int numPoints = 2;

                //Now check all the remaining points
                for (int k = j+1; k < points.size(); ++k)
                {
                    if (xCoef*points[k][0] + yCoef*points[k][1] == constant)
                    {
                        ++numPoints;
                        noCheck.emplace(std::make_pair(j,k));
                        if (numPoints > maxPoints) ++maxPoints;
                    }
                }
                if (maxPoints > points.size()/2) break;
            }
        }

        return maxPoints;
    }
};

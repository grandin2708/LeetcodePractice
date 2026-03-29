class Solution {
public:

    bool checkHorLine(const tuple<int, int, int>& horLine, pair<int, int>& curCoord, int move, int i) {
        int lineYCoord{get<0>(horLine)};
        int xStart{get<1>(horLine)};
        int xEnd{get<2>(horLine)};
        bool goUp{i % 4 == 0};
        bool crossY{false};
        if (goUp) {
            // going up, first check whether we cross yCoord
            crossY = (curCoord.second < lineYCoord && curCoord.second + move >= lineYCoord);
        } else {
            // Going down
            crossY = (curCoord.second > lineYCoord && curCoord.second - move <= lineYCoord);
        }
        if (!crossY) return false;
        if (curCoord.first >= xStart && curCoord.first <= xEnd) return true;

        return false;
    }

    bool checkVertLine(const tuple<int, int, int>& vertLine, pair<int, int>& curCoord, int move, int i) {
        int lineXCoord{get<0>(vertLine)};
        int yStart{get<1>(vertLine)};
        int yEnd{get<2>(vertLine)};
        bool goLeft{i % 4 == 1};
        bool crossX{false};

        if (goLeft) {
            crossX = (curCoord.first - move <= lineXCoord && curCoord.first > lineXCoord);
        } else {
            crossX = (curCoord.first < lineXCoord && curCoord.first + move >= lineXCoord);
        }
        if (!crossX) return false;
        if (curCoord.second >= yStart && curCoord.second <= yEnd) return true;
        return false;
    }

    bool isSelfCrossing(vector<int>& distance) {
        if (distance.size() < 4) return false;

        pair curCoord{0,0};
        deque<tuple<int, int, int>> horLines; // y coord, x start, x end. Only need to store two
        deque<tuple<int, int, int>> vertLines; // x coord, y start, y end. Only need to store two

        size_t i{0};

        for (size_t i{0}; i < distance.size(); ++i) {
            int move{distance[i]};

            if (i % 2 == 0 && horLines.size() > 1) {
                //Check horizontal lines
                for (const auto& line : horLines) {
                    if (checkHorLine(line, curCoord, move, i)) return true;
                }
                
                // Also need to check penultimate vertical line 
                auto vLine{vertLines.front()};
                int xCoord{get<0>(vLine)};
                if (xCoord == curCoord.first) {
                    if (i % 4 == 0) { // Going up
                        int yStart{get<1>(vLine)};
                        if (curCoord.second + move >= yStart) return true;
                    } else { // Going down
                        int yEnd{get<2>(vLine)};
                        if (curCoord.second - move <= yEnd) return true;
                    }
                }
            } else if (vertLines.size() > 1) {
                // Check vertical lines
                for (const auto& line : vertLines) {
                    if (checkVertLine(line, curCoord, move, i)) return true;
                }

                // Also need to check penultimate horizontal line
                auto hLine{horLines.front()};
                int yCoord{get<0>(hLine)};
                if (curCoord.second == yCoord) {
                    if (i % 4 == 1) { // Going left
                        int xEnd{get<2>(hLine)};
                        if (curCoord.first - move <= xEnd) return true;
                    } else { // Going right
                        int xStart{get<1>(hLine)};
                        if (curCoord.first + move >= xStart) return true;
                    }
                }
            }

            // Update lines
            if (i % 2 == 0) {
                // Add vertical line
                int yStart{i % 4 == 0 ? curCoord.second : curCoord.second - move};
                int yEnd{i % 4 == 0 ? curCoord.second + move : curCoord.second};
                vertLines.push_back(make_tuple(curCoord.first, yStart, yEnd));
                if (vertLines.size() > 3) vertLines.pop_front();
            } else {
                // Add horizontal line
                int xStart{i % 4 == 1 ? curCoord.first - move : curCoord.first};
                int xEnd{i % 4 == 1 ? curCoord.first : curCoord.first + move};
                horLines.push_back(make_tuple(curCoord.second, xStart, xEnd));
                if (horLines.size() > 3) horLines.pop_front();
            }

            // Actually move
            if (i % 4 == 0) curCoord.second += move;
            else if (i % 4 == 1) curCoord.first -= move;
            else if (i % 4 == 2) curCoord.second -= move;
            else curCoord.first += move;
        } 

        return false;
    }
};

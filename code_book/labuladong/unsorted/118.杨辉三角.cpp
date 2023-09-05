
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
#include <unordered_map>

#include "../utils/utils.h"
#include "../utils/tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.resize(numRows);
        res[0] = vector<int>(1, 1);
        res[1] = vector<int>(2, 1);
        for (int i = 2; i < numRows; i++) {
            res[i].resize(1 + i);
            res[i][0] = 1;
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res[i][i] = 1;
        }

        return res;
    }
};


int main() {
  Solution s;
  auto ret = s.generate(5);
  for (auto& r : ret)
    printCollection(r);
}



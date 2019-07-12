#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/longest-palindrome/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int longestPalindrome(string &s) {
        unordered_map<char, int> seen;
        for (auto c : s) {
            ++seen[c];
        }
        int sum = 0;
        bool seen_single = false;
        for (auto &p : seen) {
            sum += (p.second >> 1) << 1;
            if (!seen_single && p.second % 2 == 1)
                seen_single = true;
        }
        if (seen_single)
            ++sum;
        return sum;
    }
};

void test1() {
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    string s = "abccccdd";
    cout << "7 ? " << Solution().longestPalindrome(s) << endl;
}

void test2() {

}

void test3() {

}
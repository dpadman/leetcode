/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 *
 * https://leetcode.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (41.56%)
 * Total Accepted:    6.7K
 * Total Submissions: 16.1K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * You are given a string s, and an array of pairs of indices in the string
 * pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
 * 
 * You can swap the characters at any pair of indices in the given pairs any
 * number of times.
 * 
 * Return the lexicographically smallest string that s can be changed to after
 * using the swaps.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2]]
 * Output: "bacd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[1] and s[2], s = "bacd"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * Output: "abcd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[0] and s[2], s = "acbd"
 * Swap s[1] and s[2], s = "abcd"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cba", pairs = [[0,1],[1,2]]
 * Output: "abc"
 * Explaination: 
 * Swap s[0] and s[1], s = "bca"
 * Swap s[1] and s[2], s = "bac"
 * Swap s[0] and s[1], s = "abc"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s only contains lower case English letters.
 * 
 * 
 */

class unionf {
public:
    unionf(int n) : parent(n, -1), size(n, 1) {
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void do_union(int a, int b) {
        int roota = find(a);
        int rootb = find(b);

        if (roota == rootb)
            return;

        if (size[roota] >= size[rootb]) {
            parent[rootb] = roota;
            size[rootb] += size[roota];
        } else {
            parent[roota] = rootb;
            size[roota] += size[rootb];
        }
    }
private:
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, vector<char>> mp;
        unionf uf(s.length());
        string ans = "";
        for (auto i : pairs) {
            uf.do_union(i[0], i[1]);
        }

        for (int i=0; i<s.size(); i++) {
            int head = uf.find(i);
            mp[head].push_back(s[i]);
        }

        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
            reverse(it.second.begin(), it.second.end());
        }

        for (int i=0; i<s.size(); i++) {
            int head = uf.find(i);
            ans += mp[head].back();
            mp[head].pop_back();
        }

        return ans;
    }
};

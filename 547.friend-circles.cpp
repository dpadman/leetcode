/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (55.83%)
 * Total Accepted:    119.7K
 * Total Submissions: 213.4K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */
class Solution {
private:
    struct Node {
        int parent;
        
        Node (int p) : parent(p)
        { }
    };
    void printMap(unordered_map<int, vector<int>> &mp) {
        int cnt = 0;
        for (auto it=mp.begin(); it != mp.end(); ++it) {
            cnt += it->second.size();
            cout << "P=" << it->first << " C=";
            for (int k=0; k<it->second.size(); k++) {
                cout << it->second[k] << " ";
            }
            cout << endl;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size(), cnt = 0;
        struct Node ** heads;
        unordered_map<int, vector<int>> mp;
        
        heads = (struct Node **) malloc(N * sizeof (heads[0]));
        for (int i=0; i<N; i++) {
            heads[i] = new Node(i);
        }
        
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (M[i][j] == 1) {
                    if (heads[i]->parent == i &&
                              heads[j]->parent == j) {
                        mp[heads[i]->parent].push_back(j);
                        heads[j]->parent = heads[i]->parent;

                    } else if (heads[i]->parent == i &&
                              heads[j]->parent != j) {
                        if (heads[j]->parent == i)
                            continue;
                        mp[heads[j]->parent].push_back(i);
                        heads[i]->parent = heads[j]->parent;
                        for (int k=0; k<mp[i].size(); k++) {
                            heads[mp[i][k]]->parent = heads[j]->parent;
                            mp[heads[j]->parent].push_back(mp[i][k]);
                        }
                        mp.erase(i);

                    } else if (heads[i]->parent != i &&
                              heads[j]->parent == j) {
                        if (heads[i]->parent == j)
                            continue;
                        mp[heads[i]->parent].push_back(j);
                        heads[j]->parent = heads[i]->parent;
                        for (int k=0; k<mp[j].size(); k++) {
                            heads[mp[j][k]]->parent = heads[i]->parent;
                            mp[heads[i]->parent].push_back(mp[i][k]);
                        }
                        mp.erase(j);

                    } else {

                        if (heads[i]->parent == heads[j]->parent) {
                            
                        } else if (mp[heads[i]->parent].size() <= mp[heads[j]->parent].size()) {
                            vector<int> kk = mp[heads[i]->parent];
                            int del = heads[i]->parent;

                            mp[heads[j]->parent].push_back(heads[i]->parent);
                            heads[heads[i]->parent]->parent = heads[j]->parent;
                            for (int k=0; k<kk.size(); k++) {

                                heads[kk[k]]->parent = heads[j]->parent;
                                mp[heads[j]->parent].push_back(kk[k]);
                            }
                            mp.erase(del);
                        } else {
                            int del = heads[j]->parent;
                            vector<int> kk = mp[heads[j]->parent];
                            mp[heads[i]->parent].push_back(heads[j]->parent);
                            heads[heads[j]->parent]->parent = heads[i]->parent;
                            for (int k=0; k<kk.size(); k++) {
                                heads[kk[k]]->parent = heads[i]->parent;
                                mp[heads[i]->parent].push_back(kk[k]);
                            }
                            mp.erase(del);
                        }

                    }

                }
            }
        }

        for (int i=0; i<N; i++) {
            
            delete heads[i];
        }
        free(heads);
        
        for (auto it=mp.begin(); it != mp.end(); ++it) {
            cnt += it->second.size();
        }
        
        return N-cnt;
    }
};

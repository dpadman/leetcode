/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 *
 * https://leetcode.com/problems/online-election/description/
 *
 * algorithms
 * Medium (46.13%)
 * Total Accepted:    11.6K
 * Total Submissions: 25.1K
 * Testcase Example:  '["TopVotedCandidate","q","q","q","q","q","q"]\n' +
  '[[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]'
 *
 * In an election, the i-th vote was cast for persons[i] at time times[i].
 * 
 * Now, we would like to implement the following query function:
 * TopVotedCandidate.q(int t) will return the number of the person that was
 * leading the election at time t.  
 * 
 * Votes cast at time t will count towards our query.  In the case of a tie,
 * the most recent vote (among tied candidates) wins.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["TopVotedCandidate","q","q","q","q","q","q"],
 * [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
 * Output: [null,0,1,1,0,0,1]
 * Explanation: 
 * At time 3, the votes are [0], and 0 is leading.
 * At time 12, the votes are [0,1,1], and 1 is leading.
 * At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the
 * most recent vote.)
 * This continues for 3 more queries at time 15, 24, and 8.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= persons.length = times.length <= 5000
 * 0 <= persons[i] <= persons.length
 * times is a strictly increasing array with all elements in [0, 10^9].
 * TopVotedCandidate.q is called at most 10000 times per test case.
 * TopVotedCandidate.q(int t) is always called with t >= times[0].
 * 
 * 
 * 
 */
class TopVotedCandidate {
private:
    int numP;
    int maxT;
    vector<int> perCnt;
    vector<int> voteMx;
    vector<int> timeV;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
        : perCnt(5000, 0)
        , voteMx(times.size(), 0)
        , timeV(times) {

        int mp = -1, mx = INT_MIN;
        for (int i=0; i<times.size(); i++) {
            if (!perCnt[persons[i]])
                numP++;
            perCnt[persons[i]]++;
            if (perCnt[persons[i]] >= mx) {
                mp = persons[i];
                mx = perCnt[persons[i]];
            }
            voteMx[i] = mp;
        }

        maxT = times[times.size()-1];
    }
    
    int q(int t) {
        int N=timeV.size()-1;
        int lo=0, hi=N, mid;

        if (t >= maxT)
            return voteMx[N];

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (timeV[mid] == t) {
                return voteMx[mid];
            } else if (timeV[mid] < t && mid+1 <= N && timeV[mid+1] > t) {
                return voteMx[mid];
            } else if (timeV[mid] < t) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return 0;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

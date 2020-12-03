/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (45.73%)
 * Total Accepted:    13.5K
 * Total Submissions: 29.3K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has
 * piles[i] bananas.  The guards have gone and will come back in H hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she
 * chooses some pile of bananas, and eats K bananas from that pile.  If the
 * pile has less than K bananas, she eats all of them instead, and won't eat
 * any more bananas during this hour.
 * 
 * Koko likes to eat slowly, but still wants to finish eating all the bananas
 * before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H
 * hours.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [3,6,7,11], H = 8
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [30,11,23,4,20], H = 5
 * Output: 30
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: piles = [30,11,23,4,20], H = 6
 * Output: 23
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        sort(piles.begin(), piles.end());
        int K = piles[piles.size()-1], cnt = 0;
        int lo = 0, hi = piles[piles.size()-1], mid;

        while (lo <= hi) {

            cnt = 0;
            mid = lo + (hi - lo) / 2;
            mid = mid ? mid : 1;

            for (int i=0; i<piles.size(); i++) {
                if (piles[i] <= mid) {
                    ++cnt;
                } else if (piles[i] % mid == 0) {
                    cnt += (piles[i] / mid);
                } else {
                    cnt += (piles[i] / mid) + 1;
                }
            }

            if (cnt > H) {
                lo = lo + ((hi - lo) / 2) + 1;
            } else if (cnt <= H) {
                K = min(K, mid);
                hi = lo + ((hi - lo) / 2) - 1;
            }
        }

        return K;
    }
};

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.48%)
 * Total Accepted:    356.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        if (n == 0) {
        } else if (m == 0) {
            for (int i=0; i<n; i++)
                nums1[i] = nums2[i];
        } else if (nums2[0] >= nums1[m-1]) {
            for (int i=0; i<n; i++)
                nums1[m+i] = nums2[i];
        } else if (nums1[0] >= nums2[n-1]) {
            for (int i=m-1; i>=0; i--)
                nums1[n+i] = nums1[i];
            for (int i=0; i<n; i++)
                nums1[i] = nums2[i];
        } else {

            while (i<m && j<n) {
                if (nums1[i] > nums2[j]) {
                    for (int k=m; k>i; k--) {
                        nums1[k] = nums1[k-1];
                    }
                    nums1[i] = nums2[j];
                    j++;
                    m++;
                }
                i++;
            }
            while (j<n) {
                nums1[i] = nums2[j];
                j++;
                i++;
            }
        }
    }
};

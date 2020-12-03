class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            int k = target - nums[i];
            auto it = mp.find(k);
            if (it != mp.end() && (i != it->second)) {
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
        }
        return ans;
    }
};

/*
   Link to problem:   https://leetcode.com/problems/3sum/
   Time Complexity:   O(n^2)
   Space Complexity:  O(n)
   Idea:
          - Sort the array
          - Perform 2 for loops to choose elements a and b
          - The third element c = -(a + b)
          - Use 2 pointers approach (as b grows larger, c must be smaller),
            so every time j moves forward (to choose b), k must move backward (to choose c).
          - Never choose a to be the same twice, and never choose b to be the same twice for the same a (this solves the unique problem)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ans;
        int lastA = -1, updatedLastA = 0;
        for(int i = 0; i < n; i++){
            if(updatedLastA && lastA == nums[i]) continue;
            updatedLastA = 1, lastA = nums[i];
            int k = n - 1;
            int lstB = -1;
            int lastB = -1, updatedLastB = 0;
            for(int j = i + 1; j < n; j++){
                if(updatedLastB && lastB == nums[j]) continue;
                updatedLastB = 1, lastB = nums[j];
                int a = nums[i], b = nums[j];
                int c = -(a + b);
                while(k > j && nums[k] > c)
                    k--;
                if(k > j && nums[k] == c){
                    vector<int> res;
                    res.push_back(a);
                    res.push_back(b);
                    res.push_back(c);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};

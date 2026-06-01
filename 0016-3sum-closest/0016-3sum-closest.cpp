class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cl_sum = nums[0] + nums[1] + nums[2];;
        for (int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;

            while (i < j) {
              int  sum = nums[i] + nums[j] + nums[k];

                if (abs(t - sum) < abs(t - cl_sum)) 
                    cl_sum = sum;
                
                if (t < sum) 
                    j--;
                 else 
                    i++;
                
            }
        }
        return cl_sum;
    }
};
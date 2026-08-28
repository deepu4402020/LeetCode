class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& A, int lower, int upper) {
        sort(begin(A), end(A));
        vector<vector<int>> res;

        int st = lower;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] < lower || A[i] > upper) 
                continue;

            if(A[i] > st)
                res.push_back({st, A[i] - 1});
            
            st = A[i] + 1;
        }

        if(st <= upper)
            res.push_back({st, upper});
        
        return res;
    }
};
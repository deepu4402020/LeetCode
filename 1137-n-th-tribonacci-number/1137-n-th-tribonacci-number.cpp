class Solution {
public:
    int tribonacci(int n) {
        int n_1 = 1; 
        int n_2 = 1; 
        int n_3 = 0; 
        
        if (n <= 3) {
            if (n == 3) return 2;
            return (n == 0) ? 0 : 1;
        }

        int curr = 2;
        
        for (int i = 3; i <= n; i++) {
            curr = n_1 + n_2 + n_3;
            
           
            n_3 = n_2;
            n_2 = n_1;
            n_1 = curr;
        }
        
        return curr;
    }
};
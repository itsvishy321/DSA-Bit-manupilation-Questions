// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1],
// then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321

//**Optimal Approach**

	class Solution {
	public:
    int reverse(int x) {
        int ans=0;
        while(x){
            
            // Checking whether the ans is going beyond INT range or not?
            if(ans < INT_MIN/10 || ans > INT_MAX/10)
                return 0;
            
            int rem = x % 10;
            ans = ans*10 + rem;
            x = x/10;
        }
        
        return ans;
        
    }
	};

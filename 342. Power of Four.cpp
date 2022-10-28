// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.


// **Bruteforce**

	class Solution {
	public:
    bool isPowerOfFour(int n) {
        //edge case
        if(n==1)
            return true;
        
        //base condition
        if(n<=0)
            return false;
        
        while(n%4 == 0)
        {
            if(n==4)
                return true;
            n = n/4;
        }
        return false;
    }
	};
	
// **Bit Manipulation**

	class Solution {
	public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        
        //checking whether it is a power of 2
        if((n & (n-1)) == 0)
        {
            int count = 0;
            
            //counting number of false bits
            while(n != 1)
            {
                n = n>>1;
                count++;
            }
            
            //if number of false bits are even then true
            if(count%2 == 0)
                return true;
            else
                return false;
        }
        
        return false;
    }
	};
	
// **Optimised Bit Manupilation**
	
	class Solution {
	public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        if((n & (n-1)) == 0)
        {
            //Counting number of false bits 
            int temp = n | (n-1);
            int bits = __builtin_popcount(temp);
            
            //If false bits are even then true
            if((bits-1)%2 == 0)
                return true;
            else
                return false;
        }
        return false;
    }
	};

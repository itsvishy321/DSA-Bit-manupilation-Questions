// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

//**Bruteforce using string**

	class Solution {
	public:
    int bitwiseComplement(int n) {
        
        if(n==0)
            return 1;
        
        string ans = "";
        int digit=0;
        int complement=0;
        
        while(n)
        {
            int bit = n & 1;
            ans += to_string(bit);
            n = n>>1;
            digit++;
        }
        
        for(int i=ans.length()-1 ; i>=0 ; i--)
        {
            cout<<ans[i]<<endl;
            if(ans[i]=='0')
                complement += pow(2,i);
        }
        return complement;
    }
	};
	
//**Bit manupilation Approach**

	class Solution {
	public:
    int bitwiseComplement(int n) {
        
        if(n==0)
            return 1;
        
        //Making 1's complement of n
        int complement = ~n;
        int mask = 0;
        int count = 0;
        while(n)
        {
            n = n>>1;
            count++;
        }
        
        for(int i=0 ; i<count ; i++)
        {
            mask = mask<<1;
            mask = mask | 1;
        }
        
        //Removing unneccessary preceding 1's from complement
        complement = mask & complement;
        return complement;
    }
	};
	
//**More Optimised by Bit Manupilation**

	class Solution {
	public:
    int bitwiseComplement(int n) {

        if(n==0)
            return 1;
        
        //Making 1's complement of n
        int complement = ~n;
        int mask = 0;
        
        while(n)
        {
            mask = (mask<<1) | 1;
            n = n>>1;
        }
        
        //Removing unneccessary preceding 1's from complement
        complement = mask & complement;
        return complement;
    }
	};

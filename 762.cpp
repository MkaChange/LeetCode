class Solution {
public:
	bool isPrime(int n){
		if (n ==1)
		{
			return false;
		}
		for (int i = 2; i <= sqrt(n); ++i)
		{
			if(n % i == 0) return false;
		}
		return true;
	}
	int foo(int x)  
	{  
    	int count = 0;  
    	while(x)  
    	{  
        	count++;  
        	x = x&(x - 1);  
    	}  
    	return count;  
	}  
    int countPrimeSetBits(int L, int R) {
    	int count = 0;
        for (int i = L; i <= R; ++i)
        {
        	if(isPrime(foo(i)))count++;
        }
        return count;
    }
};
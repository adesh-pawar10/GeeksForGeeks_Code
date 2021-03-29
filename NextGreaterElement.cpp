 // A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        
         stack<long long > s;
        vector<long long > res (n);
        
        for (int i = n-1; i >= 0; i--)
        {
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
                
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
                
            s.push (arr[i]);
        }
        return res;
    }
};

/* Driver code */
int main()
{
	
}

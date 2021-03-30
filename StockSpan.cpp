// C++ program to calculate stock span values
#include <bits/stdc++.h>
using namespace std;

// Function to calculate span
// price[]: price array in input
// n: size of array

class Solution{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       
        stack<int> s;
        s.push(0);
        vector <int> S (n);
        
        // Span value of first day is always 1  
        S[0] =1;
        
        // Calculate span value of remaining days   
        // by linearly checking previous days 
        for(int i=1;i<n;i++)
        {
            // pop from the stack untill you find a greater value in the stack
            while(s.empty()==false and price[s.top()] <= price[i])
            s.pop();
            
            // calculating distance, if stack is empty then the distance is i+1 
            int span = (s.empty()) ? (i+1) : (i-s.top());
            S[i] = span;
            s.push(i);
       	}
       	return S;
    }
};

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int i, a[n];
    
    for(i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    Solution ans;
    vector <int> s = ans.calculateSpan(a, n);
    
    for(i = 0; i < n; i++)
    {
      cout << s[i] << " ";
    }
    
    cout << endl;
  }
  
  return 0;
}

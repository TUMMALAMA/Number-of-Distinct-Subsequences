//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	   int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0); // Using long long to handle large numbers

        dp[0] = 1; // Empty subsequence is always a valid subsequence

        unordered_map<char, int> last_seen;

        for (int i = 1; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1]) % MOD;

            if (last_seen.find(s[i - 1]) != last_seen.end()) {
                int idx = last_seen[s[i - 1]];
                dp[i] = (dp[i] - dp[idx - 1] + MOD) % MOD;
            }

            last_seen[s[i - 1]] = i;
        }

        // Subtract 1 to exclude the empty subsequence
        return (dp[n] + MOD) % MOD;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
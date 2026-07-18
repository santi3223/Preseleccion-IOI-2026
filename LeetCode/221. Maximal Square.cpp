//7 de Julio 2026 18:20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {
        ll n = arr.size(), m = arr[0].size();
        vector<vl> dp(n+5, vl(m+5, 0));
        ll maxx = 0;
        ff(i, 1, n+1){
            ff(j, 1, m+1){
                if(arr[i-1][j-1] == '0') continue;
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                dp[i][j]++;
                maxx = max(maxx, dp[i][j]);
            }
        }
        /*ff(i, 0, n+1){
            ff(j, 0, m+1){
                cout << dp[i][j] << ' ';
            }
            cout << ed;
        }*/
        return maxx*maxx;
    }
};

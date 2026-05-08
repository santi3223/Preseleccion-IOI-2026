//7 de Mayo 2026 13:25
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ll n = nums.size();
        multiset<ll> st;
        ll l = 0, r = k-1;
        ff(i, 0, k) st.insert(nums[i]);
        vector<int> ans;
        while(r < n){
            ans.pb(*st.rbegin());
            st.erase(st.find(nums[l]));
            l++;
            r++;
            if(r < n) st.insert(nums[r]);
        }
        return ans;
    }
};

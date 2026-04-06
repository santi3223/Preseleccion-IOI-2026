//28 de Febrero 2026 22:08
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>

int main(){
	ll n;
	string str;
	cin >> n >> str;
	map<char, ll> amount;
	unordered_set<char> st;
	ff(i, 0, n){
		st.insert(str[i]);
	}
	ll minn = LLONG_MAX;
	ll l = 0, r = 0;
	amount[str[r]]++;
	ll amo = 1;
	while(l < n){
		if(amo == st.size()){
			minn = min(minn, r-l+1);
		}
		if(amo != st.size() && r+1 < n){
			r++;
			amount[str[r]]++;
			if(amount[str[r]] == 1){
				amo++;
			}
		}
		else{
			l++;
			amount[str[l-1]]--;
			if(amount[str[l-1]] == 0){
				amo--;
			}
		}
	}
	cout << minn;
}

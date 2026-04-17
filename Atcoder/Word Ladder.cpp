//23 de Enero 2026 14:55
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	string s, t;
	cin >> s >> t;
	vector<string> ans;
	while(s != t){
		vector<string> arr;
		ff(i, 0, s.size()){
			if(s[i] != t[i]){
				string x = s;
				x[i] = t[i];
				arr.pb(x);
			}
		}
		sort(all(arr));
		s = arr[0];
		ans.pb(s);
	}
	cout << ans.size() << ed;
	ff(i, 0, ans.size()){
		cout << ans[i] << ed;
	}
}

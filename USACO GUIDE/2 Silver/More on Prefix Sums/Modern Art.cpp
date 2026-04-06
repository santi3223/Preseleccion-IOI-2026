//24 de marzo 2026 20:11
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
#define vb vector<bool>
#define ed endl
#define vs vector<string>

struct Bound{
	ll minr, maxr, minc, maxc;
};

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	
	ll n;
	cin >> n;
	vector<vl> arr(n, vl(n));
	map<ll, Bound> mp;
	ff(i, 0, n){
		ff(j, 0, n){
			cin >> arr[i][j];
			if(!mp.count(arr[i][j])) mp[arr[i][j]] = Bound{i, i, j, j};
			Bound &x = mp[arr[i][j]];
			x.minr = min(x.minr, i);
			x.maxr = max(x.maxr, i);
			x.minc = min(x.minc, j);
			x.maxc = max(x.maxc, j);
		}
	}
	mp.erase(0);
	ll ans = n*n-mp.size();
	if(mp.size() > 1){
		vector<vl> rect(n+5, vl(n+5));
		set<ll> valid;
		for(auto &[c, b] : mp){
			valid.insert(c);
			rect[b.minr][b.minc]++;
			rect[b.minr][b.maxc+1]--;
			rect[b.maxr+1][b.minc]--;
			rect[b.maxr+1][b.maxc+1]++;
		}
		ff(i, 0, n){
			ff(j, 0, n){
				if(i > 0) rect[i][j] += rect[i-1][j];
				if(j > 0) rect[i][j] += rect[i][j-1];
				if(i > 0 && j > 0) rect[i][j] -= rect[i-1][j-1];
				if(rect[i][j] > 1) valid.erase(arr[i][j]);
			}
		}
		ans += valid.size();
	}
	cout << ans;
	
}

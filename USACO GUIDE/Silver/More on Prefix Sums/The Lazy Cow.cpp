//11 de marzo 2026 20:11
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
#define ed "\n"
#define vs vector<string>

int main(){
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	vector<vl> inn(n, vl(n));
	ff(i, 0, n){
		ff(j, 0, n){
			cin >> inn[i][j];
		}
	}
	
	ll sz = 2*n-1;
	vector<vl> arr(sz, vl(sz, 0));
	ll id = n-1, jd = 0;
	ff(i, 0, n){
		id = n-1+i;
		jd = i;
		ff(j, 0, n){
			arr[id][jd] = inn[i][j];
			id--;
			jd++;
		}
	}
	
	/*ff(i, 0, sz){
		ff(j, 0, sz){
			cout << arr[i][j] << " ";
		}
		cout << ed;
	}*/
	
	vector<vl> pref(sz, vl(sz, 0));
	ff(i, 0, sz){
		ff(j, 0, sz){
			ll a = 0, b = 0, c = 0, d = arr[i][j];
			if(i-1 >= 0) a = pref[i-1][j];
			if(j-1 >= 0) b = pref[i][j-1];
			if(i-1 >= 0 && j-1 >= 0) c = pref[i-1][j-1];
			pref[i][j] = a+b-c+d;
			
		}
	}
	
	ll maxx = 0;
	ff(i, 0, sz){
		ff(j, 0, sz){
			if(arr[i][j] == 0) continue;
			
			ll a = max(0LL, i-k), b = max(0LL, j-k);
			ll c = min(sz-1, i+k), d = min(sz-1, j+k);
			
			ll q1 = 0, q2 = 0, q3 = 0, q4 = pref[c][d];
			if(a-1 >= 0) q1 = pref[a-1][d];
			if(b-1 >= 0) q2 = pref[c][b-1];
			if(a-1 >= 0 && b-1 >= 0) q3 = pref[a-1][b-1];
			
			//ll p = maxx;
			maxx = max(maxx, q4-q1-q2+q3);
			/*if(p < maxx){
				cout << a << " " << b << " " << c << " " << d << "  " << i << " " << j << ed;
			}*/
			
		}
	}
	cout << maxx;
}

//11 de Julio 2026 14:27
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
 
int main(){
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	vector<vector<char>> ans(n, vector<char>(m));
	ff(i, 0, n) cin >> arr[i];
	string lis = "ABCD";
	ff(i, 0, n){
		ff(j, 0, m){
			char prev = (j-1 >= 0 ? ans[i][j-1] : 'a'), up = (i-1 >= 0 ? ans[i-1][j] : 'a');
			bool ok = false;
			for(auto c : lis){
				if(arr[i][j] != c && up != c && prev != c){
					ok = 1;
					ans[i][j] = c;
					break;
				}
			}
			if(!ok){
				cout << "IMPOSSIBLE";
				return 0;
			}
		}
	}
	ff(i, 0, n){
		ff(j, 0, m){
			cout << ans[i][j];
		}
		cout << ed;
	}
}

//28 de Mayo 2026 15:06
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

ll n, m;
vector<string> arr;
vector<vb> vis;

void flood(ll i, ll j){
	if(i < 0 || j < 0 || i >= n || j >= m) return;
	if(vis[i][j] || arr[i][j] == '#') return;
	vis[i][j] = 1;
	flood(i+1, j);
	flood(i-1, j);
	flood(i, j+1);
	flood(i, j-1);
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll c = 0;
	arr = vs(n);
	vis = vector<vb>(n, vb(m, 0));
	ff(i, 0, n) cin >> arr[i];
	ff(i, 0, n){
		ff(j, 0, m){
			if(arr[i][j] == '.' && !vis[i][j]){
				flood(i, j);
				c++;
			}
		}
	}
	cout << c;
}

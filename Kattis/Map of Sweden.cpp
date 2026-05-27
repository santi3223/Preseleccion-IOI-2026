//26 de Mayo 2026 23:38
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

vector<string> arr;
vector<vb> visited;
ll c = 0, n, m;

void flood(ll i, ll j){
	if(i < 0 || j < 0 || i >= n || j >= m) return;
	if(arr[i][j] == '.') return;
	if(visited[i][j]) return;
	//cout << "C " << i << ' ' << j << ed;
	visited[i][j] = 1;
	c++;
	flood(i-1, j);
	flood(i+1, j);
	flood(i, j-1);
	flood(i, j+1);
}

bool check(ll i, ll j){
	ll q = 0;
	if(i-1 >= 0 && visited[i-1][j]) q++;
	if(j-1 >= 0 && visited[i][j-1]) q++;
	if(i+1 < n && visited[i+1][j]) q++;
	if(j-1 < m && visited[i][j+1]) q++;
	//cout << "Q " << q << ed;
	return q > 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin >> n >> m >> q;
	arr = vector<string>(n);
	visited = vector<vb>(n, vb(m, 0));
	ll si = 0, sj = 0;
	ff(i, 0, n){
		cin >> arr[i];
		ff(j, 0, m){
			if(arr[i][j] == 'S'){
				si = i;
				sj = j;
			}
		}
	}
	arr[si][sj] = '#';
	flood(si, sj);
	cout << c << ed;
	while(q--){
		ll xi, xj;
		cin >> xi >> xj;
		arr[--xi][--xj] = '#';
		if(check(xi, xj)){
			flood(xi, xj);
		}
		cout << c << ed;
	}
	
}

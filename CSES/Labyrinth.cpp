//28 de Mayo 2026 15:03
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

bool check(ll i, ll j){
	if(i < 0 || j < 0 || i >= n || j >= m) return 0;
	if(vis[i][j] || arr[i][j] == '#') return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	arr = vector<string>(n);
	vis = vector<vb>(n, vb(m, 0));
	ll ai = -1, aj = -1;
	ff(i, 0, n){
		cin >> arr[i];
		ff(j, 0, m){
			if(arr[i][j] == 'A'){
				ai = i;
				aj = j;
			}
		}
	}
	vector<vector<char>> dir(n, vc(m, '0'));
	queue<pll> q;
	q.push({ai, aj});
	ll bi = -1, bj = -1;
	vis[ai][aj] = 1;
	while(!q.empty()){
		auto [i, j] = q.front();
		q.pop();
		if(arr[i][j] == 'B'){
			bi = i;
			bj = j;
			break;
		}
		if(check(i-1, j)){
			q.push({i-1, j});
			vis[i-1][j] = 1;
			dir[i-1][j] = 'U';
		}
		if(check(i+1, j)){
			q.push({i+1, j});
			vis[i+1][j] = 1;
			dir[i+1][j] = 'D';
		}
		if(check(i, j-1)){
			q.push({i, j-1});
			vis[i][j-1] = 1;
			dir[i][j-1] = 'L';
		}
		if(check(i, j+1)){
			q.push({i, j+1});
			vis[i][j+1] = 1;
			dir[i][j+1] = 'R';
		}
	}
	/*ff(i, 0, n){
		ff(j, 0, m){
			cout << dir[i][j];
		}
		cout << ed;
	}*/
	if(bi == -1){
		cout << "NO";
		return 0;
	}
	cout << "YES" << ed;
	string ans = "";
	ll i = bi, j = bj;

	while(i != ai || j != aj){
		if(dir[i][j] == 'U'){
			ans += 'U';
			i++;
		}
		else if(dir[i][j] == 'D'){
			ans += 'D';
			i--;
		}
		else if(dir[i][j] == 'L'){
			ans += 'L';
			j++;
		}
		else if(dir[i][j] == 'R'){
			ans += 'R';
			j--;
		}
	}
	reverse(all(ans));
	cout << ans.size() << ed << ans;
}

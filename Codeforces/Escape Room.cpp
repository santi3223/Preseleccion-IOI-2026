//29 de Mayo 2026 17:22
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

const long double PI = acos(-1.0);

int main(){
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	vector<vb> vis(n, vb(m, 0));
	vector<vl> val(n, vl(m, 0));
	ff(i, 0, n) cin >> arr[i];
	ll ci = -1, cj = 0;
	ff(i, 0, n){
		ff(j, 0, m){
			if(arr[i][j] == 'E'){
				ci = i;
				cj = j;
				break;
			}
		}
		if(ci != -1) break;
	}
	queue<pll> q;
	q.push({ci, cj});
	vis[ci][cj] = 1;
	val[ci][cj] = 1;
	while(!q.empty()){
		auto [i, j] = q.front();
		q.pop();
		if(i-1 >= 0 && !vis[i-1][j] && arr[i-1][j] != 'X' && arr[i-1][j] != '#'){
			vis[i-1][j] = 1;
			val[i-1][j] = val[i][j]+1;
			q.push({i-1, j});
		}
		if(j-1 >= 0 && !vis[i][j-1] && arr[i][j-1] != 'X' && arr[i][j-1] != '#'){
			vis[i][j-1] = 1;
			val[i][j-1] = val[i][j]+1;
			q.push({i, j-1});
		}
		if(i+1 < n && !vis[i+1][j] && arr[i+1][j] != 'X' && arr[i+1][j] != '#'){
			vis[i+1][j] = 1;
			val[i+1][j] = val[i][j]+1;
			q.push({i+1, j});
		}
		if(j+1 < m && !vis[i][j+1] && arr[i][j+1] != 'X' && arr[i][j+1] != '#'){
			vis[i][j+1] = 1;
			val[i][j+1] = val[i][j]+1;
			q.push({i, j+1});
		}
	}
	ll qq;
	cin >> qq;
	while(qq--){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		if(arr[a][b] != '.'){
			if(arr[a][b] == '#') cout << 'W';
			else cout << arr[a][b];
		}
		else if(arr[a][b] == '.' && val[a][b] == 0){
			cout << '?';
		}
		else{
			ll minn = val[a][b];
			if(b-1 >= 0 && val[a][b-1] < minn && val[a][b-1] != 0){
				cout << 'L';
			}
			else if(a+1 < n && val[a+1][b] < minn && val[a+1][b] != 0){
				cout << 'D';
			}
			else if(b+1 < m && val[a][b+1] < minn && val[a][b+1] != 0){
				cout << 'R';
			}
			else if(a-1 >= 0 && val[a-1][b] < minn && val[a-1][b] != 0){
				cout << 'U';
			}
		}
		cout << ed;
	}
	
}

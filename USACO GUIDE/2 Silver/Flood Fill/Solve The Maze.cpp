//7 de Marzo 2026 23:11
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
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vector<string> arr(n);
		ll g = 0;
		ff(i, 0, n){
			cin >> arr[i];
			ff(j, 0, m){
				if(arr[i][j] == 'G') g++;
			}
		}
		bool ok = true;
		ff(i, 0, n){
			ff(j, 0, m){
				if(arr[i][j] == 'B'){
					if(i-1 >= 0){
						if(arr[i-1][j] == 'G') ok = false;
						else if(arr[i-1][j] == '.') arr[i-1][j] = '#';
					}
					if(i+1 < n){
						if(arr[i+1][j] == 'G') ok = false;
						else if(arr[i+1][j] == '.') arr[i+1][j] = '#';
					}
					if(j-1 >= 0){
						if(arr[i][j-1] == 'G') ok = false;
						else if(arr[i][j-1] == '.') arr[i][j-1] = '#';
					}
					if(j+1 < m){
						if(arr[i][j+1] == 'G') ok = false;
						else if(arr[i][j+1] == '.') arr[i][j+1] = '#';
					}
				}
			}
		}
		//cout << "A " << ok << ed;
		if(arr[n-1][m-1] == '#' && g != 0) ok = false;
		//cout << "B " << ok << ed;
		
		queue<pll> q;
		map<pll, bool> visited;
		q.push({n-1, m-1});
		visited[{n-1, m-1}] = true;
		if(arr[n-1][m-1] == 'G')g--;
		//cout << "G " << g << ed;
		while(!q.empty()){
			pll cur = q.front();
			q.pop();
			ll x = cur.fi, y = cur.se;
			//cout << x << " " << y << ed;
			if(arr[x][y] == 'G'){
				//cout << "X "<< x << " " << y << ed;
				g--;
			}
			if(x+1 < n && arr[x+1][y] != '#' && !visited[{x+1, y}]){
				visited[{x+1, y}] = true;
				q.push({x+1, y});
			}
			if(x-1 >= 0 && arr[x-1][y] != '#' && !visited[{x-1, y}]){
				visited[{x-1, y}] = true;
				q.push({x-1, y});
			}
			if(y+1 < m && arr[x][y+1] != '#' && !visited[{x, y+1}]){
				visited[{x, y+1}] = true;
				q.push({x, y+1});
			}
			if(y-1 >= 0 && arr[x][y-1] != '#' && !visited[{x, y-1}]){
				visited[{x, y-1}] = true;
				q.push({x, y-1});
			}
				
		}
		//cout << g << ed;
		if(g != 0) ok = false;
		if(ok) cout << "Yes" << ed;
		else cout << "No" << ed;
	}
	
}

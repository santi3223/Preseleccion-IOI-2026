//10 de Abril 2026 22:10
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

ll dist(char a, char b){
	if(a == 'N'){
		if(b == 'N') return 0;
		if(b == 'E') return 1;
		if(b == 'S') return 2;
		if(b == 'W') return 3;
		
	}
	if(a == 'E'){
		if(b == 'N') return 3;
		if(b == 'E') return 0;
		if(b == 'S') return 1;
		if(b == 'W') return 2;
		
	}
	if(a == 'S'){
		if(b == 'N') return 2;
		if(b == 'E') return 3;
		if(b == 'S') return 0;
		if(b == 'W') return 1;
		
	}
	if(a == 'W'){
		if(b == 'N') return 1;
		if(b == 'E') return 2;
		if(b == 'S') return 3;
		if(b == 'W') return 0;
		
	}
	
}

int main(){
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	if(arr[0][0] == 'X'){
		cout << -1;
		return 0;
	}
	vector<vl> dp(n, vl(m, LLONG_MAX));
	dp[0][0] = 0;
	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
	vector<vb> visited(n, vb(m, false));
	pq.push({0, {0, 0}});
	while(!pq.empty()){
		//if(dp[n-1][m-1] != LLONG_MAX) break;
		ll val = pq.top().fi, i = pq.top().se.fi, j = pq.top().se.se;
		pq.pop();
		if(visited[i][j]) continue;
		visited[i][j] = true;
		if(arr[i][j] == 'X') continue;
		dp[i][j] = val;
		if(j+1 < m && dp[i][j]+dist(arr[i][j], 'E') < dp[i][j+1]){
			dp[i][j+1] = dp[i][j]+dist(arr[i][j], 'E');
			pq.push({dp[i][j]+dist(arr[i][j], 'E'), {i, j+1}});
		}
		if(i+1 < n && dp[i][j]+dist(arr[i][j], 'S') < dp[i+1][j]){
			dp[i+1][j] = dp[i][j]+dist(arr[i][j], 'S');
			pq.push({dp[i][j]+dist(arr[i][j], 'S'), {i+1, j}});
		}
		
		if(i-1 >= 0 && dp[i][j]+dist(arr[i][j], 'N') < dp[i-1][j]){
			dp[i-1][j] = dp[i][j]+dist(arr[i][j], 'N');
			pq.push({dp[i][j]+dist(arr[i][j], 'N'), {i-1, j}});
		}
		if(j-1 >= 0 && dp[i][j]+dist(arr[i][j], 'W') < dp[i][j-1]){
			dp[i][j-1] = dp[i][j]+dist(arr[i][j], 'W');
			pq.push({dp[i][j]+dist(arr[i][j], 'W'), {i, j-1}});
		}
	}
	/*ff(i, 0, n){
		ff(j, 0, m){
			cout << dp[i][j] << ' ';
		}
		cout << ed;
	}*/
	if(dp[n-1][m-1] == LLONG_MAX) cout << -1;
	else cout << dp[n-1][m-1];
}

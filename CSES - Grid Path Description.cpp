//3 de Julio 2026 23:33
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
string s;
bool vis[9][9];
ll c = 0;
//o 1 2 3 4
// U D L R
 
void dfs(ll a, ll b, ll c);
 
inline void nxt(ll i, ll j, ll o, ll q){
	if(o == 1){
		if(i-1 >= 0 && !vis[i-1][j]) dfs(i-1, j, q+1);
	}
	if(o == 2){
		if(i+1 < 9 && !vis[i+1][j]) dfs(i+1, j, q+1);
	}
	if(o == 3){
		if(j-1 >= 0 && !vis[i][j-1]) dfs(i, j-1, q+1);
	}
	if(o == 4){
		if(j+1 < 9 && !vis[i][j+1]) dfs(i, j+1, q+1);
	}
}
 
void dfs(ll i, ll j, ll q){
	if(i == 7 && j == 1){
		if(q == 48) c++;
		return;
	}
	if(q == 48) return;
	if(vis[i-1][j] && vis[i+1][j] && !vis[i][j-1] && !vis[i][j+1]) return;
	if(!vis[i-1][j] && !vis[i+1][j] && vis[i][j-1] && vis[i][j+1]) return;
	vis[i][j] = 1;
	
	if(s[q] == '?'){
		     if(!vis[i-1][j] && vis[i+1][j] && vis[i][j-1] && vis[i][j+1]) dfs(i-1, j, q+1);
		else if(vis[i-1][j] && !vis[i+1][j] && vis[i][j-1] && vis[i][j+1]) dfs(i+1, j, q+1);
		else if(vis[i-1][j] && vis[i+1][j] && !vis[i][j-1] && vis[i][j+1]) dfs(i, j-1, q+1);
		else if(vis[i-1][j] && vis[i+1][j] && vis[i][j-1] && !vis[i][j+1]) dfs(i, j+1, q+1);
		else{
			nxt(i, j, 1, q);
			nxt(i, j, 2, q);
			nxt(i, j, 3, q);
			nxt(i, j, 4, q);
		}
	}
	if(s[q] == 'U') nxt(i, j, 1, q);
	if(s[q] == 'D') nxt(i, j, 2, q);
	if(s[q] == 'L') nxt(i, j, 3, q);
	if(s[q] == 'R') nxt(i, j, 4, q);
	
	
	vis[i][j] = 0;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> s;
	ff(i, 0, 9) vis[i][0] = vis[0][i] = vis[8][i] = vis[i][8] = 1;
	dfs(1, 1, 0);
	cout << c;
}

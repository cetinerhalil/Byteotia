/*
    Halil Çetiner
    Data Structures and Algorithms Assignment
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int	n,m,k,t,s;
int	h[200000];
vector<int>	v[200000];

void	dfs( int nod ){
	if( h[nod] )	return;
	h[nod] = 1;
	for( auto i:v[nod] )
		dfs( i );
}

int main(int argc,char** argv){
	
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);

	cin >> n >> m >> k >> t;

	for( int i=1;i<=m;i++ ){
		int	x,y;
		scanf(" %d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int>	Q;
	while( k-- ){
		int	x;
		cin >> x;
		Q.push(x);
		h[x] = 1;
	}
	while( t-- ){
		queue<int>	temp;
		while( Q.size() ){
			int	x = Q.front();
			Q.pop();
			for( auto i:v[x] )
				if( !h[i] ){
					h[i] = 1;
					temp.push( i );
				}
		}
		Q = temp;
	}
	for( int i=1;i<=n;i++ ){
		if( h[i] )	continue;
		dfs( i );
		s++;
	}
	cout << s << endl;
}

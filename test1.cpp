#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include "DirectedGraph.h"
using namespace std;
int main(){
	int n,m,x,y,z,ans1;
	double zz,ans2;
	scanf("%d%d",&n,&m);
	DirectedGraph<int> a(n,m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a.insert(x,y,z);
		}
	ans1 = a.shortestPath(1,3);
	cout<<ans1<<endl; 
	ans1 = a.shortestPath(3,2);
	cout<<ans1<<endl; 
	DirectedGraph<double> b(n,m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lf",&x,&y,&zz);
		b.insert(x,y,zz);
		}
	ans2 = b.shortestPath(1,3);
	cout<<ans2<<endl; 
	ans2 = b.shortestPath(3,2);
	cout<<ans2<<endl; 
	return 0;
	}
/*
5 12
1 2 3
2 1 1
1 5 2
5 1 3
2 5 3
2 3 3
2 4 1
4 2 2
5 4 1
4 3 2
5 3 3
3 5 3
1 2 30000000000.2
2 1 10000000000.2
1 5 2000000000.2
5 1 3000000000.2
2 5 3000000000.2
2 3 3000000000.2
2 4 1000000000.2
4 2 2000000000.2
5 4 1000000000.2
4 3 2000000000.2
5 3 3000000000.2
3 5 3000000000.2
*/

/**
 *	DirectedGraph.h
 *	Purpose: Record a directed graph and provide methods to find and print out
 *			 some properties of the directed graph.
 *	@author Zhili (Jerry) Pan -- sasoripan
 *	@version 1.0 01/20/17
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<typeinfo>
using namespace std;
const int SAFE_LIST = 5;
/** A class which recodes a directed graph */
template<class TYPE>
class DirectedGraph{
	private:
		/** A stucture which recodes the edge */
		struct Edge{
			int from; /**< the start vertice of this edge*/
			int to; /**< the end vertice of this edge*/
			int next; /**< the index of the next edge whose vertice is also
			               "from"*/
			TYPE value; /**< the value of this edge*/
			};
		Edge* graph; /**< the list of all edges in the graoh*/
		int *head; /**< the array records the index of the first edge whose
		                start vertice is the ith. vertice*/
		int nodeNumber; /**< the number of the vertices in this graph*/
		int edgeNumber; /**< the number of the directed edges in this graph*/
		int index; /**< the index of the current edge*/
	public:
		/** Constructor
		 *	@param n the number of nodes of a graph
		 *	@param m the number of edges of a graph, default -1 means don't
		 *	know the exact number
		 *	Dynamic allocate an array of Edge to store all given edges (If the
		 *	exact number is not given, set the number as n*n); Dynamic allocate
		 *	an array of int. The ith. integer means the index of the head of a
		 *	list which records all the index of the edges whose start vertice
		 *	is the No.i vertice. Set all ints in "head" -1 to show the end of 
		 *	the list.
		 */
		DirectedGraph(int n, int m = -1): nodeNumber(n), edgeNumber(m), index(-1){
			if(m == -1) edgeNumber = n*n;
		 	graph =  new Edge [m+SAFE_LIST];
			head = new int [n+SAFE_LIST];
			// Initialize the array to mark the end of a list
			for(int i=0; i<n+SAFE_LIST; i++) head[i] = -1;
			}
		/** Add one edge into the current graph
		 *	@param start the starting vertice of a edge
		 *	@param end the ending vertice of a edge
		 *	@param value the value of a edge
		 */
		void insert(int start, int end, TYPE value); 
		/** Find the length of the shortest path from vertice source to vertive
		 *  destination
		 *  @param source the starting point
		 *  @param destination the ending point
		 *  @return the length of the shortest path from vertice source to
		 *  vertive destination
		 */
		TYPE shortestPath(int source, int destination); 
		
	};
// Add one edge into the current graph
template<class TYPE> void DirectedGraph<TYPE>::insert(int start, int end, TYPE value){
	index++;
	graph[index].from = start; graph[index].to = end; graph[index].value = value;
	graph[index].next = head[start]; head[start] = index;
	}
// Find the length of the shortest path from vertice source to vertive destination
template<class TYPE> TYPE DirectedGraph<TYPE>::shortestPath(int source, int destination){
	TYPE* dis = new TYPE [nodeNumber+SAFE_LIST];
	TYPE ans;
	int* q = new int [nodeNumber+SAFE_LIST];
	bool* inque = new bool [nodeNumber+SAFE_LIST];
	int t=0, w=1, i, fr, nx;
	memset(dis,0x7F,sizeof(TYPE)*(nodeNumber+SAFE_LIST));
	memset(inque,0,sizeof(inque));
	dis[source] = 0; q[t] = source; inque[source]=true;
	while(t!=w){
		fr = q[t]; inque[fr] = false;
		for(i=head[fr]; i!=-1; i=graph[i].next){
			nx = graph[i].to;
			if(graph[i].value + dis[fr] < dis[nx]){
				dis[nx] = graph[i].value + dis[fr];
				if(!inque[nx]){
					q[w]=nx; inque[nx]=true; w=(w+1)%nodeNumber;
					}
				}
			}
		t=(t+1)%nodeNumber;
		}
	ans = dis[destination];
	delete[] dis;
	delete[] q;
	delete[] inque;
	return ans;
	}

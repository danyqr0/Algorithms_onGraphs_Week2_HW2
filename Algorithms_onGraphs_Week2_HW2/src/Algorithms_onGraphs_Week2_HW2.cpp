//============================================================================
// Name        : Algorithms_onGraphs_Week2_HW2.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW2_Week2
// Description : Determining an order of courses in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using std::vector;

//prototypes:
void explore(vector<vector<int> > &adj, vector<bool> &adj_v, int x);
void acyclic(vector<vector<int> > &adj);
void processed(vector<int> &v_processing);
void print_order(vector<int> &order_courses);

//global variables
size_t n, m,num_cycle=0;
bool cycle,sink;
vector<int> order_courses;

void processed(vector<int> &vector_set){
	vector<int>::iterator it;
	for(it=vector_set.begin();it!=vector_set.end();++it)
		cout<<" *it="<<*it<<endl;
}

void print_order(vector<int> &order_courses){
     while(!order_courses.empty()){
        cout<<order_courses.back()+1<<" ";
        order_courses.pop_back();
     }
}

void explore(vector<vector<int> > &adj, vector<int> &v_processing, vector<int> &v_visited,int x){
	vector<int>::iterator it;
	v_processing[x]=x;
	sink=(adj[x].empty()) ? true:false;
	if(sink && v_visited[x]!=x){
	     v_visited[x]=x;
	     v_processing[x]=-1;
	     order_courses.push_back(x);
	}
	else{
	  for(it=adj[x].begin();it!=adj[x].end();it++){
	     cycle=(v_processing[*it]==*it) ? true:false;
         if(!cycle && v_visited[*it]!=*it)
	  	      explore(adj,v_processing,v_visited,*it);
         else if (cycle) num_cycle++;
	     v_processing[x]=-1;
	  	 v_visited[x]=x;
	  }
	  if(v_visited[x]==x)
	  	 order_courses.push_back(x);
   }
}

void acyclic(vector<vector<int> > &adj) {
	vector<int> v_visited(n,-1);
	vector<int> v_processing(n,-1);
    for(int i=0;i<n;i++){
	   if(v_visited[i]!=i)
		   explore(adj,v_processing, v_visited, i);
	}
    if(num_cycle==0)
        print_order(order_courses);
}

int main() {
	  cin >> n >> m;
	  if( (n>=1 && n<=1e5) && (m>=0 && m<=1e5) ){
		  vector<vector<int> > adj(n, vector<int>());
		  for (size_t i = 0; i < m; i++) {
			  int x, y;
			  cin >> x >> y;
			  adj[x - 1].push_back(y - 1);
		  }
		  acyclic(adj);
	  }
	  else
		  cout << 0;
	return 0;
}

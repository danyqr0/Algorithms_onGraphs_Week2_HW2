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
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here
  return order;
}

int main() {
	  size_t n, m;
	  std::cin >> n >> m;
	  vector<vector<int> > adj(n, vector<int>());
	  for (size_t i = 0; i < m; i++) {
	    int x, y;
	    std::cin >> x >> y;
	    adj[x - 1].push_back(y - 1);
	  }
	  vector<int> order = toposort(adj);
	  for (size_t i = 0; i < order.size(); i++) {
	    std::cout << order[i] + 1 << " ";
	  }
	  return 0;
}

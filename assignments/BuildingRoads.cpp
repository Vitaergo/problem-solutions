/*
    PROBLEM: Building Roads (CSES)
    LINK: https://cses.fi/problemset/task/1666 

    We can find all the individual connected components
    and then build roads to connect them  
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> cities(m);

    //input 
    for (auto& i : cities) {
        cin >> i.first >> i.second;
        // zero index 
        i.first--;
        i.second--;
    }

    // adj matrix 
    vector<vector<int>>adj(n);
    for (auto city : cities) {
        adj[city.first].push_back(city.second);
        adj[city.second].push_back(city.first);
        
    }

    vector<int> connected_cities; // we will add new roads to connect these cities 
    vector<bool> visited (n, false); // cities that have been visited 
 
    for (int i = 0; i < n; i++) {
        // if the city hasn't been visited, it will be part
        // of a new connected component
        if (!visited[i]) {

            visited[i] = true; // you can always visit the city itself
            connected_cities.push_back(i+1); // a new city connection
            stack<int> todo;
            todo.push(i);

            while(!todo.empty()) {
                int curr = todo.top();
                todo.pop();
                for (auto j : adj[curr]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        todo.push(j); 
                    }
                }
            }
        }

    }
    
    // number of new roads = # of connected components - 1 
    int num_new_roads = connected_cities.size() - 1;
    cout << num_new_roads << '\n';
    for (int i = 0; i < num_new_roads; i++) {
      cout << connected_cities[i] << " " << connected_cities[i + 1] << '\n';
    }
}
# ifndef GRAPH_H
# define GRAPH_H

# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <vector>
# include <queue>
# include <utility>

// T -> Vertices

template <typename T> class Graph {
private:
    bool directed = false;
    bool weighted = false;
    int vertices = 0;

    std::unordered_map<T, std::vector<std::pair<T, int>>> adjList;

    void DFS(T s, std::unordered_set<T>& visited, bool print = true);

public:
    Graph(bool d = false, bool w = false);

    void addVertex(T v);

    void addEdge(T u, T v, int W = 0);

    void print();

    void DFS(T s);

    ///DFS(T s, std::unordered_set<T>& visited, bool print = true);

    void DFSComplete();

    void BFS(T s);

    void BFSComplete();

    void BFS(T s, std::unordered_set<T>& visited);

    /*
    Weighted Graph
    No Negative Weight
    Calculates the shortest to all Vertices from source.
    */
    void dijkstra(T s);

    int connectedComponents();

    // For Unweighted Graph
    void shortestPathBFS(T s, T e);

    void topSortHelper(std::unordered_set<T>& visited, T s, int& i, std::unordered_map<T, int>& res);

    // Works for only Directed Graph with no Cycle
    std::unordered_map<T, int> topSort();

    // Single Source Shortes Path
    // Can be used with negative cycles
    // O(E.V)
    void bellmanFord(T s);

};

// For Priority Queue
template <typename T> class Compare {
public:
    bool operator() (std::pair<T, int> p1, std::pair<T, int> p2);

};

template <typename T>
bool Compare<T>::operator() (std::pair<T, int> p1, std::pair<T, int> p2) {
    return p1.second > p2.second;
}




template <typename T>
Graph<T>::Graph(bool d, bool w) {directed = d; weighted = w;}

template <typename T>
void Graph<T>::addVertex(T v) {adjList[v] = {}; vertices++;}

template <typename T>
void Graph<T>::addEdge(T u, T v, int W) {
    adjList[u].push_back( std::make_pair(v, W) );
    if(!directed) {adjList[v].push_back( std::make_pair(u, W) );}
}

template <typename T>
void Graph<T>::print() {
    for(auto [u, V]: adjList) {
        std::cout << u << ": ";
        for(std::pair<T, int> p: V) {
            if(weighted) {
                std::cout << "{ " << p.first << ", " << p.second << " } ";
            }
            else {
                std::cout << p.first << ' ';
            }
        }
        std::cout << '\n';
    }
} 

template <typename T>
void Graph<T>::DFS(T s) {
    std::unordered_set<T> visited;
    DFS(s, visited);
    std::cout << '\n';
}

template <typename T>
void Graph<T>::DFS(T s, std::unordered_set<T>& visited, bool print) {
    visited.insert(s);
    if(print) {std::cout << s << ' ';}
    

    for(std::pair<T, int> p: adjList[s]) {
        if(visited.find(p.first) == visited.end()) {
            DFS(p.first, visited, print);
        }
    }

}

template <typename T>
void Graph<T>::DFSComplete() {
    std::unordered_set<T> visited;

    for (auto [u, V]: adjList) {
        for(std::pair<T, int> p: V) {
            if(visited.find(p.first) == visited.end()) {
                DFS(p.first, visited);
            }
        }
        
    }

    std::cout << '\n';

}

template <typename T>
void Graph<T>::BFS(T s) {
    std::unordered_set<T> visited;
    std::queue<T> q;
    q.push(s);
    while(!q.empty()) {
        T curr = q.front();
        q.pop();
        visited.insert(curr);
        std::cout << curr << ' ';

        for(std::pair<T, int> p: adjList[curr]) {
            if(visited.find(p.first) == visited.end()) {q.push(p.first);}
        }

    }
    std::cout << '\n';
}

// For Complete BFS
template <typename T>
void Graph<T>::BFS(T s, std::unordered_set<T>& visited) {
    std::queue<T> q;
    q.push(s);
    visited.insert(s);
    while(!q.empty()) {
        T curr = q.front();
        q.pop();
        visited.insert(curr);
        std::cout << curr << ' ';

        for(std::pair<T, int> p: adjList[curr]) {
            if(visited.find(p.first) == visited.end()) {q.push(p.first); visited.insert(p.first);}
        }

    }
}

template <typename T>
void Graph<T>::BFSComplete() {
    std::unordered_set<T> visited;
    //queue<T> q;

    for(auto [u, V]: adjList) {
        if(visited.find(u) == visited.end()) {BFS(u, visited);}

    }

    std::cout << '\n';

} 

template <typename T>
int Graph<T>::connectedComponents() {
    int count = 0;

    std::unordered_set<T> visited;
    for(auto [k, v]: adjList) {
        if(visited.find(k) == visited.end()) {
            count++;
            DFS(k, visited, false);
        }
    }

    return count;
}

template <typename T>
void Graph<T>::dijkstra(T s) {
    if(!weighted) {
        std::cout << "Dijkstra not applicable on unweighted graph.\n";
        return;
    }

        std::unordered_map<T, int> dist;
        for(auto [k, v]: adjList) {dist[k] = INT_MAX;}

        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, Compare<T> > pq;
        dist[s] = 0;
        pq.push( std::make_pair(s, 0) );

        T u, v;
        int w, d;
        while(!pq.empty()) {
            u = pq.top().first;
            d = pq.top().second;
            pq.pop();

            for(std::pair<T, int> p: adjList[u]) {
                v = p.first;
                w = p.second;
                if( dist[v] > d + w ) {
                    dist[v] = d + w;
                    pq.push( std::make_pair(v, dist[v]) );
                }
            }

        }

        std::cout << "Shortest Path\n";
        for(auto [k, v]: dist) {
            std::cout << k << ": " << v << '\n';
        }
}

template <typename T>
void Graph<T>::shortestPathBFS(T s, T e) {
    std::unordered_map<T, T> parent;
    std::unordered_set<T> visited;

    parent[s] = s;
    std::queue<T> q;
    q.push(s);
    visited.insert(s);
    T curr, next;

    while(!q.empty()) {
        curr = q.front();
        q.pop();
        if(curr == e) {break;}

        for(std::pair<T, int> p: adjList[curr]) {
            next = p.first;
            if(visited.find(next) == visited.end()) {
                q.push(next);
                visited.insert(next);
                parent[next] = curr;
            }
        }
    }

    if(parent.find(e) != parent.end()) {
        std::vector<T> path;
        T curr = e;
        while(true) {
            path.push_back(curr);
            if(curr == parent[curr]) {break;}
            curr = parent[curr];
        }

        for(int i = path.size() - 1; i >= 0; i--) {
            std::cout << path[i] << ' ';
        }
        std::cout << '\n';

    }
    else {
        std::cout << "Path Doesn't Exist\n";
    }

}

template <typename T>
void Graph<T>::topSortHelper(std::unordered_set<T>& visited, T s, int& i, std::unordered_map<T, int>& res) {
    visited.insert(s);
    for(auto p: adjList[s]) {
        if(visited.find(p.first) == visited.end()) {
            topSortHelper(visited, p.first, i, res);
        }
    }
    res[s] = i--;
}

template <typename T>
std::unordered_map<T, int> Graph<T>::topSort() {
    int i = vertices - 1;
    std::unordered_map<T, int> result;
    std::unordered_set<T> visited;

    for(auto [k, v]: adjList) {
        if(visited.find(k) == visited.end()) {
            topSortHelper(visited, k, i, result);
        }
    }

    return result;

}

template <typename T>
void Graph<T>::bellmanFord(T s) {
    std::unordered_map<T, int> dist;
    for(auto [k, v]: adjList) {
        dist[k] = INT_MAX;
    }
    dist[s] = 0;

    for(int i = 0; i < vertices - 1; i++) {
        for(auto [k, v]: adjList) {
            if(dist[k] == INT_MAX) {continue;}
            for(std::pair<T, int> p: v) {
                int newDist = dist[k] + p.second;
                if(newDist < dist[p.first]) {
                    dist[p.first] = newDist;
                }
            }
        }
    }

    for(int i = 0; i < vertices - 1; i++) {
        for(auto [k, v]: adjList) {
            if(dist[k] == INT_MAX) {continue;}
            for(std::pair<T, int> p: v) {
                int newDist = dist[k] + p.second;
                if(newDist < dist[p.first]) {
                    dist[p.first] = INT_MIN;
                }
            }
        }
    }

    std::cout << "Shortest Distance\n";
    for(auto [k, v]: adjList) {
        std::cout << k << ": " << dist[k] << '\n';
    }

}

# endif
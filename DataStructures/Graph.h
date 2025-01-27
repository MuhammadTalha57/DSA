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

    void DFS(T s, std::unordered_set<T>& visited);

public:
    Graph(bool d = false, bool w = false);

    void addVertex(T v);

    void addEdge(T u, T v, int W = 0);

    void print();

    void DFS(T s);

    void DFSComplete();

    void BFS(T s);

    void BFSComplete();

    void BFS(T s, std::unordered_set<T>& visited);

};

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
void Graph<T>::DFS(T s, std::unordered_set<T>& visited) {
    visited.insert(s);
    std::cout << s << ' ';

    for(std::pair<T, int> p: adjList[s]) {
        if(visited.find(p.first) == visited.end()) {
            DFS(p.first, visited);
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
    while(!q.empty()) {
        T curr = q.front();
        q.pop();
        visited.insert(curr);
        std::cout << curr << ' ';

        for(std::pair<T, int> p: adjList[curr]) {
            if(visited.find(p.first) == visited.end()) {q.push(p.first);}
        }

    }
}

template <typename T>
void Graph<T>::BFSComplete() {
    std::unordered_set<T> visited;
    //queue<T> q;

    for(auto [u, V]: adjList) {
        for(std::pair<T, int> p: V) {
            if(visited.find(p.first) == visited.end()) {BFS(p.first, visited);}
        }
        
    }
    std::cout << '\n';

} 

# endif
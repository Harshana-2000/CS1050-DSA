#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Graph {
    unordered_map<int, vector<pair<int, int>>> graph;

    void addEdge(int vertex1, int vertex2, int edgeWeight) {
        graph[vertex1].emplace_back(vertex2, edgeWeight);
        graph[vertex2].emplace_back(vertex1, edgeWeight);
    }

    unordered_map<int, vector<pair<int, int>>> prim(int vertex) {
        unordered_map<int, vector<pair<int, int>>> mst;
        vector<bool> visited(graph.size(), false);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.emplace(0, make_pair(vertex, vertex));

        while (!pq.empty()) {
            int current_vertex = pq.top().second.first;
            int current_weight = pq.top().first;
            int source_vertex = pq.top().second.second;
            pq.pop();

            if (visited[current_vertex]) continue;

            visited[current_vertex] = true;

            if (current_vertex != vertex) {
                mst[source_vertex].push_back({current_vertex, current_weight});
                mst[current_vertex].push_back({source_vertex, current_weight});
            }

            for (const auto& neighbor : graph[current_vertex]) {
                int neighbor_vertex = neighbor.first;
                int neighbor_weight = neighbor.second;

                if (!visited[neighbor_vertex]) {
                    pq.emplace(neighbor_weight, make_pair(neighbor_vertex, current_vertex));

                }
            }
        }

        return mst;
    }

    void printMst(int vertex) {

        unordered_map<int, vector<pair<int, int>>> mst = prim(vertex);

        cout << "   |\t0  |\t1  |\t2  |\t3  |\t4  |\t5  |" << endl;
        cout << "----------------------------------------------------" << endl ;
        for (int i = 0; i < 6; i++) {
            cout << i << ": |\t";
            vector<pair<int, int>> neighbors = mst[i];
            for (int j = 0; j < 6; j++) {
                if (j == i)
                    cout << "-  |\t";
                else {
                    bool found = false;
                    for (const auto& neighbor : neighbors) {
                        if (neighbor.first == j) {
                            cout << "" <<neighbor.second << "  |\t";
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "-  |\t";
                }
            }
            cout << endl;
            cout << "----------------------------------------------------" << endl ;
        }
    }

};

int main() {
    Graph g;
    g.addEdge(0, 1, 3);
    g.addEdge(0, 5, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 10);
    g.addEdge(2, 5, 5);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 4);

    g.printMst(0);

    return 0;
}








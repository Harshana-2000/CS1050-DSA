#include <iostream>
#include <vector>
#include <queue>

#define INF 999

using namespace std;

struct City {
    int num;
    double averageTime;
    vector<int> shortTime;
    vector<vector<int>> paths;

    void calculate_average_time() {
        averageTime = 0.0;
        for (int i = 0; i < shortTime.size(); i++) {
            if (num == i) continue;
            averageTime += shortTime[i];
        }
        averageTime = averageTime / (shortTime.size() - 1);
    }

    void printDetails() {
        cout << "City " << num << endl;
        for (int i = 0; i < shortTime.size(); i++) {
            if(num == i) continue ;
            cout << "Time for city " << num << " to city " << i << " = " << shortTime[i] << endl;
            cout << "Path: " << num;
            for (int city : paths[i]) {
                cout << "->" << city;
            }
            cout << endl;
        }
    }
};

City dijkstra(const vector<vector<int>>& graph, int source) {
    int num_node = graph.size();

    vector<int> shortTime(num_node, INF);
    vector<vector<int>> paths(num_node);
    for (int& i : shortTime) {
        i = INF;
    }
    shortTime[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > shortTime[current])
            continue;

        for (int neighbour = 0; neighbour < num_node; neighbour++) {
            int weight = graph[current][neighbour];

            if (weight > 0 && shortTime[current] + weight < shortTime[neighbour]) {
                shortTime[neighbour] = shortTime[current] + weight;
                pq.push({shortTime[neighbour], neighbour});
                paths[neighbour] = paths[current];
                paths[neighbour].push_back(neighbour);
            }
        }
    }

    City city;
    city.num = source;
    city.shortTime = shortTime;
    city.paths = paths;
    city.calculate_average_time();

    return city;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int num_nodes = graph.size();

    City city = dijkstra(graph, 6);
    city.printDetails();
    cout << "Average time for city " << city.num << " = " << city.averageTime << endl;

    return 0;
}



#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int NO_PATH_FOUND = -1;

vector < vector < bool > > removeShortestPaths(
    const vector < vector < short > > parentsTrace,
    const int destination
) {
    const int vertices = parentsTrace.size();
    queue < short > bfsQueue;
    vector < bool > visited(vertices, false);
    vector < vector < bool > > removed(
        vertices,
        vector < bool >(vertices, false)
    ); // removed[i][j] : whether the edge from `i` to `j` has been removed
    int current;

    bfsQueue.push(destination);
    while (!bfsQueue.empty()) {
        current = bfsQueue.front();
        bfsQueue.pop();

        for (auto parent : parentsTrace[current]) {
            removed[parent][current] = true;
            if (!visited[parent]) {
                visited[parent] = true;
                bfsQueue.push(parent);
            }
        }
    }

    return removed;
}

typedef struct {
    int shortestDistance;
    vector < vector < short > > parentsTrace;
} _dijkstraResult;

_dijkstraResult dijkstra(
    const vector < vector < pair < short, int > > > graph,
    const int start,
    const int destination,
    const vector < vector < bool > > removed
) {
    const int vertices = graph.size();
    vector < int > distanceTo(vertices, INT_MAX);
    priority_queue <
        pair < int, short >,
        vector < pair < int, short > >,
        greater < pair < int, short > >
    > minHeap; // pair of < DISTANCE, VERTICE >
    vector < vector < short > > parentsTrace(vertices);
    int currentVertice, newDistance, queuedDistance;

    distanceTo[start] = 0;
    minHeap.push(make_pair(0, start));

    while (!minHeap.empty()) {
        queuedDistance = minHeap.top().first;
        currentVertice = minHeap.top().second;
        minHeap.pop();

        if (queuedDistance > distanceTo[currentVertice]) {
            continue;
        }
        for (auto adjacent : graph[currentVertice]) {
            short& adjacentVertice = adjacent.first;
            int& adjacentEdge = adjacent.second;

            if (!removed.empty() && removed[currentVertice][adjacentVertice]) {
                continue;
            }
            newDistance = distanceTo[currentVertice] + adjacentEdge;
            if (newDistance >= distanceTo[adjacentVertice]) {
                // Save all parents tracing back to shortest paths
                if (newDistance == distanceTo[adjacentVertice]) {
                    parentsTrace[adjacentVertice].push_back(currentVertice);
                }
                continue;
            }
            // New shortest path found
            distanceTo[adjacentVertice] = newDistance;
            parentsTrace[adjacentVertice] = vector < short >(1, currentVertice);
            minHeap.push(make_pair(newDistance, adjacentVertice));
        }
    }

    _dijkstraResult result = {
        (distanceTo[destination] == INT_MAX ? NO_PATH_FOUND : distanceTo[destination]),
        parentsTrace
    };
    return result;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int vertices, edges, start, destination;
    int vertice1, vertice2, distance;
    vector < vector < pair < short, int > > > graph;
    _dijkstraResult result;
    vector < vector < bool > > removed;

    cin >> vertices >> edges;
    while (vertices != 0 && edges != 0) {
        graph.resize(vertices);
        cin >> start >> destination;
        while (edges--) {
            cin >> vertice1 >> vertice2 >> distance;
            // construct graph with adjacency list
            graph[vertice1].push_back(make_pair(vertice2, distance));
        }

        // 1. Run Dijkstra once
        result = dijkstra(graph, start, destination, removed);
        if (result.shortestDistance != NO_PATH_FOUND) {
            // 2. Mark edges of shortest paths as removed
            removed = removeShortestPaths(result.parentsTrace, destination);
            // 3. Run Dijkstra again
            result = dijkstra(graph, start, destination, removed);
        }

        cout << result.shortestDistance << '\n';
        graph.clear();
        removed.clear();
        cin >> vertices >> edges;
    }

    return 0;
}

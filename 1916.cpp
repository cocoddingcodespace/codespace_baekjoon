#define INF 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int start, dest;
int n, m;
vector<pair<int, int>> city[1001];

int dijkstra() {
    int dist[1001];

    for (int i = 0; i <= n; i++) {
        dist[i] = INT32_MAX;
    }

    priority_queue<pair<int, int>> pq;

    dist[start] = 0;

    pq.push({0, start});

    while(!pq.empty()) {
        int current = pq.top().second;
        int current_distance = -pq.top().first;

        pq.pop();

        if (dist[current] < current_distance) continue;

        for (int i = 0; i < city[current].size(); i++) {
            int next = city[current][i].second;
            int next_distance = current_distance + city[current][i].first;

            if (dist[next] > next_distance) {
                dist[next] = next_distance;

                pq.push({-next_distance, next});
            }
        }
    }

    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int d;
        cin >> start >> dest >> d;

        city[start].push_back({d, dest});
    }

    cin >> start >> dest;

    cout << dijkstra() << endl;

    return 0;
}
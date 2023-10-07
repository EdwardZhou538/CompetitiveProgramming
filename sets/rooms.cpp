#include <bits/stdc++.h>

using namespace std;
int main() {
    //freopen("rooms.in", "r", stdin);

    int n; cin >> n;
    pair<int, int> arrivals[n];
    for (int i = 0; i < n; i++) {
        cin >> arrivals[i].first >> arrivals[i].second;
    }
    sort(arrivals, arrivals + n);
    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>> > departures;

    int num_rooms = 0;
    int idx = 0;
    int rooms[n];
    priority_queue<int, vector<int>, greater<int> > available_rooms;
    while (idx < n) {
        if (departures.empty()) {
            if (!available_rooms.empty()) {
                departures.push({arrivals[idx].second, available_rooms.top()});
                rooms[idx] = available_rooms.top();
                available_rooms.pop();
            }
            else {
                departures.push({arrivals[idx].second, 1});
                rooms[idx] = 1;
            }
            idx++;
            if (idx == n) {
                num_rooms = max(num_rooms, 1);
                break;
            }
        }
        
        while(arrivals[idx].first <= departures.top().first) {
            if (available_rooms.empty()) {
                rooms[idx] = departures.size() + 1;
                departures.push({arrivals[idx].second, rooms[idx]});
            }
            else {
                rooms[idx] = available_rooms.top();
                available_rooms.pop();
            }
            idx++;
            if (idx == n) break;
        }
        available_rooms.push(departures.top().second);
        departures.pop();

    }
    for (int i = 0; i < n; i++) num_rooms = max(num_rooms, rooms[i]);
    cout << num_rooms << endl;
    for (int i = 0; i < n; i++) cout << rooms[i] << " ";
    return 0;
}
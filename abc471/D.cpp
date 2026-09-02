#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll queryCount, maxVoltage;
  cin >> queryCount >> maxVoltage;

  priority_queue<ll, vector<ll>> chargeQueue;

  for (ll i = 0; i < queryCount; ++i) {
    ll queryType;
    cin >> queryType;

    if (queryType == 1) {
      ll insertionTime, initialVoltage;
      cin >> insertionTime >> initialVoltage;

      /*Neat trick: v₀ + (T - t₀) becomes (v₀ - t₀) + T*/
      chargeQueue.push(initialVoltage - insertionTime);
    } else {
      ll currentTime;
      cin >> currentTime;

      if (chargeQueue.empty())
        cout << "-1\n";
      else {
        ll maxStoredOffset = chargeQueue.top();
        chargeQueue.pop();

        ll answer = min(maxStoredOffset + currentTime, maxVoltage);
        cout << answer << endl;
      }
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

struct Node {
  ll data;
  Node *next;
  Node *prev;

  Node() : data(0), next(nullptr), prev(nullptr) {};
  Node(ll x, Node *next, Node *prev) : data(x), next(next), prev(prev) {};
  Node(ll x) : data(x), next(nullptr), prev(nullptr) {};
};

void print_ll(Node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  Node *head = nullptr;
  Node *tail = nullptr;
  vector<Node *> pos(n + 1, nullptr);

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    Node *node = new Node(x);

    if (head == nullptr)
      head = tail = node;
    else {
      node->prev = tail;
      tail->next = node;
      tail = node;
    }

    /*stores the address of the actual data of x*/
    pos[x] = node;
  }

  for (int i = 0; i < q; i++) {
    ll a;
    cin >> a;
    /*
     * 1. Search the number in the ll
     * 2. remove it from it pos
     * 3. add to the end and update the required pointers*/

    Node *curr = pos[a];

    if (curr == tail)
      continue;

    if (curr == head) {
      /*data at head*/
      head = curr->next;
      if (head)
        head->prev = nullptr;
    } else {
      /*deleting that node*/
      curr->prev->next = curr->next;
      if (curr->next)
        curr->next->prev = curr->prev;
    }
    /*need to insert at the end*/
    curr->next = nullptr;
    curr->prev = tail;

    if (tail)
      tail->next = curr;

    tail = curr;
    if (!head)
      head = curr;
  }

  print_ll(head);
  /*Cleanup*/
  Node *curr = head;
  while (curr) {
    Node *next = curr->next;
    delete curr;
    curr = next;
  }
  return 0;
}

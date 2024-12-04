#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

struct Node {
  Node* parent;
  Node* left;
  Node* right;
  int value;
  Node(const int& value = 0) : value(value) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
};

Node* root = new Node();

void insertNode(Node* node) {
  int v = node->value;
  Node *par;
  Node *nex = root;

  while(nex) {
    par = nex;
    if(v <= par->value) {
      nex = par->left;
    } else {
      nex = par->right;
    }
  }

  if (v <= par->value) {
    node->parent = par;
    par->left = node;
  } else {
    node->parent = par;
    par->right = node;
  }

  return;
}

bool findNode(int v) {
  Node *current = root;

  while(current) {
    if (current->value == v) {
      return true;
    }
    if (v <= current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return false;
}

Node* min_node(Node *node) {
  if(node->left) {
    return min_node(node->left);
  } else {
    return node;
  }
}

bool deleteNode(int v) {
  Node *current = root;

  while(current) {
    if (current->value == v) {
      break;
    }
    if (v <= current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  if (current == nullptr) {
    return false;
  }

  if (current->left && current->right) {
    int nextKey = min_node(current->right)->value;
    deleteNode(nextKey);
    current->value = nextKey;
  } else {
    Node *par = current->parent;
    Node *ch = nullptr;
    if (current->left) {
      ch = current->left;
    }
    if (current->right) {
      ch = current->right;
    }
    if (ch) {
      ch->parent = par;
    }
    if (par->left == current) {
      par->left = ch;
    }
    if (par->right == current) {
      par->right = ch;
    }
    delete current;
  }
  return true;
}

int main() {
  int Q;
  cin >> Q;

  rep(i, Q) {
    int t, v;
    cin >> t >> v;

    if (t == 0) {
      Node *node = new Node(v);
      insertNode(node);
    } else if(t == 1) {
      if(findNode(v)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      if(deleteNode(v)) {
        cout << "Complete" << endl;
      } else {
        cout << "Error" << endl;
      }
    }
  }
  return 0;
}

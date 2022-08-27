#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *parent = nullptr;
    Node *child = nullptr;
    Node(int x): val(x) {}
};

void insert(Node **minNode, int val) {
    Node node(val);
    Node head = *minNode;
    node.next = head->next;
    node.prev = head;
    head->next = &node;
    if (head->val > val)
        minNode = &&node;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

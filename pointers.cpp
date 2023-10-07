#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

int main() {
    node *head = new node;
    node *second = new node;
    node *third = new node;

    head->data = 4;

    head->next = second;
    second->data = 6;
    cout << head->next->data << endl;

    head->next = third;
    third->data = 15;
    cout << head->next->data << endl;

    delete head;
    delete second;
    delete third;

    return 0;
}
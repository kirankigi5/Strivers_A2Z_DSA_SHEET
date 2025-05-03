#include <bits/stdc++.h>

using namespace std;

class Node
// struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // can have multiple constructors as well
    // constrcutor is a special type of member function which is used to initialise the objects of the class
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    Node *z = new Node(arr[1]);
    Node *y = new Node(arr[0], z);

    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl << endl;

    cout << z << endl;
    cout << z->data << endl;
    cout << z->next << endl << endl;

   

    return 0;
}
#include <iostream>
#include <limits>

using namespace std;

// Creating node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Creating linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Inserting node at the beginning of the linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Inserting node at the end of the linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Inserting node at the given position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1" << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position is out of range" << endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Displaying the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList list;
    list.insertAtBeginning(200);
    list.insertAtBeginning(100);
    list.insertAtEnd(300);
    list.insertAtPosition(400, 2);
    list.insertAtBeginning(50);
    list.display();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// This is an input class. Do not edit.

class LinkedList {
    struct node {
        int value;
        node* next;

        node() : value(0), next(NULL) {}
        node(int _val) : value(_val), next(NULL) {}
    };

    int length;
    node* head;
    node* tail;
    int termination = -100;
    node* newnode(int val) { return new node(val); }

   public:
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }

    LinkedList(int val) {
        this->head = this->tail = this->newnode(val);
        this->length = 1;
    }

    LinkedList(vector<int> arr) {
        if (arr.size() > 0) {
            this->head = this->newnode(arr[0]);
            node* holder = this->head;
            for (int i = 1; i < arr.size() - 1; i++) {
                node* temp = this->newnode(arr[i]);
                holder->next = temp;
                holder = holder->next;
            }
            if (arr.size() > 1) {
                node* temp = this->newnode(arr[arr.size() - 1]);
                holder->next = temp;
                this->tail = holder->next;
            } else {
                this->tail = this->head;
            }
            this->length = arr.size();
        } else {
            LinkedList();
        }
    }

    void insertAtFront(int val) {
        node* temp = this->newnode(val);
        if (!this->head) {
            this->head = temp;
            this->tail = temp;
            this->length++;
            return;
        }
        temp->next = this->head;
        this->head = temp;
        this->length++;
    }

    void insertAtBack(int val) {
        node* temp = this->newnode(val);
        if (!this->head) {
            this->head = temp;
            this->tail = temp;
            this->length++;
            return;
        }

        this->tail->next = temp;
        this->tail = this->tail->next;
        this->length++;
    }

    void insertAtIndex(int idx, int val) {
        if (idx >= this->length) {
            return this->insertAtBack(val);
        } else if (idx <= 0) {
            return this->insertAtFront(val);
        }
        node* temp = this->head;

        int i = 0;
        while (i < idx - 1) {
            temp = temp->next;
            i++;
        }

        node* new_node = this->newnode(val);
        new_node->next = temp->next;
        temp->next = new_node;
        this->length++;
    }

    void removeHead() {
        if (!this->head) {
            cout << "can`t remove from empty list\n\n";
            return;
        }
        this->head = this->head->next;
        this->length--;
    }

    void removeTail() {
        if (!this->head) {
            cout << "can`t remove from empty list\n\n";
            return;
        }
        if (!this->head->next) {
            this->head = NULL;
            this->tail = NULL;
            this->length--;
            return;
        }

        node* temp = this->head;
        while (temp->next->next) {
            temp = temp->next;
        }
        this->tail = temp;
        temp->next = NULL;
        this->length--;
    }

    void removeAtIndex(int ind) {
        if (!this->head) {
            cout << "can`t remove from  empty list \n";
            return;
        } else if (ind >= this->length) {
            return this->removeTail();
        } else if (ind <= 0) {
            return this->removeHead();
        }

        node* temp = this->head;
        int i = 0;
        while (i < ind - 1) {
            temp = temp->next;
            i++;
        }

        temp->next = temp->next->next;
        if (!temp->next) this->tail = temp;
        this->length--;
    }

    void pushFront(int val) { return this->insertAtFront(val); }

    void pushBack(int val) { return this->insertAtBack(val); }

    void popRont() { return this->removeHead(); }

    void popBack() { return this->removeTail(); }

    int front() {
        if (this->length > 0)
            return this->head->value;
        else
            return -1;
    }

    int back() {
        if (this->length > 0)
            return this->tail->value;
        else
            return -1;
    }

    int At(int idx) {
        if (idx <= 0)
            return this->front();
        else if (idx >= this->length - 1)
            return this->back();

        node* temp = this->head;
        int i = 0;

        while (i < idx) {
			temp = temp->next;
			i++;
        }

		return temp->value;
    }

    void printLinkedList() {
        node* temp = this->head;

        if (this->head)
            cout << "Linked List : ";
        else
            cout << "Linked List is Empyty";
        for (int i = 0; i < this->length; i++) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        if (this->head) cout << "NULL \n";
        if (this->length > 0) {
            cout << "\nHead : " << this->head->value << "\n";
            cout << "Tail : " << this->tail->value << "\n";
            cout << "Length : " << this->length << "\n";
        }
        cout << "\n\n";
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList* list = new LinkedList(arr);

    list->printLinkedList();
    return 0;
}
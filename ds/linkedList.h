#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int currentSize;

public:
    LinkedList() : head(nullptr), currentSize(0) {}

    // Destructor to clean up all nodes
    ~LinkedList() {
        clear();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        currentSize = 0;
    }

    // Insert at the end of the list
    void insert(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        currentSize++;
    }

    int size() const { return currentSize; }

    // --- Iterator Class to enable for(auto& x : list) ---
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        Iterator& operator++() { // Prefix increment
            if (current) current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        T& operator*() {
            return current->data;
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    Iterator begin() const {return Iterator(head); }
    Iterator end() const {return Iterator(nullptr); }
};

#endif
#include <bits/stdc++.h>
using namespace std;
template<class T>
class Node {
public:
    T e;
    Node *next;

    Node(T e, Node *next) : e(e), next(next) {
    }

    Node(T e) : e(e), next(NULL) {
    }
    
    Node() : next(NULL) {
    }
};

template<class T>
class LinkedList {
private:
    Node<T> *head;
    int size;
public:
    class Range {
    };

    class Empty {
    };

    LinkedList() {
        head = new Node<T>();
	size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void add(int index, T e) {
        if (index < 0 || index > size) {
            throw Range();
        }
        Node<T> *prev = head;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        prev->next = new Node<T>(e, prev->next);
        size++;
    }

    void addFirst(T e) {
        add(0, e);
    }

    void addLast(T e) {
        add(size, e);
    }

    T get(int index) {
        if (size == 0) {
            throw Empty();
        }
        if (index < 0 || index >= size) {
            throw Range();
        }
        Node<T> *cur = head->next;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->e;
    }

    T getFirst() {
        return get(0);
    }

    T getLast() {
        return get(size - 1);
    }

    void set(int index, T e) {
        if (size == 0) {
            throw Empty();
        }
        if (index < 0 || index >= size) {
            throw Range();
        }
        Node<T> *cur = head->next;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->e = e;
    }

    void setFirst(T e) {
        set(0, e);
    }

    void setLast(T e) {
        set(size - 1, e);
    }

    T remove(int index) {
        if (index < 0 || index >= size) {
            throw Range();
        }
        if (size == 0) {
            throw Empty();
        }
        Node<T> *prev = head;
        for (int i = 0; i < index; ++i) {
            prev = prev -> next;
        }
        Node<T> *retNode = prev -> next;
        prev -> next = retNode -> next;
        retNode -> next = NULL;
        size--;
        return retNode -> e;
    }

    T removeFirst() {
        return remove(0);
    }

    T removeLast() {
        return remove(size - 1);
    }

    void removeElement(T e) {
        Node<T> *prev = head;
        while (prev -> next != NULL) {
            if (prev -> next -> e == e) {
                break;
            }
            prev = prev -> next;
        }

        if (prev->next != NULL) {
            Node<T> *delNode = prev -> next;
            prev -> next = delNode -> next;
            delNode -> next = NULL;
            size--;
        }
    }

    bool contains(T e) {
        Node<T> *cur = head;
        for (int i = 0; i < size; ++i) {
            cur = cur -> next;
            if (cur -> e == e) {
                return true;
            }
        }
        return false;
    }

    void print() {
        Node<T> *prev = head;
        cout << "LinkedList: size = " << size << endl;
        cout << "[";
        for (int i = 0; i < size; ++i) {
            prev = prev -> next;
            cout << prev -> e;
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};
int main() {
    LinkedList<int> *linkedList = new LinkedList<int>();
    for (int i = 0; i < 5; ++i) {
		linkedList -> addFirst(i);
    }
    linkedList -> add(2, 30);
    linkedList -> print(); 
    linkedList -> remove(2);
    linkedList -> print();
    linkedList -> removeFirst();
    linkedList -> print();
    linkedList -> removeLast();
    linkedList -> print();   
    return 0;
}
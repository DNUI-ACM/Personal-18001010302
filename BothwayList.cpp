#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
public:
	T value;
	Node *prev;
	Node *next;
	Node(T e, Node *prev, Node *next){
		this -> value = e;
		this -> prev = prev;
		this -> next = next;
	}
	Node(){};
};

template <class T>
class BothwayList
{
private:
	Node<T> *head;
	int count;
public:
	BothwayList():count(0){
		head = new Node<T>();
		head -> prev = head -> next = head;
	};
	~BothwayList(){
		Node<T> *tmp;
		Node<T> *node = head -> next;
		while (node != head){
			tmp = node;
			node = node -> next;
			delete tmp;
		} 
		delete head;
		head = NULL;
	};

	int size(){
		return count;
	}
	
	bool empty(){
		return count == 0;
	}

	Node<T>* get_node(int index){
		if(index < 0 || index >= count){
			return NULL;
		}

		if(index <= count / 2){
			Node<T> *find = head -> next;
			for (int i = 0; i < index; i++){
				find = find -> next;
			}
			return find;
		}

		Node<T> *findd = head -> prev;
		for (int i = 0; i < count - index - 1; i++){
			findd = findd -> prev;
		}
		return findd;
	} 

	T get(int index){
		return get_node(index) -> value;
	}

	T get_frist(){
		return get_node(0) -> value;
	}

	T get_last(){
		return get_node(count - 1) -> value;
	}

	void insert(int index, T e){
		if(index == 0){
			return insert_first(e);
		}
		Node<T> *pindex = get_node(index);
		Node<T> *pnode = new Node<T>(e,pindex -> next,pindex);
		pindex -> prev -> next = pnode;
		pindex -> prev = pnode;
		count++;
	}

	void insert_first(T e){
		Node<T> *pnode = new Node<T>(e,head,head -> next);
		head -> next -> prev = pnode;
		head -> next = pnode;
		count++;
	}

	void insert_end(T e){
		Node<T> *pnode = new Node<T>(e,head -> prev,head);
		head -> prev -> next = pnode;
		head -> prev = pnode;
		count++;
	}

	void de(int index){
		Node<T> *pindex = get_node(index);
		pindex -> next -> prev = pindex -> prev;
		pindex -> prev -> next = pindex -> next;
		delete pindex;
		count--;
	}

	void de_first(){
		de(0);
	}

	void de_end(){
		de(count - 1);
	}

	void print() {
        Node<T> *prev = head;
        cout << "LinkedList: count = " << count << endl;
        cout << "[";
        for (int i = 0; i < count; ++i) {
            prev = prev -> next;
            cout << prev -> value;
            if (i < count - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};
int main(int argc, char const *argv[])
{
	BothwayList<int> *list = new BothwayList<int>();
	for (int i = 0; i < 5; i++){
		list -> insert_end(i);
	}
	list -> print();
	list -> insert_end(12);
	list -> print();
	list -> insert_first(154);
	list -> print();
	list -> de(2);
	list -> print();
	list -> de_first();
	list -> print();
	list -> de_end();
	list -> print();
	return 0;
}
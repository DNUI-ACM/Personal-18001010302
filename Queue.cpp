#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{

private:
	T *data;
	int front,tail,capacity;
	void resize(int newcapacity){
		T *newdada = new T[newcapacity + 1];
		for (int i = 0; i < getSize(); i++){
			newdada[i] = data[(i + front) % capacity];
		}
		data = newdada;
		tail = getSize();
		front = 0;
		capacity = newcapacity;
	}
public:
	Queue(int capacity){
		data = new T[capacity + 1];
		front = 0;
		tail = 0;
		this -> capacity = capacity;
	};
	
	Queue(){
		data = new T[10];
		front = 0;
		tail = 0;
		capacity = 10;
	};

	~Queue();

	int getCapacity(){
		return capacity;
	}

	bool empty(){
		return front == tail;
	}

	int getSize(){
		return (tail + capacity - front) % capacity;
	}

	void push(T e){
		if((tail + 1) % capacity == front){
			resize(capacity * 2);
		}
		data[tail] = e;
		tail = (tail + 1) % capacity;
	}

	void pop(){
		assert(front != tail);
		front = (front + 1) % capacity;
		if(getSize() == capacity / 4 && capacity / 2 != 0)
			resize(capacity / 2);
	}

	int Front(){
		assert(front != tail);
		return data[front];
	}

	int back(){
		assert(front != tail);
		return data[tail];
	}

	void print(){
		cout << "Queue: size = " << getSize() << ", capacity = " << capacity << std::endl;
        cout << "front [";
        for (int i = front; i != tail; i = (i + 1) % capacity) {
            cout << data[i];
            if ((i + 1) % capacity != tail) {
                cout << ", ";
            }
        }
        cout << "] tail" << endl;
	}
};
int main(int argc, char const *argv[])
{
	Queue<int> *queue = new Queue<int>(5);
    for (int j = 0; j < 5; ++j) {
        queue -> push(j);
        queue -> print();
    }
    queue -> push(20);
    queue -> push(33);
    queue -> print();
    queue -> pop();
    queue -> print();
    cout << queue -> Front() << endl;

	return 0;
}
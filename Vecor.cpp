#include <bits/stdc++.h>
using namespace std;
template<class T>
class Vector {
private:
    T *data;
    int size;
    int capacity;

    //修改数组容量
    void resize(int newCapacity){
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        data = newData;
        capacity = newCapacity;
    }

public:
	//构造函数
    Vector(int capacity) {
        data = new T[capacity];
        size = 0;
        this->capacity = capacity;
    }

    //默认构造函数
    Vector() {
        data = new T[5];
        size = 0;
        capacity = 5;
    }

    //拷贝构造函数
	Vector(const Vector & arr)
	{
		size = arr.size;
		capacity = arr.capacity;
		data = new T[capacity];
		memcpy(data,arr.data,data * sizeof(T));
	}

	//拷贝赋值运算符
	Vector& operator=(const Vector & arr)
	{
		if(this == &arr)
			return *this;
		size = arr.size;
		capacity = arr.capacity;

		T *temp = new T[capacity];
		memcpy(temp,arr.data,size * sizeof(T));
		delete [] data;
		data = temp;

		return *this;
	}

	//获取数组容量
    int getCapacity() {
        return capacity;
    }

    //获取数组大小
    int getSize() {
        return size;
    }

    //判空
    bool isEmpty() {
        return size == 0;
    }

    //在索引为index处插入元素e
    void insert(int index, T e) {
        assert(index >= 0 && index <= size);
        if (size == capacity) {
            resize(2 * capacity);
        }
        for (int i = size - 1; i >= index; --i) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }

    //在索引为[First,End]中插入元素e
    void insert(int First, int End, T e)
    {
    	for (int i = First; i <= End; i++)
    	{
    		insert(i,e);
    	}
    }

    //在首部插入一个元素e
    void push_First(T e) {
        insert(0, e);
    }

    //在最后插入一个元素e
    void push_back(T e) {
        insert(size, e);
    }

    //获取索引为index的元素
    T get(int index) {
        assert(index >= 0 && index < size);
        return data[index];
    }

    //将索引index中的元素修改为元素e
    void set(int index, T e) {
        assert(index >= 0 && index < size);
        data[index] = e;
    }

    //判断元素e存不存在
    bool contains(T e) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == e) {
                return true;
            }
        }
        return false;
    }

    //寻找指定元素e，找到了返回所在索引，没有返回-1
    int find(T e) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == e) {
                return i;
            }
        }
        return -1;
    }

    //访问指定元素e的索引
    void at(T e)
    {
    	if(find(e) != -1)
    		cout << find(e) << endl;
    	else
    		cout << "error" << endl;
    }

    //访问首元素
    T front()
    {
    	return data[0];
    }

    //访问尾元素
    T back()
    {
    	return data[size - 1];
    }

    //清空数组
    void clear(Vector<T> *arr)
    {
    	delete[] arr;
    }

    //删除索引为index的元素
    T pop(int index) {
        assert(index >= 0 && index < size);
        T ret = data[index];
        for (int i = index + 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size--;
        if (size == capacity / 2){
            resize(capacity / 2);
        }
        return ret;
    }

    //删除索引为[pop_First,pop_end]间的元素
    void pop(int pop_First,int pop_end)
	{
		for (int i = pop_First; i <= pop_end; i++)
		{
			pop(i);
		}
	}

	//删除首元素
    T pop_first() {
        return pop(0);
    }

    //删除尾元素
    T pop_back() {
        return pop(size - 1);
    }

    //删除指定元素
    void pop_Element(T e) {
        int index = find(e);
        if (index != -1) {
            pop(index);
        }
    }

    
    // 打印
    void print() {
        cout << "size = " << size << ", capacity = " << getCapacity() << endl;
        for (int i = 0; i < size; ++i) {
            cout << data[i];
            if (i != size - 1) {
                cout << " ";
            }
        }
	cout << endl << endl;
    }
};

int main() {
    Vector<int> *array = new Vector<int>();
    for (int i = 0; i < 10; ++i) {
        array->push_back(i);
        array->print();
    }

    array -> push_back(12);
    array -> print();

    array -> insert(0,20,12);
    array -> print();

    cout << array -> front() << endl;
    cout << array -> back() << endl;

    array -> at(12);

    array -> pop(0,15);
    array -> print();
    return 0;
}
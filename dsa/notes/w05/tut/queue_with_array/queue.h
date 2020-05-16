// implementing an unrestricted queue
// using array

#include <iostream>

template<typename T>
class queue
{
	private:
	T * data;
	int capacity, head, length;

	public:
	queue()
	{
		capacity = 0;		// last elem
		head = 0;			// first elem
		length = 0;			// size
		data = new T[capacity];
	}
	queue(int cap)
	{
		this->capacity = cap;	// last elem
		head = 0;					// first elem
		length = 0;					// size
		data = new T[capacity];
	}
	~queue() { delete[] this->data; }

	T front() { return data[head]; }

	void push(T t)
	{
		if (length >= capacity)
		{	// dynamic array
			int newCap = capacity * 2;
			T * newData = new T[newCap];

			for (int i = 0; i < this->length; i++)
			{
				newData[i] = data[(head + i) % capacity];	// prevent overflow
			}
			delete[] data;
			data = newData;

			capacity = newCap;
			head = 0;
		}

		// push data into stack
		data[(head + length) % capacity] = t;
		length++;
	}

	void pop()
	{
		length--;
		head = (head + 1) % capacity;
	}

	void displayInfo() {
		std::cout << "cap = " << this->capacity << "\n"
			<< "len = " << this->length << "\n"
			<< "head pos = " << this->head << std::endl;
	}

	bool empty() { return this->length == 0; }
};
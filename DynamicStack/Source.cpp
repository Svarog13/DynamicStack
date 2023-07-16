#include<iostream>

class Stack
{
private:
	int size;
	int* arr;
	int top;
	enum{EMPTY = -1};
public:
	Stack() = delete;
	
	Stack(int size):size(size),arr(new int[size]),top(EMPTY){}
	bool IsFull()const
	{
		return top == size - 1;
	}
	bool Push(int elem)
	{
		if (!IsFull())
		{
			arr[++top] = elem;
			return true;
		}
		return false;
	}

	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
		{
			return arr[top--];
		}
		return 0;
	}
	int GetCount()const
	{
		return top + 1;
	}
	int Peek()
	{
		if (!IsEmpty())
		{
			return arr[top];
		}
		return 0;
	}
	void Show()const
	{
		for (size_t i = 0; i < top; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	~Stack()
	{
		if (arr!=nullptr)
		{
			delete[]arr;
		}
	}
};

int main()
{
	Stack st(10);
	st.Push(100);
	st.Push(200);
	st.Push(300);
	st.Push(400);
	std::cout << "Cout : " << st.GetCount() << std::endl;
	std::cout << "Last : " << st.Peek() << std::endl;
	std::cout << "Last element : " << st.Pop() << std::endl;
	std::cout << "Count : " << st.GetCount() << std::endl;
	st.Show();
	while (!st.IsFull())
	{
		st.Push(rand() % 30);
	};
	st.Show();
	std::cout << "Last : " << st.Peek() << std::endl;
	std::cout << "Count : " << st.GetCount() << std::endl;
}
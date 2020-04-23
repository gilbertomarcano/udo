#pragma once

/* A template container adaptor class that provides a restriction of functionality for 
	some underlying container type, limiting access to the front and back elements. 
	Elements can be added at the back or removed from the front, and elements can be 
	inspected at either end of the queue.
*/

#ifndef CAPACITY
#define CAPACITY 100
#endif

/* Parameters
	Type
	The element data type to be stored in the queue. */
template <class Type>
struct static_queue
{
	/* Members */

private:
	/* Typedefs */
	Type container_type[CAPACITY]; /* A type that provides the base container to be adapted by the queue. */
	unsigned int back_type; /* An unsigned integer type that can represent the position of the last added alement at the back of the queue. */
	unsigned int front_type; /* An unsigned integer type that can represent the position of the first element at the front of the queue. */
	unsigned int size_type; /* An unsigned integer type that can represent the number of elements in a queue. */


public:
	/* Constructors */

	/* Constructs a queue that is empty or that is a copy of a base container object. */
	static_queue();
	static_queue(static_queue<Type>& right);

	/* Functions */

	/* Returns a constant reference to the last and most recently added element at the back of the queue. */
	Type& back() const;

	/* Tests if a queue is empty. */
	bool empty() const;

	/* Returns a reference to the first element at the front of the queue. */
	Type& front() const;

	/* Removes an element from the front of the queue. */
	Type pop();

	/* Adds an element to the back of the queue. */
	void push(const Type& val);

	/* Returns the number of elements in the queue. */
	unsigned int size() const;

	/* Equals operator */
	static_queue<Type>& operator=(static_queue<Type>& right);

	/* Ostream operator */
	friend std::ostream& operator<<(std::ostream& os, static_queue<Type>& queue)
	{
		os << "[";

		if (queue.empty())
		{
			os << "]";
			return os;
		}

		static_queue<Type> copy = queue;
		for (unsigned int i = 0, size = queue.size(); i < size; i++)
		{
			os << copy.pop();

			if (i == size - 1) break; else os << ", ";
		}

		os << "]";
		return os;
	}
};

/* Returns a constant reference to the last and most recently added element at the back of the queue.
	Return Value
	The last element of the queue. If the queue is empty, the return value is undefined. */
template <class Type> Type& static_queue<Type>::back() const
{
	return container_type[back_type];
}

/* Tests if a queue is empty.
	Return value
	true if the queue is empty; false if the queue is nonempty. */
template <class Type> bool static_queue<Type>::empty() const
{
	return size_type == 0 ? true : false;
}

/* Constructs a queue that is empty or that is a copy of a base container object. */
template <class Type> static_queue<Type>::static_queue()
{
	back_type = 0;
	front_type = 0;
	size_type = 0;
}

template <class Type> static_queue<Type>::static_queue(static_queue<Type>& right)
{
	*this = right;
}

/* Returns a reference to the first element at the front of the queue.
	Return Value
	The first element of the queue. If the queue is empty, the return value is undefined. */
template <class Type> Type& static_queue<Type>::front() const
{
	return container_type[front_type];
}

/* Removes an element from the front of the queue. 
	Return value
	The first element at the front of the queue. */
template <class Type> Type static_queue<Type>::pop()
{
	if (empty())
	{
		throw UNDERFLOW;
	}

	unsigned int front = front_type;

	front_type = front_type + 1 == CAPACITY ? 0 : front_type + 1;

	size_type--;
	return container_type[front];
}

/* Adds an element to the back of the queue.
	Parameters
	val
	The element added to the back of the queue. */
template <class Type> void static_queue<Type>::push(const Type& val)
{
	if (size_type == CAPACITY)
	{
		throw OVERFLOW;
	}

	unsigned int back = back_type;

	back_type = back_type + 1 == CAPACITY ? 0 : back_type + 1;

	size_type++;
	container_type[back] = val;
}

/* Returns the number of elements in the queue.
	Return Value
	The current length of the queue. */
template <class Type> unsigned int static_queue<Type>::size() const
{
	return size_type;
}


/* Equals operator
	Return Value
	A copy by value of the right queue. */
template<class Type> static_queue<Type>& static_queue<Type>::operator=(static_queue<Type>& right)
{
	back_type = right.back_type;
	front_type = right.front_type;
	size_type = right.size_type;

	for (unsigned int i = 0; i < CAPACITY; i++)
	{
		container_type[i] = right.container_type[i];
	}

	return *this;
}
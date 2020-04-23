#pragma once

/* A template container adaptor class that provides a restriction of functionality limiting access 
to the element most recently added to some underlying container type.The stack class is 
used when it is important to be clear that only stack operations are being performed on the 
container. */

#ifndef CAPACITY
#define CAPACITY 100
#endif

/* Parameters
    Type
    The element data type to be stored in the stack. */
template <class Type>
struct static_stack
{
    /* Members */

private:
    /* Typedefs */

    Type container_type[CAPACITY]; /* A type that provides the base container to be adapted by a stack. */
    unsigned int size_type; /* An unsigned integer type that can represent the number of elements in a stack. */

public:
	/* Constructors */

    /* Constructs a stack that is empty or that is a copy of a base stack object. */
    static_stack();
    static_stack(static_stack<Type>& right);

    /* Functions */

    /* Tests if a stack is empty. */
    bool empty() const;

    /* Removes the element from the top of the stack. */
    Type pop();

    /* Adds an element to the top of the stack. */
    void push(const Type& val);

    /* Returns the number of elements in the stack.  */
    unsigned int size() const;

    /* Returns a constant reference to an element at the top of the stack. */
    const Type& top() const;

    /* Equals operator */
    static_stack<Type>& operator=(static_stack<Type>& right);

    /* Ostream operator */
    friend std::ostream& operator<<(std::ostream& os, static_stack<Type>& stack)
    {
        os << "[";

        if (stack.empty())
        {
            os << "]";
            return os;
        }

        static_stack<Type> copy = stack;
        static_stack<Type> reverse_copy;
        for (unsigned int i = 0, size = stack.size(); i < size; i++)
        {
            reverse_copy.push(copy.pop());
        }

        for (unsigned int i = 0, size = stack.size(); i < size; i++)
        {
            os << reverse_copy.pop();

            if (i == size - 1) break; else os << ", ";
        }

        os << "]";
        return os;
    }
};

/* Tests if a stack is empty.
    Return Value
    true if the stack is empty; false if the stack is nonempty. */
template <class Type> bool static_stack<Type>::empty() const
{
    return size_type == 0 ? true : false;
}

/* Removes the element from the top of the stack.
    Return Value
    The previous last element in the container at the top of the stack. */
template <class Type> Type static_stack<Type>::pop()
{
    if (empty())
    {
        throw UNDERFLOW;
    }

    return container_type[--size_type];
}

/* Adds an element to the top of the stack.
    Parameters
    val
    The element added to the top of the stack. */
template <class Type> void static_stack<Type>::push(const Type& val)
{
    if (size_type == CAPACITY)
    {
        throw OVERFLOW;
    }

    container_type[size_type++] = val;
}

/* Returns the number of elements in the stack.
    Return Value
    The current length of the stack. */
template <class Type> unsigned int static_stack<Type>::size() const
{
    return size_type;
}

/* Constructs a stack that is empty or that is a copy of a base stack object. */
template <class Type> static_stack<Type>::static_stack()
{
    size_type = 0;
}

template <class Type> static_stack<Type>::static_stack(static_stack<Type>& right)
{
    *this = right;
}

/* 	Returns a constant reference to an element at the top of the stack. 
    Return Value
    A reference to the last element in the container at the top of the stack. */
template <class Type> const Type& static_stack<Type>::top() const
{
    if (empty())
    {
        throw UNDERFLOW;
    }

    return container_type[size_type - 1];
}

/* Equals operator 
    Return Value
    A copy by value of the right stack. */
template<class Type> static_stack<Type>& static_stack<Type>::operator=(static_stack<Type>& right)
{
    size_type = 0;

    for (unsigned int i = 0; i < right.size_type; i++)
    {
        push(right.container_type[i]);
    }

    return *this;
}
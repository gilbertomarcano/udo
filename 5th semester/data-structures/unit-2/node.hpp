#pragma once

/* A template container adaptor class that represents the information contained and also 
	may link to other nodes. Links between nodes are implemented by pointers.
*/

/* Parameters
	Type
	The element data type of the stored key data. */
template <class Type>
struct node
{
	/* Members */

private:
	/* Typedefs */
	Type key; /* A type that provides the base contained data. */
	node* next; /* A pointer that links the node with its next node. */
	node* prev; /* A pointer that links the node with its previous node. */

public:
	/* Constructors */

	/* Constructs a node that is empty, holds key data and its pointers or is a copy of a base node object. */
	node();
	node(Type key, node<Type>* next, node<Type>* prev);
	node(node<Type>& right);

	/* Functions */
	
	/* Returns the key data of the node. */
	Type get_key();

	/* Returns the next linked node of the node.*/
	node<Type>* get_next();

	/* Returns the previous linked node of the node. */
	node<Type>* get_prev();

	/* Sets the key data of the node. */
	void set_key(Type& key);

	/* Sets the next linked node of the node. */
	void set_next(node<Type>* next);

	/* Sets the previous linked node of the node. */
	void set_prev(node<Type>* prev);

	/* Equals operator */
	node<Type>& operator=(node<Type>& right);

	/* Ostream operator */
	friend std::ostream& operator<<(std::ostream& os, node<Type>& node)
	{
		os << "{\n    key: " << node.key << ",\n    next: " << node.next << ",\n    prev: " << node.prev << "\n}";

		return os;
	}
};

/* Returns the key data of the node. */
template <class Type> Type node<Type>::get_key()
{
	return this->key;
}

/* Returns the next linked node of the node.*/
template <class Type> node<Type>* node<Type>::get_next()
{
	return this->next;
}

/* Returns the previous linked node of the node. */
template <class Type> node<Type>* node<Type>::get_prev()
{
	return this->prev;
}

/* Constructs a node that is empty. */
template <class Type> node<Type>::node()
	: next(nullptr), prev(nullptr) 
{}

/* Constructs a node that holds key data and its pointers. */
template <class Type> node<Type>::node(Type key, node<Type>* next, node<Type>* prev)
	: key(key), next(next), prev(prev) 
{}

/* Constructs a node that is a copy of a base node object. */
template <class Type> node<Type>::node(node<Type>& right)
{
	*this = right;
}

/* Sets the key data of the node. */
template <class Type> void node<Type>::set_key(Type& key)
{
	this->key = key;
}

/* Sets the next linked node of the node. */
template <class Type> void node<Type>::set_next(node<Type>* next)
{
	this->next = next;
}

/* Sets the previous linked node of the node. */
template <class Type> void node<Type>::set_prev(node<Type>* prev)
{
	this->prev = prev;
}

/* Equals operator */
template <class Type> node<Type>& node<Type>::operator=(node<Type>& right)
{
	this->key = right.key;
	this->next = right.next;
	this->prev = right.prev;
}
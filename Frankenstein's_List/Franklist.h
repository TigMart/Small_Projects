#ifndef _FRANKENSTEINS_LIST_
#define _FRANKENSTEINS_LIST_

#include <initializer_list>
#include <iostream>


template <typename T>
class Franklist
{
public:
	//Constructors
	Franklist();
	Franklist(const Franklist<T>& other);
	Franklist(std::initializer_list<T> init);
	//destructor
	~Franklist();
	//Modifiers
	void push_front(const T& value);
	void push_back(const T& value);
	void pop_back();
	void pop_front();
	void insert(int pos, const T& value);
	void clear();
	//Element access
	T& front();
	T& back();
	//Capacity
	bool empty() const;
	int size() const;
	void print();
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
		Node* asc;
		Node* desc;
		Node(T data = T(), Node* next = nullptr, Node* prev = nullptr, Node* asc = nullptr, Node* desc = nullptr) 
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
			this->asc = asc;
			this->desc = desc;
		}
	};
	int m_size;
	Node* m_head;
	Node* m_tail;
	Node* m_asc;
	Node* m_desc;
	void _sort(Node& other);
};


template<typename T>
Franklist<T>::Franklist() : m_size{ 0 }, m_head{ nullptr }, m_tail{ nullptr }, m_asc{ nullptr }, m_desc{ nullptr } {}

template <typename T>
Franklist<T>::Franklist(const Franklist<T>& other) 
{
	std::cout << std::endl << "Copy ctor" << std::endl;
	if (other.m_head == nullptr)
	{
		this->m_head->data = other.m_head->data;
		this->m_size = other.m_size;
		this->m_head = other.m_head;
		this->m_tail = other.m_tail;
		this->m_desc = other.m_desc;
		this->m_asc = other.m_asc;
	}
	else 
	{
		Node* objhead = other.m_head;
		m_head = new Node;
		m_head->data = objhead->data;
		m_asc = m_head;
		m_desc = m_head;
		m_tail = m_head;
		Node* cur = m_head->next;
		Node* tmp = m_head;
		objhead = objhead->next;
		while (objhead!=nullptr)
		{
			cur = new Node;
			tmp->next = cur;
			_sort(*objhead);
			cur->data = objhead->data;
			cur->prev = tmp;
			objhead = objhead->next;
			cur = cur->next;
			tmp = tmp->next;
		}
		m_tail = tmp;
	}
}

template<typename T>
Franklist<T>::Franklist(std::initializer_list<T> init) :Franklist()
{
	typename std::initializer_list<T>::iterator it = init.begin();
	m_size = init.size();
	while (it != init.end())
	{
		this->push_back(*it);
		++it;
	}
}
template<typename T>
Franklist<T>::~Franklist()
{
	for (int i = 0; i < m_size; ++i)
	{
		pop_front();
	}
}


template<typename T>
void Franklist<T>::_sort(Node& other)
{
	if (m_asc->data > other.data)
	{
		m_asc->desc = &other;
		other.asc = m_asc;
		m_asc = &other;
		return;
	}
	if (m_desc->data < other.data)
	{
		m_desc->asc = &other;
		other.desc = m_desc;
		m_desc = &other;
		return;
	}
	else
	{
		Node* tmp = m_asc;
		Node* tmp2 = m_asc->asc;
		while (tmp2 != nullptr)
		{
			if (other.data <= tmp2->data && other.data >= tmp->data)
			{
				other.asc = tmp2;
				other.desc = tmp;
				tmp->asc = &other;
				tmp2->desc = &other;
			}
			tmp = tmp2;
			tmp2 = tmp2->asc;
		}
	}
}

template<typename T>
void Franklist<T>::push_front(const T& value)
{
	if (m_head == nullptr)
	{
		m_head = new Node(value);
		m_tail = m_head;
		m_asc = m_head;
		m_desc = m_head;
	}
	else
	{
		Node* newnode = new Node(value);
		_sort(*newnode);
		newnode->next = m_head;
		m_head->prev = newnode;
		m_head = newnode;
	}
	++m_size;
}

template<typename T>
void Franklist<T>::push_back(const T& value)
{  
	if (m_head == nullptr)
	{
		m_head = new Node(value);
		m_tail = m_head;
		m_asc = m_head;
		m_desc = m_head;
	}
	else
	{
		Node* cur = m_head;
		while (cur->next)
		{
			cur = cur->next;
		}
		Node* newnode = new Node(value);
		_sort(*newnode);
		newnode->prev = cur;
		cur->next = newnode;
		m_tail = newnode;
	}
	++m_size;
}

template<typename T>
void Franklist<T>::pop_back()
{
	if (!m_head)
	{
		std::cout << "There is no element in the list." << std::endl;
		return;
	}

	if (!m_head->next)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
		m_asc = nullptr;
		m_desc = nullptr;
		return;
	}

	Node* tmp = m_tail;
	m_tail = m_tail->prev;
	m_tail->next = nullptr;
	if (tmp == m_desc)
	{
		tmp->desc->asc = nullptr;
		m_desc = tmp->desc;
		delete tmp;
		return;
	}
	if (tmp == m_asc)
	{
		tmp->asc->desc = nullptr;
		m_asc = tmp->asc;
		delete tmp;
		return;
	}
	tmp->desc->asc = tmp->asc;
	tmp->asc->desc = tmp->desc;
	delete tmp;
}

template<typename T>
void Franklist<T>::pop_front()
{
	if (!m_head)
	{
		std::cout << "There is no element to pop in the list." << std::endl;
		return;
	}

	if (!m_head->next)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
		m_asc = nullptr;
		m_desc = nullptr;
		return;
	}
	Node* tmp = m_head;
	m_head = m_head->next;
	m_head->prev = nullptr;
	if (tmp == m_desc)
	{
		tmp->desc->asc = nullptr;
		m_desc = tmp->desc;
		delete tmp;
		return;
	}
	if (tmp == m_asc)
	{
		tmp->asc->desc = nullptr;
		m_asc = tmp->asc;
		delete tmp;
		return;
	}
	tmp->desc->asc = tmp->asc;
	tmp->asc->desc = tmp->desc;
	delete tmp;
}


template<typename T>
void Franklist<T>::insert(int pos, const T& value)
{
	if (pos > -1 && pos <= m_size)
	{
		if (pos == 0)
		{
			push_front(value);
			return;
		}
		else if (pos == m_size)
		{
			push_back(value);
			return;
		}
		else
		{
			Node* newnode = new Node(value);
			_sort(*newnode);
			Node* tmp = m_head;
			Node* tmp2 = m_head->next;
			for (int i = 1; i < pos; ++i)
			{
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
			newnode->next = tmp->next;
			tmp->next = newnode;
			tmp2->prev = newnode;
			++m_size;
		}
	}
}

template<typename T>
void Franklist<T>::clear()
{
	Node* current = m_head;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	m_head = nullptr;
	m_tail = nullptr;
	m_asc = nullptr;
	m_desc = nullptr;
}

template<typename T>
T& Franklist<T>::front()
{
	if (m_head == nullptr)
	{
		std::cout << "You dont have elemenets: ";
		exit(1);
	}
	return m_head->data;
}

template<typename T>
T& Franklist<T>::back()
{
	if (m_head == nullptr)
	{
		std::cout << "You dont have elemenets: ";
		exit(1);
	}
	else
	{
		Node* current = m_head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->data;
	}
}

template<typename T>
bool Franklist<T>::empty() const
{
	return !m_size;
}

template<typename T>
int Franklist<T>::size() const
{
	return this->m_size;
}

template<typename T>
void Franklist<T>::print()
{
	Node* cur = m_head;
	while (cur!=nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl << "Asc: ";
	cur = m_asc;
	while (cur)
	{
		std::cout << cur->data << " ";
		cur = cur->asc;
	}
	std::cout << std::endl << "Desc: ";
	cur = m_desc;
	while (cur)
	{
		std::cout << cur->data << " ";
		cur = cur->desc;
	}

}

#endif // !_FRANKENSTEINS_LIST_
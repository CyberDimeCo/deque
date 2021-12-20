#include "Iterator.h"

template<typename T>
class Deque
{
private:
	struct Node
	{
		T data;
		Node* next = NULL;
		Node* prev = NULL;
	};
	int m_size;
	Node* m_head;
	Node* m_tail;
public:
	//определ€ю псевдоним дл€ измен€емого итератора
	typedef Iterator<Node, T> iterator;
	//определ€ю псевдоним дл€ неизмен€емого итератора
	typedef Iterator<const Node, const T> const_iterator;

	Deque() : m_head(NULL), m_tail(NULL), m_size(0) {};
	Deque(iterator first, iterator last);
	Deque(const Deque& d);
	~Deque() { this->clear(); };

	int length() { return m_size; };
	bool is_empty() { return m_size == 0; };

	void pop_front();
	void pop_back();
	void push_back(T value);
	void push_front(T value);
	//обмен€ть очереди элементами
	void swap(Deque& other);
	void clear();


	iterator begin() { return iterator(m_head); }
	iterator begin() const { return const_iterator(m_head); }
	iterator end() { return iterator(); }
	iterator end() const { return const_iterator(); }

	Node* pre_end() const { return m_tail; }
};

template<typename T>
inline Deque<T>::Deque(iterator first, iterator last)
{
	Deque<T>* tmp = new Deque<T>();
	for (iterator it = first; it != last; it++)
		tmp->push_back(*it);
	*this = *tmp;
}

template<typename T>
inline Deque<T>::Deque(const Deque& d)
{
	*this = *(new Deque<T>(iterator(d.m_head), iterator(NULL)));
}

template<typename T>
inline void Deque<T>::pop_front()
{
	Node* temp = m_head;
	m_head = m_head->next;
	delete temp;
	--m_size;
}

template<typename T>
inline void Deque<T>::pop_back()
{
	Node* temp = m_tail;
	m_tail = m_tail->prev;
	m_tail->next = NULL;
	delete temp;
	--m_size;
}

template<typename T>
inline void Deque<T>::push_back(T value)
{
	if (is_empty())
	{
		Node* first = new Node;
		first->data = value;
		m_head = m_tail = first;
	}
	else {
		Node* s = new Node;
		s->data = value;

		m_tail->next = s;
		s->prev = m_tail;
		m_tail = s;
	}
	m_size++;
}

template<typename T>
inline void Deque<T>::push_front(T value)
{
	if (is_empty())
	{
		Node* first = new Node;
		first->data = value;
		m_head = m_tail = first;
	}
	else {
		Node* s = new Node;
		s->data = value;

		s->next = m_head;
		m_head->prev = s;
		m_head = s;
	}
	m_size++;
}

template<typename T>
inline void Deque<T>::swap(Deque& other)
{
	Deque<T>* tmp = new Deque<T>(other);
	other = *this;
	*this = *tmp;
}

template<typename T>
inline void Deque<T>::clear()
{
	while (m_size)
		pop_front();
}
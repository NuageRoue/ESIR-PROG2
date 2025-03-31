#ifndef List_H
#define List_H


#include "cyclicNode.h"
#include <cstddef>
#include <cassert>
#include <ostream>


template <class T>
class Liste
{

protected:
	typedef DataStructure::cyclicNode<T> Chainon;
	Chainon *sentinel;
	size_t count;
	
public:
	class const_iterator
	{
	private:
		friend class Liste;
		Chainon *current;
		Chainon *sentinel;

		const_iterator(Chainon *_current, Chainon *_sentinelle) : current(_current), sentinel(_sentinelle) {}

	public:
		const_iterator & operator++(void)
		{
			assert(current != sentinel); // on verifie ne pas etre en fin de liste;
			current = current->next();
			return *this;
		}
		
		const_iterator & operator--(void)
		{
			current = current->previous();
			assert(current != sentinel); // on verifie ne pas etre en debut de liste;
			return *this;
		}

		const T & operator*(void) const
		{
			assert(current != sentinel);
			return current->data();
		}

		const T *operator->(void) const
		{		
			assert(current != sentinel);
			return &(current->data());
		}

		bool operator==(const const_iterator o) const
		{
			return current == o.current;
		}
	
		bool operator!=(const const_iterator o) const
		{
			return current != o.current;
		}
	};

	class iterator
	{
	private:
		friend class Liste;
		Chainon *current;
		Chainon *sentinel;

		iterator(Chainon *_current, Chainon *_sentinelle) : current(_current), sentinel(_sentinelle) {}

	public:
		iterator & operator++(void)
		{
			assert(current != sentinel); // on verifie ne pas etre en fin de liste;
			current = current->next();
			return *this;
		}
		
		iterator & operator--(void)
		{
			current = current->previous();
			assert(current != sentinel); // on verifie ne pas etre en debut de liste;
			return *this;
		}

		T & operator*(void) 
		{
			assert(current != sentinel);
			return current->data();
		}

		T *operator->(void) 
		{		
			assert(current != sentinel);
			return &(current->data());
		}

		bool operator==(const iterator o) const
		{
			return current == o.current;
		}
	
		bool operator!=(const iterator o) const
		{
			return current != o.current;
		}
	};
	Liste<T>() : sentinel(new Chainon()), count(0)
	{
		
	}
	
	~Liste()
	{
		flushList();
		delete sentinel;
	}

	void flushList()
	{
		while (sentinel->next() != sentinel)
		{
			delete sentinel->next();
		}
		count = 0;
	}

	void addList(const Liste<T> &toAdd)
	{
		const_iterator i = toAdd.begin();

		while(i != toAdd.end())
		{
			push_back(*i);
			++i;
		}
	}

	
	Liste<T>(const Liste<T> &copy)
	{
		sentinel = new Chainon();
		count = 0;
		addList(copy);
	}
	

	Liste &operator=(const Liste &l)
	{
		if (this != &l)
		{
			flushList();
			addList(l);
		}
		return *this;
	}

	Liste operator+(const Liste &l) const
	{
		Liste toReturn;
		toReturn.addList(*this);
		toReturn.addList(l);

		return toReturn;

	}



	bool empty() const
	{
		return (count == 0);
	}

	size_t size() const
	{
		return count;
	}

	const T &front() const
	{
		assert(!empty());
		return sentinel->next()->data();
	}

	T &front()
	{
		assert(!empty());
		return (T&)(sentinel->next()->data());
	}

	const T &back() const
	{
		assert(!empty());
		return sentinel->previous()->data();
	}

	T &back()
	{
		assert(!empty());
		return (T&)(sentinel->previous()->data());
	}

	void push_front(T newValue)
	{
		sentinel->insertAfter(new Chainon(newValue));
		count++;
	}
	

	void push_back(T newValue)
	{
		sentinel->insertBefore(new Chainon(newValue));
		count++;
	}

	void pop_front()
	{
		assert(count > 0);
		delete sentinel->next();
		count--;
	}

	void pop_back()
	{
		assert(count > 0);
		delete sentinel->previous();
		count--;
	}


	/* partie 2.2 */

	const_iterator begin() const
	{
		return const_iterator(sentinel->next(), sentinel);	
	}

	const_iterator end() const
	{
		return const_iterator(sentinel, sentinel);	
	}

	iterator begin()
	{
		return iterator(sentinel->next(), sentinel);	
	}

	iterator end()
	{
		return iterator(sentinel, sentinel);	
	}

	iterator insert(iterator position, const T &x)
	{
		assert(position.sentinel == sentinel);
		position.current->insertBefore(new Chainon(x));
		count++;
		return --position;
	}

	iterator erase(iterator toErase)
	{
		assert (toErase.sentinel == sentinel && !empty());
		
		Chainon *next = toErase.current->next();
		delete toErase.current;
		count--;
		return iterator(next, sentinel);
	}
};

template <class InputIterator, class T>
InputIterator find (InputIterator premier, InputIterator dernier, const T &x)
{
	while (premier != dernier)
	{
		if (*premier == x)
			return premier;

		++premier;
	}
	return dernier;
}

template <class T>
std::ostream &operator<<(std::ostream &stream, const Liste<T> &l)
{
	using iterator = typename Liste<T>::const_iterator;

	stream << "<";
	iterator i = l.begin();
	while(i != l.end())
	{
		stream << (*i) << " ";
		++i;
	}
	stream << ">";
	return stream;
}
#endif

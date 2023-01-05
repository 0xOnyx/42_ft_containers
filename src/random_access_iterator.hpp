#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
	struct	random_access_iterator_tag	{};

	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
	public:
		random_access_iterator(void) :_elem(nullptr) {};
		random_access_iterator(pointer elem) :_elem(elem) {};
		random_access_iterator(const random_access_iterator<T> &rhs) :_elem(rhs._elem) {};
		~random_access_iterator(void) {};
		random_access_iterator	&operator=(const random_access_iterator<T> &op)
		{
			this->_elem = op._elem;
			return (*this);
		}
		random_access_iterator	&operator++()
		{
			this->_elem++;
			return (*this);
		}
		random_access_iterator	operator++(int)
		{
			random_access_iterator<T>	res(*this);

			this->_elem++;
			return (res);
		}

		bool		operator==(const random_access_iterator<T> &rhs) const {return (this->_elem == rhs._elem)};
		bool		operator!=(const random_access_iterator<T> &rhs) const {return (this->_elem != rhs._elem)};
		Reference	operator*() {return (*this->_elem)};
		Pointer		operator->() {return (this->_elem)};

		random_access_iterator	&operator--()
		{
			this->_elem--;
			return (res);
		}
		random_access_iterator	operator--(int)
		{
			random_access_iterator<T>	res(*this);

			this->_elem++;
			return (res);
		}
	private:
		Pointer	_elem;
	};

}

#endif

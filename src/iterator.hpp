#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>

namespace ft
{
	struct	random_access_iterator_tag	{};

	template <
			class Category, class T,
			class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator
	{
	public:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	private:
	};

	template <class Iter>
	struct iterator_traits
	{
		difference_type		Iter::difference_type;
		value_type			Iter::value_type;
		pointer				Iter::pointer;
		reference			Iter::reference;
		iterator_category	Iter::iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		difference_type	std::ptrdiff_t;
		value_type			T;
		pointer				const T*;
		reference			const T&;
		iterator_category	ft::random_access_iterator_tag;
	};


}

#endif
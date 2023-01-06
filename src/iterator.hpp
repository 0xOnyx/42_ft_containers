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
}

#endif
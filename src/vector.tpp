#ifndef VECTOR_TPP
# define VECTOR_TPP
# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		typename T									value_type;
		typename Alloc								allocator_type;
		typename allocator_type::reference			reference;
		typename allocator_type::const_reference	const_reference;
		typename allocator_type::pointer			pointer;
		typename allocator_type::const_pointer		const_pointer;
		typename ft::random_access_iterator			iterator;
		typename 									const_iterator;
		typename 									const_reverse_iterator;
		typename 									difference_type;
		typename allocator_type::size_type			size_type;


		//(1) empty container constructor (default constructor)
		//Constructs an empty container, with no elements.
		explicit vector (const allocator _type	&alloc = allocator_type())
		{

		}

		//(2) fill constructor
		//Constructs a container with n elements. Each element is a copy of val.
		explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{

		}

		//(3) range constructor
		//Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{

		}

		//(4) copy constructor
		//Constructs a container with a copy of each of the elements in x, in the same order.
		vector (const vector &x)
		{

		}

	};
}

#endif

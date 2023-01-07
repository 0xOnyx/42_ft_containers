#ifndef VECTOR_TPP
# define VECTOR_TPP
# include <memory>
# include "random_access_iterator.hpp"
//https://cplusplus.com/reference/stl/

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef 									const_reverse_iterator;
		typedef 									difference_type;
		typedef typename allocator_type::size_type			size_type;


		explicit vector (const allocator_type	&alloc = allocator_type()) :_alloc(alloc), _start(nullptr), _end(NULL), _end_capacity(NULL) {};

		//(2) fill constructor
		//Constructs a container with n elements. Each element is a copy of val.
		explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) :_alloc(alloc)
		{
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _end + n;
			while (n--)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		}

		//(3) range constructor
		//Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) :_alloc(alloc)
		{
			_start = _alloc.allocate(first - last);
			_end = _start;
			_end_capacity = _end;
			while (first != last)
			{
				_alloc.construct();
			}
		}

		//(4) copy constructor
		//Constructs a container with a copy of each of the elements in x, in the same order.
		vector (const vector &x) :_alloc(x._alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
		{
				this->insert(this->begin(), x.begin(), x.begin());
		}

		//Deconstructor
		~vector()
		{
			pointer current = _start;

			while (current != _end_capacity)
				_alloc.destory(current++);
			_alloc.deallocate(current, _end_capacity - _start);
		}

		iterator	begin(){
			return (iterator(_start));
		};

		iterator insert

	private:
		allocator_type	_alloc;
		pointer 		_start;
		pointer 		_end;
		pointer			_end_capacity;
	};
}

#endif

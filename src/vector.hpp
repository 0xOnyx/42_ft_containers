#ifndef VECTOR_TPP
# define VECTOR_TPP
# include <memory>
# include <stdexcept>
# include "random_access_iterator.hpp"
//https://cplusplus.com/reference/stl/

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef				T 														value_type;
		typedef 			Alloc 													allocator_type;
		typedef typename	allocator_type::reference 								reference;
		typedef typename	allocator_type::const_reference							const_reference;
		typedef typename	allocator_type::pointer 								pointer;
		typedef typename	allocator_type::const_pointer 							const_pointer;
		typedef 			ft::random_access_iterator<value_type> 					iterator;
		typedef				ft::random_access_iterator<const value_type> 			const_iterator;
		typedef 			ft::reverse_iterator<value_type> 						reverse_iterator;
		typedef				ft::reverse_iterator<const value_type> 					const_reverse_iterator;
		typedef typename	ft::random_access_iterator<value_type>::difference_type	difference_type;
		typedef typename	allocator_type::size_type 								size_type;

		//(1) empty container constructor (default constructor)
		//Constructs an empty container, with no elements.
		explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(nullptr), _end(NULL), _end_capacity(NULL) {};

		//(2) fill constructor
		//Constructs a container with n elements. Each element is a copy of val.
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc)
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
		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) :_alloc(alloc)
		{
			this->insert(this->begin(), first, last);
		}

		//(4) copy constructor
		//Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector &x) : _alloc(x._alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
		{
			this->insert(this->begin(), x.begin(), x.end());
		}

		//Deconstructor
		~vector() { this->clear(); }

		//Assign content
		vector &operator=(const vector &x)
		{
			this->clear();
			this->insert(this->begin(), x.begin(), x.end());
		}

		void clear()
		{
			this->clear();
			pointer current = _start;

			while (current != _end)
				_alloc.destory(current++);
			_alloc.deallocate(_start, _end_capacity - _start);
			_start = nullptr;
			_end = _start;
			_end_capacity = _start;
		}

		iterator				begin() 			{ return (iterator(_start)); }
		const_iterator			begin()		const	{ return (const_iterator(_start)); }

		iterator				end()				{ return (iterator(_end)); }
		const_iterator			end() 		const	{ return (const_iterator(_end));}

		reverse_iterator		rbegin()			{ return (reverse_iterator(_end - 1)); }
		const_reverse_iterator	rbegin()	const	{ return (const_reverse_iterator(_end - 1)); }

		reverse_iterator		rend() 				{ return (reverse_iterator(_start - 1)); }
		const_reverse_iterator	rend()		 const	{ return (reverse_iterator(_start - 1)); }

		size_type				size() 		const	{ return (_end - _start); }
		size_type				max_size()	const 	{ return (_alloc.max_size());}

		void	resize(size_type n, value_type val = value_type())
		{
			size_type current_size;

			current_size = size();
			if (n < current_size)
			{
				while (current_size--)
					_alloc.destroy(--_end);
			}
			else
				this->insert(this->end(), n - current_size, val);
		}

		size_type	capacity()	const	{ return (_end_capacity - _start); }
		bool		empty()		const	{ return (this->size() == 0); }

		void	reserve(size_type n)
		{
			iterator 	old_start;
			iterator	old_end;
			size_type	current_capacity;
			size_type	current_size;

			current_capacity = this->capacity();
			current_size = this->size();
			if (n > current_capacity)
			{
				old_start = this->begin();
				old_end	= this->end();
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				while (old_start != old_end)
				{
					_alloc.construct(_end++, *old_start);
					_alloc.destroy(old_start++);
				}
				old_start -= current_size;
				_alloc.deallocate(old_start, current_capacity);
			}
		}

		void	shrink_to_fit()
		{
			iterator 	old_start;
			iterator	old_end;
			size_type	current_capacity;
			size_type	current_size;

			current_capacity = this->capacity();
			current_size = this->size();
			if (_end != _end_capacity)
			{
				old_start = this->begin();
				old_end	= this->end();
				_start = _alloc.allocate(current_size);
				_end = _start;
				_end_capacity = _start + current_size;
				while (old_start != old_end)
				{
					_alloc.construct(_end++, *old_start);
					_alloc.destroy(old_start++);
				}
				old_start -= current_size;
				_alloc.deallocate(old_start, current_capacity);
			}
		}

		reference operator[](size_type n)
		{
			iterator current;

			current = this->begin();
			return (current[n]);
		}

		const_reference operator[](size_type n) const
		{
			const_reference 	current;

			current = this->begin();
			return (current[n]);
		}

		reference at(size_type n)
		{
			iterator	current;

			if (n >= this->size())
				throw std::out_of_range("is out of range");
			current = this->begin();
			return (current[n]);
		}

		const_reference	at(size_type n) const
		{
			iterator	current;

			if (n >= this->size())
				throw std::out_of_range("is out of range");
			current = this->begin();
			return (current[n]);
		}

		reference			front() 		{ return (*this->begin()); }
		const_reference		front()	const	{ return (*this->begin()); }
		reference			back() 			{ return (*(this->end() - 1)); }
		const_reference		back()	const	{ return (*(this->end - 1)); }
		value_type			*data() 		{ return (this->_start); }
		const value_type	*data()	const 	{ return (this->_start); }


		template <class	InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			size_type len;

			this->clear();
			while (first != last)
			{
				this->push_back(*first);
			}
		}
	private:
		allocator_type	_alloc;
		pointer 		_start;
		pointer 		_end;
		pointer			_end_capacity;
	};
}

#endif

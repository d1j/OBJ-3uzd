#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class Vector
{
public:
	using value_type = T;
	using reference = T &;
	using const_reference = const T &;
	using size_type = std::size_t;
	using pointer = T *;
	using iterator = T *;
	using const_iterator = const T *;

	//////////////////////CONSTRUCTORS//////////////////////
	//default
	Vector() : size_{0}, capacity_{0}, elem_{new value_type[0]} {}
	//fill with specified value
	Vector(size_type s, value_type val)
	{
		if (s < 0)
			throw std::out_of_range{"class Vector cannot contain negative amount of values"};
		size_ = s;
		capacity_ = size_;
		elem_ = new value_type[capacity_];

		std::fill_n(elem_, s, val);
	}
	//copy
	Vector(const Vector &vec) : size_{vec.size_},
								capacity_{vec.size_},
								elem_{new value_type[vec.size_]}
	{
		for (int i = 0; i != size_; ++i)
			elem_[i] = vec.elem_[i];
	}
	//initializer list
	Vector(std::initializer_list<value_type> il) : size_{il.size()},
												   capacity_{il.size()},
												   elem_{new value_type[il.size()]}
	{
		std::copy(il.begin(), il.end(), elem_);
	}
	//move
	Vector(Vector &&vec) : size_{vec.size_},
						   capacity_{vec.size_},
						   elem_{vec.elem_}
	{
		vec.elem_ = nullptr;
		vec.size_ = 0;
		vec.capacity_ = 0;
	}
	~Vector() { delete[] elem_; }

	//////////////////////METHODS//////////////////////
	//assign "size" amount of "values"
	void assign(size_type size, const_reference value)
	{
		if (size < 0)
			throw std::out_of_range{"Vector::assign"};
		delete[] elem_;
		size_ = size;
		capacity_ = size_;
		elem_ = new value_type[size_];
		std::fill_n(elem_, size_, value);
	}
	void assign(std::initializer_list<value_type> il)
	{
		delete[] elem_;
		size_ = il.size();
		capacity_ = size_;
		elem_ = new value_type[size_];
		std::copy(il.begin(), il.end(), elem_);
	}

	//element at specified position
	reference at(size_type pos)
	{
		if (pos < 0 || size() < pos)
			throw std::out_of_range{"Vector::at_ref"};
		return elem_[pos];
	}
	const_reference at(size_type pos) const
	{
		if (pos < 0 || size() < pos)
			throw std::out_of_range{"Vector::at_c_ref"};
		return elem_[pos];
	}

	//reference to the last element
	reference back() { return elem_[size() - 1]; }
	const_reference back() const { return elem_[size() - 1]; }

	//iterator pointing to the first element of the container
	iterator begin()
	{
		return &elem_[0];
	}

	//capacity of a Vector
	size_type capacity() const { return capacity_; }

	//size_ = 0, capacity stays the same
	void clear() noexcept
	{
		for (auto i = 0; i < size_; i++)
		{
			elem_[i].~value_type();
		}
		size_ = 0;
	}

	//pointer to the data of a vector
	pointer data() noexcept { return elem_; }
	const pointer data() const noexcept { return elem_; }

	//emplaces new object at specified pos and returns iterator, pointing to that place
	template <class... Ts>
	iterator emplace(const_iterator pos, Ts &&... args)
	{
		iterator tmp = begin();
		size_type i = 0;
		while (tmp != pos)
		{
			i++;
			tmp++;
		}
		tmp = nullptr;

		if (size_ + 1 > capacity_)
		{
			reserve(capacity_ * 2);
		}
		for (auto j = size_; j > i; j--)
		{
			elem_[j] = elem_[j - 1];
		}
		elem_[i] = value_type(std::forward<Ts>(args)...);

		size_++;

		return &elem_[i];
	}

	//emplaces new object back to the array
	template <typename... Ts>
	void emplace_back(Ts &&... args)
	{
		push_back(value_type(std::forward<Ts>(args)...));
	}

	//check if container is empty. //TODO: rebuild with iterators
	bool empty() const { return size_ == 0; }

	//next address after the last element
	iterator end() { return elem_ + size_; }

	//reference to the first element
	reference front() { return elem_[0]; }
	const_reference front() const { return elem_[0]; }

	//inserts new object at specified pos and returns iterator, pointing to that place
	iterator insert(iterator pos, const_reference value)
	{
		iterator tmp = begin();
		size_type i = 0;
		while (tmp != pos)
		{
			i++;
			tmp++;
		}
		tmp = nullptr;

		if (size_ + 1 > capacity_)
		{
			reserve(capacity_ * 2);
		}
		for (auto j = size_; j > i; j--)
		{
			elem_[j] = elem_[j - 1];
		}
		elem_[i] = value;

		size_++;

		return &elem_[i];
	}

	//removes last element from the container
	void pop_back()
	{
		if (size_ > 0)
		{
			elem_[--size_].~value_type();
		}
	}

	//pushes a new element to the back of the container
	void push_back(const_reference value)
	{
		if (capacity_ == 0)
		{
			elem_ = new value_type[1];
			elem_[0] = value;
			capacity_ = 1;
			size_ = 1;
		}
		else
		{
			if (!(size_ < capacity_))
			{
				reserve(capacity_ * 2);
			}
			elem_[size_++] = value;
		}
	}
	void push_back(T &&value)
	{
		if (capacity_ == 0)
		{
			elem_ = new value_type[1];
			elem_[0] = value;
			capacity_ = 1;
			size_ = 1;
		}
		else
		{
			if (!(size_ < capacity_))
			{
				reserve(capacity_ * 2);
			}
			elem_[size_++] = value;
		}
	}

	//reserve "new_cap" amount of memory
	void reserve(size_type new_cap)
	{
		if (capacity_ < new_cap)
		{
			value_type *tmp = new value_type[new_cap];
			for (auto i = 0; i < size_; i++)
			{
				tmp[i] = elem_[i];
			}
			delete[] elem_;
			elem_ = tmp;
			capacity_ = new_cap;
			tmp = nullptr;
		}
	}

	//resizes the container
	void resize(size_type count)
	{
		if (count < 0)
			throw std::out_of_range{"Vector::resize"};
		if (count < size_)
		{
			pointer tmp = new value_type[count];
			size_ = count;
			for (auto i = 0; i < size_; i++)
			{
				tmp[i] = elem_[i];
			}
			delete[] elem_;
			elem_ = tmp;
			tmp = nullptr;
		}
		else if ((count > size_ && count <= capacity_) || count > capacity_)
		{
			if (count > capacity_)
			{
				reserve(count);
			}
			pointer tmp = new value_type[count];
			for (auto i = 0; i < size_; i++)
			{
				tmp[i] = elem_[i];
			}
			for (auto i = size_; i < count; i++)
			{
				tmp[i] = value_type();
			}
			size_ = count;
			delete[] elem_;
			elem_ = tmp;
			tmp = nullptr;
		}
	}

	//size of a Vector
	size_type size() const { return size_; }

	//shrinks Vector capacity to size
	void shrink_to_fit()
	{
		if (size_ < capacity_)
		{
			value_type *tmp = new value_type[size_];
			for (auto i = 0; i < size_; i++)
			{
				tmp[i] = elem_[i];
			}
			delete[] elem_;
			elem_ = tmp;
			tmp = nullptr;
			capacity_ = size_;
		}
	}

	void swap(Vector &other)
	{
		Vector tmp = *this;
		*this = other;
		other = tmp;
	}
	//////////////////////OPERATORS//////////////////////
	//member access
	reference operator[](size_type i)
	{
		if (i < 0 || capacity() <= i)
			throw std::out_of_range{"Vector::operator[]"};
		return elem_[i];
	}
	//const memeber access
	const_reference operator[](size_type i) const
	{
		if (i < 0 || capacity() <= i)
			throw std::out_of_range{"Vector::operator[]_c"};
		return elem_[i];
	}
	//coppy assignmment
	Vector<value_type> &operator=(const Vector &vec)
	{
		if (&vec == this)
			return *this;
		pointer p = new value_type[vec.size_];
		for (int i = 0; i != vec.size_; ++i)
			p[i] = vec.elem_[i];
		delete[] elem_;
		elem_ = p;
		size_ = vec.size_;
		capacity_ = size_;
		return *this;
	}
	//move assignment
	Vector<value_type> &operator=(Vector &&vec)
	{
		if (&vec == this)
			return *this;
		delete[] elem_;
		elem_ = vec.elem_;
		size_ = vec.size_;
		capacity_ = size_;
		vec.elem_ = nullptr;
		vec.size_ = 0;
		vec.capacity_ = 0;
		return *this;
	}

private:
	pointer elem_;
	size_type size_;
	size_type capacity_;
};

#endif

//get_allocator

//rbegin
//rend

//max_size

//emplace

#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#include <stdexcept>
#include <iostream>

class TVector
{
public:
	using value_type = int;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;  
	int Num(iterator pos)
	{
		for (int i = 0; i < Count; i++)
		{
			if (Ptr[i] == *pos)
				return i;
		}
		return -1;
	}
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
	{
   		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		if (InternalCapacity > size)
			return;
		TVector copy(*this);
		Ptr = new value_type[size];
		for (size_type i = 0; i < Count; i++)
			Ptr[i] = copy.Ptr[i];
		InternalCapacity = size;
	}

	TVector(const TVector& rhs)
	:Count(rhs.Count)
	, InternalCapacity(rhs.InternalCapacity)
	{
		Ptr = new value_type[InternalCapacity];
		for (int i = 0; i < Count; i++)
		{
			Ptr[i] = rhs.Ptr[i];
		}
	}

	TVector& operator=(const TVector& rhs)
	{
		if (this == &rhs)
			return *this;
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		for (int i = 0; i < Count; i++)
		{
			Ptr[i] = rhs.Ptr[i];
		}
		return *this;
	}

	void push_back(const value_type& value)
	{
		if (Count + 1 > InternalCapacity)
			reserve(InternalCapacity + 1);
		Count++;
		Ptr[Count - 1] = value;
	}

	reference at(size_type index)
	{
		if (index >= Count || index < 0)
			throw std::out_of_range ("out of range!");
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index >= Count || index < 0)
			throw std::out_of_range("out of range!");
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		return Ptr[index];
	}

	reference front()
	{
		if (Ptr == nullptr)
			throw std::out_of_range("out of range!");
		return Ptr[0];
	}

	const_reference front() const
	{
		if (Ptr == nullptr)
			throw std::out_of_range("out of range!");
		return Ptr[0];
	}

	reference back()
	{
		if (Ptr == nullptr)
			throw std::out_of_range("out of range!");
		return Ptr[Count - 1];
	}  

	const_reference back() const
	{
		if (Ptr == nullptr)
			throw std::out_of_range("out of range!");
		return Ptr[Count - 1];
	}

	void clear()
	{
		delete []Ptr;
		Count = 0;
		InternalCapacity = 0;
	}

	void pop_back()
	{
		if (Count == 0)
			throw std::out_of_range("out of range!");
		Count--;
	}

	void swap(TVector& other) throw()
	{
		std::swap(Ptr, other.Ptr);
		std::swap(Count, other.Count);
		std::swap(InternalCapacity, other.InternalCapacity);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count > InternalCapacity)
			reserve(count);
		for (int i = Count; i < count; i++)
		{
			Ptr[i] = value;
		}
		Count = count;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		Count++;
		if (Count > InternalCapacity)
			reserve(InternalCapacity + 1);
		int Pos = Num(pos);
		for (int i = Count - 1; i > Pos; i--)
		{
			Ptr[i] = Ptr[i - 1];
		}
		Ptr[Pos] = value;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		Count += count;
		if (Count > InternalCapacity)
			reserve(InternalCapacity + count);
		for (int i = Count - 1; i > Num(pos); i--)
		{
			Ptr[i] = Ptr[i - count];
		}
		for (int i = Num(pos); i < Num(pos) + count; i++)
		{
			Ptr[i] = value;
		}
	}

	iterator erase(iterator pos)
	{
		if (Num(pos) >= Count &&  Num(pos) < 0)
			throw std::out_of_range("out of range!");
		for (int i = Num(pos); i < Count - 1; i++)
		{
			Ptr[i] = Ptr[i + 1];
		}
		Count--;
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		if (Num(first) >= Count && Num(last) >= Count && Num(first) < 0 && Num(last) < Count)
			throw std::out_of_range("out of range!");
		for (int i = 0; i < Count; i++)
		{
			*(first + i) = *(last + i);
		}
		Count -= (last - first);
		return first;
	}	
};

#endif // __TVECTOR_INCLUDED__

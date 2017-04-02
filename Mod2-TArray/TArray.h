#include <initializer_list>
#include <exception>

template<class T, std::size_t N> 

struct TArray
{
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

	value_type Arr[N];
	size_type Count;

	TArray() = default;

	~TArray() = default;
	
	reference at(size_type index)
	{
		if (index >= Count || index < 0)
			throw std::out_of_range("out of range!");
		return Arr[index];
	}

	const reference at(size_type index) const
	{
		if (index >= Count || index < 0)
			throw std::out_of_range("out of range!");
		return Arr[index];
	}
	
	reference operator[](size_type  index)
	{
		return Arr[index];
	}
	
	const_reference operator[](size_type  index) const
	{
		return Arr[index];
	}
	
	reference front()
	{
		return Arr[0];
	}

	const_reference front() const
	{
		return Arr[0];
	}
		
	reference back()
	{
		return Arr[Count - 1];
	}

	const_reference back() const
	{
		return Arr[Count - 1];
	}
		
	iterator data() 
	{
		return Arr;
	}

	const iterator data() const
	{
		return Arr;
	}

	bool empty() const throw()
	   {
			return size() == 0;
		}

	size_type size() const throw()
	   {
		   return Count;
	   }

	size_type max_size() const throw()
	   {
		   return N;
	   }

	iterator begin() const throw()
	   {
		   return Arr;
	   }

	iterator end() const throw()
	   {
		   return Arr + Count;
	   }
	
	void fill(const T& value)
	   {
		   for (int i = 0; i < Count; i++)
		   {
			   Arr[i] = value;
		   }
	   }

	void swap(TArray& other) 
	{
		std::swap(Arr, other.Arr);
		std::swap(Count, other.Count);
	}

	TArray(std::initializer_list<T> init)
	{
		size_type size = 0;
		for (auto i : init){
			Arr[size] = i;
			size++;
		}
		Count = size;
	}
};
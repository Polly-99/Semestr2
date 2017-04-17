#include<initializer_list>

// узел дерева
template<class T>
struct TTree 
{
	T Data;
	TTree * Parent;
	TTree * Left;
	TTree * Right;
	int Count;

	TTree()
		:Count(0)
		, Data(0)
		, Left(nullptr)
		, Right(nullptr)
		, Parent(nullptr)
	{}

	TTree(const T & value)
		: Count(1)
		, Data(value)
		, Left(nullptr)
		, Right(nullptr)
		, Parent(nullptr)
	{}

	~TTree()
	{}

	void add()
	{
		Count++;
	}
};

//итератоp
template <class T>
class Iterator
{
	TTree <T> * Ptr;
public: 

	Iterator()
		:Ptr(nullptr)
	{}

	Iterator(TTree <T> & rhs)
		:Ptr(&rhs)
	{}

	Iterator(const Iterator <T> & rhs)
		:Ptr(rhs.Ptr)
	{}

	~Iterator()
	{}

	TTree <T> & operator * ()
	{
		return *Ptr;
	}

	TTree <T> * operator -> ()
	{
		return Ptr;
	}

	//проверка на последний элемент
	bool end()
	{
		if (Ptr->Right != nullptr)
			return 0;
		Iterator cur(*this);
		while (cur.Ptr->Parent != nullptr)
		{
			cur = *cur.Ptr->Parent;
			if (Ptr->Data < cur.Ptr->Data)
				return 0;
		}
		return 1;
	}

	//проверка на первый элемент
	bool begin()
	{
		if (Ptr->Left != nullptr)
			return 0;
		Iterator cur(*this);
		while (cur.Ptr->Parent != nullptr)
		{
			cur = *cur.Ptr->Parent;
			if (Ptr->Data > cur.Ptr->Data)
				return 0;
		}
		return 1;
	}

	Iterator & operator = (TTree<T> & rhs)
	{
		Ptr = &rhs;
		return *this;
	}

	bool operator != (Iterator & rhs)
	{
		if (Ptr == rhs.Ptr)
			return 0;
		return 1;
	}

	Iterator& operator ++ ()
	{
		if (this->end())
		{
			Iterator <T> END(*Ptr->Right);
			return END;
		}
		if (Ptr->Right != nullptr)
		{
			*this = *(Ptr->Right);
			while (Ptr->Left != nullptr)
				*this = *(Ptr->Left);
			return *this;
		}
		Iterator cur(*this);
		do
		{
			*this = *(Ptr->Parent);
		} while ( Ptr->Parent != nullptr && cur.Ptr->Data > Ptr->Data );
		return *this;
	}
	
	Iterator operator -- ()
	{
		if (begin())
			return *this;
		if (Ptr->Left != nullptr)
		{
			*this = *(Ptr->Left);
			while (Ptr->Right != nullptr)
				*this = *(Ptr->Right);
			return *this;
		}
		Iterator cur(*this);
		do
		{
			*this = *(Ptr->Parent);
		} while (Ptr->Parent != nullptr && cur.Ptr->Data < Ptr->Data);
		return *this;
	}

	/*void deleted()
	{
		Ptr->Left = nullptr;
		Ptr->Right = nullptr;
		Ptr->Parent = nullptr;
		delete Ptr;
	}*/
};

//компаратор
template<typename T>
struct less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

template<typename T, typename Cmp = less<T>>
class TMultiset
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = Iterator <T>;
	using reference = value_type&;
	using const_reference = const value_type&;
private:
	TTree <T> * Root;
	TTree <T> * End;
public:
	TMultiset()
		:Root(nullptr)
	{}

	TMultiset(std::initializer_list<T> init)
	{
		for (auto &i : init)
			insert(init);	
	}

	~TMultiset()
	{
		delete Root;
	}

	bool empty() const throw()
	{
		if (Root == nullptr)
			return 1;
		return 0;
	}

	iterator begin() throw()
	{
		Iterator <T> cur(*Root);
		while (!cur.begin())
		{
			--cur;
		}
		return cur;
	}

	iterator end() throw()
	{
		return *End;
	}

	size_type size()  throw()
	{ 
		size_t Num = 0;
		Iterator <T> cur = begin();
		do
		{
			++Num;
			++cur;
		} while (cur != end());
		return Num;
	}

	iterator insert(const value_type & value)
	{
		if (Root == nullptr)
		{
			Root = new TTree<value_type>(value);
			End = new TTree<value_type>;
			Root->Right = End;
			End->Parent = Root;
			return *Root;
		}
		TTree <value_type> * next = Root;
		TTree <value_type> * prev = next;
		while (next != End && next != nullptr)
		{
			prev = next;
			if (Cmp ()(value, next->Data))
				next = next->Left;
			else
			{
				if (value == next->Data)
				{
					next->add();
					return *next;
				}
				next = next->Right;
			}
		}
		TTree<value_type> * List = new TTree<value_type>(value);
		if (Cmp()(value, prev->Data))
			prev->Left = List;
		else
		{
			if (prev->Right == End)
			{
				List->Right = End;
				End->Parent = List;
				prev->Right = List;
			}
			else
				prev->Right = List;
		}	
		List->Parent = prev;
		return *List;
	}

	iterator find(const value_type & value)
	{
		Iterator <T> cur = begin();
		while (cur->Data != value && cur != end())
		{
			++cur;
		}
		return cur;
	}

	iterator erase(iterator Node)
	{
		Iterator <T> cur;
		Iterator <T> cur1;
		bool ind = 0;  //указывает на то, есть ли у узла потомки
		if (Node->Right != nullptr && Node->Right != End)
		{
			cur = *(Node->Right);
			ind++;
			cur1 = *(Node->Right);
			if (Node->Left != nullptr) // если у удаляемого узла есть левый узел, прикрепляем его к правому
			{
				while (cur1->Left != nullptr)
					cur1 = *(cur1->Left);
				cur1->Left = Node->Left;
			}
		}
		else
		{
			if (Node->Left != nullptr)
			{
				cur = *(Node->Left);
				ind++;
				if (Node->Right == End)
				{
					cur1 = *(Node->Left);
					while (cur1->Right != nullptr)
						cur1 = *(cur1->Right);
					cur1->Right = End;
				}
			}
		}
		if (Node->Parent != nullptr)
		{
			if (ind)
			{
				cur->Parent = Node->Parent;
				if (Node->Data < Node->Parent->Data) //значит узел находится слева от родителя
					*(Node->Parent->Left) = *cur;
				else //значит узел справа
					*(Node->Parent->Right) = *cur;
			}
			else
			{
				if (Node->Data < Node->Parent->Data)
					Node->Parent->Left = nullptr;
				else
					Node->Parent->Right = nullptr;
				cur = *(Node->Parent);
			}
		}
		else
		{
			if (ind)
			{
				*Root = *cur;
				Root->Parent = nullptr;
				return *Root;
			}
			else
			{
				delete Root;
				Root = nullptr;
				return *End;
			}
		}
		return cur;
	}

	iterator erase(iterator first, iterator last)
	{
		Iterator <T> del = first;
		while (del != last)
		{
			del = erase(del);
		}
		return last;
	}

	size_type erase(const value_type & value)
	{
		size_t Num = 0;
		Iterator<T> Node = find(value);
		erase(Node);
		Num = Node->Count;
		return Num;
	}

	void swap(TMultiset <T> & other)
	{
		std::swap(Root, other.Root);
		std::swap(End, other.End);
	}

	void clear()
	{
		erase(begin(), end());
	}

	void Print()
	{
		Iterator <T> cur = begin();
		do
		{
			for (int i = 0; i < cur->Count; i++)
				std::cout << cur->Data << " ";
			++cur;
		} while (cur != end());
		std::cout << std::endl;
	}
};

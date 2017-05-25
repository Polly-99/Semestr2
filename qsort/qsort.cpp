#include <iostream>
#include <vector>

static int count = 0;

template<class It, class Cmp>
It get_opr(It beg, It end, Cmp cmp)
{
	It opr = beg;
	int size = 0;
	while (opr != end)
	{
		size++;
		opr++;
	}
	opr = beg;
	int num = 0;
	while (num != size / 2)
	{
		num++;
		opr++;
	}
	if (cmp(*opr, *beg))
		std::swap(beg, opr);
	if (cmp(*end, *opr))
		std::swap(end, opr);
	if (cmp(*opr, *beg))
		std::swap(beg, opr);
	return opr;
}

template<class It, class Cmp>
It partition(It beg, It end, Cmp cmp)
{
	bool flag = false, flag1 = false;
	It i = beg, j = end - 1, pivot = get_opr(beg, end - 1, cmp);
		while (i != j && (*i != *j || i + 1 != j))
		{
			flag1 = false;
			while (cmp(*i, *pivot))
				i++;
			while (i != j && cmp(*pivot, *j))
				j--;
			if (*i == *j && i != j)
			{
				i++;
				flag = true;
				flag1 = true;
				
			}
			if (i != j)
			{
				flag = false;
				if (flag1)
				{
					if (*i > *j)
					{
						std::swap(*pivot, *j);
						pivot = j;
					}
					else
					{
						std::swap(*pivot, *i);
						pivot = i;
					}
				}
				else{
					if (pivot == j)
						pivot = i;
					else {
						if (pivot == i)
							pivot = j;
					}
					std::swap(*i, *j);
				}
			}
	}
	if (flag)
		i--;
	return i;
}

template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp)
{
	if (beg != end - 1)
	{
		It i = partition(beg, end, cmp);
		qsort(beg, i + 1, cmp);
		qsort(i + 1, end, cmp);
	}
}

int main()
{
	std::vector<int> a = { 9, 3, 4, 7, 4, 8, 5, 2, 1, 9, 5 };
	std::less<int> l;
	std::cout << "Array before" << std::endl;
	for (auto it = a.begin(); it != a.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	qsort(a.begin(), a.end(), l);
	std::cout << "Array after" << std::endl;
	for (auto it = a.begin(); it != a.end(); ++it)
	{
		std::cout << *it << " ";
	}
	system("pause");
}

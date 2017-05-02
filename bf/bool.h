#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__
#include <string>
#include <vector>
#include <math.h>
#include <exception>
#include <iostream>

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = std::vector<value_type>::iterator;
	using const_iterator = std::vector<value_type>::const_iterator;

private:
	std::vector <bool> bf;

public:

	// ���������� ������� ������� ����� xn � ������������ dimension
	// ������ 1
	// n = 0
	// dimension = 3
	// �������� ������� "01010101"
	// ������ 2
	// n = 1
	// dimension = 4
	// �������� ������� "0011001100110011"

	static boolean_function var(size_t n, size_t dimension)
	{
		boolean_function rhs;
		int i = 0;
		while (i != pow(2, dimension))
		{
			for (int j = 0; j < pow(2, dimension) / pow(2, dimension - n); j++)
			{
				rhs.bf.push_back(0);
				i++;
			}
			for (int j = 0; j < pow(2, dimension) / pow(2, dimension - n); j++)
			{
				rhs.bf.push_back(1);
				i++;
			}
		}
		return rhs;
	}

	// ������������� ���� "�� dimension ����������"
	static boolean_function zero(size_t dimension)
	{
		boolean_function rhs;
		for (int i = 0; i < pow(2, dimension); i++)
			rhs.bf.push_back(0);
		return rhs;
	}

	// ������������� ������� "�� dimension ����������"
	static boolean_function one(size_t dimension)
	{
		boolean_function rhs;
		for (int i = 0; i < pow(2, dimension); i++)
			rhs.bf.push_back(1);
		return rhs;
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		boolean_function rhs(v);
		rhs = rhs.anf();
		return rhs;
	}

	boolean_function()
	{}

	// ������ ������ �������������� ���� �� n ����������
	boolean_function(size_t n)
	{
		for (int i = 0; i < pow(2, n); i++)
			bf.push_back(0);
	}

	// ������ ������ ��   n ����������. �������� ����� value
	// ������
	// ����� value = 14, �.�. 0...00001110 � �������� �������
	// � n = 3
	// ����� ��� boolean_function ����� ����� x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		int i = 0;
		while (value != 0)
		{
			bf.push_back(value % 2);
			value = value / 2;
			i++;
		}
		while (i < pow(2, n))
		{
			bf.push_back(0);
			i++;
		}
	}


	// ����� table = "01110000"
	// ����� ��� boolean_function ����� ����� x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table) 
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i] != '1' && table[i] != '0')
				throw;
			if (table[i] == '1')
				bf.push_back(1);
			else
				bf.push_back(0);
		}
		if (log2(bf.size()) - (dimension()) != 0)
			throw std::exception();
	}

	// ����� table = {true, false, false, true};
	// ����� ��� boolean_function ����� ����� x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i] != true)
				bf.push_back(table[1]);
			if (table[i] != false)
				bf.push_back(table[0]);
		}
		if (log2(bf.size()) - (dimension()) != 0)
			throw std::exception();
	}

	boolean_function(const std::initializer_list<bool> vars)
	{
		for (auto &i : vars)
			bf.insert(end(), vars);
		if (log2(bf.size()) - (dimension()) != 0)
			throw std::exception();
	}

	boolean_function(const boolean_function& table)
	{
		bf = table.bf;
	}

	boolean_function& operator=(const boolean_function& rhs)
	{
		if (bf == rhs.bf)
			return *this;
		bf = rhs.bf;
		return *this;
	}

	// �������� �� ������ 2
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception();
		for (int i = 0; i < bf.size(); i++)
			bf[i] = abs(bf[i] - rhs.bf[i]);
		return *this;
	}

	// ����������
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception();
		for (int i = 0; i < bf.size(); i++)
			bf[i] = rhs.bf[i] * bf[i];
		return *this;
	}

	// ����������
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception();
		for (int i = 0; i < bf.size(); i++)
			bf[i] = bf[i] + rhs.bf[i] - bf[i] * rhs.bf[i];
		return *this;
	}

	// ��������� ���������
	boolean_function operator ~ ()
	{
		for (int i = 0; i < bf.size(); i++)
			bf[i] = abs(1 - bf[i]);
		return *this;
	}

	// true ���� ������� �����
	//  ����� false
	bool operator == (const boolean_function& rhs) const
	{
		int num = size();
		if (size() > rhs.size())
			num = rhs.size();
		for (int i = 0; i < num; i++)
		{
			if (bf[i] != rhs.bf[i])
				return false;
		}
		return true;
	}

	// true ���� ���� ������� �������� � ������ ��� ����� rhs
	// false ���� �������� � ������ rhs
	// logic_error ���� ������ �� ��������

	bool operator >= (const boolean_function& rhs) const
	{
		int i = 0;
		while (bf[i] == rhs.bf[i] && i < size() - 1)
			i++;
		if (bf[i] - rhs.bf[i] == -1)
		{
			for (i; i < size(); i++)
			{
				if (bf[i] - rhs.bf[i] == 1)
					throw std::logic_error("ERROR");
			}
			return false;
		}
		for (i; i < size(); i++)
		{
			if (bf[i] - rhs.bf[i] == -1)
				throw std::logic_error("ERROR");
		}
		return true;
	}

	reference operator[](size_type ind)
	{
		return bf[ind];
	}

	const_reference operator[](size_type ind) const
	{
		return bf[ind];
	}

	reference at(size_type ind)
	{
		if (ind < 0 || ind > size() - 1 || size() == 0)
			throw std::exception();
		return bf[ind];
	}

	const_reference at(size_type ind) const
	{
		if (ind < 0 || ind > size() - 1 || size() == 0)
			throw std::exception();
		return bf[ind];
	}

	iterator begin()
	{
		return bf.begin();
	}
	iterator end()
	{
		return bf.end();
	}

	const_iterator cbegin() const
	{
		return bf.cbegin();
	}
	const_iterator cend() const
	{
		return bf.cend();
	}

	// ����� ������� �������
	size_type size() const throw()
	{
		return bf.size();
	}

	// ���������� ����������
	size_type dimension() const throw()
	{
		return log2(bf.size());
	}

	// ���������� �������� �������
	// ����� boolean_function ������ ������� f(x, y, z)
	// ����� ������� ������ f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const
	{
		if (vars.size() != dimension())
			throw std::exception();
		int Num = 0;
		for (int i = 0; i < vars.size(); i++)
			Num = Num + vars[i] * pow(2, vars.size() - 1 - i);
		return bf[Num];
	}

	bool operator()(const std::initializer_list <bool> vars) const
	{
		if (vars.size() != dimension())
			throw std::exception();
		int Num = 0, i = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it)
		{
			Num += *it * pow(2, vars.size() - 1 - i);
			i++;
		}
		return bf[Num];
	}


	// T(x1, x2, ..., xN) - ������� �������
	// operator ������ ����� �������, ������� ����� ���������� G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const
	{
		std::vector<value_type> res;
		std::vector<boolean_function> f;

		int s = 0;
		for (int i = 0; i < fs.size(); i++)
		{
			if (fs[i].size() > s)
				s = fs[i].size();
			f.push_back(fs[i]);
		}

		int len = fs.size();
		int** mas = new int*[s];
		for (int i = 0; i < s; i++)
		{
			mas[i] = new int[len];
		}

		int it = 0;
		while (it < f.size())
		{
			for (int i = 0; i < len; i++)
			{
				int k = 0;
				for (int j = 0; j < s; j++)
				{
					if (k >= f[it].size())
						k = 0;
					mas[j][i] = f[it][k];
					k++;
				}
				it++;
			}
		}

		for (int i = 0; i < s; i++)
		{
			int ch = 0;
			int st = 0;
			for (int j = len - 1; j > -1; j--)
			{
				ch = ch + pow(2, st)*mas[i][j];
				st++;
			}
			res.push_back(bf[ch]);
		}
		for (int i = 0; i < s; i++)
			delete[] mas[i];

		delete[] mas;

		boolean_function result(res);
		return result;
	}


	/*boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		if (vars.size() != dimension())
			throw std::exception();
		boolean_function res;
		int num = 0;
		for (int i = 0; i < vars.size(); i++)
		{
			std::vector <value_type> vec;
			for (auto it = vars.begin(); it != vars.end(); ++it)
			{
				std::vector <value_type> vec;
				vec.push_back((*it).bf[i]);
			}
			res[num] = (*this)(vec);
		}*/

	bool is_monotone() const
	{
		for (int i = 0; i < size() / 2; i++)
		{
			if (bf[i] - bf[i + size() / 2] > 0)
				return 0;
		}
		return 1;
	}

	bool is_symmetric() const
	{
		boolean_function otr = *this;
		otr = ~otr;
		for (int i = 0; i < size() / 2; i++)
		{
			
			if (otr[i] != bf[size() - 1 - i])
				return 0;
		}
		return 1;
	}

	bool is_linear() const
	{
		std::vector<value_type> ANF = anf();
		for (int i = 1; i < size(); i++) {
			if (ANF[i] == 1 && log2(i) - (int)log2(i) != 0) 
				return false;
		}
		return  true;
	}

	bool is_T1() const
	{
		if (bf[size() - 1] == 1)
			return 1;
		return 0;
	}

	bool is_T0() const
	{
		if (bf[0] == 0)
			return 1;
		return 0;
	}

	bool is_balanced() const //����������� ��
	{
		if (weight() == size() - weight())
			return 1;
		return 0;
	}

	size_t weight() const
	{
		size_t Weight = 0;
		for (int i = 0; i < size(); i++)
		{
			if (bf[i] == 1)
				Weight++;
		}
		return Weight;
	}

	bool is_functionally_complete_system() const
	{
		if (is_monotone() || is_symmetric() || is_linear() || is_T1() || is_T0())
			return 0;
		return 1;
	}

	// ���������� ��� �������
	std::vector<value_type> anf() const
	{
		std::vector<value_type> a;
		boolean_function rhs = *this;
		while (rhs.size() != 0)
		{
			a.push_back(rhs[0]);
			for (int i = 0; i < rhs.size() - 1; i++)
				rhs[i] = abs(rhs[i] - rhs[i + 1]);
			rhs.bf.pop_back();
		}
		return a;
	}

};

	// ����� boolean_function ������������ �� ���� ������� "01110000"
	// ����� get_polynom ������ ������ "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
	std::string get_polynom(const boolean_function& f);

	boolean_function operator + (const boolean_function& a, const boolean_function& b)
	{
		boolean_function res = a;
		res += b;
		return res;
	}

	boolean_function operator * (const boolean_function& a, const boolean_function& b)
	{
		boolean_function res = a;
		res *= b;
		return res;
	}

	boolean_function operator | (const boolean_function& a, const boolean_function& b)
	{
		boolean_function res = a;
		res |= b;
		return res;
	}

	bool operator != (const boolean_function& a, const boolean_function& b)
	{
		if (a == b)
			return 0;
		return 1;
	}
#endif  __BOOLEAN_FUNCTION_INCLUDED__
#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__
#include <string>
#include <vector>
#include <math.h>
#include <exception>
#include <iostream>

std::vector <bool> perevod(int num, int dim)
{
	std::vector <bool> res;
	int i = 0;
	while (num != 0)
	{
		res.push_back(num % 2);
		num = num / 2;
		i++;
	}
	while (i < pow(2, dim))
	{
		res.push_back(0);
		i++;
	}
	return res;
}

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;

private:
	std::vector <bool> bf;

public:

	// возвращает функцию которая равна xn с размерностью dimension
	// пример 1
	// n = 0
	// dimension = 3
	// вернется функция "01010101"
	// пример 2
	// n = 1
	// dimension = 4
	// вернется функция "0011001100110011"

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

	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension)
	{
		boolean_function rhs;
		for (int i = 0; i < pow(2, dimension); i++)
			rhs.bf.push_back(0);
		return rhs;
	}

	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension)
	{
		boolean_function rhs;
		for (int i = 0; i < pow(2, dimension); i++)
			rhs.bf.push_back(1);
		return rhs;
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		boolean_function res(v);
		res = res.anf();
		return res;
	}

	boolean_function()
	{}

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n)
	{
		for (int i = 0; i < pow(2, n); i++)
			bf.push_back(0);
	}

	// задает фунцию от   n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
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


	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
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

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i] == true)
				bf.push_back(1);
			if (table[i] == false)
				bf.push_back(0);
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

	// сложение по модулю 2
	// если разное количество переменных - исключение
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception();
		for (int i = 0; i < bf.size(); i++)
			bf[i] = abs(bf[i] - rhs.bf[i]);
		return *this;
	}

	// конъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception();
		for (int i = 0; i < bf.size(); i++)
			bf[i] = rhs.bf[i] * bf[i];
		return *this;
	}

	// дизъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception();
		for (int i = 0; i < bf.size(); i++)
			bf[i] = bf[i] + rhs.bf[i] - bf[i] * rhs.bf[i];
		return *this;
	}

	// побитовое отрицание
	boolean_function operator ~ ()
	{
		for (int i = 0; i < bf.size(); i++)
			bf[i] = abs(1 - bf[i]);
		return *this;
	}

	// true если функции равны
	//  иначе false
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

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы

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

	// длина столбца функции
	size_type size() const throw()
	{
		return bf.size();
	}

	// количество переменных
	size_type dimension() const throw()
	{
		return log2(bf.size());
	}

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
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
		std::vector<bool> vec = vars;
		return (*this)(vec);
	}

	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const
	{
		if (fs.size() != dimension())
			throw std::exception();
		std::vector <value_type> vec;
		int Size = 0;
		for (int i = 0; i < fs.size(); i++)
		{
			if (fs[i].size() > Size)
				Size = fs[i].size();
		}
		for (int j = 0; j < Size; j++)
		{
			std::vector <value_type> vec1;
			for (int i = 0; i < fs.size(); i++)
			{
				int z = j;
				if (fs[i].size() != Size)
				{
					while (z >= fs[i].size())
						z = z - fs[i].size();
				}
				vec1.push_back(fs[i].bf[z]);
			}
			vec.push_back((*this)(vec1));
		}
		boolean_function res(vec);
		return res;
	}

	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		std::vector<boolean_function> vec = vars;
		return (*this)(vec);
	}

	bool is_monotone() const
	{
		for (int i = 0; i < size() - 1; i++)
		{
			for (int j = i + 1; j < size(); j++)
			{
				boolean_function a( perevod (i, dimension()));
				boolean_function b(perevod(j, dimension()));
				try
				{
					if (b >= a)
					{
						if (bf[i] > bf[j])
							return false;
					}
				}
				catch (const std::logic_error & e)
				{ }
			}
		}
		return true;
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

	bool is_balanced() const //равновесная ли
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

	// Возвращает АНФ функции
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

	// пусть boolean_function представляет из себя функцию "01110000"
	// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function& f)
{
	boolean_function ANF = f.anf();
	std::string str;
	bool ind = false;
	for (int i = 0; i < ANF.size(); i++)
	{
		if (ANF[i] != 0)
		{
			if (ind)
				str += " + ";
			for (int j = 0; j < f.dimension(); j++)
			{
				if ((f.var(j, f.dimension()))[i] == 1)
				{
					str += "x";
					char a = 48 + j;
					str += a;
					ind = true;
				}
			}
		}
	}
	return str;
}

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

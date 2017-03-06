#include <iostream>
#include <string>
#include <fstream>
bool find_end(std::string const & line, int pos)
{
	std::string symbol = "!@#$%^&*()№;:?*{}[] \ /.,<>~` - _ =+";
	for (size_t j = 0; j < symbol.length(); j++)
	{
			if (symbol[j] == line[pos]) return 1;
	}
	return 0;
}
std::string find_word(std::string const & word, std::string const & line, int pos_poiska)
{
	std::string str;
	int pos = line.find(word, pos_poiska), pos_last = pos + 1, pos_first = pos - 1;
	if (pos == -1){
		str = "ERROR!";
		return str;
	}
	if (pos_first < 0)
	{
		pos_first = pos;
	}
	else
	{
		while (find_end (line, pos_first) != 1)
		{
			if (pos_first == 0) 
			{
				break;
			}
			pos_first--;
		}
		if (pos_first != 0)
		{
			pos_first++;
		}
	}
	while (find_end(line, pos_last) != 1)
	{
		if (pos_last == line.length())
		{
			break;
		}
		pos_last++;
	}
	int letters = pos_last - pos_first;
	str = line.substr(pos_first, letters);
	return str;
}
std::string find_neighbor_word(std::string const & word, std::string const & line, int pos_poiska, int number)
{
	std::string before, after, str1, str;
	str1 = find_word(word, line, pos_poiska);
	if (str1 == "ERROR!") return str1;
	if (number == 0)
	{
		return str1;
	}
	int pos1 = line.find(word, pos_poiska);
	std::string copy_line, neighbor;
	copy_line = line;
	copy_line = copy_line.erase(0, str1.length() - str1.find(word) + pos1);
	if (copy_line.length() != 0) {
		for (int i = 0; i < number; i++)
		{
			int pos = 1;
			while (find_end(copy_line, pos) != 1)
			{
				if (pos == copy_line.length())
				{
					break;
				}
				pos++;
			}
			neighbor = copy_line.substr(0, pos + 1);
			after += neighbor;
			copy_line.erase(0, pos + 1);
			if (copy_line.length() == 0) break;
		}
		if (find_end(after, after.length() - 1)){
			after = after.erase(after.length() - 1, 1);
		}
	}
	copy_line = line;
	while (find_end (copy_line, pos1) != 1)
	{
		if (pos1 == 0)
		{
			str = str1 + after;
			break;
		}
		pos1--;
	}
	if (pos1 != 0) {
		copy_line = copy_line.erase(pos1 + 1, line.length());
		for (int i = 0; i < number; i++)
		{
			if (copy_line.length() == 0)
			{
				break;
			}
			int pos = copy_line.length() - 2;
			while (find_end(copy_line, pos) != 1)
			{
				if (pos == 0)
				{
					break;
				}
				pos--;
			}
			neighbor = copy_line.substr(pos, copy_line.length() - pos + 1);
			before = neighbor + before;
			copy_line.erase(pos, copy_line.length() - pos);
		}
		if (find_end (before, 0 )){
			before = before.erase(0, 1);
		}
		str = before + str1 + after;
	}
	return str;
}
void find_all_words(std::string const & word, std::string const & filename, int n)
{
	std::fstream file(filename, std::fstream::in);
	std::string line, str, str1;
	int pos = 0;
	while (!file.eof()){
		int pos_poiska = 0;
		std::getline(file, line);
		str1 = "0";
		while (str1 != "ERROR!"){
			str = find_neighbor_word(word, line, pos_poiska, n);
			if (str != "ERROR!"){
				std::cout << str << std::endl << std::endl;
			}
			str1 = find_word(word, line, pos_poiska);
			pos = line.find(str1);
			pos_poiska = pos + str1.length() + 1;
			str1 = find_word(word, line, pos_poiska);
		}
	}
}
int main()
{
	std::string str;
	int n = 0;
	std::cout << "Vvedite slovo:";
	std::cin >> str;
	int t = 0;
	std::cout << "Vvedite kol-vo sosednih slov: ";
	std::cin >> n;
	if (n < 0)
	{
		std::cout << "ERROR" << std::endl;
	}
	find_all_words(str, "C:\\Test\\list.txt", n);
	system("pause");
}

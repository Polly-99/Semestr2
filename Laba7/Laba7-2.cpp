#include <iostream>
#include <string>
#include <fstream>
std::string find_word(std::string word, std::string line)
{
	std::string str;
	int pos = line.find(word), pos_last = pos + 1, pos_first = pos - 1;
	if (pos == -1){
		str = "ERROR!";
		return str;
	}
	if (pos_first < 0) pos_first = pos;
	else
	{
		while (line[pos_first] != ' ' && pos_first != 0) pos_first--;
		if (line[pos_first] == ' ')	pos_first++;
	}
	while (line[pos_last] != ' ' && line[pos_last] != '\0')	pos_last++;
	int letters = pos_last - pos_first;
	str = line.substr(pos_first, letters);
	return str;
}
std::string find_neighbor_word(std::string word, std::string line, int number)                          
{
	std::string before, after, str1, str;
	str1 = find_word(word, line);
	if (number < 0)
	{
		str1 = "ERROR";
		return str1;
	}
	if (number == 0) return str1;
	int pos1 = line.find(word);
	std::string str2, str3;
	str2 = line;
	str2 = str2.erase(0, str1.length() - str1.find(word)+ pos1 + 1);
	for (int i = 0; i < number; i++)
	{
		int pos = str2.find(" ");
		if (pos == -1)	pos = str2.length();
		str3 = str2.substr(0, pos+1);
		after += str3;
		str2.erase(0, pos + 1);
	}
	str2 = line;
	while (str2[pos1] != ' ' && pos1 != 0) pos1--;
	if (pos1 == 0)
	{
		str1.push_back(' ');
		str = str1 + after;
	}
	else {
		str2 = str2.erase(pos1, line.length());
		for (int i = 0; i < number; i++)
		{
			if (str2.length() == 0) break;
			int pos = str2.find_last_of(" ");
			if (pos == -1) pos = 0;
			str3 = str2.substr(pos, str2.length() - pos);
			before = str3 + before;
			str2.erase(pos, str2.length() - pos);
		}
		str1.push_back(' ');
		before.push_back(' ');
		str = before + str1 + after;
	}
	if (str[0] == ' ') str.erase(0, 1);
	return str;
}
void find_all_words(std::string word, std::string filename, int n)
{
	std::fstream file(filename, std::fstream::in);
	std::string line, str, str1;
	while (file){
		std::getline(file, line);
		str1 = find_word(word, line);
		int pos = line.find(str1);
		while (pos != -1){
			str = find_neighbor_word(word, line, n);
			std::cout << str << std::endl;
			line = line.erase(0, pos + str1.length() + 1);
			str1 = find_word(word, line);
			pos = line.find(str1);
		}
	}
}
int main()
{
	std::string str;
	int n = 0;
	std::cout << "Vvedite slovo:";
	std::cin >> str;
	std::cout << "Vvedite kol-vo sosednih slov: ";
	std::cin >> n;
	find_all_words(str, "C:\\Test\\list.txt", n);
	system("pause");
}
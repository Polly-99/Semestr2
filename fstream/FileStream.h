#include <iostream>
#include <vector>

class FileStream
{
	FILE * file;

public:

	FileStream() = default;

	FileStream(const char *filename, const char *mode)
	{
		fopen_s(&file, filename, mode);
		if (!file)
			throw std::exception("This file doesn't exist");
	}

	~FileStream()
	{
		if (file)
			close();
	}

	void open(const char *filename,	const char *mode)
	{
		if (file)
			throw std::exception("This file is allready open");
		fopen_s(&file, filename, mode);
		if (!file)
			throw std::exception("This file doesn't exist");
	}

	void close()
	{
		if (!file)
			throw std::exception("This file was not open");
		fclose(file);
		file = nullptr;
	}

	bool is_open() const
	{
		return (file);
	}

	bool eof()
	{
		return feof(file);
	}

	FileStream & operator<<(const char * string)
	{
		if (is_open())
			fputs(string, file);
		return *this;
	}

	FileStream & operator >> (std::string & string)
	{
		if (is_open())
		{
			while (!eof())
				string = getline();
		}
		return *this;
	}

	std::string getline()
	{
		if (!file)
			throw std::exception("This file was not open");
		std::vector<char> str;
		while (!eof())
		{
			char c = fgetc(file);
			str.push_back(c);
		}
		std::string string;
		for (int i = 0; i < str.size(); i++)
			string.push_back(str[i]);
		return string;
	}
};


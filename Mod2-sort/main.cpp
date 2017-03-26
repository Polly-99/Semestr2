#include <iostream>
#include <vector>

template<class IT>

void sort(IT beg, IT end)
{
	for (IT i = beg; i != end; ++i)
	{
		for (IT j = beg; j != end; ++j)
		{
			if (*j > *i) {
				std::swap(*i, *j);
			}
		}
	}
}

//для печати данного массива
void Print_arr(int * arr)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[] = { 123, 3, 0, 13212, -100 };
	sort(arr + 0, arr + 3);  // arr: 0, 3, 123, 13212, -100
	Print_arr(arr);
	
	sort(arr + 2, arr + 5); // arr: 0, 3, -100, 123, 13212
	Print_arr(arr);

	sort(std::begin(arr), std::end(arr)); // arr: -100, 0, 3, 123, 13212
	Print_arr(arr);

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 }; // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
}
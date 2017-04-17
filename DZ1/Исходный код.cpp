#include "Multiset.h"
#include <iostream>

int main()
{
	TMultiset<int, less<int>> derevo;
	derevo.insert(6);
	derevo.insert(10);
	derevo.insert(4);
	derevo.insert(5);
	derevo.insert(5);
	derevo.insert(3);
	derevo.Print();
	Iterator <int> Node;
	Node = derevo.find(4);
	//std::cout << Node->Data << std::endl;
	derevo.erase(Node);
	derevo.Print();
	derevo.erase(5);
	derevo.Print();

	TMultiset<int, less<int>> derevo1;
	
	derevo1.insert(8);
	derevo1.insert(10);
	derevo1.insert(14);
	derevo1.insert(13);
	derevo1.insert(3);
	derevo1.insert(6);
	derevo1.insert(7);
	derevo1.insert(1);
	derevo1.insert(4);
	derevo1.Print();
	Iterator <int> Node2 = derevo1.find(10);
	Iterator <int> Node3 = derevo1.find(13);
	derevo1.erase(Node2, Node3);
	derevo1.Print();

	derevo.swap(derevo1);
	derevo.Print();
	derevo1.Print();
	//TMultiset<int, less<int>> derevo2 (derevo1);
	std::cout << derevo.size() << std::endl;
	derevo1.clear();
	std::cout << derevo1.empty() << std::endl;
	system("pause");
}
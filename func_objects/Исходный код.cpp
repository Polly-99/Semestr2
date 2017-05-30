#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

enum Grade
{
	F = 1,
	D,
	C,
	B,
	A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
	return{
		{
			"Anna", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::A },
				{ "english", Grade::A },
				{ "dutch", Grade::B },
			}
		},
		{
			"Petr", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Vova", "G1",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
			}
		},
		{
			"Vasya", "G3",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Anton", "G4",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "dutch", Grade::C },
				{ "cs", Grade::C },
			}
		},
		{
			"Masha", "G2",
			{
				{ "math", Grade::A },
			}
		},
		{
			"Sasha", "G6",
			{
				{ "english", Grade::F },
				{ "russian", Grade::F },
				{ "dutch", Grade::F },
			}
		},
		{
			"Jeka", "G2",
			{
				{ "english", Grade::A },
			}
		},
		{
			"Sveta", "G3",
			{
			}
		}
	};
}

struct FindGroup{
	std::string neededGroup;
	std::vector <Student> group;

	void operator()(const Student& st){
		if (st.Group == neededGroup)
			group.insert(group.begin(), st);
	}
};

Grade AV_Grade(const Student & st)
{
	int gr = 0;
	for (auto it = st.Grades.begin(); it != st.Grades.end(); it++)
		gr = gr + it->second;
	gr = gr / st.Grades.size();
	Grade grade = (Grade)gr;
	return grade;
}

int main()
{
	std::vector<Student> students = LoadStudents();

	//ëó÷øå âñåõ çíàåò ìàòåìàòèêó
	auto i = std::max_element(students.begin(), students.end(),
		[](const Student & f, const Student & s)
	{
		try
		{
			return f.Grades.at("math") < s.Grades.at("math");
		}
		catch (...)
		{
			return false;
		}
	});
	std::cout << "Best in math" << std::endl << i->FIO << std::endl;

	//õóäøàÿ ñðåäíÿÿ îöåíêà çà ïðåäìåòû
	auto it2 = std::min_element(students.begin(), students.end(),
		[](const Student & f, const Student & s)
	{
		return (AV_Grade(f) < AV_Grade(s));
	});
	if (it2 != students.end())
		std::cout << "Worst average grade:" << it2->FIO << std::endl;

	//èçó÷àåò ìåíüøå âñåãî ïðåäìåòîâ
	auto it = std::min_element(students.begin(), students.end(),
		[](const Student & f, const Student & s)
	{
		return (f.Grades.size() < s.Grades.size());
	});
	if (it != students.end())
		std::cout << "Min subjects:" << it->FIO << std::endl;

	//èçó÷àåò áîëüøå âñåãî ïðåäìåòîâ
	auto it1 = std::max_element(students.begin(), students.end(),
		[](const Student & f, const Student & s)
	{
		return (f.Grades.size() < s.Grades.size());
	});
	if (it1 != students.end())
		std::cout << "Max subjects:" << it1->FIO << std::endl;

	// ïîëó÷èòü ó÷åíèêîâ ãðóïïû ïî åå íàçâàíèþ
	FindGroup finderObj;
	finderObj.neededGroup = "G3";
	for (auto it = students.begin(); it != students.end(); it++)
		finderObj(*it);
	std::cout << std::endl <<  "Group G3:" << std::endl;
	for (auto it3 = finderObj.group.begin(); it3 != finderObj.group.end(); it3++)
		std::cout << it3->FIO << std::endl;

	//íàéòè âñåõ ó÷åíèêîâ, êîòîðûå çíàþò ìàòåìàòèêó íà B, à cs íà A
	std::cout << std::endl << "Math - B, cs - A" << std::endl;
	std::for_each(students.begin(), students.end(),
		[](const Student & st)
	{
		try
		{
			if (st.Grades.at("math") == 4 && st.Grades.at("cs") == 5)
				std::cout << st.FIO << std::endl;
		}
		catch (...)
		{ }
	});

	//äîáàâèòü íîâûé ïðåäìåò Russian literature, â êà÷åñòâå îöåíêè - ñðåäíþþ îöåíêà ñ îêðóãëåíèåì â áîëüøóþ ñòîðîíó 
		std::for_each(students.begin(), students.end(),
		[](const Student & st)
	{
		st.Grades.insert(std::pair<std::string, Grade>("Russian literature", AV_Grade(st)));
	});

	//âûâåñòè èõ îöåíêè ïî dutch, åñëè ñòóäåíò íå èçó÷àåò ýòî ïðåäìåò, òî âûâåñòè îá ýòîì ñîîáùåíèå
	std::cout << std::endl << "Dutch" << std::endl;
	std::for_each(students.begin(), students.end(),
		[](const Student & st)
	{
		try
		{
			std::cout << st.FIO << " - " << st.Grades.at("dutch") << std::endl;
		}
		catch (...)
		{
			std::cout << st.FIO << " don't study dutch" << std::endl;;
		}
	});

	system("pause");
}

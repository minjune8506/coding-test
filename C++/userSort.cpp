#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Student
{
public:
	string name;
	int age;
	Student(string name, int age) : name(name), age(age) {}	
};

void print(vector<Student> &v)
{
	cout << "Student : ";
	for (int i = 0 ; i < 5 ; i++)
	{
		cout << "[" << v[i].name << ", " << v[i].age << "]";
	}
	cout << endl;
}

bool compare(Student a, Student b)
{
	if (a.name == b.name) // 나이가 같다면
		return a.age < b.age; // 나이가 적은 순
		// 뒤의 인자의 나이가 더 크다. -> 나이가 적은 순
	else // 이름이 다르면 이름 사전 순
		return a.name < b.name;
}

int main(void)
{
	vector<Student> v;

	v.push_back(Student("aa", 10));
	v.push_back(Student("ba", 24));
	v.push_back(Student("aa", 11));
	v.push_back(Student("cc", 8));
	v.push_back(Student("bb", 21));

	print(v);
	sort(v.begin(), v.end(), compare);
	print(v);

	return (0);
}

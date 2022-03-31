#include <iostream>
#include <stack>

using namespace std;

int	main(void)
{
	stack<int> s1;
	stack<int> s2;

	s1.push(3);
	s1.push(2);	
	s1.push(1);

	s2.push(30);
	s2.push(20);
	s2.push(10);

	cout << "s1 top element : " << s1.top() << endl;
	cout << "s2 top element : " << s2.top() << endl;

	swap(s1, s2);

	cout << "s1 top element : " << s1.top() << endl;
	cout << "s2 top element : " << s2.top() << endl;

	cout << "stack size : " << s1.size() << endl;
	cout << "stack size : " << s2.size() << endl;

	for ( ; !s1.empty() ; s1.pop())
		cout << s1.top() << endl;
	for ( ; !s2.empty() ; s2.pop())
		cout << s2.top() << endl;
	
	return (0);
}

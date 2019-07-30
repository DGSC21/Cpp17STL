//역방향 반복자 어댑터를 사용해 반대로 순환.

#include<iostream>
#include<list>
#include<iterator>

using namespace std;

int main()
{
	list<int> l{ 1,2,3,4,5 };
	copy(l.rbegin(), l.rend(), ostream_iterator<int>{cout, ", "});
	cout << endl;

	copy(make_reverse_iterator(end(l)),
		make_reverse_iterator(begin(l)),
		ostream_iterator<int>{cout, ", "});
	cout << endl;
}
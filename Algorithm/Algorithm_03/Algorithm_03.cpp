//�����̳ʷ� ���� Ư�� ��� ����. (���͸� �ϴ� ���)
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void print(const vector<int>& v)
{
	copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
	cout << endl;
}

int main()
{
	vector<int> v{ 1,2,3,4,5,6 };
	print(v);

	{
		const auto new_end(remove(begin(v), end(v), 2)); // ������ ����� ���� �ƴ϶� ��ҵ��� �� ĭ�� ������ ���ܼ� ������. �׸��� ���ο�
		//end�ݺ��� ��ȯ.
		v.erase(new_end, end(v)); // ������ ������ ���ο� end�ݺ��ڿ� ���� �ݺ��� ������ ������ erase�Ѵ�.
	}
	print(v);

	{
		auto odd_number([](int i) {return i % 2 != 0; }); // predicate�Լ��� ���ٷ� �����ߴ�.
		const auto new_end(remove_if(begin(v), end(v), odd_number));
		v.erase(new_end, end(v));
	}
	print(v);

	replace(begin(v), end(v), 4, 123);
	print(v);

	v = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v2;
	vector<int> v3;
	auto odd_number([](int i) {return i % 2 != 0; });
	auto even_number([](int i) {return i % 2 == 0; });

	remove_copy_if(begin(v), end(v), back_inserter(v2), odd_number);
	copy_if(begin(v), end(v), back_inserter(v3), even_number);

	print(v);
	print(v2);
	print(v3);

	return 0;
}
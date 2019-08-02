//컨테이너로 부터 특정 요소 제거. (필터링 하는 방법)
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
		const auto new_end(remove(begin(v), end(v), 2)); // 실제로 지우는 것이 아니라 요소들을 한 칸씩 앞으로 땡겨서 덮어씌운다. 그리고 새로운
		//end반복자 반환.
		v.erase(new_end, end(v)); // 땡겨진 벡터의 새로운 end반복자와 원래 반복자 범위를 지정해 erase한다.
	}
	print(v);

	{
		auto odd_number([](int i) {return i % 2 != 0; }); // predicate함수를 람다로 구현했다.
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
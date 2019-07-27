//map::insert가 삽입 판별 파라미터를 받아서 효율적으로 삽입할 수 있도록!

#include<iostream>
#include<map>
#include<string>
using namespace std;


int main()
{
	map<string, size_t> m{ {"b", 1}, {"c", 2}, {"d", 3} };
	
	auto insert_it(end(m)); // 처음에는 판별이 없으므로 맵의 end 반복자를 가리키는 가장 첫 번째 삽입을 처리한다.

	for (const auto& s : { "z", "y", "x", "w" })
	{
		insert_it = m.insert(insert_it, { s, 1 });
	}

	m.insert(end(m), { "a", 1 });

	for (const auto& [key, value] : m) {
		cout << "\"" << key << "\":" << value << ", ";
	}
	cout << endl;

	return 0;
}
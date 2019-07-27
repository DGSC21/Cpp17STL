//C++17에는 try_emplace 함수가 있어 삽입에 따른 조건부 요소를 생성할 수 있다.
//국가별로 부자가 몇 명이 있는지 알려주는 프로그램 + 각 국가에서 가장 부자인 사람을 나타내는 기능
//map으로 구현

#include<iostream>
#include<functional>
#include<list>
#include<map>

using namespace std;

struct billionaire
{
	string name;
	double dollars;
	string country;
};

int main()
{
	list<billionaire> billionaires
	{
	{"Bill Gates", 86.0, "USA"},
	{"Warren Bauffet", 75.6, "USA"},
	{"Jeff Bezos", 75.6, "USA"},
	{"Amancio Ortega", 71.3, "Spain"},
	{"Mark Zuckerberg", 56.0, "USA"},
	{"Carlos Slim", 54.5, "Mexico"},
	//...
	{"Bernard Arnault", 41.5, "France"},
	//...
	{"Liliane Bettencourt", 39.5, "France"},
	//...
	{"Wang Jianlin", 31.3, "China"},
	{"Li Ka-shing", 31.2, "Hong Kong"}
	//...
	};

	map<string, pair<const billionaire, size_t>> m;
	
	for (const auto& b : billionaires)
	{
		auto [iterator, success] = m.try_emplace(b.country, b, 1);

		if (!success)
		{
			iterator->second.second += 1;
		}
	}

	for (const auto& [key, value] : m)
	{
		const auto& [b, count] = value;
		cout << b.country << " : " << count
			<< " billionaires. Richest is "
			<< b.name << " with " << b.dollars
			<< " B$\n";
	}

	return 0;
}
//이 코드에서 핵심은 try_emplace. 국가 키가 이미 존재하는 경우에 삽입에 실패하고, 해당 데이터가 생성되지 않는다. 카운터 값만 올라감.
//map의 insert와 emplace 함수 모두 똑같은 방식으로 작동한다. 그러나 키가 이미 존재하는 경우에 try_emplace가 해당 키와 관련된 객체를
//생성하지는 않는다. 해당 타입의 객체 생성 비용이 매우 높은 경우 성능 향상에 이점이 있다.
//벡터에 함수 객체를 넣고 싶다. 호출 인터페이스만 제한하고 어떤 함수 객체 종류든 상관 없이 모두 저장할 수 있게 하려면 어떻게 해야하나.
//캡처하는 변수의 타입은 전혀 다르지만 같은 함수 호출 시그너쳐를 갖는 경우를 보자.
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<functional>

template<typename T>
auto consumer(T &container)
{
	return [&](auto value)
	{
		container.push_back(value);
	};
}

template <typename U>
 void print(const U& c)
{
	for (auto i : c)
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	std::deque<int> d;
	std::list<int> l;
	std::vector<int> v;

	const std::vector<std::function<void(int)>> consumers
	{ consumer(d), consumer(l), consumer(v) };

	for (size_t i{ 0 }; i < 10; ++i)
	{
		for (auto&& consume : consumers)
		{
			consume(i);
		}
	}

	print(d);
	print(l);
	print(v);

}
//���Ϳ� �Լ� ��ü�� �ְ� �ʹ�. ȣ�� �������̽��� �����ϰ� � �Լ� ��ü ������ ��� ���� ��� ������ �� �ְ� �Ϸ��� ��� �ؾ��ϳ�.
//ĸó�ϴ� ������ Ÿ���� ���� �ٸ����� ���� �Լ� ȣ�� �ñ׳��ĸ� ���� ��츦 ����.
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
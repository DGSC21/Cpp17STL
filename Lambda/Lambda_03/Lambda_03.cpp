//병합을 이용해 함수 구성.
//간단 모형 함수 객체를 몇 개 정의하고 이를 연결고리처럼 만들어 하나씩 입력에 적용하는 단일 함수를 구한다.
#include<iostream>
#include<functional>

template <typename T, typename ... Ts>
auto concat(T t, Ts ... ts)
{
	if constexpr (sizeof ...(ts) > 0)
	{
		return [=](auto ...parameters)
		{
			return t(concat(ts...)(parameters...));
		};
	}
	else
	{
		return t;
	}
}

int main()
{
	auto twice([](int i) {return i * 2; });
	auto thrice([](int i) {return i * 3; });
	auto combined(concat(twice, thrice, std::plus<int>{}));

	std::cout << combined(2, 3) << std::endl;

	return 0;
}
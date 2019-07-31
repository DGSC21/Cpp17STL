//같은 입력으로 두 개 이상의 함수 호출
//단일 호출을 여러 파라미터로 복수의 리시버에 전달하기 위한 람다표현식을 살펴본다.

#include<iostream>

template <typename ...Ts>
static auto multicall(Ts... functions)
{
	return [=](auto x)
	{
		(void)std::initializer_list<int>
		{
			((void)functions(x), 0)...
		};
	};
}

template <typename U, typename ...Us>
static auto for_each(U f, Us ... xs)
{
	(void)std::initializer_list<int>
	{
		((void)f(xs), 0)...
	};
}

static auto brace_print (char a, char b)
{
	return [=](auto x)
	{
		std::cout << a << x << b << ", ";
	};
}

int main()
{
	auto f(brace_print('(', ')'));
	auto g(brace_print('[', ']'));
	auto h(brace_print('{', '}'));
	auto nl([](auto) {std::cout << std::endl; });

	auto call_fgh(multicall(f, g, h, nl));

	for_each(call_fgh, 1, 2, 3, 4, 5);
}
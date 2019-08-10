//std::optional을 이용해 실패를 안전하게 밝혀내기.
//사용자 입력으로 정수를 받아와 합하는 프로그램
//숫자가 아닌 다른 것이 입력되면?
#include <iostream>
#include <optional>

using namespace std;

using oint = optional<int>;

oint read_int()
{
	int i;
	if (cin >> i) { return { i }; }
	return {};
}

oint operator+(oint a, oint b)
{
	if (!a || !b) { return {}; }

	return { *a + *b };
}

oint operator+(oint a, int b)
{
	if (!a) { return {}; }

	return { *a + b };
}

int main()
{
	cout << "Please enter 2 integers.\n> ";

	auto a{ read_int() };
	auto b{ read_int() };

	auto sum(a + b);

	if (sum) {
		cout << *a << " + " << *b << " = "
			<< *sum << '\n';
	}
	else {
		cout << "sorry, the input was "
			"something else than 2 numbers.\n";
	}

}
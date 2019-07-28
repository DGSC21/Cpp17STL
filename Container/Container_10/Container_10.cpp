//stack으로 RPN(후위표기)계산기 만들기.
#include<iostream>
#include<stack>
#include<iterator>
#include<map>
#include<sstream>
#include<cassert>
#include<vector>
#include<stdexcept>
#include<cmath>
using namespace std;

template<typename IT>
double evaluate_rpn(IT it, IT end)
{
	stack<double> val_stack;

	auto pop_stack([&]()
		{
			auto r(val_stack.top()); // 가장 위의 값을 복사
			val_stack.pop(); // 가장 위의 값을 버림
			return r; // 복사본을 반환
		});

	map<string, double (*)(double, double)> ops
	{
		{"+", [](double a, double b) {return a + b; }},
		{"-", [](double a, double b) {return a - b; }},
		{"*", [](double a, double b) {return a * b; }},
		{"/", [](double a, double b) {return a / b; }},
		{"^", [](double a, double b) {return pow(a, b); }},
		{"%", [](double a, double b) {return fmod(a, b); }},
	};

	for (; it != end; ++it)
	{
		stringstream ss{ *it };
		if (double val; ss >> val)
		{
			val_stack.push(val);
		} // 반복자로부터 문자열을 받았는데 이게 double로 파싱될 수 있는경우
		else // 그 외의경우는 연산자다.
		{
			const auto r{ pop_stack() };
			const auto l{ pop_stack() };

			try
			{
				const auto& op(ops.at(*it));
				const double result{ op(l,r) };
				val_stack.push(result);
			}
			catch (const out_of_range&)
			{
				throw invalid_argument(*it);
			}
		}
	}
	return val_stack.top();
}

int main()
{
	try
	{
		cout << evaluate_rpn(istream_iterator<string> {cin}, {})
			 << endl;
	}
	catch (const invalid_argument& e)
	{
		cout << "Invalid operator : " << e.what() << endl;
	}
}
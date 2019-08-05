//문자열 처음부터 끝까지 공백 제거.
//문자열에 둘러싸인 빈 곳을 식별해서 공백이 없는 사본을 반환하는 헬퍼 함수를 작성한 후 간단하게 테스트.
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string trim_whitespace_surrounding(const string& s)
{
	const char whitespace[]{ " \t\n" };
	const size_t first(s.find_first_not_of(whitespace));
	//핵심 함수 string::find_first_not_of whitespace를 받아서 whitespace가 아닌 첫 번째 문자의 위치를 반환한다.

	if (string::npos == first) { return {}; }
	const size_t last(s.find_last_not_of(whitespace));
	//find_last_not_of whitespace가 없는 문자열의 끝 위치를 반환한다.
	return s.substr(first, (last - first + 1));
	//substr(시작위치, (해당 위치 다음의 문자 개수))
}

int main()
{
	string s{ " \t\n  string surrounded by ugly whitespace   \t\n   " };

	cout << "{" << s << "}\n";
	cout << "{" << trim_whitespace_surrounding(s) << "}\n";
}
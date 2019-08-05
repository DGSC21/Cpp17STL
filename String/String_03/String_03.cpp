//생성 비용 없이 std::string 객체 사용
//string의 단점은 문자열 일부를 전달 하고 싶을 때 포인터와 변수의 길이 또는 두 개의 반복자나 문자열의 사본을 전달해야 한다는 점.
//포인터와 문자열의 길이를 묶음으로 구현해줘야함.
//간단한 방법으로 string_view 일부 문자와 문자열의 길이를 함께 쌍으로 가리키는 방법을 제공한다.

#include <iostream>
#include <string_view>
#include<algorithm>

using namespace std;

void print(string_view v) // string_view를 받는 print함수 구현 그러면 해당 함수에 전달될 수 있는 타입은?
{
	
	const auto words_begin(v.find_first_not_of(" \t\n"));
	v.remove_prefix(min(words_begin, v.size())); // 내부 string_view의 포인터는 공백이 아닌 첫 번째 문자를 가리킨다.

	const auto words_end(v.find_last_not_of(" \t\n"));

	if (words_end != string_view::npos) {
		v.remove_suffix(v.size() - words_end - 1);
	}

	cout << "length: " << v.length()
		<< " [" << v << "]\n";
}

int main(int argc, char* argv[])
{
	print(argv[0]); // 타입이 런타임 char*
	print({}); //빈 string_view
	print("a const char * array"); // C스타일 정적
	print("an std::string_view literal"sv); // string_view 리터럴
	print("an std::string instance"s); // string

	print("   \t\n foobar  \n  \t "); // 공백을 포함한 문자열 테스트.

	char cstr[]{ 'a', 'b', 'c' };  // 마지막 값이 \0이 아니다.
	print(string_view(cstr, sizeof(cstr))); // 이렇게 문자열의 크기 같이 전달 가능.
}

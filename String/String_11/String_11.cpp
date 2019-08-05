//char_traits로 부터 상속받아 커스텀 string 클래스를 만들어본다.
//lc_string은 특정 문자열 입력으로부터 소문자를 생성한다.
//ci_string은 대소문자를 구분하지 않는 문자열 비교를 할 수 있다. 특정 문자열로 변환하지는 않는다.


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

static constexpr char tolow(char c) {

	
	if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 'a');
	}
	else
	{
		return c;
	}
}

class lc_traits : public char_traits<char> {
public:
	static constexpr void assign(char_type& r, const char_type& a) {
		r = tolow(a);
	}

	static char_type* copy(char_type* dest, const char_type* src, size_t count) {
		transform(src, src + count, dest, tolow);
		return dest;
	}
};

class ci_traits : public char_traits<char> {
public:
	static constexpr bool eq(char_type a, char_type b) {
		return tolow(a) == tolow(b);
	}

	static constexpr bool lt(char_type a, char_type b) {
		return tolow(a) < tolow(b);
	}

	static constexpr int compare(const char_type* s1,
		const char_type* s2,
		size_t count) {
		for (; count; ++s1, ++s2, --count) {
			const char_type diff(tolow(*s1) - tolow(*s2));
			if (diff < 0) { return -1; }
			else if (diff > 0) { return +1; }
		}
		return 0;
	}

	static constexpr const char_type* find(const char_type* p,
		size_t count,
		const char_type& ch) {
		const char_type find_c{ tolow(ch) };

		for (; count != 0; --count, ++p) {
			if (find_c == tolow(*p)) { return p; }
		}

		return nullptr;
	}
};

using lc_string = basic_string<char, lc_traits>;
using ci_string = basic_string<char, ci_traits>;

ostream& operator<<(ostream& os, const lc_string& str) {
	return os.write(str.data(), str.size());
}

ostream& operator<<(ostream& os, const ci_string& str) {
	return os.write(str.data(), str.size());
}

int main()
{
	lc_string e{ "Foo Bar Baz" };

	cout << "   string: "
		<< string{ "Foo Bar Baz" } << '\n'
		<< "lc_string: "
		<< lc_string{ "Foo Bar Baz" } << '\n'
		<< "ci_string: "
		<< ci_string{ "Foo Bar Baz" } << '\n';

	ci_string user_input{ "MaGiC PaSsWoRd!" };
	ci_string password{ "magic password!" };

	if (user_input == password) {
		cout << "Passwords match: \"" << user_input
			<< "\" == \"" << password << "\"\n";
	}
}

//원래 tolower함수가 표준이 아닌 case 'A'...'Z'로 돼있어서 ifelse문으로 바꿨는데 lc_traits가 제대로 동작하지 않는다.
//일단 보류,
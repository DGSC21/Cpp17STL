//정규표현식 라이브러리로 입력 토큰화
//C++11부터 정규표현식 기능을 가지고 있다.
//링크를 검출하는 정규 표현식을 정의해서 HTML 파일에 존재하는 모든 링크가 잘 출력 되도록 해당 파일에 적용한다.
#include <iostream>
#include <iterator>
#include <regex>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename InputIt>
void print(InputIt it, InputIt end_it)
{
	while (it != end_it) {
		const string link{ *it++ };
		if (it == end_it) { break; }
		const string desc{ *it++ };

		cout << left << setw(28) << desc << " : " << link << '\n';
	}
}

int main()
{
	cin >> noskipws;
	const std::string in{ istream_iterator<char>{cin}, {} };

	const regex link_re{ "<a href=\"([^\"]*)\"[^<]*>([^<]*)</a>" };

	sregex_token_iterator it{ begin(in), end(in), link_re, {1, 2} };

	print(it, {});
}

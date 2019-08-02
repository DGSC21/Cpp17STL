//사전식 병합(merge)도구 std::merge 사용
//영어 단어에서 독일어로 번역된 단어를 일대일로 매핑하는 저렴한 사전을 만들어 deque에 저장한다.
//프로그램은 파일과 표준 입력으로부터 이와 같은 사전을 읽고 다시 표준 출력에 하나로 머지된 거대한 사전을 출력한다.

#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <tuple>
#include <string>
#include <fstream>

using namespace std;

using dict_entry = pair<string, string>;

namespace std {
	ostream& operator<<(ostream& os, const dict_entry p)
	{
		return os << p.first << " " << p.second;
	}

	istream& operator>>(istream& is, dict_entry& p)
	{
		return is >> p.first >> p.second;
	}
}

template <typename IS>
deque<dict_entry> from_instream(IS&& is)
{
	deque<dict_entry> d{ istream_iterator<dict_entry>{is}, {} };
	sort(begin(d), end(d));
	return d;
}

int main()
{
	ifstream file_in{ "dict.txt" };

	const auto dict1(from_instream(ifstream{ "dict.txt" }));
	const auto dict2(from_instream(cin));

	merge(begin(dict1), end(dict1),
		begin(dict2), end(dict2),
		ostream_iterator<dict_entry>{cout, "\n"});
}
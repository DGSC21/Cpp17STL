#include<iostream>
#include<set>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	set<string> s;
	istream_iterator<string> it{ cin };
	istream_iterator<string> end; // 처음보는 istream_iterator 입력반복기 개체라고 한다. 아무튼 cin>>it와 같은것일듯? 띄어쓰기 포함으로

	copy(it, end, inserter(s, s.end())); // 핵심 구문 입력 내용 토큰화 -> 알파벳 순 정렬, 중복 내용 제거를 한 줄로!
	//입력 반복자를 통해 std::cin으로부터 다음 단어 토큰을 이끌어 내 std::set에 넣는다.

	for (const auto word : s)
	{
		cout << word << ", ";
	}
	cout << endl;

}
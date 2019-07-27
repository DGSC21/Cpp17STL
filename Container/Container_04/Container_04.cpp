#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<cassert>
using namespace std;

void insert_sorted(vector<string>& v, const string& word)
{
	const auto insert_pos(lower_bound(begin(v), end(v), word));
	v.insert(insert_pos, word);
}
int main()
{
	vector<string> v{ "some", "random", "words", "without", "order", "aaa", "yyy" };

	assert(false == is_sorted(begin(v), end(v))); // v가 정렬 되어있으면 프로그램 중단
	sort(begin(v), end(v)); // 일단 문자열을 정렬해야함.
	assert(true == is_sorted(begin(v), end(v))); // v가 정렬되어있지 않으면 프로그램 중단

	insert_sorted(v, "foobar");
	insert_sorted(v, "zzz");

	for (const auto& w : v)
	{
		cout << w << " ";
	}
	cout << endl;

	return 0;
}

//이 코드의 핵심은 lower_bound(a,b,c) 시작, 끝, 값. 범위 내의 c보다 크거나 같은 첫 번째 요소를 찾아내 이를 가리키는 반복자를 반환한다.
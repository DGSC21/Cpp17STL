//표준 입력으로부터 복수의 단어를 읽는 프로그램을 작성해본다. std::next_permutation을 사용해 해당 문자열의 모든 치환을 생성해 출력함.

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v{ istream_iterator<string>{cin}, {} };
	sort(begin(v), end(v)); // 입력을 벡터에 받고 정렬한다.

		do {
			copy(begin(v), end(v), ostream_iterator<string>{cout, ", "});
			cout << '\n';
		} while (next_permutation(begin(v), end(v))); // std::next_permuation 다음 수열을 찾을 수 있으면 true를 반환한다.
}

//중요한 것은 next_permutation이 사전 순서라는 것!! cba입력하고 정렬이 되지 않으면 해당 알고리즘이 즉시 종료한다.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v{ 1,2,3,2,5,2,6,2,4,8 };

	const auto new_end(remove(begin(v), end(v), 2));
	v.erase(new_end, end(v)); // 위 두 줄의 코드로 중복된 2를 제거하고 vector의 크기 또한 줄인다.

	for (auto i : v)
	{
		cout << i << ", "; //출력
	}
	cout << endl;

	const auto odd([](int i) { return i % 2 != 0; }); //람다펑션 사용. 하나의 숫자를 인자로 받고 홀수면 true를 반환한다.

	v.erase(remove_if(begin(v), end(v), odd), end(v)); //처음부터 끝까지 돌면서 odd가 true면 뒤로 보내고 remove값이 시작하는 반복자를 반환한다.
	//즉 이코드는 odd람다펑션을 사용해 v의 홀수를 삭제하는것!

	for (auto i : v)
	{
		cout << i << ", "; //출력
	}
	cout << endl;

	v.shrink_to_fit(); //이 코드를 통해 vector의 크기에 맞게 신규 메모리 영역으로 옮기고 할당한다.

	return 0;
}
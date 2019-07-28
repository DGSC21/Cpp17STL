//map 구조체 안에 자동차 경주를 임의로 설정하고, 참가 운전자의 배치 순서를 결정한다.
//레이스 도중 추월이 일어났을 경우 이 운전자들의 배치 키를 변경해야한다.

#include<iostream>
#include<map>
using namespace std;

template <typename M>
void print(const M& m)
{
	cout << "Race placement : \n";
	for (const auto& [placement, driver] : m)
	{
		cout << placement << ": " << driver << endl;
	}
} // 자동차 경주 배치 출력

int main()
{
	map<int, string> race_replacement
	{
		{1, "Mario"}, {2, "Luigi"}, {3, "Bowser"}, {4, "Peach"},
		{5, "Yoshi"}, {6, "Kim"}, {7, "Park"}, {8, "Lee"}
	}; //map 생성 및 초기화
	print(race_replacement);

	auto a(race_replacement.extract(3)); // extract함수가 핵심. 메모리 재할당이 일어나지 않는다.
	auto b(race_replacement.extract(5));

	swap(a.key(), b.key()); //키값만 서로 바꿨다. 순위만 서로 바꿈!

	race_replacement.insert(move(a));
	race_replacement.insert(move(b)); // 다시 삽입. 자동으로 키값 중심 정렬이 된다.

	print(race_replacement);

	return 0;
}
//extract함수는 두가지 버전이 있다. extract(반복자), extract(키값) 여기에서는 두번째 버전을 사용함.
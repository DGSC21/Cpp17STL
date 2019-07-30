//확인된 반복자로 반복자 코드를 자동 검사.
#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{ 1,2,3 };
	v.shrink_to_fit();
	const auto it(std::begin(v));

	std::cout << *it << std::endl;

	v.push_back(123);
	std::cout << *it << std::endl; // 여기세어 오류 벡터의 값을 한계 이상으로 증가시키면 (3->4) 새로운 메모리 영역에 재할당.
	//비주얼 스튜디오로 디버그모드 빌드시 "**_Mycont**이(가) nullptr였습니다. 예외를 던진다.
	//릴리즈 모드에서는 어떻게든 실행한다.
}
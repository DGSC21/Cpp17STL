//파일의 모든 단어 개수 세기.
//입력 버퍼로부터 단어 수를 세는 한 줄짜리 함수를 작성해서 사용자가 어디에서 입력 버퍼를 읽어올지 선택하게 한다.


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
size_t wordcount(T& is)
{
	return distance(istream_iterator<string>{is}, {}); // 두개의 반복자를 받는데 하나의 반복자 위치에서 다른 반복자 위치의 거리를
	//구하기 위해 얼마나 많은 반복자 증가 단계가 필요한지 계산함.총 진행 단계는 단어 수와 같다.
}

int main(int argc, char** argv)
{
	size_t wc;
	if (argc == 2) {
		ifstream ifs{ argv[1] };
		wc = wordcount(ifs);
	}
	else {
		wc = wordcount(cin); // 그냥 실행했을 경우 cin
	}

	cout << "There are " << wc << " words\n";
};
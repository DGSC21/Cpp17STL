//난수 데이터의 아주 큰 벡터를 표본화한다.

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	const size_t data_points{ 100000 }; 
	const size_t sample_points{ 100 };
	const int    mean{ 10 };
	const size_t dev{ 3 };
	random_device rd; // 난수장치를 인스턴스로 만든다
	mt19937 gen{ rd() }; //난수 생성!
	normal_distribution<> d{ mean, dev }; // 난수 출력에 기본 분배를 적용하는 분배 객체의 인스턴스를 생성한다.

	vector<int> v;
	v.reserve(data_points); // 데이터포인트 만큼 정수 벡터를 생성한다(비어있음)

	generate_n(back_inserter(v), data_points, [&] { return d(gen); }); // std::generate_n 알고리즘 세번째 인자는 생성기 객체 함수. d(gen_
	//난수 장치로부터 난수를 구해 분배 객체에 넣는 역할을 한다.

	vector<int> samples;
	v.reserve(sample_points); // 더 적은 샘플 세트

	sample(begin(v), end(v), back_inserter(samples), sample_points, mt19937{ random_device{}() });
	//핵심, std::sample()알고리즘. copy와 유사하지만 2개의 추가 파라미터.
	//sample_point는 표본의 개수 그 다음 파라미터는 임의의 표본화된 위치를 구하게 조사하는 임의의 숫자 생성기 객체.
	map<int, size_t> hist;

	for (int i : samples) { ++hist[i]; }

	for (const auto& [value, count] : hist) {
		cout << setw(2) << value << " "
			<< string(count, '*') << '\n';
	}
}
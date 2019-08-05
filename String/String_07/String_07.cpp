//파일 입력으로부터 복잡한 객체 초기화
//operator>>()의 오버로딩법!!
#include <iostream>
#include <iomanip>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

struct city {
	string name;
	size_t population;
	double latitude;
	double longitude;
}; // 이 city구조체를 >>로 읽어본다.

istream& operator>>(istream& is, city& c)
{
	is >> ws; // 일단 공백 건너뛰고.
	getline(is, c.name);
	is >> c.population >> c.latitude >> c.longitude;
	return is;
}

int main()
{
	vector<city> l;

	copy(istream_iterator<city>{cin}, {}, back_inserter(l)); // 여기에서 >>operator 사용한다.

	for (const auto& [name, pop, lat, lon] : l) {
		cout << left << setw(15) << name
			<< " population=" << pop
			<< " lat=" << lat
			<< " lon=" << lon << '\n';
	}
}
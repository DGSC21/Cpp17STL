//���� �������� ���� ū ���͸� ǥ��ȭ�Ѵ�.

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
	random_device rd; // ������ġ�� �ν��Ͻ��� �����
	mt19937 gen{ rd() }; //���� ����!
	normal_distribution<> d{ mean, dev }; // ���� ��¿� �⺻ �й踦 �����ϴ� �й� ��ü�� �ν��Ͻ��� �����Ѵ�.

	vector<int> v;
	v.reserve(data_points); // ����������Ʈ ��ŭ ���� ���͸� �����Ѵ�(�������)

	generate_n(back_inserter(v), data_points, [&] { return d(gen); }); // std::generate_n �˰��� ����° ���ڴ� ������ ��ü �Լ�. d(gen_
	//���� ��ġ�κ��� ������ ���� �й� ��ü�� �ִ� ������ �Ѵ�.

	vector<int> samples;
	v.reserve(sample_points); // �� ���� ���� ��Ʈ

	sample(begin(v), end(v), back_inserter(samples), sample_points, mt19937{ random_device{}() });
	//�ٽ�, std::sample()�˰���. copy�� ���������� 2���� �߰� �Ķ����.
	//sample_point�� ǥ���� ���� �� ���� �Ķ���ʹ� ������ ǥ��ȭ�� ��ġ�� ���ϰ� �����ϴ� ������ ���� ������ ��ü.
	map<int, size_t> hist;

	for (int i : samples) { ++hist[i]; }

	for (const auto& [value, count] : hist) {
		cout << setw(2) << value << " "
			<< string(count, '*') << '\n';
	}
}
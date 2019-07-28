//map ����ü �ȿ� �ڵ��� ���ָ� ���Ƿ� �����ϰ�, ���� �������� ��ġ ������ �����Ѵ�.
//���̽� ���� �߿��� �Ͼ�� ��� �� �����ڵ��� ��ġ Ű�� �����ؾ��Ѵ�.

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
} // �ڵ��� ���� ��ġ ���

int main()
{
	map<int, string> race_replacement
	{
		{1, "Mario"}, {2, "Luigi"}, {3, "Bowser"}, {4, "Peach"},
		{5, "Yoshi"}, {6, "Kim"}, {7, "Park"}, {8, "Lee"}
	}; //map ���� �� �ʱ�ȭ
	print(race_replacement);

	auto a(race_replacement.extract(3)); // extract�Լ��� �ٽ�. �޸� ���Ҵ��� �Ͼ�� �ʴ´�.
	auto b(race_replacement.extract(5));

	swap(a.key(), b.key()); //Ű���� ���� �ٲ��. ������ ���� �ٲ�!

	race_replacement.insert(move(a));
	race_replacement.insert(move(b)); // �ٽ� ����. �ڵ����� Ű�� �߽� ������ �ȴ�.

	print(race_replacement);

	return 0;
}
//extract�Լ��� �ΰ��� ������ �ִ�. extract(�ݺ���), extract(Ű��) ���⿡���� �ι�° ������ �����.
#include<iostream>
#include<set>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	set<string> s;
	istream_iterator<string> it{ cin };
	istream_iterator<string> end; // ó������ istream_iterator �Է¹ݺ��� ��ü��� �Ѵ�. �ƹ�ư cin>>it�� �������ϵ�? ���� ��������

	copy(it, end, inserter(s, s.end())); // �ٽ� ���� �Է� ���� ��ūȭ -> ���ĺ� �� ����, �ߺ� ���� ���Ÿ� �� �ٷ�!
	//�Է� �ݺ��ڸ� ���� std::cin���κ��� ���� �ܾ� ��ū�� �̲��� �� std::set�� �ִ´�.

	for (const auto word : s)
	{
		cout << word << ", ";
	}
	cout << endl;

}
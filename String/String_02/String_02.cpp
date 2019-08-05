//���ڿ� ó������ ������ ���� ����.
//���ڿ��� �ѷ����� �� ���� �ĺ��ؼ� ������ ���� �纻�� ��ȯ�ϴ� ���� �Լ��� �ۼ��� �� �����ϰ� �׽�Ʈ.
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string trim_whitespace_surrounding(const string& s)
{
	const char whitespace[]{ " \t\n" };
	const size_t first(s.find_first_not_of(whitespace));
	//�ٽ� �Լ� string::find_first_not_of whitespace�� �޾Ƽ� whitespace�� �ƴ� ù ��° ������ ��ġ�� ��ȯ�Ѵ�.

	if (string::npos == first) { return {}; }
	const size_t last(s.find_last_not_of(whitespace));
	//find_last_not_of whitespace�� ���� ���ڿ��� �� ��ġ�� ��ȯ�Ѵ�.
	return s.substr(first, (last - first + 1));
	//substr(������ġ, (�ش� ��ġ ������ ���� ����))
}

int main()
{
	string s{ " \t\n  string surrounded by ugly whitespace   \t\n   " };

	cout << "{" << s << "}\n";
	cout << "{" << trim_whitespace_surrounding(s) << "}\n";
}
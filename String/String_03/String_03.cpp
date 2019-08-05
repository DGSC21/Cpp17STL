//���� ��� ���� std::string ��ü ���
//string�� ������ ���ڿ� �Ϻθ� ���� �ϰ� ���� �� �����Ϳ� ������ ���� �Ǵ� �� ���� �ݺ��ڳ� ���ڿ��� �纻�� �����ؾ� �Ѵٴ� ��.
//�����Ϳ� ���ڿ��� ���̸� �������� �����������.
//������ ������� string_view �Ϻ� ���ڿ� ���ڿ��� ���̸� �Բ� ������ ����Ű�� ����� �����Ѵ�.

#include <iostream>
#include <string_view>
#include<algorithm>

using namespace std;

void print(string_view v) // string_view�� �޴� print�Լ� ���� �׷��� �ش� �Լ��� ���޵� �� �ִ� Ÿ����?
{
	
	const auto words_begin(v.find_first_not_of(" \t\n"));
	v.remove_prefix(min(words_begin, v.size())); // ���� string_view�� �����ʹ� ������ �ƴ� ù ��° ���ڸ� ����Ų��.

	const auto words_end(v.find_last_not_of(" \t\n"));

	if (words_end != string_view::npos) {
		v.remove_suffix(v.size() - words_end - 1);
	}

	cout << "length: " << v.length()
		<< " [" << v << "]\n";
}

int main(int argc, char* argv[])
{
	print(argv[0]); // Ÿ���� ��Ÿ�� char*
	print({}); //�� string_view
	print("a const char * array"); // C��Ÿ�� ����
	print("an std::string_view literal"sv); // string_view ���ͷ�
	print("an std::string instance"s); // string

	print("   \t\n foobar  \n  \t "); // ������ ������ ���ڿ� �׽�Ʈ.

	char cstr[]{ 'a', 'b', 'c' };  // ������ ���� \0�� �ƴϴ�.
	print(string_view(cstr, sizeof(cstr))); // �̷��� ���ڿ��� ũ�� ���� ���� ����.
}

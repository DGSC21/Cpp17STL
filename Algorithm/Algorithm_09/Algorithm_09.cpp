//ǥ�� �Է����κ��� ������ �ܾ �д� ���α׷��� �ۼ��غ���. std::next_permutation�� ����� �ش� ���ڿ��� ��� ġȯ�� ������ �����.

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v{ istream_iterator<string>{cin}, {} };
	sort(begin(v), end(v)); // �Է��� ���Ϳ� �ް� �����Ѵ�.

		do {
			copy(begin(v), end(v), ostream_iterator<string>{cout, ", "});
			cout << '\n';
		} while (next_permutation(begin(v), end(v))); // std::next_permuation ���� ������ ã�� �� ������ true�� ��ȯ�Ѵ�.
}

//�߿��� ���� next_permutation�� ���� ������� ��!! cba�Է��ϰ� ������ ���� ������ �ش� �˰����� ��� �����Ѵ�.
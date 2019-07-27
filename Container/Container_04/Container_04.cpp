#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<cassert>
using namespace std;

void insert_sorted(vector<string>& v, const string& word)
{
	const auto insert_pos(lower_bound(begin(v), end(v), word));
	v.insert(insert_pos, word);
}
int main()
{
	vector<string> v{ "some", "random", "words", "without", "order", "aaa", "yyy" };

	assert(false == is_sorted(begin(v), end(v))); // v�� ���� �Ǿ������� ���α׷� �ߴ�
	sort(begin(v), end(v)); // �ϴ� ���ڿ��� �����ؾ���.
	assert(true == is_sorted(begin(v), end(v))); // v�� ���ĵǾ����� ������ ���α׷� �ߴ�

	insert_sorted(v, "foobar");
	insert_sorted(v, "zzz");

	for (const auto& w : v)
	{
		cout << w << " ";
	}
	cout << endl;

	return 0;
}

//�� �ڵ��� �ٽ��� lower_bound(a,b,c) ����, ��, ��. ���� ���� c���� ũ�ų� ���� ù ��° ��Ҹ� ã�Ƴ� �̸� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
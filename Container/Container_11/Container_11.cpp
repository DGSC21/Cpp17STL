#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

string filter_punctuation(const string& s)
{
	const char* forbidden{ ".,:;" };
	const auto idx_start(s.find_first_not_of(forbidden));
	const auto idx_end(s.find_last_not_of(forbidden));
	return s.substr(idx_start, idx_end - idx_start + 1);
} // ��ǥ�� ��ħǥ, �ݷ��� �ܾ�κ��� �и��س��� ���� ���� �Լ� �ϳ��� �����.

int main()
{
	map<string, size_t> words;
	int max_word_len{ 0 };
	string s;
	while (cin >> s)
	{
		auto filtered(filter_punctuation(s));
		max_word_len = max<int>(max_word_len, filtered.length());
		++words[filtered];
	} //��������� �Է��� �޴� �κ� map�� �����ȴ�

	vector<pair<string, size_t>> word_counts; 
	word_counts.reserve(words.size());
	move(begin(words), end(words), back_inserter(word_counts)); // �״�� ���Ϳ� �Űܴ�Ƽ�
	
	sort(begin(word_counts), end(word_counts), [](const auto& a, const auto& b) {return a.second > b.second; }); // �����Ѵ�.

	cout << '# ' << setw(max_word_len) << "<WORD>" << "#<COUNT>\n";
	for (const auto& [word, count] : word_counts)
	{
		cout << setw(max_word_len + 2) << word << " #"
			<< count << endl;
	} // �����

	return 0;
}
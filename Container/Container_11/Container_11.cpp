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
} // 쉼표와 마침표, 콜론을 단어로부터 분리해내기 위해 헬퍼 함수 하나를 사용함.

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
	} //여기까지가 입력을 받는 부분 map이 생성된다

	vector<pair<string, size_t>> word_counts; 
	word_counts.reserve(words.size());
	move(begin(words), end(words), back_inserter(word_counts)); // 그대로 벡터에 옮겨담아서
	
	sort(begin(word_counts), end(word_counts), [](const auto& a, const auto& b) {return a.second > b.second; }); // 정렬한다.

	cout << '# ' << setw(max_word_len) << "<WORD>" << "#<COUNT>\n";
	for (const auto& [word, count] : word_counts)
	{
		cout << setw(max_word_len + 2) << word << " #"
			<< count << endl;
	} // 출력쪽

	return 0;
}
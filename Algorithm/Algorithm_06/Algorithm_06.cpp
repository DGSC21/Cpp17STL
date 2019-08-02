//std::clamp로 벡터 값을 특정 숫자 범위로 제한 
//예제 숫자 범위를 사용해 두 가지 서로 다른 방법으로 벡터의 값을 정규화함.
//minmax_element 범위의 끝까지 반복해서 가장 큰 요소와 가장 작은 요소를 기록한다.
//clamp함수는 입력값, 최솟값, 최댓값 세 개의 값을 받아서 입력값이 최소, 최대에 맞춰서 줄어든다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

static auto norm(int min, int max, int new_max)
{
	const double diff(max - min);
	return [=](int val) {
		return int((val - min) / diff * new_max);
	};
}


static auto clampval(int min, int max)
{
	return [=](int val) -> int {
		return clamp(val, min, max);
	};
}


int main()
{
	vector<int> v{ 0, 1000, 5, 250, 300, 800, 900, 321 };

	copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
	cout << '\n';

	const auto [min_it, max_it](minmax_element(begin(v), end(v)));

	vector<int> v_norm;
	v_norm.reserve(v.size());

	transform(begin(v), end(v), back_inserter(v_norm),
		norm(*min_it, *max_it, 255));

	copy(begin(v_norm), end(v_norm), ostream_iterator<int>{cout, ", "});
	cout << '\n';

	transform(begin(v), end(v), begin(v_norm), clampval(0, 255));

	copy(begin(v_norm), end(v_norm), ostream_iterator<int>{cout, ", "});
	cout << '\n';
}
//문맥마다 숫자들을 언제든지 완전히 다르게 출력함
//IO처리자는 한번 적용하면 그 것이 지속되어서 관련 없는 코드에서 처리되지 않도록 사용한 후에는 해당 효과를 되돌려야한다.
//여전히 printf를 사용한다.
//IO처리자의 사용 없이도 자유롭게 서식을 설정하는 방법을 살펴본다.

#include <iostream>
#include <iomanip>

using namespace std;

class format_guard {
	ostream& os;
	ios::fmtflags f;

public:
	explicit format_guard(ostream& guarded_stream = cout) : os(guarded_stream), f(os.flags()) {}
	~format_guard() { os.flags(f); }
}; // cout이 설정되는 서식 설정 플래그를 저장한다. 소멸자에서 플래그를 복구함.


template <typename T>
struct scientific_type {
	T value;

	explicit scientific_type(T val) : value{ val } {}
}; // 아무것도 하지 않는다.

template <typename T>
ostream& operator<<(ostream& os, const scientific_type<T>& w) {
	format_guard _{ os }; // 포맽가드를 끼워넣어서 연산자가 종료될때 플래그에 기록된 서식도 무효가 된다.
	os << scientific << uppercase << showpos;
	return os << w.value;
}

int main()
{
	{
		format_guard _;
		cout << hex << scientific << showbase << uppercase;

		cout << "Numbers with special formatting:\n";
		cout << 0x123abc << '\n';
		cout << 0.123456789 << '\n';
	}

	cout << "Same numbers, but normal formatting again:\n";
	cout << 0x123abc << '\n';
	cout << 0.123456789 << '\n';

	cout << "Mixed formatting: "
		<< 123.0 << " "
		<< scientific_type{ 123.0 } << " "
		<< 123.456 << '\n';

}
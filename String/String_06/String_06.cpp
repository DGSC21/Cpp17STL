//I/O 스트림 처리자로 출력 서식 지정.

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

void print_aligned_demo(int val, size_t width, char fill_char = ' ') {

	cout << "================\n";
	cout << setfill(fill_char);
	cout << left << setw(width) << val << '\n';
	cout << right << setw(width) << val << '\n';
	cout << internal << setw(width) << val << '\n'; // 10진수 형태일 때는 right와 같다. 16진수 0x일 경우 0x뒤에 공백이 들어간다.
}

int main()
{
	print_aligned_demo(123456, 15);
	print_aligned_demo(123456, 15, '_');

	cout << hex << showbase; // cout에게 16진수라고 알려주는 구문.
	print_aligned_demo(0x123abc, 15);

	cout << oct; // cout에게 8진수라고 알려주는 구문. showbase가 여전히 활성화되어있음 그래서 모든 출력 숫자 앞에 0이 붙게 된다.
	print_aligned_demo(0123456, 15);

	cout << "A hex number with upper case letters: "
		<< hex << uppercase << 0x123abc << '\n';

	cout << "A number: " << 100 << '\n';
	cout << dec;

	cout << "Oops. now in decimal again: " << 100 << '\n';

	cout << "true/false values: "
		<< true << ", " << false << '\n';
	cout << boolalpha
		<< "true/false values: "
		<< true << ", " << false << '\n';

	cout << "doubles: "
		<< 12.3 << ", "
		<< 12.0 << ", "
		<< showpoint << 12.0 << '\n'; //showpoint 즉 소수점을 생략하지 않고 항상 보여준다.

	cout << "scientific double: " << scientific << 123000000000.123 << '\n';
	cout << 100.0 << '\n';
	cout << "fixed      double: " << fixed << 123000000000.123 << '\n';

	cout << "Very precise double: " << setprecision(10) << 0.0000000001 << '\n'; // 부동 소수점 출력 정밀도 결정
	cout << "Less precise double: " << setprecision(1) << 0.0000000001 << '\n';
}
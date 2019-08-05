//iostream 오류로부터 읽을 수 있는 예외 처리.

#include <iostream>
#include <fstream>
#include <system_error>
#include <cstring>

using namespace std;

int main()
{
	ifstream f;
	f.exceptions(f.failbit | f.badbit);

	try {
		f.open("mmes.txt");

		int i;
		f >> i;

		cout << "integer has value: " << i << '\n';
	}
	catch (const ios_base::failure& e) {
		cerr << "Caught error: ";
		if (errno) {
			// This is not thread safe.
			cerr << strerror(errno) << '\n';
		}
		else {
			cerr << e.what() << '\n';
		} // what()으로 나타나는 메시지가 표준화돼있지 않다.
	}
}
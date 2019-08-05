//사용자 입력으로부터 값 읽어오기. 표준 입력이나 파일과 같이 입력 소스로부터 값을 읽어와 처리함.
//오류처리 기법과  토큰화(파싱)에 대해 알아본다.


#include <iostream>
#include<string>

using namespace std;

int main()
{
	cout << "Please Enter two numbers:\n> ";
	int    x;
	double y;
	if (cin >> x >> y) {
		cout << "You entered: " << x << " and " << y << '\n';
	}
	else {
		cout << "Oh no, that did not go well!\n";
		cin.clear(); // 새로운 입력에 대해 파싱할 수 있도록 현재까지 받은 입력을 제거한다.
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //입력버퍼 ignore함.
	}

	cout << "now please enter some comma-separated names:\n> ";

	for (string s; getline(cin >> ws, s, ',');) { // getline함수를 사용했다. cin>>ws는 s(이름 문자열) 앞에 있는 공백을 받고 무시하겠다는 것.
		if (s.empty()) { break; }
		cout << "name: \"" << s << "\"\n";
	}
}
//����� �Է����κ��� �� �о����. ǥ�� �Է��̳� ���ϰ� ���� �Է� �ҽ��κ��� ���� �о�� ó����.
//����ó�� �����  ��ūȭ(�Ľ�)�� ���� �˾ƺ���.


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
		cin.clear(); // ���ο� �Է¿� ���� �Ľ��� �� �ֵ��� ������� ���� �Է��� �����Ѵ�.
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //�Է¹��� ignore��.
	}

	cout << "now please enter some comma-separated names:\n> ";

	for (string s; getline(cin >> ws, s, ',');) { // getline�Լ��� ����ߴ�. cin>>ws�� s(�̸� ���ڿ�) �տ� �ִ� ������ �ް� �����ϰڴٴ� ��.
		if (s.empty()) { break; }
		cout << "name: \"" << s << "\"\n";
	}
}
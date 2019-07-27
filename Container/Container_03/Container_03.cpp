#include<iostream>
#include<vector>

using namespace std;

int main()
{
	const size_t container_size{ 1000 };
	vector<int> v{ container_size, 123 };

	cout << "Out of range element value : "
		<< v[container_size + 10] << endl;
	
	try {
		cout << "Out of range element value:"
			<< v.at(container_size + 10) << endl;
	}
	catch (const out_of_range& e)
	{
		cout << "Out of range access detected: "
			<< e.what() << endl;
	}
	
	return 0;
}
//vector�� []�� at�� �̿��� ���� �ۿ� �����ߴ�. []�� ��쿡�� ���ܸ� ���� �ʴ´�.
//����Ŵ� �ƿ� ���尡 �ȵȴ�. �׷��� at�Լ��� �����˻縦 ������ �ؼ� ���ܸ� ������!!
//���� �ӵ��� �ʿ��� ��쿡�� [], �� �ܿ��� at�Լ��� ����ؼ� ���ܸ� ��°� ����.
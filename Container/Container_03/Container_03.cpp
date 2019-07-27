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
//vector에 []와 at을 이용해 범위 밖에 접근했다. []의 경우에는 예외를 잡지 않는다.
//디버거는 아예 빌드가 안된다. 그러나 at함수는 범위검사를 스스로 해서 예외를 던진다!!
//빠른 속도가 필요할 경우에는 [], 그 외에는 at함수를 사용해서 예외를 잡는게 낫다.
//Ȯ�ε� �ݺ��ڷ� �ݺ��� �ڵ带 �ڵ� �˻�.
#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{ 1,2,3 };
	v.shrink_to_fit();
	const auto it(std::begin(v));

	std::cout << *it << std::endl;

	v.push_back(123);
	std::cout << *it << std::endl; // ���⼼�� ���� ������ ���� �Ѱ� �̻����� ������Ű�� (3->4) ���ο� �޸� ������ ���Ҵ�.
	//���־� ��Ʃ����� ����׸�� ����� "**_Mycont**��(��) nullptr�����ϴ�. ���ܸ� ������.
	//������ ��忡���� ��Ե� �����Ѵ�.
}
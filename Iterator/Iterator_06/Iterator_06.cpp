//반복자 감시자로 범위를 초과하면 반복자 종료
//C++17에서는 begin과 end의 반복자를 같은 타입으로 제한하지 않는다.

#include<iostream>
class cstring_iterator_sentinel {};

class cstring_iterator
{
	const char* s{ nullptr };
public:
	explicit cstring_iterator(const char * str) :s{str}{}
	char operator*() const { return *s; }
	cstring_iterator& operator++() {
		++s;
		return *this;
	}
	bool operator!=(const cstring_iterator_sentinel) const
	{
		return s != nullptr && *s != '\0';
	}
};

class cstring_range
{
	const char* s{ nullptr };
public:
	cstring_range(const char* str) : s{ str } {}
	cstring_iterator begin() const
	{
		return cstring_iterator{ s };
	}
	cstring_iterator_sentinel end() const
	{
		return {};
	}
};

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please provide one parameter.\n";
		return 1;
	}
	for (char c : cstring_range(argv[1]))
	{
		std::cout << c;
	}
	std::cout << std::endl;
}
#include<iostream>
#include<unordered_map>

struct coord
{
	int x;
	int y;
}; // 이걸 키값으로 사용할것.

bool operator==(const coord& l, const coord& r)
{
	return l.x == r.x && l.y == r.y;
} // 내부적으로 필요한 연산자 오버로딩

namespace std
{
	template<>
	struct hash<coord>
	{
		using argument_type = coord;
		using result_type = size_t;

		result_type operator()(const argument_type& c) const
		{
			return static_cast<result_type>(c.x)
				+ static_cast<result_type>(c.y);
		} // 이 연산자 오버로딩이 해시 펑션의 핵심. x와 y를 더한 값을 키값으로 매핑한다.
	};
}

int main()
{
	std::unordered_map<coord, int> m{ {{0,0}, 1}, {{0,1}, 2}, {{2,1}, 3} };

	for (const auto& [key, value] : m)
	{
		std::cout << "{(" << key.x << ", " << key.y << "): " << value << "} ";
	}
	std::cout << std::endl;

	return 0;
}
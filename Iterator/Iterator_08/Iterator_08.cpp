//자신만의 zip 반복자 어댑터 생성
#include<iostream>
#include<vector>
#include<numeric>

class zip_iterator
{
	using it_type = std::vector<double>::iterator;

	it_type it1;
	it_type it2;
public:
	zip_iterator(it_type iterator1, it_type iterator2)
		: it1{iterator1}, it2{iterator2} {}
	zip_iterator& operator++ ()
	{
		++it1;
		++it2;
		return *this;
	}
	bool operator!=(const zip_iterator& o) const
	{
		return it1 != o.it1 && it2 != o.it2;
	}
	bool operator ==(const zip_iterator& o) const
	{
		return !operator!=(o);
	}
	std::pair<double, double>operator *() const
	{
		return { *it1, *it2 };
	}
};

class zipper
{
	using vec_type = std::vector<double>;
	vec_type& vec1;
	vec_type& vec2;
public:
	zipper(vec_type& va, vec_type& vb)
		: vec1{ va }, vec2{ vb }{}
	zip_iterator begin() const
	{
		return { std::begin(vec1), std::begin(vec2) };
	}
	zip_iterator end() const {
		return { std::end(vec1), std::end(vec2) };
	}
};

int main()
{
	using namespace std;
	vector<double> a{ 1.0, 2.0, 3.0 };
	vector<double> b{ 4.0, 5.0, 6.0 };
	zipper zipped{ a,b };
	
	const auto add_product([](double sum, const auto& p)
		{
			return sum + p.first * p.second;
		});
	const auto dot_product(accumulate(begin(zipped), end(zipped), 0.0, add_product));

	cout << dot_product << endl;
}
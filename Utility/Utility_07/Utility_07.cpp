//std::variant로 다양한 타입을 저장한다.
//struct나 class 외에 variant를 사용해서 데이터 타입을 구성.
//cat과 dog타입을 인지하는 프로그램 하나를 구현해서 런타임 다형성을 사용하지 않고도 cat과 dog를 뒤섞어 저장하자.
#include <iostream>
#include <variant>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class cat {
	string name;

public:
	cat(string n) : name{ n } {}

	void meow() const {
		cout << name << " says Meow!\n";
	}
};

class dog {
	string name;

public:
	dog(string n) : name{ n } {}

	void woof() const {
		cout << name << " says Woof!\n";
	}
};

using animal = variant<dog, cat>;

template <typename T>
bool is_type(const animal& a) {
	return holds_alternative<T>(a);
}

struct animal_voice
{
	void operator()(const dog& d) const { d.woof(); }
	void operator()(const cat& c) const { c.meow(); }
};

int main()
{
	list<animal> l{ cat{"Tuba"}, dog{"Balou"}, cat{"Bobby"} };

	for (const animal& a : l) {
		switch (a.index()) {
		case 0:
			get<dog>(a).woof();
			break;
		case 1:
			get<cat>(a).meow();
			break;
		}
	}
	cout << "-----\n";

	for (const animal& a : l) {
		if (const auto d(get_if<dog>(&a)); d) {
			d->woof();
		}
		else if (const auto c(get_if<cat>(&a)); c) {
			c->meow();
		}
	}
	cout << "-----\n";

	for (const animal& a : l) {
		visit(animal_voice{}, a);
	}
	cout << "-----\n";

	cout << "There are "
		<< count_if(begin(l), end(l), is_type<cat>)
		<< " cats and "
		<< count_if(begin(l), end(l), is_type<dog>)
		<< " dogs in the list.\n";
}

#include <iostream>

// Cap
/*class Cap {
public:
	Cap() {
		std::cout << "Cap()" << '\n';
	}
	int getX() {
		return _x;
	}
private:
	int _x;
};


class Human {
public:
	Human() {
		std::cout << "Human()" << '\n';
	}
	int getCapX() {
		return _cap.getX();
	}
private:
	Cap _cap;
	std::string _name;
};*/

// Electrofuel
/*class Electrofuel {
public:
	const std::string& getInfo() {
		return _info;
	}
private:
	const std::string _info = "Electrofuel";
};

template <class T>
class Vehicle {
public:
	void printInfo() {
		std::cout << _fuel.getInfo() << '\n';
	}
private:
	T _fuel;
};

class ElectricBicycle : public Vehicle<Electrofuel> {
public:
	ElectricBicycle(const std::string& name) : _name(name) {}
	void printName() {
		std::cout << _name << '\n';
	}
private:
	const std::string _name;
};*/

// Преобразование типов
class Parent {
public:
	virtual void sleep() {
		std::cout << "sleep()" << '\n';
	}
	virtual ~Parent(){}
};

class Child : public Parent {
public:
	void sleep() override {
		std::cout << "child sleep()" << '\n';
	}
	void gotoSchool() {
		std::cout << "gotoSchool()" << '\n';
	}
};


int main() {
	/*Cap p;
	Human h;*/

	// Vehicle<Electrofuel> v;
	// ElectricBicycle eb("Kawasaki");

	// Преобразование типов
	Parent parent;
	Child child;

	// upcast (неявное преобразование типов разрешено)
	Parent* pParent = &child;			// стек, по нему делать не надо
	Parent* pParent2 = new Child();		// куча

	// downcast
	Child* pChild = (Child*)pParent; // работает, потому что pParent указывает на child, ему есть куда downcast'иться

	// C-style каст выполняет первый успешный каст в порядке: 
	// 
	// const_cast		// снимает константность
	// static_cast		// делает преобразования в одной иерархии, но если есть несвязанные между собой классы, то это UB
	// static_cast-> const_cast 
	// reinterpret_cast
	// reinterpret_cast -> const_cast

	// Если классы в иерархии наследования не виртуальные, то можно кастовать (upcast/downcast) через static_cast
	Child* pChild2 = static_cast<Child*>(pParent);

	// douncast UB - так делать нельзя
	// Child* pChild2 = (Child*)&parent;	// залез не в свою ячейку памяти. Работает как надо, но нельзя: превышение полномочий

	pParent->sleep();	// sleep() non-virtual	// child sleep(), если virtual
	pChild->sleep();	// child sleep()
	//pChild2->sleep();	// UB

	delete pParent2;

	// static_cast<new_type>(expression)
	int a = 5;
	std::cout << "a: " << a << '\n';
	double b = static_cast<double>(a);	// раньше: double(a) или (double)a;
	std::cout << "b: " << b << '\n';

	int c = 6;
	const int* pC = &c;
	int* ppC = const_cast<int*>(pC);
	std::cout << "============\n";
	std::cout << *ppC << '\n';
	*ppC = 4;
	std::cout << *ppC << " " << c << '\n';

	// dinamic_cast<new_type>(expression)
	// Классы должны быть одной иерархии: и виртуальные, и наследуются
	Child* pChild3 = dynamic_cast<Child*>(&parent);	// в случае с виртуальными классами. Позволяет проверить получилось или нет(если нет, то нулптр)
	if (pChild3 == nullptr) {
		std::cout << "pChild3 is nullptr" << '\n';
	}

	/*Parent* pParent3 = new Child();
	Child* pChild = dynamic_cast<Child*>(pParent3);
	delete pParent3;*/

	try {
		Child& pChild5 = dynamic_cast<Child&>(parent);
	}
	catch(std::bad_cast& e) {
		std::cout << "cast parent to child result in bad_cast\n";
		std::cout << e.what() << '\n';
	}

	// reinterpred_cast


}

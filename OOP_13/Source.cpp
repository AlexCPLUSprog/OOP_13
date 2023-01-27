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

// �������������� �����
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

	// �������������� �����
	Parent parent;
	Child child;

	// upcast (������� �������������� ����� ���������)
	Parent* pParent = &child;			// ����, �� ���� ������ �� ����
	Parent* pParent2 = new Child();		// ����

	// downcast
	Child* pChild = (Child*)pParent; // ��������, ������ ��� pParent ��������� �� child, ��� ���� ���� downcast'�����

	// C-style ���� ��������� ������ �������� ���� � �������: 
	// 
	// const_cast		// ������� �������������
	// static_cast		// ������ �������������� � ����� ��������, �� ���� ���� ����������� ����� ����� ������, �� ��� UB
	// static_cast-> const_cast 
	// reinterpret_cast
	// reinterpret_cast -> const_cast

	// ���� ������ � �������� ������������ �� �����������, �� ����� ��������� (upcast/downcast) ����� static_cast
	Child* pChild2 = static_cast<Child*>(pParent);

	// douncast UB - ��� ������ ������
	// Child* pChild2 = (Child*)&parent;	// ����� �� � ���� ������ ������. �������� ��� ����, �� ������: ���������� ����������

	pParent->sleep();	// sleep() non-virtual	// child sleep(), ���� virtual
	pChild->sleep();	// child sleep()
	//pChild2->sleep();	// UB

	delete pParent2;

	// static_cast<new_type>(expression)
	int a = 5;
	std::cout << "a: " << a << '\n';
	double b = static_cast<double>(a);	// ������: double(a) ��� (double)a;
	std::cout << "b: " << b << '\n';

	int c = 6;
	const int* pC = &c;
	int* ppC = const_cast<int*>(pC);
	std::cout << "============\n";
	std::cout << *ppC << '\n';
	*ppC = 4;
	std::cout << *ppC << " " << c << '\n';

	// dinamic_cast<new_type>(expression)
	// ������ ������ ���� ����� ��������: � �����������, � �����������
	Child* pChild3 = dynamic_cast<Child*>(&parent);	// � ������ � ������������ ��������. ��������� ��������� ���������� ��� ���(���� ���, �� ������)
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

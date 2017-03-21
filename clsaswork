#include <iostream>

using namespace std;

class A{
public:
	void A::public_method();
protected:
	void A::protected_method();
private:
	void A::private_method();
};

void A::public_method(){
	cout << "public" << endl;
}

void A::protected_method(){
	cout << "protected" << endl;
}

void A::private_method(){
	cout << "private" << endl;
}

class B : public A{

};
class C : protected A{

};
class D : private A{

};

int main(){
	A a;
	B b;
	C c;
	D d;

	cout << "protected A: " << endl;
	a.public_method();
	//a.protected_method();
	//a.private_method();
	
	cout << "public B: " << endl;
	b.public_method();
	//b.privete_method();
	//b.protected_method();
	
	cout << "protected C: " << endl;
	//c.public_method();
	//c.private_method();
	//c.protected_method();
	
	cout << "private D: " << endl;
	//d.public_method();
	//d.private_method();
	//d.protected_method();
	
	system("pause");
}

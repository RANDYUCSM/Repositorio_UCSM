#include<iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido()=0;
};
class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "El perro ladra" <<endl;
    }
};
class Gato : public Animal {
public:
    void hacerSonido() {
        cout << "El gato maulla" <<endl;
    }
};
class Vaca : public Animal {
public:
    void hacerSonido() {
        cout << "La vaca hace mu XD" <<endl;
    }
};
int main() {
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();
    Animal* animal3 = new Vaca();
    animal1->hacerSonido();
    animal2->hacerSonido();
    animal3->hacerSonido();

    return 0;
};


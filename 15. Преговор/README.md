# Преговор

### Задача 1

Отстранете грешката в програмата. Намерете резултата от изпълнението на поправената програма.

```c++
#include <iostream.h>

class A {
public:
    A(int a = 2);
    void f();
    void g();
    int h() const;
    void k() const;
private:
    int n;
};

A::A(int a) {
    std::cout << "A(int)\n";
    n = a-1;
}

void A::f() {
    std::cout << "f()\n";
    n++;
}

void A::g() {
    std::cout << "g()\n";
    f();
    n = 2*h() + 3;
    f();
}

int A::h() const {
    std::cout << "h()\n";
    n--;
    return n;
}

void A::k() const {
    std::cout << "k()\n";
    std::cout << n << std::endl;
}

int main() {
    A a;
    A b(5);
    A c = b;
    A d = A(13);
    a.f(); b.g(); c.f(); d.g(); d.k();
    A e(a.h()+b.h()+c.h());
    e.k();
    return 0;
}
```


### Задача 2

Отговорете на въпросите:
- Кои са основните принципи на ООП?
- В кои случаи се извикват конструкторите за присвояване/копиране?
- Обяснете свойството полиморфизъм. Дайте пример.
- Кои са компонентите на каноничното представяне на клас?
- Каква е ролята на указателя this?


### Задача 3

Определене възможността за достъп до обектите:

```c++
class Base {
    private: a1;
    protected: a2;
    public: a3;
};

class D1: public Base {
    private: a4;
    protected: a5;
    public: a6;
};

class D2: D1 {
    private: a7;
    protected: a8;
    public: a9;
};

class D3: protected D2 {
    private: a10;
    protected: a11;
    public: a12;
};

class D4: private D1 {
    private: a13;
    protected: a14;
    public: a15;
};

class D5: public D2 {
    private: a16;
    protected: a17;
    public: a18;
}
```

### Задача 4

Имате следната йерархия:
```c++
class A {};
class B: virtual public A {};
class C {};
class D: public C, public B {};
```
В какъв ред ще се извикат конструкторите и деструкторите при инициализиране и изтриване на обект от тип D?
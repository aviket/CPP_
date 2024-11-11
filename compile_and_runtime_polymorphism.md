### Generic Programming
Generic programming in C++ is a style of programming that allows writing code that works with any data type. This is achieved through **templates**. Templates let you write a function or class where some of the types are parameters, allowing them to operate on multiple types without rewriting code for each one.

**Key Aspects of Generic Programming**:
- **Type Independence**: Functions and classes are written without knowing the specific types they will operate on.
- **Code Reusability**: Templates allow writing flexible code that can handle different data types, improving reusability.
- **Compile-Time**: Templates are resolved at compile time, meaning the compiler generates specific instances of template code for each data type used.

For example, a function template for finding the maximum of two values:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 5, y = 10;
    double p = 3.14, q = 2.72;

    std::cout << max(x, y) << std::endl;  // Uses T as int
    std::cout << max(p, q) << std::endl;  // Uses T as double

    return 0;
}
```

Here, `max` works for any type `T`, provided `T` supports the `>` operator. The compiler will generate separate instances of `max` for `int` and `double` when you call it with those types.

### Compile-Time vs. Runtime Polymorphism

**Polymorphism** allows objects to be treated as instances of their parent class type, enabling flexibility in code design. C++ supports **compile-time polymorphism** through templates and **runtime polymorphism** through inheritance and virtual functions.

#### Compile-Time Polymorphism
Compile-time polymorphism occurs when the compiler determines the exact method to call at compile time. This is primarily achieved through:
- **Function Overloading**: Multiple functions with the same name but different parameters.
- **Operator Overloading**: Defining custom behaviors for operators based on operand types.
- **Templates**: Allowing generic types in functions and classes.

**Advantages**:
- Fast execution, as the function call is resolved at compile time.
- Reduced overhead since there is no need for dynamic dispatch (vtable lookup).

**Disadvantages**:
- Less flexibility, as the types and functions are fixed during compilation.
- Not suitable for scenarios requiring late binding.

Example of function overloading:

```cpp
#include <iostream>

void print(int x) { std::cout << "Integer: " << x << std::endl; }
void print(double x) { std::cout << "Double: " << x << std::endl; }

int main() {
    print(5);       // Calls print(int)
    print(3.14);    // Calls print(double)
}
```

#### Runtime Polymorphism
Runtime polymorphism is achieved using **inheritance** and **virtual functions**. It allows the decision about which function to call to be made at runtime. When a derived class overrides a virtual function from the base class, the appropriate version of the function is called based on the actual object type.

**Key Mechanism**: Virtual functions and **dynamic dispatch** using a vtable (a table of function pointers for each object).

**Advantages**:
- Greater flexibility, as the exact function that’s called is determined at runtime.
- Suitable for scenarios where behavior needs to vary for derived classes.

**Disadvantages**:
- Slightly slower due to the overhead of dynamic dispatch.
- Requires more memory for storing the vtable.

Example of runtime polymorphism:

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() const { std::cout << "Animal sound" << std::endl; }
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof!" << std::endl; }
};

int main() {
    Animal* animal = new Dog();  // Pointer to base class
    animal->speak();             // Calls Dog's speak due to virtual function

    delete animal;
}
```

In this example, the type of `animal` is determined at runtime, so `Dog`'s `speak` function is called even though `animal` is an `Animal*`.

### Summary

| Feature                    | Compile-Time Polymorphism                | Runtime Polymorphism                   |
|----------------------------|------------------------------------------|----------------------------------------|
| Mechanism                  | Function overloading, templates          | Virtual functions                      |
| Resolution                 | At compile time                          | At runtime                             |
| Flexibility                | Limited                                  | High                                   |
| Overhead                   | None (or minimal)                        | vtable lookup (slight runtime cost)    |
| Common Use Cases           | Generic algorithms, type-independent code| Inheritance-based polymorphic behavior |
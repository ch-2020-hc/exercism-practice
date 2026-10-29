
# C++ Concept Learning Goals: Headers, Classes & Namespaces

This document summarizes the core C++ concepts, syntax rules, and architectural patterns covered in the **Doctor Data** exercise.

---

## 1. Header & Source Separation
* **Declarations vs. Definitions:** Header files (`.h`) act as an API contract specifying *what* a codebase offers, while source files (`.cpp`) contain the actual implementation details.
* **Include Guards:** Use `#pragma once` or `#ifndef` / `#define` / `#endif` macros in headers to prevent duplicate inclusions during compilation.
* **Default Arguments:** Default parameter values (e.g., `int size = 0`) **must** be specified in the header file declaration, not in the source file definition.

---

## 2. Classes & Encapsulation
* **Private State & Lifetime:** Private member variables store the internal state of an object and persist in memory for as long as the object exists. **private variables will be served to let other public functions exchange values.**

* **Default Privacy:** In a C++ `class`, all members default to `private` unless placed under a `public:` access specifier (unlike a `struct`, where members default to `public`).
* **In-Class Member Initialization:** Adding `{}` to member declarations (e.g., `int size{};`) ensures primitive types are default-initialized to zero rather than containing random garbage memory values.

---

## 3. Constructors & Object Instantiation
* **Constructors:** Special public member functions with the exact same name as the class and no return type. They initialize objects upon creation.
* **Objects vs. Constructors:** Writing `heaven::Vessel bob{"Robert Johansson", 1};` creates an **object instance** (`bob`) by invoking the `Vessel` constructor.
* **Constructor Overloading:** A class can have multiple constructors or a single constructor with default arguments to support different initialization signatures.
* **Member Initializer Lists:** The preferred C++ idiom for assigning constructor parameters directly to member variables before the constructor body executes:
  ```cpp
  Vessel::Vessel(std::string vessel_name, int vessel_id)
      : name{vessel_name}, id{vessel_id} {}


---

## 4. Syntax: `.` vs. `::`

* **Dot Operator (`.`):** Used on an **object instance** to access its public functions or variables (e.g., `bob.get_name()`).
* **Scope Resolution Operator (`::`):** Used with **type or namespace names** to define functions outside the class header, access static members, or navigate nested scopes (e.g., `heaven::Vessel::start_engine()`).

---

## 5. Scope & Member Functions

* **Implicit Context:** Inside member functions, private variables can be accessed directly by name (e.g., `generation + 1`). The compiler automatically maps them to the calling object's instance via the implicit `this` pointer.
* **Returning Same-Type Instances:** A member function can construct and return a new instance of its own class type:
```cpp
Vessel Vessel::replicate(std::string new_name) {
    return Vessel{new_name, id + 1, current_system, generation + 1};
}

```



---

## 6. Namespaces & Free Functions

* **Namespaces:** Group related code (e.g., `namespace heaven`, `namespace star_map`) to avoid global name collisions.
* **Namespace Definitions:** Definitions in `.cpp` files must either be wrapped in a `namespace name { ... }` block or explicitly qualified with the namespace prefix (e.g., `heaven::Vessel::Vessel`).
* **Free / Standalone Functions:** Functions that operate on class instances without belonging to the class itself (e.g., `heaven::in_the_same_system(vessel1, vessel2)`).


#include <stdio.h>

// Define three structs with typedef
typedef struct {
  char firstName[20];
  char lastName[20];
} Owner;

typedef struct {
  char brand[20];
  int year;
  Owner owner;
} Car;

typedef struct {
  char name[30];
  Car featuredCar;
} Dealership;

int main() {
  Owner person = {"John", "Doe"};
  Car car1 = {"Toyota", 2010, person};
  Dealership d = {"City Motors", car1};

  printf("Dealership: %s\n", d.name);
  printf("Featured Car: %s (%d), owned by %s %s\n",
    d.featuredCar.brand,
    d.featuredCar.year,
    d.featuredCar.owner.firstName,
    d.featuredCar.owner.lastName);

  return 0;
}

/*
| | `typedef enum` | `typedef struct` |  
|---|---|---|  
| **儲存的內容** | **整數值**（列舉常數）   | **多個成員變數的集合** |  
| **佔用記憶體** | 通常 4 bytes（一個整數） | 所有成員大小總和（可能很大） |  
| **用途**       | 表示**有限的狀態選項**   | 表示**複合資料結構** |  
| **運算方式**   | 可比大小、switch、賦值   | 存取內部成員（`.` 或 `->`） |  


*/
// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include <string>
#include "doctor_data.h"
/* You need to define in detail how the members inside the namespace work.
The compiler needs to know that the definitions in your .cpp file belong to the exact same namespace you declared in your header file.
 
You have two ways to do this in your .cpp file:
 
Method 1: Wrap the code in the namespace block (Recommended)
This is the cleanest and most common approach.
 
Method 2: Explicitly prefix everything with the namespace
If you don't use a namespace block, you must explicitly qualify every function definition with both the namespace and the class name using ::.
E.g. heaven::Vessel::Vessel(...) without using the namespace heaven{}
*/
namespace heaven {
    
// Vessel::Vessel(std::string vessel_name, int vessel_id){
//     Vessel::name = vessel_name;
//     Vessel::generation = vessel_id;
// }
/* Two ways to declare the constructor:
1. Vessel::Vessel(std::string vessel_name, int vessel_id,
               star_map::System system)
    : name(vessel_name), generation(vessel_id), current_system(system) {}
 2. see below, same idea as method 1. With both methods, you need to make sure the arguments inside the constructor Vessel are all used.
*/
Vessel::Vessel(std::string vessel_name, int vessel_id, star_map::System system){
    Vessel::name = vessel_name;
    Vessel::generation = vessel_id;
    Vessel::current_system = system;
}
    
// !!Important: you need a new Vessel OBJECT to return the new members.
// 1. Calculate new values based on current object ('this' instance)
// 2. Create a new Vessel object passing the updated values
/*
You don't need to write Vessel:: because when you are inside a member function of a class, C++ automatically knows that plain variable names like generation and id refer to the member variables of the object that called the function.
 
Here is what is happening under the hood:
 
1. The Implicit this Pointer
Every non-static member function in C++ receives a hidden, implicit pointer named this that points to the specific object executing the function.
 
When you call:
 
C++
bob.replicate("Mario");
Inside replicate(), writing:
 
C++
int new_generation = generation + 1;
is automatically translated by the compiler into:
 
C++
int new_generation = this->generation + 1; // "Take bob's generation and add 1"
Because replicate() is a member function of Vessel, C++ automatically searches the class's scope first whenever you use a variable name.
*/
Vessel Vessel::replicate(std::string new_name){
    Vessel V{new_name, generation +1, current_system};
    return V;
}
void Vessel::make_buster(){
    Vessel::busters += 1;
}
bool Vessel::shoot_buster(){
    if (Vessel::busters > 0){
        Vessel::busters -= 1;
        return true;
    } 
    else return false;
}
std::string get_older_bob(Vessel v1, Vessel v2){
    if(v1.generation > v2.generation) return v2.name;
    else return v1.name;
}
bool in_the_same_system(Vessel v1, Vessel v2){
    return v1.current_system == v2.current_system;
}

Vessel bob{"Robert Johansson", 1};
Vessel will{"Riker", 2, star_map::System::BetaHydri};
}
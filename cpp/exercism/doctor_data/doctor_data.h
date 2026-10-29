// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#ifndef DOCTOR_DATA_H
#define DOCTOR_DATA_H
#include <string>
namespace star_map{
    enum class System{
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}
namespace heaven{
    class Vessel{
        // In C++, any member (variable or function) defined inside a class 
        // before an explicit access specifier (like public: or protected:) defaults to private.
        public:
            // Vessel(std::string vessel_name, int vessel_id);
            //Instead of writing two separate constructors, you can often achieve the exact same behavior 
            // with one constructor by providing a default value for the third parameter
            Vessel(std::string vessel_name, int vessel_id, star_map::System system = star_map::System::Sol);
    
            Vessel replicate(std::string new_name);
            void make_buster();
            bool shoot_buster();
    
            std::string name{};
            star_map::System current_system{} ;
            int generation{1};
            int busters{0};
    };   
    std::string get_older_bob(Vessel v1, Vessel v2);
    bool in_the_same_system(Vessel v1, Vessel v2);
}
#endif
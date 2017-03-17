#include "tech.h"

Tech::Tech(std::string path, ParentsVector newParents)
          : parents(newParents) {}

Tech::ParentsVector& Tech::getParents(){
    return parents;
}

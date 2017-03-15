#ifndef TECH_H
#define TECH_H

#include <memory>
#include <vector>

class Tech {
private:
    typedef std::vector<const std::unique_ptr<Tech>&> ParentsVector;

    ParentsVector parents;

public:
    Tech(std::string path, ParentsVector newParents);

    ParentsVector& getParents();
};

#endif

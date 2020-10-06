//
// Created by W on 10/6/20.
//

#ifndef LUDUMDARE2020_ROOT_HPP
#define LUDUMDARE2020_ROOT_HPP
#include "wilo_dev_core.hpp"
namespace wlo {
    class Root {
    public:
        Root();
        std::string getShaderPath();
    private:
        std::string shaderPath;
    };

}


#endif //LUDUMDARE2020_ROOT_HPP

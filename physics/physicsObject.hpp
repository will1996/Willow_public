#include<glm/glm.hpp>
#include<vector>

//physics object interface, enforces basic functionality of physics objects. 
//
//Requires the implementation of only two methods:
//  Step(double increment): void method that increments physics objects 1 time-step
//  GetVerticies(): returns a vector of glm::vec3's,
//  the order of returned verticies in the vector is the implied 
//  rendering order
//
//
//

class PhysicsObject{
  public:
    virtual void Step(double increment);
    virtual std::vector<glm::vec3> GetVerticies();
};

#include "physicsObject.hpp"
#include<vector>

class PointMass : public PhysicsObject {
  public:
  void Step(double increment);
  //implements update from the physics Object Interface, update
  //s velocity and position
    
   
  std::vector<glm::vec3> GetVerticies();
  //implements GetVerticies from the physics Object Interface, 
  //returns a vector of 1 element containing position
    
  PointMass();//default constructor creates a stationary unit point mass at the origin
  PointMass(float mass); //creates a point of mass mass at the origin 
  PointMass(float mass, glm::vec3 position, glm::vec3 velocity);

  void apply(glm::vec3 Force); //updates acceleration for next time step
  private: 
  //physical attributes
   glm::vec3 d_position;
   glm::vec3 d_velocity;
   glm::vec3 d_acceleration;
   float d_mass;
  
  
    



};

#include "PointMass.hpp"
using std::vector;

void PointMass::Step(double increment){
  d_velocity+=d_acceleration*(float)increment; 
  d_position+=d_velocity*(float)increment;
  d_acceleration = {0,0,0};
}


std::vector<glm::vec3> PointMass::GetVerticies(){
 vector verticies = {d_position};
  return verticies; 
}


PointMass::PointMass(){
d_mass = 1;
d_position= {0,0,0};
d_velocity= {0,0,0};
d_acceleration= {0,0,0};
}
PointMass::PointMass(float mass){
d_mass = mass;
d_position= {0,0,0};
d_velocity= {0,0,0};
d_acceleration= {0,0,0};
}
PointMass::PointMass(float mass, glm::vec3 position, glm::vec3 velocity){
d_mass = 1;
d_position= position;
d_velocity= velocity;
d_acceleration= {0,0,0};
}


void PointMass::apply(glm::vec3 force){
  d_acceleration+=force/d_mass;
}

#include "renderable.hpp"


namespace wilo{
  namespace rendr{
    renderable::renderable(){
      //the default implementation just draws a 
      //red triangle in normalzied coordinates
      //to the screen for debugging
      m_vertices = {
      {{0.0,0.5,0.0},{1.0,0.0,0.0},{0.0,0.0}},
      {{0.5,-0.5,0.0},{1.0,0.0,0.0},{0.0,0.0}},
      {{-0.5,-0.5,0.0},{1.0,0.0,0.0},{0.0,0.0}},
                   };
      m_indices = {0,1,2};
    
    } 
    renderable::~renderable(){
    //do nothing for the base class; 
    }
    std::vector<Vertex> renderable::vertices(){
    return m_vertices; 
    }
    std::vector<Index> renderable::indices(){
    return m_indices;
    }

    std::string renderable::name(){
      return m_name; 
    }
  
  
  }



}

#include<glm/glm.hpp>
#include<vector>
#include<string>
#include "rendrtypes.hpp"

//baseclass for renderable
namespace wilo{
  namespace rendr{
    class renderable{
        public:
          renderable();
          ~renderable(); 
          std::vector<Vertex> vertices();
          std::vector<Index> indices();
          std::string name();
        private:
          std::string m_name; 
          std::vector<Vertex> m_vertices;
          std::vector<Index> m_indices;

    };
  }
}


add_Library(physics PhysicsObject.hpp)
find_Package(glm REQUIRED)
target_link_libraries(physics PUBLIC glm)

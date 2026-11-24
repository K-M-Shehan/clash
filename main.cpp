#include <iostream>

// X-macro list : (id, display name, damage multiplier)
#define ELEMENT_LIST \
  X(FIRE, "Fire", 1.5f) \
  X(ICE, "Ice", 1.2f) \
  X(LIGHTNING, "Lightning", 2.0f)

// Position struct
struct Point {
  int x;
  int y;

  // overloading the + operator to let us add 2 points x or y coordinates
  Point operator+(const Point& other) const {
    return Point{ x + other.x, y + other.y };
  }
};

// generate the enum
enum class Element {
  #define X(id, name, mult) id,
  ELEMENT_LIST
  #undef X
};

// generate the name lookup function
const char* get_element_name(Element e) {
  switch (e) {
    #define X(id, name, mult) case Element::id: return name;
    ELEMENT_LIST
    #undef X
  }
  return "Unknown";
}

// generate the multiplier lookup function
const float get_element_mult(Element e) {
  switch (e) {
    #define X(id, name, mult) case Element::id: return mult;
    ELEMENT_LIST
    #undef X
  }
  return 0;
}

int main() {
  Element spell = Element::LIGHTNING;
  std::cout << "Spell: " << get_element_name(spell) << std::endl;
  std::cout << "Multiplier: " << get_element_mult(spell) << "x" << std::endl;

  Point start{10, 20};
  Point move{5, -3};
  Point new_position = start + move;
  std::cout << "New position: (" << new_position.x << ", " << new_position.y << ")" << std::endl;

  return 0;
}

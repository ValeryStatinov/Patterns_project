#ifndef ADDITIONALALGEBRAICFUNCTIONS_H
#define ADDITIONALALGEBRAICFUNCTIONS_H
//---algebraic vector functions
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include <cmath>
template <typename T>
sf::Vector2<T> normalize(const sf::Vector2<T>& v) {
  sf::Vector2<T> normalized;
  if (v.x == 0 && v.y == 0) {
    normalized.x = 0;
    normalized.y = 0;
    return normalized;
  }
  normalized = v;
  T norm = v.x * v.x + v.y * v.y;
  norm = sqrt(norm);
  normalized.x /= norm;
  normalized.y /= norm;
  return normalized;
}

template <typename T>
T operator *(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2) {
  T scalar_prod = v1.x * v2.x + v1.y * v2.y;
  return scalar_prod;
}

template <typename T>
float squared_module_vector(const sf::Vector2<T>& v) {
  return v.x * v.x + v.y * v.y;
}
#endif // ADDITIONALALGEBRAICFUNCTIONS_H

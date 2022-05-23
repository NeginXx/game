#include <cstdint>

template <typename T>
struct Vec2 {
  T x;
  T y;
  Vec2& operator+=(const Vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
  }
  Vec2& operator-=(const Vec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }
  Vec2 operator-() {
    return Vec2{-x, -y};
  }
};

template <typename T>
Vec2<T> operator*(T c, const Vec2<T>& v) {
  return Vec2<T>{v.x * c, v.y * c};
}

template <typename T>
Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2) {
  Vec2<T> res = v1;
  return res += v2;
}

template <typename T>
Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2) {
  Vec2<T> res = v1;
  return res -= v2;
}

template <typename T>
bool operator==(const Vec2<T>& v1, const Vec2<T>& v2) {
  return v1.x == v2.x && v1.y == v2.y;
}

template <>
bool operator==(const Vec2<float>& v1, const Vec2<float>& v2) = delete;
template <>
bool operator==(const Vec2<double>& v1, const Vec2<double>& v2) = delete;

using Vec2f = Vec2<float>;
using Vec2i = Vec2<int32_t>;
using Vec2u = Vec2<uint32_t>;
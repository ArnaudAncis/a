struct vector2d {
  double x, y;

  vector2d(double x = 0, double y = 0)
    : x(x), y(y) { }
  
  vector2d(const vector&) = default;
  
  vector2d operator +(const vector2d& v) const {
    return vector2d(x + v.x, y + v.y);
  }

  vector2d& operator +=(const vector2d& v) {
    return *this = *this + v;
  }

  vector2d& operator =(const vector2d& v) {
    x = v.x;
    y = v.y;

    return *this;
  }
};

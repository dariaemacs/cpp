#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>

struct Rectangle{
  double left   {0};
  double right  {0};
  double top    {0};
  double bottom {0};

  std::int8_t gray_color {0};

  float score {0};
  
  bool is_drawn {true};
};

#endif //RECTANGLE_HPP

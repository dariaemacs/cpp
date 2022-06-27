#ifndef PARAMETERS_DATA_HPP
#define PARAMETERS_DATA_HPP

#include <cstdint>
#include <string>

#include "rectangle.hpp"

struct ParametersData{
  char *path {nullptr};

  Rectangle *rectangles {nullptr};
  std::uint32_t rectangle_size {0};

  float  theta {0};
  double sigma {0};
  
  bool normalize {true};
  
  ParametersData(){}
  ParametersData(const ParametersData& oth);
  ParametersData(ParametersData&&);
  ParametersData& operator=(const ParametersData& oth);
  ParametersData& operator=(ParametersData&&);
  ~ParametersData();

  void set_path(const std::string& path);
};

#endif //PARAMETERS_DATA_HPP

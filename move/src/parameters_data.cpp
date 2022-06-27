#include "parameters_data.hpp"
#include <iostream>

ParametersData::ParametersData(const ParametersData& oth){
  *this = oth;
}

ParametersData::ParametersData(ParametersData&& oth){
  *this = std::move(oth);
}

ParametersData& ParametersData::operator=(const ParametersData& oth){
  if (this == &oth) {
    return *this;
  }

  if(oth.path){
    set_path(oth.path);
  }

  if(rectangles){
    delete[] rectangles;
    rectangle_size = 0;
  }
  
  if(oth.rectangles && oth.rectangle_size > 0){
    rectangle_size = oth.rectangle_size;
    rectangles = new Rectangle[oth.rectangle_size];
    std::copy(oth.rectangles, oth.rectangles + oth.rectangle_size, rectangles);
  }else{
    std::cerr << "Wrong copy contructor with rectangles;"
              << " oth.rectangle {" << oth.rectangles << "} "
              << " oth.rectangle_size {" << oth.rectangle_size << "}"
              << std::endl;
  }

  theta = oth.theta;
  sigma = oth.sigma;
  normalize = oth.normalize;

  return *this;
}

ParametersData& ParametersData::operator=(ParametersData&& oth){
  if (this == &oth) {
    return *this;
  }

  if(path){
    delete[] path;
  }
  
  if(oth.path){
    path = oth.path;
    oth.path = nullptr;
  }

  if(rectangles){
    delete[] rectangles;
    rectangle_size = 0;
  }
  
  if(oth.rectangles && oth.rectangle_size > 0){
    rectangles = oth.rectangles;
    oth.rectangles = nullptr;
    
    rectangle_size = oth.rectangle_size;
    oth.rectangle_size = 0;
  }else{
    std::cerr << "Wrong copy contructor with rectangles;"
              << " oth.rectangle {" << oth.rectangles << "} "
              << " oth.rectangle_size {" << oth.rectangle_size << "}"
              << std::endl;
  }


  theta = std::move(oth.theta);
  sigma = std::move(oth.sigma);
  normalize = std::move(oth.normalize);

  return *this;
}

ParametersData::~ParametersData(){
  if(path){
    delete[] path;
  }

  if(rectangles){
    delete[] rectangles;
  }
}

void ParametersData::set_path(const std::string& new_path){
  if(path){
    delete[] path;
  }
  path = new char[new_path.size() + 1];
  std::copy(new_path.begin(), new_path.end(), path);
  path[new_path.size()] = '\0';
}

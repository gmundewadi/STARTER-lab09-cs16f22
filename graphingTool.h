#ifndef GRAPHINGTOOL_H
#define GRAPHINGTOOL_H

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

void plot(const std::vector<int>& x, 
          const std::vector<int>& y, 
          const std::string& xlabel, 
          const std::string& ylabel, 
          const std::string& title,
          const std::string& color);


#endif // GRAPHINGTOOL_H
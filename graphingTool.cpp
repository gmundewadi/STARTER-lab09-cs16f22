#include "graphingTool.h"

void plot(const std::vector<int>& x, 
          const std::vector<int>& y, 
          const std::string& xlabel, 
          const std::string& ylabel, 
          const std::string& title, 
          const std::string& c) {
    
    // Set the size of output image to 1200x780 pixels
    plt::figure_size(1200, 780);
    
    // Plot line from given x and y data and set the color.
    plt::plot(x, y, c);

    // set x and y labels
    plt::xlabel(xlabel);
    plt::ylabel(ylabel);

    // Add graph title
    plt::title(title);

    // Save the image as {title}.png
    plt::save("./" + title + ".png");
}
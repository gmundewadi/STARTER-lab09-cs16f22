#include "dataManipulationFuncs.h"
#include "matplotlibcpp.h"
#include <vector>

using namespace std;
namespace plt = matplotlibcpp;

/**
 * Generates a scatterPlot using matplotlib and saves it as {title}.png
 *
 * @param[in] x x data points
 * @param[in] y y data points 
 * @param[in] xLabel x-axis label on graph
 * @param[in] yLabel y-axis label on graph
 * @param[in] title title of graph
 * @param[in] color color of scatter points on graph
 */
void scatterPlot(
    const vector<double>& x, 
    const vector<double>& y, 
    const string xlabel, 
    const string ylabel, 
    const string title, 
    const string color) {    
    
    /* Plot line from given x and y data and set the color. */

    /* set x and y labels */

    /* Add graph title */
  
    /* Save the image as {title}.png */
}


int main() {
   /*TODO: STUB*/
   return 0;   
}


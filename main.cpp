#include "matplotlibcpp.h"

#include <fstream>
#include <sstream>

#include <string>
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
    
    // Plot line from given x and y data and set the color.
    plt::figure();
    plt::scatter(x, y, 1.0, {{"color", color}});

    // set x and y labels
    plt::xlabel(xlabel);
    plt::ylabel(ylabel);

    // Add graph title
    plt::title(title);

    // Save the image as {title}.png
    plt::save("./" + title + ".png");
}


/**
 * Parse data from a csv file. All datapoints in the csv are doubles
 *
 * @param[out] result data from the csv file. Each vector is the data from a column. {{Age}, {d180}, {d13C}}
 * @param[in] pathToFile path the csv
 * @param[in] numCol number of columns in the csv 
 */
vector<vector<double>> parseData(const string pathToFile, size_t numCol) {
    vector<vector<double>> result;
    for(size_t i = 0; i < numCol; i++){
        result.push_back(vector<double>{});
    }

    ifstream ifs(pathToFile);
    if(ifs.fail()){ 
        cerr << "Could not open file " + pathToFile << endl;
        exit(2);
    }

    string line;
    getline(ifs,line);
    while (!ifs.eof()) {  
        /*
            Parse each line into (double, double, double) where
            digits = [Age(ma), rO, rC]
        */
        string digit;
        vector<double> digits;    
        istringstream ss(line);
        while (getline(ss, digit, ',')) {
            if(digit != ""){
                digits.push_back(stod(digit));
            } 
        }

        /* If no NULL data, apped data to result */
        if(digits.size() == numCol){ 
            for(size_t cIndex = 0; cIndex < numCol; cIndex++){ 
                result[cIndex].push_back(digits[cIndex]);
            }
        } 
        getline(ifs,line);
    }    

    ifs.close();
    return result;
}


int main() {
    const size_t NUM_COLUMNS = 3;

    /* Deliverable 1 */
    vector<vector<double>> data = parseData("./2008CompilationData.csv", NUM_COLUMNS);
    
    /* Deliverable 2 */
    scatterPlot(data[0], data[1], "Age (ma)", "d18O", "d18O vs Age (ma)", "blue");
    scatterPlot(data[0], data[2], "Age (ma)", "d13C", "d13C vs Age (ma)", "red");

    /* Deliverable 3 */



}


#ifndef DATAMANIPULATIONFUNCS_H
#define DATAMANIPULATIONFUNCS_H

using namespace std; 
#include <vector>
#include <string>

vector<vector<double>> parseData(const string pathToFile, size_t numCol);
vector<vector<double>> smoothData(vector<vector<double>>& rawData, size_t windowSize); 
vector<vector<double>> filterData(vector<vector<double>>& rawData, int minAge, int maxAge);
double getAvgNextNValues(vector<double> const& v, size_t startIndex , size_t windowLength);

#endif // DATAMANIPULATIONFUNCS_H
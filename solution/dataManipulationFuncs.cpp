#include "dataManipulationFuncs.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



/**
 * Parse data from a csv file. All datapoints in the csv are doubles
 *
 * @param[out] result data from the csv file. result[i] is the data from a column i.
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

    // string line;
    // getline(ifs,line);
    // while (!ifs.eof()) {  
    //     /* Parse each line into (double, double, double) where digits = [Age(ma), rO, rC] */
    //     string digit;
    //     vector<double> digits;    
    //     istringstream ss(line);
    //     while (getline(ss, digit, ',')) {
    //         if(digit != ""){
    //             digits.push_back(stod(digit));
    //         } 
    //     }

    //     /* If no NULL data, apped data to result */
    //     if(digits.size() == numCol){ 
    //         for(size_t cIndex = 0; cIndex < numCol; cIndex++){ 
    //             result[cIndex].push_back(digits[cIndex]);
    //         }
    //     } 
    //     getline(ifs,line);
    // }    

    // ifs.close();
    string line;
    
    if (ifs.is_open()) {
        while (getline(ifs, line)) {
            string digit;
            vector<double> digits;    
            istringstream ss(line);
            while (getline(ss, digit, ',')) {
                if(digit != ""){
                    digits.push_back(stod(digit));
                }
            }

            if(digits.size() == numCol){
                for(size_t cIndex = 0; cIndex < numCol; cIndex++){ 
                    result[cIndex].push_back(digits[cIndex]);
                }
            } 
        }
        ifs.close();
    }
    return result;
}


/**
 * Smooth data from csv using the sliding window technique. 
   HINT: use getAvgNextNValues in this function so get that working first
 *
 * @param[out] result smoothed data. result[i] is the smoothed data from a column i.
 * @param[in] rawData the raw (not smoothed) data already gathered from parseData.  
 * @param[in] windowSize the length of the window
 */
vector<vector<double>> smoothData(vector<vector<double>>& rawData, size_t windowSize) {
    if(rawData.size() == 0){ 
        cerr << "No data provided to the smooth data function" << endl;
        exit(2);
    }

    vector<vector<double>> result(rawData);

    /*  start dataIndex at 1 because you don't smooth age. result[i] is the data from a column i. */
    for(size_t dataIndex = 1; dataIndex < result.size(); dataIndex++){
        for(size_t i = 0; i < result[dataIndex].size(); i++){ 
            /* smooth data using avg over sliding window */
            result[dataIndex][i] = getAvgNextNValues(result[dataIndex], i , windowSize);
        }
    }
    
    return result;
}

/**
 * filter data from csv based on its age. 
 *
 * @param[out] result data with that has ages in the range [minAge, maxAge]
 * @param[in] minAge the minAge as an int
 * @param[in] maxAge the minAge as an int
 */
vector<vector<double>> filterData(vector<vector<double>>& rawData, int minAge, int maxAge) {
    if(rawData.size() == 0){ 
        cerr << "No data provided to the filter data function" << endl;
        exit(2);
    }

    vector<vector<double>> result;
    for(size_t i = 0; i < rawData.size(); i++){
        result.push_back(vector<double>{});
    }

    /*  
        only add data with ages [minAge, maxAge] 
        The vector push backs get 'hacky'. 
        this portion of the code will require refactoring to be more generic.
    */
    for(size_t i = 0; i < rawData[0].size(); i++){ 
        double age = rawData[0][i];
        double dO = rawData[1][i];
        double dC = rawData[2][i];
        if(age >= minAge && age <= maxAge){
            result[0].push_back(age);
            result[1].push_back(dO);
            result[2].push_back(dC);
        }
    }

    return result;
}
 
/**
 * Compute the avg of the values in a sliding window given a starting index and window length. 
    If the length of the window exceeds the length of the list, compute the avg of the remaining elements instead.
 *
 * @param[out] avg the avg of the sliding window. Don't need to round this.
 * @param[in] startIndex the starting index of the sliding window
 * @param[in] windowLength the length of the window
 * @param[in] v a vector of doubles

 * @Example 1:  
    v = [1.0,2.0,3.0,4.0,5.5]
    startIndex = 2
    windowLength = 3
    avg = (3.0 + 4.0 + 5.5) / 3 = 4.16

 * @Example 2:  
    v = [1.0,2.0,3.0,4.0,5.5]
    startIndex = 3
    windowLength = 3
    avg = (4.0 + 5.5) / 2 = 9.5
 */
double getAvgNextNValues(vector<double> const& v, size_t startIndex , size_t windowLength){ 
    double sum = 0; 
    int stopIndex = min(v.size(), startIndex + windowLength); 
    for(int i = startIndex; i < stopIndex; i++){ 
        sum += v[i];
    }
    return sum / (stopIndex - startIndex);
}   

#include "matplotlibcpp.h"

#include <fstream>
#include <sstream>

#include <string>
#include <vector>

using namespace std;

vector<vector<double>> parseData(string pathToFile) {
    vector<vector<double>> result;

    ifstream ifs(pathToFile);
    if(ifs.fail()){ 
        cerr << "Could not open file " + pathToFile << endl;
        exit(2);
    }

    string line;
    int count = 0;
    getline(ifs,line);
    while (!ifs.eof()) {  
        // parse each line into (double, double, double) format  
        string num;
        vector<double> nums;    
        istringstream ss(line);
        while (getline(ss, num, ',')) {
            if(num != ""){
                nums.push_back(stod(num));
            } 
        }
        // of add if no NULL numbers
        if(nums.size() == 3){ 
            result.push_back(nums);
        } 
        getline(ifs,line);
    }    

    ifs.close();
    return result;
    
}

int main() {
    vector<vector<double>> data = parseData("./2008CompilationData.csv");
}


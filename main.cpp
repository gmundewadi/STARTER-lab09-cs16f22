#include "matplotlibcpp.h"
#include <vector>
namespace plt = matplotlibcpp;
using namespace std;


vector<vector<double>> parse(string filename) {
    vector<vector<double>> data;
    //import data from file

    return data;
}

// void plot(vector<vector<double>> data) {
//     //plot data
// }

int main() {
    vector<int> datas = {1, 3};
    plt::plot(datas);
    plt::save("test.png");
}


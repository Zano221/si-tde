#include <iostream>
#include ".\lib\json.hpp"
#include <fstream>
#include <filesystem>
#include <vector>

using json = nlohmann::json;
using namespace std;
namespace fs = filesystem;

struct processor {
    int package = 0;

};

struct matrix {
    
};

json readJson(string jsonDir) {
    ifstream j(jsonDir);
    return json::parse(j);
}

vector<string> getFileList(string path) {

}


int main() {

    //Define Configuration for tasks
    json taskConfig = readJson("Test1.json");
    //json applications = readJson(".\\Applications\\appA.json");
    
    vector<json> applications;
    string path = ".\\Applications\\";
    for (const auto & entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
        string dir =  entry.path();
        json app = readJson(dir);
        applications.push(app);
    }

    ///This is useless
    string _matrixSizeX = taskConfig["MPSOC_SIZE_X"];
    string _matrixSizeY = taskConfig["MPSOC_SIZE_Y"];
    string _tasksPerProcessor = taskConfig["TASKS_PER_PROCESSOR"];
    //string _taskList = taskConfig["TEST"];

    /// This is what is gonna be used
    int matrixSizeX = atoi(_matrixSizeX.c_str());
    int matrixSizeY = atoi(_matrixSizeY.c_str());
    int tasksPerProcessor = atoi(_tasksPerProcessor.c_str());
 
}
#include "CSVFilesDatabase.hpp"
#include <fstream>
#include <ostream>
#include <string>

CSVFilesDatabase::CSVFilesDatabase(std::string dbPath){
    this->loadFromFile(dbPath);
}

bool CSVFilesDatabase::getFileNameFromSHA256FingerPrint(std::string const& footprint, std::string * name){

    auto iterator = this->files.find(footprint);
    if (iterator == this->files.end()){
        return false;
    }
    *name = iterator->second;
    return true;
}

bool CSVFilesDatabase::loadFromFile(std::string const& path){
    std::ifstream file(path, std::ios::in);

    if (!file.good()) {
        return false;
    }

    std::string line;

    while (std::getline(file,line)) {
        std::string footprint = line.substr(0, line.find(" "));
        std::string name = line.erase(0,1+ footprint.length());
        if(footprint.length() == 64 && !name.empty()){
            this->files.insert(std::pair<std::string, std::string>{footprint, name});
        }
    }
    return true;
}
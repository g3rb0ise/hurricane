#include "Radare.hpp"
#include "CSVFilesDatabase.hpp"
#include "ChecksumTools.hpp"
#include <iostream>

Radare::Radare(std::vector<std::string> * files,CSVFilesDatabase * db){
    this->files = files;
    this->db = db;
}

void Radare::runScan(){
    for (auto const& path : *(this->files))
    {
        std::string footprint;
        std::string name;
        CheksumTools::sha256sum(path, &footprint);

        if(this->db->getFileNameFromSHA256FingerPrint(footprint, &name)){
             std::cout << "Found ("<< name << ") " << path << std::endl;
        }
    }
}
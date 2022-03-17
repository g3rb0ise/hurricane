#include "Radare.hpp"
#include "CSVFilesDatabase.hpp"
#include "ChecksumTools.hpp"
#include <iostream>
#include <filesystem>

Radare::Radare(CSVFilesDatabase * db){
    this->db = db;
}

void Radare::runScan(std::vector<std::string>files){
    for (auto const& path : files)
    {
        std::string footprint;
        std::string name;
        CheksumTools::sha256sum(path, &footprint);

        if(this->db->getFileNameFromSHA256FingerPrint(footprint, &name)){
             std::cout << "Found ("<< name << ") " << path << std::endl;
        }
    }
}

void Radare::runScanInDirectory(std::string basedir){
    const std::filesystem::directory_options options = ( std::filesystem::directory_options::skip_permission_denied);
    for (const auto & directory_entry : std::filesystem::recursive_directory_iterator(basedir,options)){
        std::string footprint;
        std::string name;
        CheksumTools::sha256sum(directory_entry.path(), &footprint);

        if(this->db->getFileNameFromSHA256FingerPrint(footprint, &name)){
            std::cout << "Found ("<< name << ") " << directory_entry.path() << std::endl;
        }
    }
}
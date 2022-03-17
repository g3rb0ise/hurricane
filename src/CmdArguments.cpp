#include "CmdArguments.hpp"
#include <ostream>
#include <string>
#include <iostream>

bool CmdArguments::getCmdArguments(int argc, char ** argv){
    if(argc < 2){
        return RETURN_ERROR;
    }

    std::string command{argv[1]};

    if(command == "checksum"){

        return this->parseChecksum(argc,argv);
    }else if (command == "radare") {
        return this->parseRadare(argc, argv);
    }
    return RETURN_ERROR;
}

bool CmdArguments::parseChecksum(int argc, char ** argv){
    if(argc < 3 ){
        return RETURN_ERROR;
    }
    this->requestChecksum = true;

    for(int i = 2 ; i < argc ; i++){
        this->filesTargeted.push_back(argv[i]);
    }

    return RETURN_OK;
}

bool CmdArguments::parseRadare(int argc, char ** argv){
    if(argc < 4){
        return RETURN_ERROR;
    }
    this->requestRadare = true;

    this->dbPath = std::string{argv[2]};

    for(int i = 3 ; i < argc ; i++){
        this->filesTargeted.push_back(argv[i]);
    }

    return RETURN_OK;
}

std::vector<std::string> CmdArguments::getFilesTargeted(){
    return this->filesTargeted;
}

std::string CmdArguments::getDatabasePath(){
    return this->dbPath ;
}
bool CmdArguments::getChecksumCmdFlag(){
    return this->requestChecksum;
}

bool CmdArguments::getRadareCmdFlag(){
    return this->requestRadare;
}
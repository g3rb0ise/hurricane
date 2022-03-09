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
    }

    return RETURN_ERROR;
}

std::vector<std::string> CmdArguments::getFilesTargeted(){
    return this->filesTargeted;
}

bool CmdArguments::parseChecksum(int argc, char ** argv){
    if(argc < 3 ){
        return RETURN_ERROR;
    }

    for(int i = 2 ; i < argc ; i++){
        this->filesTargeted.push_back(argv[i]);
    }

    return RETURN_OK;
}
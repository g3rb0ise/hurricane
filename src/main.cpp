#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include "CSVFilesDatabase.hpp"
#include "CmdArguments.hpp"
#include "ChecksumTools.hpp"
#include "Radare.hpp"

void usage(char ** argv){

    std::cout << "Usage: " << "hurricane <cmd> [arguments]" << std::endl;
    std::cout << "Commands : " << std::endl;
    std::cout << "\tchecksum <file1> [ <file2> [...]]" << std::endl;
    std::cout << "\tradare <database> <file1> [ <file2> [...]]" << std::endl;
}

int main(int argc, char ** argv){
    CmdArguments arguments;
    
    if(!arguments.getCmdArguments(argc, argv)){
        usage(argv);
        return EXIT_FAILURE;
    }
    
    if(arguments.getChecksumCmdFlag()){
        std::string footprint;
        for(auto const& path : arguments.getFilesTargeted()){
            if(!CheksumTools::sha256sum(path, &footprint)){
                std::cerr << "Cannot open file " << "\"" << path << "\"" << std::endl; 
            }else{
                std::cerr << footprint << "\t" << path <<   std::endl;
            }
        }
        return EXIT_SUCCESS;
    }else if(arguments.getRadareCmdFlag()){
        std::vector<std::string> files = arguments.getFilesTargeted();
        CSVFilesDatabase db(arguments.getDatabasePath());
        Radare radare(&files,&db);
        radare.runScan();
        return EXIT_SUCCESS;
    }
    
    return EXIT_FAILURE;
}
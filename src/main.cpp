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
    std::cout << "\tchecksum <file1> [ <file2> [...]]\t\tdisplay files checksum" << std::endl;
    std::cout << "\tradare <database> <file1> [ <file2> [...]] \tChecks if files have a footprint in the database" << std::endl;
    std::cout << "\tradare <database> -r <basedir>\t\t\tChecks if files in a directory (recursively) have a footprint in the database" << std::endl;
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
        CSVFilesDatabase db(arguments.getDatabasePath());
        Radare radare(&db);
        if(arguments.getRecursiveFlag()){
            radare.runScanInDirectory(arguments.getRecursiveBaseDir());
        }else{
            std::vector<std::string> files = arguments.getFilesTargeted();
            radare.runScan(files);
        }
        return EXIT_SUCCESS;
    }
    
    return EXIT_FAILURE;
}
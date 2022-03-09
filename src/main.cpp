#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include "CmdArguments.hpp"
#include "ChecksumTools.hpp"

void usage(char ** argv){

    std::cout << "Usage: " << "hurricane <cmd> [arguments]" << std::endl;
    std::cout << "Commands : " << std::endl;
    std::cout << "\tchecksum <file1> [ <file2> [...]]" << std::endl;
}

int main(int argc, char ** argv){
    CmdArguments arguments;
    
    if(!arguments.getCmdArguments(argc, argv)){
        usage(argv);
        return EXIT_FAILURE;
    }
        
    std::string footprint;
    for(auto const& file : arguments.getFilesTargeted()){
        if(!CheksumTools::sha256sum(file, &footprint)){
            std::cerr << "Cannot open file " << "\"" << file << "\"" << std::endl; 
        }else{
            std::cout << footprint << "\t" << file << std::endl; 
        }
    }
    
    return EXIT_SUCCESS;
}
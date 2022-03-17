#ifndef _RADARE_
#define _RADARE_

    #include "CSVFilesDatabase.hpp"
    #include <string>
    #include <vector>
    /***************************************************
    * Scan to detect files with sepecifics fingerprint 
    ****************************************************/
    class Radare{
        public:
            /**
            * @param[in] files : set of files to check
            */
            explicit Radare(std::vector<std::string> * files,CSVFilesDatabase * db);

            /**
            * Scan all files in database
            */
            void runScan();
            
        protected:
            std::vector<std::string> * files;
            CSVFilesDatabase * db;
    };

#endif 
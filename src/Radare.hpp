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
            * @param[in] db : footprint datase
            */
            explicit Radare(CSVFilesDatabase * db);

            /**
            * Scan all files in parameters and check if file footprint is on datavase
            *
            * @param[in] files to scan
            */
            void runScan(std::vector<std::string> files);
            
            /**
            * Scan all files in a directory (recursively) and check if file footprint is on datavase
            *
            * @param[in] basedir : directory path 
            */
            void runScanInDirectory(std::string basedir);

        protected:
            std::vector<std::string> * files;
            CSVFilesDatabase * db;
    };

#endif 
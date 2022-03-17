#ifndef _CSV_FILES_DATABASE_
#define _CSV_FILES_DATABASE_

    #include <string>
    #include <vector>
    #include <unordered_map>

    class CSVFilesDatabase{
        public:
            /**
            * Return file name with their fingerprint
            *
            * @param[in] fingerprint file fingerprint 
            * @param[out] name file name
            */
            explicit CSVFilesDatabase(std::string dbPath);

            /**
            * Return file name with their fingerprint
            *
            * @param[in] fingerprint file fingerprint 
            * @param[out] name file name
            */
            
            bool getFileNameFromSHA256FingerPrint(std::string const& footprint, std::string * name);

        protected:
            /**
            * Fill database with a file
            *
            * @param[in] path database file path 
            * @returns returns if the loading went well
            */
            bool loadFromFile(std::string const& path);

            std::unordered_map<std::string, std::string> files;
    };

#endif
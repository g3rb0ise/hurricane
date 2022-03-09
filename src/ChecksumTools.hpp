#ifndef _CHECKSUM_TOOLS_
#define _CHECKSUM_TOOLS_

    #include <string>

    /*********************************************************
    * Tools to handle checksum
    **********************************************************/
    class CheksumTools{
        public:
            /**
            * Gives SHA256 checksum of a file
            *
            * @param[in] path the file path
            * @param[out] checksum the resulting checksum
            * @returns validate the correct execution 
            */
            static bool sha256sum(std::string const& path, std::string * checksum);
        
        protected:
            /**
            * Format a hash in hexadecimal string format
            *
            * @param[in] hash the hash to format
            * @returns hash formated in a hexadecimal string format
            */
            static std::string hexaFormat(const unsigned char hash[]);
    };

#endif
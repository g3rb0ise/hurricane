#ifndef _CMD_ARGUMENTS_
#define _CMD_ARGUMENTS_
    #include <vector>
    #include <string>

    #define RETURN_ERROR false
    #define RETURN_OK true

    /*********************************************************
    * Parse & manage program arguments
    **********************************************************/
    class CmdArguments{
        public:
            /**
            * Parse cmd arguments
            *
            * @param[in] argc number of arguments
            * @param[in] argv cmd arguments 
            * @returns validate the correct execution
            */
            bool getCmdArguments(int argc, char ** argv);

            /**
            * Return files in argument 
            * 
            * @returns file list 
            */
            std::vector<std::string> getFilesTargeted();

            /**
            * Get database path in arguments for radare command
            */
            std::string getDatabasePath();

            /**
            * Get information if user use command "radare"
            *
            * @returns flag status
            **/
            bool getRadareCmdFlag();

            /**
            * Get information if user use command "checksum"
            *
            * @returns flag status
            **/
            bool getChecksumCmdFlag();
        protected:
            /**
            * Parse arguments for checksum command
            *
            * @param[in] argc number of arguments
            * @param[in] argv cmd arguments 
            * @returns validate the correct execution
            */
            bool parseChecksum(int argc, char ** argv);

            /**
            * Parse arguments for radare command
            *
            * @param[in] argc number of arguments
            * @param[in] argv cmd arguments 
            * @returns validate the correct execution
            */
            bool parseRadare(int argc, char ** argv);
            
            // all files in input
            std::vector<std::string> filesTargeted;
            
            // database path
            std::string dbPath;
            
            // flag to signal if user use checksum command 
            bool requestChecksum = false;
            
            // flag to signal if user use radare command 
            bool requestRadare = false;
    };

#endif
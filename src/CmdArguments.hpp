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

        protected:
            /**
            * Parse arguments for checksum command
            *
            * @param[in] argc number of arguments
            * @param[in] argv cmd arguments 
            * @returns validate the correct execution
            */
            bool parseChecksum(int argc, char ** argv);

            // field with all files
            std::vector<std::string> filesTargeted;
    };

#endif
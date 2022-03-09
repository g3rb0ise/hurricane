#include "ChecksumTools.hpp"
#include <openssl/sha.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iomanip>

bool CheksumTools::sha256sum(std::string const& path, std::string * checksum){
    std::ifstream file(path, std::ios::in | std::ios::binary);

    if (not file.good()) {
        return false;
    }

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    constexpr const std::size_t bufferSize { 1 << 8 };
    char buffer[bufferSize];

    while (file.good()) {
        file.read(buffer, bufferSize);
        SHA256_Update(&ctx, buffer, file.gcount());
    }
    
    unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };
    SHA256_Final(hash, &ctx);
    file.close();

    *checksum =  CheksumTools::hexaFormat(hash);

    return true;
}

std::string CheksumTools::hexaFormat(const unsigned char hash[]){
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::setw(2) << static_cast<unsigned int>(hash[i]);
    }
    return ss.str();
}

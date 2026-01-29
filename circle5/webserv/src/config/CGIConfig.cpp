#include "CGIConfig.hpp"

CGIConfig::CGIConfig() : extension(""), executable("") {}

CGIConfig::CGIConfig(const std::string &ext, const std::string &exec) 
    : extension(ext), executable(exec) {}

CGIConfig::~CGIConfig() {}

CGIConfig::CGIConfig(const CGIConfig& other) 
    : extension(other.extension), executable(other.executable) {}

CGIConfig& CGIConfig::operator=(const CGIConfig& other) 
{
    if (this != &other) 
    {
        extension = other.extension;
        executable = other.executable;
    }
    return *this;
}

const std::string& CGIConfig::getExtension() const 
{
    return extension;
}

const std::string& CGIConfig::getExecutable() const 
{
    return executable;
}

void CGIConfig::setExtension(const std::string &ext) 
{
    extension = ext;
}

void CGIConfig::setExecutable(const std::string &exec) 
{
    executable = exec;
}

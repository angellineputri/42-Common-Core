#ifndef CGICONFIG_HPP
#define CGICONFIG_HPP

#include <string>

class CGIConfig {
private:
    std::string extension;
    std::string executable;

public:
    CGIConfig();
    CGIConfig(const std::string &ext, const std::string &exec);
    ~CGIConfig();
    CGIConfig(const CGIConfig &other);
    CGIConfig &operator=(const CGIConfig &other);

    const std::string &getExtension() const;
    const std::string &getExecutable() const;

    void setExtension(const std::string &ext);
    void setExecutable(const std::string &exec);
};

#endif

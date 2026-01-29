#include "../../inc/config/mainConfig.hpp"

void executeCGI(const std::string &script_path, const RouteConfig &route)
{
    std::string ext = script_path.substr(script_path.find_last_of('.'));
    const CGIConfig *cgi_config = 0;

    const std::vector<CGIConfig> &cgis = route.getCGIs();
    for (size_t i = 0; i < cgis.size(); ++i) {
        if (cgis[i].getExtension() == ext) {
            cgi_config = &cgis[i];
            break;
        }
    }

    if (!cgi_config) {
        std::cerr << "No CGI config found for " << ext << "\n";
        return;
    }

    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        close(pipefd[0]);
        close(pipefd[1]);
        perror("fork");
        return;
    }

    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[1]);

        char *argv[3];
        argv[0] = const_cast<char*>(cgi_config->getExecutable().c_str());
        argv[1] = const_cast<char*>(script_path.c_str());
        argv[2] = 0;

        execv(argv[0], argv);
        _exit(1);
    }

    close(pipefd[1]);
    char buffer[1024];
    int n;
    while ((n = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
        std::cout.write(buffer, n);
    }
    close(pipefd[0]);

    int status;
    waitpid(pid, &status, 0);
}

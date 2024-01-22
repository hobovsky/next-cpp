#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using std::filesystem::exists;
using std::filesystem::path;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage:\n\tcwpp [PRELOADED|SOLUTION] [path to cw snippet]";
        return 1;
    }

    std::string snippetTag = argv[1];
    if(snippetTag != "PRELOADED" && snippetTag != "SOLUTION") {
        std::cerr << "Usage:\n\tcwpp [PRELOADED|SOLUTION] [path to cw snippet]";
        return 1;
    }

    auto snippetFile = path(argv[2]);
    if (!exists(snippetFile)) {
        std::cerr << "Snippet file [" << snippetFile << "] does not exist.";
        return 1;
    }
    std::ifstream inputStream(snippetFile);
    std::ofstream headerStream(".tmp_header"), implStream(".tmp_cpp");

    enum LastTag { NONE, HEADER, CPP };

    bool hasHeaderTag = false;
    bool hasImplTag = false;
    LastTag lastTag = NONE;

    std::string headerTag = snippetTag == "SOLUTION" ? "//! CW_SOLUTION_H"   : "//! CW_PRELOADED_H";
    std::string implTag   = snippetTag == "SOLUTION" ? "//! CW_SOLUTION_CPP" : "//! CW_PRELOADED_CPP";

    std::string line;
    while (std::getline(inputStream, line)) {
        if (line == headerTag) {
            hasHeaderTag = true;
            lastTag = HEADER;
        } else if (line == implTag) {
            hasImplTag = true;
            lastTag = CPP;
        } else if (lastTag == HEADER) {
            headerStream << line << std::endl;
        } else if (lastTag == CPP) {
            implStream << line << std::endl;
        }
    }
    inputStream.close();
    headerStream.close();
    implStream.close();

    std::string targetHeader, targetImpl;
    if (snippetTag == "SOLUTION") {
        targetHeader = "include/solution.h";
        targetImpl = "src/solution.cpp";
    }
    else {
        targetHeader = "include/preloaded.h";
        targetImpl = "src/preloaded.cpp";
    }

    if (hasHeaderTag && hasImplTag) {
        std::filesystem::copy_file(path(".tmp_header"), path(targetHeader));
        std::filesystem::copy_file(path(".tmp_cpp"), path(targetImpl));
    } else if (!hasHeaderTag && !hasImplTag) {
        std::filesystem::copy_file(path(snippetFile), path(targetHeader));
        std::filesystem::copy_file(path(snippetFile), path(targetImpl));
    } else if (hasHeaderTag && !hasImplTag) {
        std::filesystem::copy_file(path(".tmp_header"), path(targetHeader));
        std::ofstream(targetImpl).close();
    } else if (!hasHeaderTag && hasImplTag) {
        std::ofstream(targetHeader).close();
        std::filesystem::copy_file(path(".tmp_cpp"), path(targetImpl));
    }
}

#ifndef SEARCH_LIBRARY_H
#define SEARCH_LIBRARY_H

#include <string>

class SearchLibrary {
public:
    static bool searchFile(const std::string& current_path, const std::string& targetFile, bool& found);
    static void startSearchingFile(const std::string& current_path,const std::string& targetFile);
};
#endif // SEARCH_LIBRARY_H
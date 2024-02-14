#include "search_library.h"

int main() {
    std::string targetFileName = "bscamp.txt";
    std::string PathToBegin = "C:\\";
    SearchLibrary::startSearchingFile(PathToBegin, targetFileName);
    return 0;
}
#include "search_library.h"
#include <iostream>
#include <filesystem> 
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>


namespace fs = std::filesystem;
std::atomic<bool> stopSearch(false);


void SearchLibrary::startSearchingFile(const std::string& current_path,const std::string& targetFile)
{
    bool found = false;
    std::vector<std::thread> threads;
    std::mutex mutex;

    auto searchFunction = [&](const std::string& path) {
        bool localFound = false;
         try {
            searchFile(path, targetFile, localFound);
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        if (localFound) {
            std::lock_guard<std::mutex> lock(mutex);
            found = true;
        }
    };

    for (const auto& entry : fs::directory_iterator(current_path, fs::directory_options::skip_permission_denied)) {
        if (fs::is_directory(entry)) {
            try {
                threads.emplace_back(searchFunction, entry.path().string());
            } catch (const std::filesystem::filesystem_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    if(SearchLibrary::searchFile(current_path, targetFile, found) == false)
    {
        std::cout << "Can't find file with this name";
    }
}

bool SearchLibrary::searchFile(const std::string& current_path, const std::string& targetFile, bool& found) {
    for(const auto& file : fs::directory_iterator(current_path, fs::directory_options::skip_permission_denied))
    {
        try
        {
            if(found || stopSearch.load())
                return true;
            if(fs::is_directory(file))
            {
                searchFile(file.path().string(), targetFile, found);
            }
            else if(file.is_regular_file())
            {
                if(file.path().filename().string() == targetFile)
                {
                    std::cout << file.path().string();
                    found = true;
                    stopSearch.store(true);
                    return true;
                }
            }
        }
        catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Permission denied: " << e.what() << std::endl;
        }
    }
    return false;
}

#include <fileManipulation.h>
#ifdef LLGE_WINDOWS

#include <logger.h>
#include <windows.h>

namespace LLGE
{
	namespace fileManipulation
	{
        std::string get_game_path()
        {
            char buffer[MAX_PATH];
            GetModuleFileName(NULL, buffer, MAX_PATH);

            // remove the file name
            std::string::size_type pos = std::string(buffer).find_last_of("\\/");
            std::string path = std::string(buffer).substr(0, pos);

            // Return the path as string_view
            return path;
        }

        bool createFile(std::string path)
        {
            std::ofstream create = std::ofstream(path, std::ios::binary);
            return create.good();
        }

        bool writeEntireFileBinary(std::string name, void *buffer, size_t s)
        {
            std::ofstream file(name, std::ios::binary | std::ios::app);
            file.write((char*)buffer, s);
            return file.good();
        }

        bool appendToFileBinary(std::string name, void *buffer, size_t s)
        {
            std::ofstream file(name, std::ios::binary | std::ios::app);
            file.write((char*)buffer, s);
            return file.good();
        }

        bool appendToFileBinary(std::string name, std::string append)
        {
            std::ofstream file(name, std::ios::binary | std::ios::app);
            file.write(append.c_str(), append.size());
            return file.good();
        }

        size_t readEntireFileBinary(std::string name, void *buffer, size_t s, size_t from)
        {
            std::ifstream file(name, std::ios::binary | std::ios::ate);
            if (!file.is_open()) {
                log(LLGE::Logger::LogLevel::ERR, "Failed to open file %s", name.c_str());
            }
            std::streampos fileSize = file.tellg();
            if (fileSize <= 0) {
                log(LLGE::Logger::LogLevel::ERR, "Failed to read file %s", name.c_str());
                return -1;
            }
            if (from > fileSize) {
                log(LLGE::Logger::LogLevel::ERR, "Failed to read file %s", name.c_str());
                return -1;
            }
            if (s < (fileSize - from)) {
                log(LLGE::Logger::LogLevel::ERR, "Failed to read file %s", name.c_str());
                return 0;
            }

            file.seekg(from, std::ios::beg);
            file.read(static_cast<char*>(buffer), s);
            if (!file) {
                std::cerr << "Error: Failed to read file " << name << std::endl;
                return 0;
            }
            file.close();
            return s;
        }
    };
};

#endif
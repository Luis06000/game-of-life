#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <vector>

class FileParser {
private:
    int length;
    int width;
    std::vector<std::vector<int>> data;

public:
    FileParser(const std::string& filePath);
    int GetLength() const;
    int GetWidth() const;
    const std::vector<std::vector<int>>& GetData() const;
};

#endif // FILEPARSER_H

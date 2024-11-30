#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>

class FileParser {
private:
    int length;
    int width;

public:
    void GetFile(const std::string& filename);
    int GetLength() const { return length; }
    int GetWidth() const { return width; }
};

#endif // FILEPARSER_H

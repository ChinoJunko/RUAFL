#ifndef BUGLOCATION_H_
#define BUGLOCATION_H_

#include "SVFIR/SVFType.h"
// AFL_CHECK_REZZAN=1 ./AFL/afl-clang-fast example/uaf.c -o example/uaf
//
namespace SVF
{

class BugLocation
{
private:
    u32_t line;
    u32_t column;
    std::string file;
    u32_t distance;
public:
    BugLocation(u32_t ln, u32_t cl, std::string name, u32_t dist)
        : line(ln), column(cl), file(name), distance(dist)
    {
    }

    BugLocation(const std::string& srcLoc, u32_t dist)
    {
        char filename[256];
        sscanf(srcLoc.c_str(), "%*[^0-9]%u  cl: %u  fl: %255s } }", &line,
               &column, filename);
        file.append(filename);
        distance = dist;
    }

    BugLocation(const char* s, u32_t dist)
    {
        char filename[256];
        sscanf(s, "%*[^0-9]%u  cl: %u  fl: %255s } }", &line,
               &column, filename);
        file.append(filename);
        distance = dist;
    }

    inline u32_t getLine() const
    {
        return line;
    }

    inline u32_t getColumn() const
    {
        return column;
    }

    inline std::string getFile() const
    {
        return file;
    }

    inline u32_t getDistance() const
    {
        return distance;
    }

    bool operator==(const BugLocation& bl)
    {
        return line == bl.line && column == bl.column && file == bl.file;
    }

    friend bool operator==(const BugLocation& bl1, const BugLocation& bl2)
    {
        return bl1.line == bl2.line && bl1.column == bl2.column &&
               bl1.file == bl2.file;
    }

    bool operator<(const BugLocation& bl)
    {
        return line < bl.line || (line == bl.line && column < bl.column);
    }

    friend bool operator<(const BugLocation& bl1, const BugLocation& bl2)
    {
        return bl1.line < bl2.line ||
               (bl1.line == bl2.line && bl1.column < bl2.column);
    }

    bool operator>(const BugLocation& bl)
    {
        return line > bl.line || (line == bl.line && column > bl.column);
    }

    friend bool operator>(const BugLocation& bl1, const BugLocation& bl2)
    {
        return bl1.line > bl2.line ||
               (bl1.line == bl2.line && bl1.column > bl2.column);
    }
};

} // End namespace SVF

#endif /* BUGLOCATION_H_ */
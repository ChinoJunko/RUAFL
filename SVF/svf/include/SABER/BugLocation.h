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

public:
    BugLocation(u32_t ln, u32_t cl, std::string name)
        : line(ln), column(cl), file(name)
    {
    }

    BugLocation(const std::string& srcLoc)
    {
        char filename[256];
        sscanf(srcLoc.c_str(), "%*[^0-9]%u  cl: %u  fl: %255s } }", &line,
               &column, filename);
        file.append(filename);
    }

    BugLocation(const char* s)
    {
        char filename[256];
        sscanf(s, "%*[^0-9]%u  cl: %u  fl: %255s } }", &line,
               &column, filename);
        file.append(filename);
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
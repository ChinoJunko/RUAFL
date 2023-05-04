#ifndef BLSETMAP_H_
#define BLSETMAP_H_

#include "BugLocation.h"
#include "map"
#include "set"
// AFL_CHECK_REZZAN=1 ./AFL/afl-clang-fast example/uaf.c -o example/uaf
//
namespace SVF
{

class BLSetMap
{
private:
    std::map<std::string,std::set<BugLocation>*> map;
public:
    BLSetMap(){}

    bool insert(BugLocation bl){
        std::string filename = bl.getFile();
        if(map.find(filename)==map.end()){
            map[filename] = new std::set<BugLocation>();
        }
        return map[filename]->insert(bl).second; 
    }

    std::set<BugLocation>* getFileBugLocSet(std::string& filename){
        if(map.find(filename)==map.end()){
            return nullptr;
        }
        return map[filename];
    }

    std::map<std::string,std::set<BugLocation>*> getMap() const{
        return map;
    }

    ~BLSetMap(){
        for(auto &i: map){
            delete i.second;
        }
    }
};

} // End namespace SVF

#endif /* BLSETMAP_H_ */
#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <set>
#include <string>
#include <cstdlib>

class Database {
    public:
             Database   ( const std::string & filename );
        void Set_Source ( const std::string & filename );
        void Load       ( void );
    private:
        std::string                             m_Source;
        std::map<std::string, size_t>           m_Players;
        std::map<std::set<std::string>, size_t> m_Teams;
};

#endif
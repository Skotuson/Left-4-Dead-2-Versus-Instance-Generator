#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <set>
#include <string>
#include <fstream>
#include <cstdlib>

class Database {
    public:
               Database   ( const std::string & filename );
        void   SetSource  ( const std::string & filename );
        void   Load       ( void );
        size_t GetGames   ( void );
    private:
        bool   ParseEntry ( std::ifstream     & ifs );

        std::string                             m_Source;
        std::map<std::string, size_t>           m_Players;
        std::map<std::set<std::string>, size_t> m_Teams;
        size_t                                  m_Games    = 0;
};

#endif
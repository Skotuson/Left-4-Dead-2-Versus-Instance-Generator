#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

#include "Database.h"

using Player = std::string;

class Generator {
    public:
        void                Load           ( const std::string & filename );
        void                GenerateRandom ( Database & db );
        void                GenerateFair   ( Database & db );
        std::vector<Player> GetPlayers     ( void );
    private:
        std::vector<Player> m_Players;
        size_t              m_TeamOne  = 0,
                            m_TeamTwo  = 0;
};

#endif
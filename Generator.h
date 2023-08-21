#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

#include "Database.h"

using Player = std::string;

const std::vector <std::string> MAPS = {
    "No Mercy", "Crash Course", "Death Toll", "Dead Air", "Blood Harvest", "The Sacrifice", "The Last Stand",
    "Dead Center", "The Passing", "Dark Carnival", "Swamp Fever", "Hard Rain", "The Parish", "Cold Stream"
};

const std::set <std::string> REROLL = {
    "Crash Course", "The Sacrifice", "The Last Stand", "The Passing"
};

/**
 * @brief Class which encapsulates team composition and map generation
 */
class Generator {
    public:
        void                Load           ( const std::string         & filename );
        void                GenerateRandom ( Database                  & db );
        void                GenerateFair   ( Database                  & db );
        std::vector<Player> GetPlayers     ( void );

        void                GenerateMap    ( void );
    private:
        void                PrintShuffled  ( Database                  & db,
                                             const std::vector<Player> & shuffled );

        std::vector<Player> m_Players;
        size_t              m_TeamOne  = 0,
                            m_TeamTwo  = 0;
};

#endif
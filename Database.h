#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <set>
#include <string>
#include <fstream>
#include <cstdlib>

using Team  = std::set<std::string>;
using Score = std::pair<size_t, size_t>;

class Database {
    public:
               Database            ( const std::string           & filename );
        void   SetSource           ( const std::string           & filename );
        //Load the data from file
        void   Load                ( void );
        void   Add                 ( std::istream                & is );
        void   Save                ( void );
        size_t GetGames            ( void );
        size_t GetPlayerGames      ( const std::string           & player );
        double GetPlayerPercentage ( const std::string           & player );
        void   PrintPlayerStats    ( void );
        void   PrintTeamStats      ( void );
        void   PrintMatches        ( std::ostream                & os = std::cout );

    private:
        bool   ParseEntry          ( std::istream                & is );
        void   UpdateTeam          ( const std::set<std::string> & team,
                                     size_t                        val );
        void   UpdatePlayer        ( const std::set<std::string> & team,
                                     size_t                        val );

        std::string                           m_Source;
        std::map<std::string, size_t>         m_Players;
        std::map<Team, size_t>                m_Teams;
        std::multimap<std::set<Team>, Score>  m_Matches;
        size_t                                m_Games    = 0;
};

#endif
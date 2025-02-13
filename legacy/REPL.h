#ifndef REPL_H
#define REPL_H

#include <queue>
#include <string>

#include "Database.h"

using Command = std::string;

class REPL {
    public:
             REPL      ( Database * db );
        void Run       ( void );
        bool Read      ( void );
        void Eval      ( void );
    private:
        void PrintHelp ( void );
        Database            * m_Database;
        std::queue<Command>   m_Commands;
};

#endif
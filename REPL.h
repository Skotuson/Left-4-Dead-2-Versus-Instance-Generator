#ifndef REPL_H
#define REPL_H

#include <queue>
#include <string>

using Command = std::string;

class REPL {
    public:
        void Run       ( void );
        bool Read      ( void );
        void Eval      ( void );
    private:
        void PrintHelp ( void );
        std::queue<Command> m_Commands;
};

#endif
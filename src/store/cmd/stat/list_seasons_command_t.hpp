#pragma once

#include "../command_t.h"

struct list_seasons_command_t : command_t {
    
    list_seasons_command_t(void);
    void execute(database_t &db) const;
};
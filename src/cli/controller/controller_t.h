#pragma once

#pragma once

#include <string>
#include <memory>

#include "../../io/loader/database/database_loader_t.h"

struct controller_t
{

private:
    std::shared_ptr<database_loader_t> db_loader_;
};

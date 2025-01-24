#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>
#include <string>
#include <list>

#include "store/database_t.h"
#include "cli/arg_parser_t.h"

#include "io/deserializer/database/stream/old_format_stream_database_deserializer_t.h"

#include "io/serializer/database/string/old_format_string_database_serializer_t.h"

int main(int argc, char *argv[])
{
    std::list<std::string> params(argv, argv + argc);
    controller_t controller;
    arg_parser_t(controller).parse(params);

    database_t db;
    std::ifstream ifs("persistence/save.txt");
    std::shared_ptr<stream_database_deserializer_t> deserializer(new old_format_stream_database_deserializer_t());
    std::shared_ptr<string_database_serializer_t> serializer(new old_format_string_database_serializer_t());

    db = deserializer->deserialize(ifs);
    ifs.close();

    std::ofstream ofs("persistence/matches_old_format.txt");
    ofs << serializer->serialize(db);
    ofs.close();
    return 0;
}
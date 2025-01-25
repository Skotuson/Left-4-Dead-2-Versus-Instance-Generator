#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>
#include <string>
#include <list>

#include "store/database_t.h"
#include "cli/arg_parser_t.h"

#include "io/deserializer/database/stream/old_format_stream_database_deserializer_t.h"
#include "io/deserializer/database/stream/new_format_stream_database_deserializer_t.h"

#include "io/serializer/database/string/old_format_string_database_serializer_t.h"
#include "io/serializer/database/string/new_format_string_database_serializer_t.h"

#include "io/saver/text/file_stream_text_saver_t.h"

int main(int argc, char *argv[])
{
    std::list<std::string> params(argv, argv + argc);
    controller_t controller;
    arg_parser_t(controller).parse(params);

    std::shared_ptr<stream_database_deserializer_t> deserializer_old(new old_format_stream_database_deserializer_t());
    std::shared_ptr<stream_database_deserializer_t> deserializer_new(new new_format_stream_database_deserializer_t());
    std::shared_ptr<string_database_serializer_t> serializer_old(new old_format_string_database_serializer_t());
    std::shared_ptr<string_database_serializer_t> serializer_new(new new_format_string_database_serializer_t());

    database_t db_old;
    std::ifstream ifs_old("persistence/save.txt");
    db_old = deserializer_old->deserialize(ifs_old);
    ifs_old.close();

    database_t db_new;
    std::ifstream ifs_new("persistence/save_new.txt");
    db_new = deserializer_new->deserialize(ifs_new);
    ifs_new.close();

    auto saver_old = std::make_shared<file_stream_text_saver_t>("persistence/matches_old_format.txt");
    saver_old->save(serializer_old->serialize(db_old));

    auto saver_new = std::make_shared<file_stream_text_saver_t>("persistence/matches_new_format.txt");
    saver_new->save(serializer_new->serialize(db_new));
    return 0;
}
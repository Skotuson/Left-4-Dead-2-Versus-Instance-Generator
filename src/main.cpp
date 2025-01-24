#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>

#include "store/database_t.h"

#include "io/deserializer/database/stream/stream_database_deserializer_t.h"
#include "io/deserializer/database/stream/old_format_stream_database_deserializer_t.h"

#include "io/saver/database/database_saver_t.h"
#include "io/saver/database/stream/text_stream_old_format_database_saver_t.h"

int main(int argc, char *argv[])
{
    database_t db;
    std::ifstream ifs("persistence/save.txt");
    std::shared_ptr<stream_database_deserializer_t> deserializer(new old_format_stream_database_deserializer_t());
    std::shared_ptr<database_saver_t> saver(new text_stream_old_format_database_saver_t("persistence/matches_old_format.txt"));

    db = deserializer->deserialize(ifs);
    ifs.close();
    saver->save(db);
    return 0;
}
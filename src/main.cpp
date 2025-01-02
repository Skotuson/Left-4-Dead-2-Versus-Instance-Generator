#include <iostream>
#include <cstring>
#include <memory>

#include "store/database_t.h"
#include "io/loader/database/database_loader_t.h"
#include "io/saver/database/database_saver_t.h"
#include "io/loader/database/stream/text_stream_old_format_database_loader_t.h"
#include "io/saver/database/stream/text_stream_old_format_database_saver_t.h"

int main(int argc, char *argv[])
{
    database_t db;
    std::shared_ptr<database_loader_t> loader(new text_stream_old_format_database_loader_t("save.txt"));
    std::shared_ptr<database_saver_t> saver(new text_stream_old_format_database_saver_t("matches.txt"));

    db = loader->load();
    saver->save(db);
    return 0;
}
#include "ASM.h"

int main(int argc, char* argv[])
{
    files_struct files = {};
    int err = open_logfile(&files);
    if (err) return err;

    ASSERT(argc == 2, Incorrect_Number_Of_CMD_Arguments);

    err = open_files(&files, argv);
    VERIFY_err;

    commands_struct commands = {};
    err = record_commands_to_buffer(&files, &commands);
    VERIFY_err;

    code_struct code = {};
    err = create_code_array(&code, &commands);
    VERIFY_err;

    err = write_code_to_file(&code, &files);
    VERIFY_err;

    close_files(&files);
    
    return 0;
}

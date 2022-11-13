#ifndef _ASM_H_
#define _ASM_H_

#include "Logger.h"

#define ASSERT(condition, err, code) {  if (!(condition))           \
                                        {                           \
                                            code;                   \
                                            dump(logfile, err);     \
                                            fclose(logfile);        \
                                            return err;             \
                                        }                           }

#define VERIFY(err) {  if (err)                    \
                       {                           \
                           dump(logfile, err);     \
                           fclose(ASM_in);         \
                           fclose(logfile);        \
                           return err;             \
                       }                           }

struct commands_struct
{
    char** array_of_commands;
    size_t number_of_commands;
};

int record_commands_to_buffer(FILE* ASM_in, commands_struct* commands);

struct code_struct
{
    int* pointer;
    size_t number_of_elements;
};

int create_code_array(commands_struct* commands, code_struct* code);

#endif
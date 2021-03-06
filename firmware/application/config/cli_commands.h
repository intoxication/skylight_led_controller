#ifndef CLI_COMMANDS_H
#define CLI_COMMANDS_H

#include <cli.h>
#include <stdint.h>

// If set to 1, command parsing recognizes multi-word arguments in quotes
#define PARSE_QUOTED_ARGS   0

// If set to 1, performs command lookup using a binary search instead of linear.
#define USE_BINARY_SEARCH   0

// maximum length of a command input line
#define CLI_STRBUF_SIZE    96

// Maximum number of arguments in a command (including command).
#define CLI_MAX_ARGC    16

// Table of commands: {"command_word" , function_name }
// Command words MUST be in alphabetical (ascii) order!! (A-Z then a-z) if using binary search
#define CMDTABLE    {"cfg_erase"        , cmd_cfg_erase       },\
                    {"cfg_read"         , cmd_cfg_read        },\
                    {"cfg_reload"       , cmd_cfg_reload      },\
                    {"cfg_write"        , cmd_cfg_write       },\
                    {"chroma"           , cmd_chroma          },\
                    {"echo"             , cmd_echo            },\
                    {"get_ttl_clk_correct"  , cmd_get_ttl_clk_correct },\
                    {"get_ref_time"     , cmd_get_ref_time    },\
                    {"get_time"         , cmd_get_time        },\
                    {"id"               , cmd_id              },\
                    {"print_cfg"        , cmd_print_cfg       },\
                    {"reset"            , cmd_reset           },\
                    {"rgbw"             , cmd_rgbw            },\
                    {"set_dst"          , cmd_set_dst         },\
                    {"set_time"         , cmd_set_time        }

// Custom command function prototypes:

// echo <0/1>
int cmd_echo(uint8_t argc, char *argv[]);

int cmd_id(uint8_t argc, char *argv[]);

int cmd_reset(uint8_t argc, char *argv[]);

// rgbw <r> <g> <b> <w>
int cmd_rgbw(uint8_t argc, char *argv[]);

// get_time
// <DOW> <year> <month> <day> <hour> <minute> <second>
int cmd_get_time(uint8_t argc, char *argv[]);
int cmd_get_ref_time(uint8_t argc, char *argv[]);

int cmd_get_ttl_clk_correct(uint8_t argc, char *argv[]);

// set_time <year> <month> <day> <hour> <minute> <second>
int cmd_set_time(uint8_t argc, char *argv[]);

// set_dst <observed 0/1> <enabled 0/1>
int cmd_set_dst(uint8_t argc, char *argv[]);

int cmd_cfg_erase(uint8_t argc, char *argv[]);
int cmd_cfg_write(uint8_t argc, char *argv[]);
int cmd_cfg_read(uint8_t argc, char *argv[]);
int cmd_cfg_reload(uint8_t argc, char *argv[]);

int cmd_chroma(uint8_t argc, char *argv[]);

int cmd_print_cfg(uint8_t argc, char *argv[]);
#endif

#include "util.h"

#include <iostream>

static constexpr auto WHITE = "\x1B"
                              "[0;37m";
static constexpr auto BLUE = "\x1B"
                             "[0;34m";
static constexpr auto YELLOW = "\x1B"
                               "[0;33m";
static constexpr auto RED = "\x1B"
                            "[0;31m";

#define PRINT_IMPL(color, prefix, str, out)                                    \
  out << color << prefix << ": " << str << WHITE << "\n";

void print_info(const std::string_view str) {
  PRINT_IMPL(BLUE, "INFO", str, std::cout);
}
void print_warn(const std::string_view str) {
  PRINT_IMPL(YELLOW, "WARN", str, std::cout);
}
void print_err(const std::string_view str) {
  PRINT_IMPL(RED, "ERROR", str, std::cerr);
}
#pragma once

#include <string_view>

#define MOVE_ONLY_TYPE(type)                                                   \
  type(const type &) = delete;                                                 \
  type(type &&o);                                                              \
  type &operator=(const type &) = delete;                                      \
  type &operator=(type &&o);

void print_info(const std::string_view str);
void print_warn(const std::string_view str);
void print_err(const std::string_view str);
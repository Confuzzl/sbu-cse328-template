#include "app.h"

#include "util.h"
#include <stdexcept>

int main() {
  try {
    app().run();
  } catch (const std::runtime_error &e) {
    print_err(e.what());
  }
}

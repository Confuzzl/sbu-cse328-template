#pragma once

struct Key {
  using Callback = void (*)(const double);
  static constexpr Callback NONE = [](const double) {};

  bool on = false;
  bool justUsed = false;

  Callback justOn, holdOn, justOff;

  Key(const Callback justOn, const Callback holdOn, const Callback justOff);
  Key(const Callback holdOn, const Callback holdOff = NONE);

  void react(const int action);

  void operator()(const double dt);
};
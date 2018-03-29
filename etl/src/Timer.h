// -*- C++ -*-

#ifndef _Timer_h_
#define _Timer_h_

#include <chrono>


class Timer
{
private:
  using Resolution = std::chrono::nanoseconds;

public:
  void start()
  {
    _start = std::chrono::high_resolution_clock::now();
  }

  void stop()
  {
    std::chrono::time_point<std::chrono::system_clock> const stop =
      std::chrono::high_resolution_clock::now();
    _duration = std::chrono::duration_cast<Resolution>(stop - _start);
  }

  double duration() const
  {
    return static_cast<double>(_duration.count());
  }

private:
  std::chrono::time_point<std::chrono::system_clock> _start;
  Resolution _duration;
};


#endif // _Timer_h_

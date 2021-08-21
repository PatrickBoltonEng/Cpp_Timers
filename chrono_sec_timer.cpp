// Infinite Chrono seconds timer
#include <chrono>
#include <iostream>

struct timer
{
  typedef std::chrono::steady_clock clock ;
  typedef std::chrono::seconds seconds ;

  void reset() { start = clock::now() ; }

  unsigned long long seconds_elapsed() const
  { return std::chrono::duration_cast<seconds>( clock::now() - start ).count() ; }

  private: clock::time_point start = clock::now() ;
};

// function to be called every second
void foo() {std::cout << "Tick" << std::endl;}

int main()
{
  timer t ;
  foo() ;

  for(;; )
  {
    if( t.seconds_elapsed() > 1 ) {foo(); t.reset();}
  }
}

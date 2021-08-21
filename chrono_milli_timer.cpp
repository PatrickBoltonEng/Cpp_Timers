// Infinite Chrono seconds timer
#include <chrono>
#include <iostream>

struct timer
{
  typedef std::chrono::steady_clock clock ;
  typedef std::chrono::milliseconds milliseconds ;

  void reset() { start = clock::now() ; }

  unsigned long long milliseconds_elapsed() const
  { return std::chrono::duration_cast<milliseconds>( clock::now() - start ).count() ; }

  private: clock::time_point start = clock::now() ;
};

// function to be called every second / 1000 milliseconds
void foo() {std::cout << "Tick" << std::endl;}

int main()
{
  timer t ;
  foo() ;

  for(;; )
  {
    if( t.milliseconds_elapsed() > 1000 ) {foo(); t.reset();}
  }
}

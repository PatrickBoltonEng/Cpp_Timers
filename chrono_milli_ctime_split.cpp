// Infinite Chrono milliseconds timer to retrieve current time and split it into components
//PJB 08/20/21
#include <chrono>
#include <ctime>
#include <iostream>
#include <cstring>

struct timer
{
  typedef std::chrono::steady_clock clock ;
  typedef std::chrono::milliseconds milliseconds ;

  void reset() { start = clock::now() ; }

  unsigned long long milliseconds_elapsed() const
  { return std::chrono::duration_cast<milliseconds>( clock::now() - start ).count() ; }

  private: clock::time_point start = clock::now() ;
};

void get_time()
{
  time_t rawtime;
  std::string time_string, weekday, month, daydate, hour, minute, second, year;
  time(&rawtime);
  time_string = ctime(&rawtime);
  std::cout << "Tick: " + time_string;
  weekday = time_string.substr(0,3);
  std::cout << "weekday= " << weekday << std::endl;
  month = time_string.substr(4,3);
  std::cout << "month = " << month << std::endl;
  daydate = time_string.substr(8,2);
  std::cout << "daydate " << daydate << std::endl;
  hour = time_string.substr(11,2);
  std::cout << "hour= " << hour << std::endl;
  minute = time_string.substr(14,2);
  std::cout << "minute= " << minute << std::endl;
  second = time_string.substr(17,2);
  std::cout << "second= " << second << std::endl;
  year = time_string.substr(20,4);
  std::cout << "year= " << year << std::endl;
}


int main()
{
  timer t;
  get_time();

  for(;; )
  {
    if( t.milliseconds_elapsed() > 1000 )
    {
      get_time();
      t.reset();
    }
  }
}

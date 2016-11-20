#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <exception>

struct socketexception;
struct packetexception;

struct socketexception : public std::exception {
   std::string h;
   unsigned int p;
   socketexception(std::string host, unsigned int port ){
      h=host;
      p=port;
   }
   const char * what () const throw () {
      QString p(p);
      const char * what = ("Exception on connection: Host{"+h+"} Port{"+p.toStdString()+"}").c_str();
      return what;
   }
};

struct packetexception : public std::exception {
   const char * what () const throw () {
      const char * what = (std::string("packet was not formed correctly")).c_str();
      return what;
   }
};

#endif // EXCEPTIONS_H

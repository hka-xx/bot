#ifndef CHATTER_H
#define CHATTER_H

#include <vector>

typedef struct {
  std::string keyword[10];
  std::string respons[10];
} record;


class chatter
{
 public:
  chatter();
  void analyze(std::string input);
  std::string answer();
  void init_th();
  void init_init_know();
  float fuzzymatch(std::string pattern, std::string text); //function doing checking how close two strings are syntactically, perfect match returns 1

 private:
  std::vector<std::string>prev_msg;
  std::vector<std::vector<std::string> >th_sv;
  record *knowledge;

};

#endif

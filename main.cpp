#include <iostream>
#include "chatter.h"
using namespace std;

string find_match(string input);

record KnowledgeBase[] = {

  {{"Hej", "Hej!","Hej."},
   {"Hallå!", 
    "Tjena."}
  },

  {"Vad heter du",
"Mitt namn är wkuwus."
  }
};

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]); 

int main()
{
  string input;
  string sResp;

  while(1)
    {
      cout<<">";
      getline(cin,input);
      sResp=find_match(input);

      if(!input.compare("Hejdå."))
	{
	  cout<<"Hejdå.\n";
	  break;
	}
      else if(!input.compare(""))
	cout<<"Du är väldigt tyst.\n";
      else
      cout<<sResp<<endl;
    }
	
  return 0;
}

string find_match(string input)
{
  string result;
  for(int i=0;i<nKnowledgeBaseSize;++i)
    {
      string tmp=KnowledgeBase[i].keyword[0];
      if(!tmp.compare(input))
	{
	  result=KnowledgeBase[i].respons[0];
	  break;
	}
    }
  return result;
}

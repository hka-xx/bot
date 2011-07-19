#include <sstream>
#include <iterator>
#include <vector>
#include <boost/regex.hpp>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

#include "chatter.h"

using namespace std;

chatter::chatter()
{
  init_th();
}

void chatter::analyze(string input)
{
  prev_msg.push_back(input);

  //seperate input at each whitespace
  istringstream iss;
  vector<string>parts;
  copy(istream_iterator<string>(iss),
       istream_iterator<string>(),
       back_inserter<vector<string> >(parts));


}


//wont work, will read first string on each row only...or maybe will...
void chatter::init_th()
{
  ifstream th("dic/th_sv_SE.dat");
  for(int i=0;th.good();i++)
    {
      string tmp,tmpw;
      th_sv.push_back(vector <string>());
      getline(th,tmp,'|');
      th_sv[i].push_back(tmp);
      getline(th,tmp);
      
      stringstream stream(tmp);
      while( getline(stream, tmpw, '|') )
	th_sv[i].push_back(tmpw);
    }
  th.close();
}

bool is_in( int *array, int index, int val )
{
  for(int i=0; i <= index; i++)
    {
      if(array[i] == val) return true;
    }
  return false;
}

//code taken from http://ai-programming.com/ written by Gonzales Cenelia
float chatter::fuzzymatch(string pattern, string text)
{
  int Plen=pattern.size();
  int Tlen=text.size();
  if(Tlen>Plen)
    {
      swap(pattern, text);
      swap(Plen,Tlen);
    }
  float cost=0.0f;
  float hit=0.0f;
  int Textloc=0;
  float min_cost=(float)1/Plen;
  int *hit_pos=new int[Plen];
  for(int Textoff=0;Textoff<Plen;++Textoff)
    {
      Textloc=text.find(pattern[Textoff]);
      if(is_in(hit_pos,Textoff,Textloc))
	{
	  int Tempoff=Textloc+1;
	  while(Tempoff<Tlen)
	    {
	      Textloc=text.find(pattern[Textoff],++Tempoff);
	      if(Textloc!=-1&& !is_in(hit_pos,Textoff,Tempoff))break;
	    }
	}

      if(Textloc!=-1)
	{
	  hit_pos[Textoff]=Textloc;
	  int distance=abs(Textloc-Textoff);
	  cost=distance*min_cost;
	  hit+=1-cost;
	}
    }
  delete hit_pos;
  return hit/Plen;
}

void chatter::init_know()
{
  ifstream rec("key_resp.txt");

  string sCount;
  int nCount;
  getline(rec,sCount);
  nCount=atoi(sCount);
  knowledge=new record[nCount];

  bool ans=false;
  int nKey=0,nRes=0;

  for(int i=0;th.good();i++)
    {
      string tmp;
      getline(rec,tmp);
      if(tmp.compare("#"))
	{
	  ans=true;
	  getline(rec,tmp);
	}
      if(tmp.compare("##"))
	{
	  ans=false;
	  nKey=0;
	  nRes=0;
	  getline(rec,tmp);
	}
      if(!ans)
	{
	  knowledge[i].keyword[nKey]=tmp;
	  nKey++;
	  continue;
	}
      if(ans)
	{
	  knowledge[i].respons[nRes]=tmp;
	  nRes++;
	  continue;
	}
    }
}

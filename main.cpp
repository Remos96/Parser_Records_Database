#include "Records.h"
#include <iostream>

int main()
{
   HardDisk disc;
   MyManager engine(disc.read_f());
   Parser parser;
    
   std::string userInput;
   bool shouldStop{false};
   while(!shouldStop)
   {
      getline(std::cin, userInput);
      shouldStop = engine.Process( parser(userInput) );
   }
}
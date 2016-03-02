#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include "Coor.h"
#include "Grid.h"
#include "helper.h"
#include "findMove.h"

using namespace std;

int main (void)
{
   Coor c;
   char tmp[25];
   bool exit = false;
   int x,y; 
   Grid grid(20,20,5);
   grid.calculateGroups();
   while (!grid.isFinished())
   {
      grid.printGrid(true, false, false);
      c = greedyFindBestMove(grid);
      grid.makeMove(c);
      grid.calculateGroups();
   }
   grid.printGrid(true, false, false);
   /*while (!exit)
   {
      scanf("%s", tmp);
      if (strcmp("exit",tmp)==0)
         exit = true;
      if (strcmp("printGrid",tmp)==0)
         grid.printGrid(true,false,true);
      if (strcmp(tmp, "calculateGroups")==0)
         grid.calculateGroups();
      if (strcmp(tmp, "makeMove")==0)
      {
         scanf("%d %d", &x, &y);
         grid.makeMove(Coor(x,y));
      }
          
   }*/   
   return 0;
}

#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

#include "Coor.h"
#include "Grid.h"

using namespace std;

Grid readGridFromFile(string fileName)
{
   ifstream gridFile;
   int numRows, numCols, numColors;
   char temp;

   gridFile.open(fileName, ifstream::in);
   gridFile >> numRows;
   gridFile >> numCols;
   gridFile >> numColors;
   Grid grid = Grid(numRows, numCols, numColors);
   for (int rowIndex = 0; rowIndex < numRows; rowIndex++)
   {
      for(int Colindex = 0; Colindex < numCols; Colindex++)
      {
         gridFile >> temp;
         grid.setGridValue(Coor(rowIndex,Colindex), temp);
      }
   }

   gridFile.close();

   return grid;
}

int main (void)
{
   Grid grid = readGridFromFile("ex1.grd");
   vector <Coor> coors = grid.calculateGroup(Coor(0,0)).coors;
   while (coors.size() > 0)
   {
      cout << coors.back();
      coors.pop_back();
   }
   cout << Coor(2,2) + Coor(1,2);

   cout << grid.findNeighbour(Coor(3,4),UP);
   cout << grid.findNeighbour(Coor(3,4),DOWN);
   cout << grid.findNeighbour(Coor(3,4),LEFT);
   cout << grid.findNeighbour(Coor(3,4),RIGHT);
   cout << grid.findNeighbour(Coor(0,0),UP);
   cout << grid.findNeighbour(Coor(0,grid.getNumCols()-1), RIGHT);
   return 0;
}

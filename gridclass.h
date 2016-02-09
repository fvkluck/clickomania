#ifndef __GRIDCLASS_INCLUDED__
#define __GRIDCLASS_INCLUDED__

#include "coorclass.h"

class Gridclass {
private:
   int num_rows;
   int num_cols;
   int num_colors;
   char** grid;

public:
   //Constructors
   Gridclass(int num_r, int num_c, int num_clrs);
   ~Gridclass(void);

   //get and set functions
   void setGridValue(Coor c, char value) { grid[c.getColIndex()][c.getRowIndex()] = value; }
   int getGridValue(Coor c) { return grid[c.getColIndex()][c.getRowIndex()]; }
   int getNumRows(void) { return num_rows; }
   int getNumCols(void) { return num_cols; }
   int getNumColors(void) { return num_colors; }

   //other functions
   void printGrid(void);
   int calculateGroupSize(Coor start_search);
};



#endif
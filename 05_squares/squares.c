#include <stdio.h>
#include <stdlib.h>

int max (int num1, int num2) {
  if (num1 > num2) {
    return num1;
  }
  else {
    return num2;
  }
}

int rangeCheck (int index, int offset, int size) {
  if ((index >= offset) && (index < (offset + size))) {
    return 1;
  } else {
    return 0;
  }
}

int equalityCheck (int index, int offset, int size) {
  if ((index == offset) || (index == (offset + size - 1))) {
    return 1;
  } else {
    return 0;
  }
}

int eitherOrCheck (int index1, int index2, int size) {
  if ((index1 < size && (index2 == 0 || index2 == size-1)) || (index2 < size && (index1 == 0 || index1 == size - 1))) {
    return 1;
  } else {
    return 0;
  }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w

  //compute the max of size1 and (y_offset + size2).  Call this h

  //count from 0 to h. Call the number you count with y

    //count from 0 to w. Call the number you count with x

      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *

      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #

      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline

  int w = max(size1, (x_offset + size2));
  int h = max(size1, (y_offset + size2));
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (((rangeCheck(x, x_offset, size2) == 1) && (equalityCheck(y, y_offset, size2) == 1)) || ((rangeCheck(y, y_offset, size2) == 1) && (equalityCheck(x, x_offset, size2) == 1))) {
        printf("*");
      } else {
        if (eitherOrCheck(x, y, size1) == 1) {
          printf("#");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "header/stack.h"
#include "header/display.h"

int main(void)
{
     bool running = true; 
     int choice = 0;
     stack pile; 

     display(choice, running, pile);
     
     return 0;
}
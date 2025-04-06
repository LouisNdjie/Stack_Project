#ifndef __STACK__H__
#define __STACK__H__

//Définition d'une pile
typedef struct STACK
{
    int value;
    struct STACK *next;
}STACK, *stack;

//Prototypage des fonctions  
void print_menu(void);
stack New_Stack(void);
bool Is_Empty_Stack(stack pile);
stack Push_Stack(stack pile, int val);
stack Clear_Stack(stack pile);
void Print_Stack(stack pile);
stack Pop_Stack(stack pile);
int Top_Stack(stack pile);
int Length_Stack(stack pile);
int Search_In_Stack(stack pile, int search);
stack Reverse_Stack(stack pile); 
stack Asc_Stack(stack pile); 
stack Desc_Stack(stack pile);   
#endif
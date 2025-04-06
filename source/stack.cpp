#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../header/stack.h"

void print_menu(void)
{
    printf(" _________________________________________________________________________________________________________________________________ \n");
    printf("| |||||     |||||    |||||   |||||||||    |||||||      |||||      |||||     |||||   ||||||||    ||||||||   |||||  ||||||  |||||| |\n");
    printf("| |||||||||||||||    || ||      |||         |||      || |||       |||||||||||||||   |||           ||||   || |||     |||    |||   |\n");
    printf("| ||||| ||| |||||    || ||      |||         |||    ||   |||       ||||| ||| |||||   ||||||||      |||| ||   |||     |||    |||   |\n");
    printf("| ||||| ||| |||||    |||||      |||         |||  ||     |||       ||||| ||| |||||   |||           |||||     |||     |||    |||   |\n");
    printf("| ||||| ||| |||||   |||||||  |||||||||     ||||||      |||||      ||||| ||| |||||   ||||||||     |||||||   |||||    ||||||||||   |\n");
    printf(" _________________________________________________________________________________________________________________________________\n");
    printf("|                                                [1] - CREER UNE PILE                                                            |\n");
    printf("|                                              [2] - AJOUTEZ UN ELEMENT                                                          |\n");
    printf("|                                             [3] - SUPPRIMER UN ELEMENT                                                         |\n");
    printf("|                                            [4] - AFFICHER LES ELEMENTS                                                         |\n");
    printf("|                                         [5] - AFFICHER LE PREMIER ELEMENT                                                      |\n");
    printf("|                                               [6] - VIDER LA PILE                                                              |\n");
    printf("|                                            [7] - VERIFIER SI PILE VIDE                                                         |\n");
    printf("|                                      [8] - VERIFIER SI LA PILE EST PLEINE                                                      |\n");
    printf("|                                      [9] - AFFICHER LA TAILLE DE LA PILE                                                       |\n");
    printf("|                                         [10] - RECHERCHER UN ELEMENT                                                           |\n");
    printf("|                                           [11] - INVERSER LA PILE                                                              |\n");
    printf("|                                  [12] - TRIER LA PILE PAR ORDRE CROISSANT                                                      |\n");
    printf("|                                 [13] - TRIER LA PILE PAR ORDRE DECROISSANT                                                     |\n");
    printf("|                                                  [14] - EXIT                                                                   |\n");
    printf("__________________________________________________________________________________________________________________________________\n\n");
    printf("Choissisez une option : ");
}

/*---------------------------------------------------------------------------------------*/
//creation d'une nouvelle pile
stack New_Stack(void)   
{
    return NULL;
}
/*---------------------------------------------------------------------------------------*/
//verifier si la pile est vide
bool Is_Empty_Stack(stack pile)
{
    if(pile == NULL)
        return true;
    return false;
}
/*---------------------------------------------------------------------------------------*/
//ajouter un nouvel élément
stack Push_Stack(stack pile, int val)
{
    STACK *element;

    element = new STACK;
    
    if(element == NULL)
        fprintf(stderr, "Probleme lors de l'allocation dynamique de la memoire" );
    
    element->value = val;
    element->next = pile;

    return element;
}
/*---------------------------------------------------------------------------------------*/
//supprimer un élément
stack Pop_Stack(stack pile)
{
    STACK * element;

    if(Is_Empty_Stack(pile))
        return New_Stack();
    
    element = pile->next;
    delete(pile);
    return element;
}
/*---------------------------------------------------------------------------------------*/
//afficher le sommet de la pile
int Top_Stack(stack pile)
{
    if(Is_Empty_Stack(pile))
    {
        printf("la pile est vide est vide");
        return 1;
    }

    return pile->value;

}
/*---------------------------------------------------------------------------------------*/
//afficher la pile
void Print_Stack(stack pile)
{
    if(Is_Empty_Stack(pile))
    {
        printf("rien a afficher, la pile est vide");
        return ; 
    }

    printf("[");
    while(!Is_Empty_Stack(pile))
    {
        printf("%d", pile->value);
        pile = pile->next;
        if(!Is_Empty_Stack(pile))
            printf(",");
    }
    printf("]\n");
}
/*---------------------------------------------------------------------------------------*/
//afficher la taille de la pile 
int Length_Stack(stack pile)
{
    int size = 0;
    if(Is_Empty_Stack(pile))
    {
        return 0 ; 
    }
    
    while(!Is_Empty_Stack(pile))
    {
        size++;
        pile = pile->next;
    }

    return size;

}
/*---------------------------------------------------------------------------------------*/
//rechercher un élément dans la pile 
int Search_In_Stack(stack pile, int search)
{
    if(Is_Empty_Stack(pile))
    {
        return 0 ; 
    }

    while(!Is_Empty_Stack(pile))
    {
        if(pile->value == search)
            return 1;
        pile = pile->next;
    }
    return 0 ;
}
/*---------------------------------------------------------------------------------------*/
//inverser la pile 
stack Reverse_Stack(stack pile)
{
    stack element = New_Stack();
    int subs;

    if(Is_Empty_Stack(pile))
    {
        return New_Stack(); 
    }
    
    while(!Is_Empty_Stack(pile))
    {
        subs = pile->value;
        element = Push_Stack(element, subs);
        pile = pile->next;
    }

    return element;
}
/*---------------------------------------------------------------------------------------*/
//tri de la pile dans l'ordre croissant
stack Asc_Stack(stack pile)
{
   stack asc =  New_Stack();
   int size_stack = Length_Stack(pile);
   int temp = 0;
   int tab[size_stack] = {0};
   int i = 0, j = 0;

   if(Is_Empty_Stack(pile))
    return New_Stack();

    while(!Is_Empty_Stack(pile))
    {
        tab[i] = pile->value;
        i++;
        pile = pile->next;
    }

    for (i=size_stack-1; i>=1; i--)
    {
        for(j=0; j<=i-1; j++)
        {
            if(tab[j+1]>tab[j])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }

    for(i=0; i< size_stack; i++)
    {
       asc = Push_Stack(asc, tab[i]);
    }

    return asc; 

}
/*---------------------------------------------------------------------------------------*/
//tri de la pile dans l'ordre decroissant 
stack Desc_Stack(stack pile)
{
    stack desc =  New_Stack();
   int size_stack = Length_Stack(pile);
   int temp = 0;
   int tab[size_stack] = {0};
   int i = 0, j = 0;

   if(Is_Empty_Stack(pile))
    return New_Stack();

    while(!Is_Empty_Stack(pile))
    {
        tab[i] = pile->value;
        i++;
        pile = pile->next;
    }

    for (i=size_stack-1; i>=1; i--)
    {
        for(j=0; j<=i-1; j++)
        {
            if(tab[j+1]<tab[j])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }

    for(i=0; i< size_stack; i++)
    {
       desc = Push_Stack(desc, tab[i]);
    }

    return desc; 

}
/*---------------------------------------------------------------------------------------*/
//vider la pile
stack Clear_Stack(stack pile)
{
    while(!Is_Empty_Stack(pile))
        pile = Pop_Stack(pile);
    
    return New_Stack();
}

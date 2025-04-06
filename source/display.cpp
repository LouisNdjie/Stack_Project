#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../header/display.h"
#include "../header/stack.h"

void display(int choice, bool running, stack pile)
{
    while(running)
     {
          system("cls");
          print_menu();
          scanf("%d", &choice);
          switch(choice)
          {
               case 1 :
               {
                    system("cls");
                    printf("NOUS ALLONS CREER UNE NOUVELLE LISTE\n\n");
                    pile = New_Stack();
                    printf("LA PILE A ETE CREE AVEC SUCCES\n");
                    system("pause");
                    break;
               }
               case 2 :
               {
                    system("cls");
                    printf("VOUS POUVEZ EMPILER LES ELEMENTS DANS LA PILE\n\n");
                    int element = 0;
                    printf("Entrez la valeur a empiler:");
                    scanf("%d", &element);
                    pile = Push_Stack(pile, element);
                    printf("SUCCES LORS DE L'EMPILAGE DE L'ELEMENT\n");
                    system("pause");
                    break;
               }
               case 3 :
               {
                    system("cls");
                    printf("VOUS POUVEZ DEPLIER LES ELEMENTS DANS LA PILE\n\n");
                    pile = Pop_Stack(pile);
                    printf("SUCCES LORS DU DEPLIAGE DES ELEMENTS DANS LA PILE\n");
                    system("pause");
                    break;
               }
               case 4 :
               {
                    system("cls");
                    printf("NOUS ALLONS AFFICHER LA PILE\n\n");
                    Print_Stack(pile);
                    system("pause");
                    break;
               }
               case 5 :
               {
                    system("cls");
                    printf("AFFICHONS LE PREMIER ELEMENT DE LA PILE\n\n");
                    int top = Top_Stack(pile);
                    printf("LE PREMIER ELEMENT DE LA PILE EST: %d\n", top);
                    system("pause");
                    break;
               }
               case 6 :
               {
                    system("cls");
                    printf("VIDONS LA PILE\n\n");
                    pile = Clear_Stack(pile);
                    system("pause");
                    break;
               }
               case 7 :
               {
                    system("cls");
                    printf("VERIFIONS SI LA PILE EST VIDE\n\n");
                    bool stack_state = Is_Empty_Stack(pile);
                    if(stack_state)
                         printf("LA PILE EST VIDE\n");
                    system("pause");
                    break;
               }
               case 8 :
               {
                    system("cls");
                    printf("VERIFIONS SI LA PILE EST PLEINE\n\n");
                    bool stack_state = Is_Empty_Stack(pile);
                    if(!stack_state)
                         printf("LA PILE EST PLEINE\n");
                    system("pause");
                    break;
               }
               case 9 :
               {
                    system("cls");
                    printf("AFFICHONS LA TAILLE DE LA PILE\n\n");
                    int stack_size = Length_Stack(pile);
                    printf("LA TAILLE DE LA PILE EST : %d\n", stack_size);
                    system("pause");
                    break;
               }
               case 10 :
               {
                    system("cls");
                    printf("NOUS ALLONS RECHERCHER UN ELEMENT DANS LA PILE\n\n");
                    int search_element = 0, find_in_stack = 0;
                    printf("Entrez la valeur a rechercher dans la pile :");
                    scanf("%d", &search_element);
                    find_in_stack = Search_In_Stack(pile, search_element);
                    
                    if(find_in_stack == 1)
                         printf("l'element [%d] existe dans la pile\n", search_element);
                    else 
                         printf("l'element [%d] n'existe pas dans la pile\n", search_element);

                    system("pause");
                    break;
               }
               case 11 :
               { 
                    system("cls");
                    printf("NOUS ALLONS INVERSER LA PILE\n\n");
                    stack inv = Reverse_Stack(pile);
                    printf("la pile inversee est :");
                    Print_Stack(inv);
                    system("pause");
                    break;
               }
               case 12 :
               {
                    system("cls");
                    printf("NOUS ALLONS TRIER LA PILE DANS L'ODRE CROISSANT\n\n");
                    stack ascendant_stack = Asc_Stack(pile);
                    printf("la pile triee est :");
                    Print_Stack(ascendant_stack);
                    system("pause");
                    break;
               }
               case 13 :
               {
                    system("cls");
                    printf("NOUS ALLONS TRIER LA PILE DANS L'ODRE DECROISSANT\n\n");
                    stack descendant_stack = Desc_Stack(pile);
                    printf("la pile triee est :");
                    Print_Stack(descendant_stack);
                    system("pause");
                    break;
               }
               case 14 :
               {
                    system("cls");
                    printf("MERCI D'AVOIR UTILISER STACK_PROJECT");
                    running = false;
                    break;
               }
          }

     }

}
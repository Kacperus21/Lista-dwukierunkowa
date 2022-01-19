#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


typedef struct ListElement {
    int data;
    struct ListElement * previous;  //deklaracja struktury listy
    struct ListElement * next;
} ListElement_type;

void push_front(ListElement_type **head, int number)
{

    if(*head==NULL) { //tylko wtedy gdy lista jest pusta czyli dodajemy pierwszy element
    	*head = (ListElement_type *)malloc(sizeof(ListElement_type)); //alokacja pamieci na liste o danym rozmiarze
   		(*head)->data = number; //liczba z klawiatury                   // jesli element jest pierwszy zostaje "glowa"
   		(*head)->previous=NULL; //poniewaz jest to pierwszy element nie ma elementu nastepnego ani poprzedniego
    	(*head)->next = NULL;
	} else {
		ListElement_type *current;
    	        current=(ListElement_type *)malloc(sizeof(ListElement_type));
    	        current->data=number;
    	        current->previous=NULL; //nadajemy null poprzednikowi wstawianego elementu poniewaz jest on teraz pierwszy
    	        current->next=(*head);
    	        (*head)->previous=current;
    	        *head=current;
	}

}

void push_back(ListElement_type **head, int number)
{


	if(*head==NULL) //tylko wtedy gdy lista jest pusta czyli dodajemy pierwszy element
	{
		*head = (ListElement_type *)malloc(sizeof(ListElement_type));//alokacja pamieci na liste o danym rozmiarze
   		(*head)->data = number;
   		(*head)->previous = NULL;
    	(*head)->next = NULL;
	}else
	{
		ListElement_type *current=*head; //wskaznik glowy rowna sie wskaznikowi bierzacego elementu


	    while (current->next != NULL) { //dopóki nastepnik bierzacego elementu jest rózny od null
	        current = current->next;    //Birzacy element rowna sie swojemu nastepnikowi
	    }

	    current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
	    current->next->data = number; //nadajemy liczbe z klawiatury
	    current->next->previous=current;//ustawiamy poprzednik
	    current->next->next = NULL;//ustawiamy jako nastepnik dodanego elementu null bo po nim juz nic nie ma
	}



}



void pop_front(ListElement_type **head)
{

    if (*head!=NULL) {//jesli nie ma elementow w liscie
    	if((*head)->next==NULL) {//jesli jest jeden element w liscie
    		*head=NULL;
		} else {
			ListElement_type *pom;
			pom=(*head)->next;//pom rowna sie nastepnik glowy
   			free(*head);//zwolnienie glowy
   			*head=pom;//nowa glowa rowna sie pom
   	 		(*head)->previous=NULL;//poprzednik nowej glowy ustawiamy na null
		}

	}

}

void pop_back(ListElement_type **head) //wskaznik wskaznika
{

	if((*head)->next==NULL)//jezeli nastepnik glowy jest null
	{
		*head=NULL; //to przypisz wskaznikowi glowy null
	}else
	{
		ListElement_type *current=*head;
		while (current->next->next!= NULL) { //wykonuj dopóki nastepnik nastepnki bierzacego elementu jest rozny od null
        current = current->next; //przypisz bierzacemu elementowi jego nastepnik
    	}
   		 free(current->next); //zwolnij nastepnik bierzacego
   		 current->next=NULL;
	}
}

void show(ListElement_type *head)
{
    printf(" ");
    if(head==NULL) printf("Lista jest pusta");//jesli nie ma glowy
    else
    {
        ListElement_type *current=head;
        do {
            printf("%i", current->data); //wypisz bierzacy element
            printf(" ");
            current = current->next; //wez za bierzacy element jego nastepnik
        }while (current != NULL);  //petla wykonuje sie dopoki bierzacy element bedzie rozny od null
    }
}
void show_reverse(ListElement_type *head)
{
    printf(" ");
    if(head==NULL) printf("List is empty");
    else
    {
        ListElement_type *current=head;
        while (current->next != NULL) {
            current = current->next; //idziemy na koniec listy
        }


        do {
        	printf("%i", current->data);
            printf(" ");
            current = current->previous;
		}while(current!=NULL);

    }
}


int main()
{
    ListElement_type *head;
    head = (ListElement_type *)malloc(sizeof(ListElement_type));
    head=NULL;


    int wybor;
    int number;
    int ile=0;
    int i;
    while(wybor!=0)
    {

    system("cls");
    printf("\nAktualny stan listy: ");
    show(head);

    printf("Co chcesz zrobic?\n");
    printf("1. Dodac element na poczatek listy\n");
    printf("2. Dodac element na koniec listy\n");
    printf("3. Usunac element z poczatku listy\n");
    printf("4. Usunac element z konca listy\n");
    printf("5. Wyswietl odwrocona liste\n");
    printf("0. Zakonczyc program.\n");




    scanf("%i", &wybor);

    switch (wybor)
    {
    case 0:
    	return 0;
    	break;

    case 1:
        printf("Podaj ile liczb chcesz dodac");
        scanf("%d", &ile);
        for(i=0;i<ile;i++)
            {
            printf("Wpisz liczbe jaka chcesz dodac: ");
            scanf("%i", &number);
            push_front(&head, number);
            }

        break;
     case 2:
        printf("Podaj ile liczb chcesz dodac");
        scanf("%d", &ile);
        for(i=0;i<ile;i++)
            {
            printf("Wpisz liczbe jaka chcesz dodac: ");
            scanf("%i", &number);
            push_back(&head, number);
            }
        break;
    case 3:
        printf("Podaj ile liczb chcesz dodac");
        scanf("%d", &ile);
        for(i=0;i<ile;i++)
            {
        pop_front(&head);
            }
        break;
	case 4:
	    printf("Podaj ile liczb chcesz dodac");
        scanf("%d", &ile);
        for(i=0;i<ile;i++)
            {
        pop_back(&head);
            }
        break;
    case 5:
        show_reverse(head);
        break;
    default:
        printf("Podaj wlasciwa opcje.");
        break;

    }

    }


    return 0;
}



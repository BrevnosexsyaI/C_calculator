#pragma once

#include <stdio.h> // ñòàíäàðòíàÿ áèáëèîòåêà Ñè
#include <string.h> // äëÿ ðàáîòû ñî ñòðîêàìè
#include <stdlib.h> // äëÿ ðàáîòû ñ ïàìÿòüþ
#include "Lecksema.h"

// ñòðóêòóðà ýëåìåíòà ñïèñêà
typedef struct list_item {
    Leksema data; // ïî ýòîìó óêàçàòåëþ ìû õðàíèì êàêèå-òî äàííûå
    struct list_item* next; // ýòî ó íàñ ññûëêà íà ñëåäóþùèé óêàçàòåëü
    struct list_item* prev; // ýòî ó íàñ ñ  ñûëêà íà ïðåäûäóùèé óêàçàòåëü
} list_item;

// Îáùàÿ ñòðóêòóðà ñïèñêà
typedef struct list {
    int count; // èíôîðìàöèÿ î ðàçìåðå ñïèñêà
    list_item* head; // ýòî ññûëêà íà ãîëîâíîé ýëåìåíò
    list_item* tail; // ýòî ó íàñ ññûëêà íà ïîñëåäíèé ýëåìåíò (õâîñò ñïèñêà)
} list;

list* db_create();

void db_insert(list* lst, int index, Leksema data);

Leksema* db_read(list* lst, int index);

//void db_print(list* lst);

void push_front(list* lst, Leksema lex);

void push_back(list* lst, Leksema* lex);

Leksema* pop_front(list* lst);

Leksema* pop_back(list* lst);

list_item* get_element(list* lst, int index); // òèï äàííûõ âîçâðàøàåìûé ôóíêöèåé ? ýòî ñòðóêòóðà ?

void db_delete(list* lst, int index);
void db_delete_2(list* lst, int index);

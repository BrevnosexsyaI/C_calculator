#include <stdio.h> // стандартная библиотека Си
#include <string.h> // для работы со строками
#include <stdlib.h> // для работы с памятью

// структура элемента списка
typedef struct list_item {
    void* data; // по этому указателю мы храним какие-то данные
    struct list_item* next; // это у нас ссылка на следующий указатель
    struct list_item* prev; // это у нас ссылка на предыдущий указатель
} list_item;

// Общая структура списка
typedef struct list {
    int count; // информация о размере списка
    list_item* head; // это ссылка на головной элемент
    list_item* tail; // это у нас ссылка на последний элемент (хвост списка)
} list;

list* db_create();

void db_insert(list* lst, int index, char* data);

char* db_read(list* lst, int index);

int db_search(list* lst, char* data);

void db_delete(list* lst, int index);

void db_print(list* lst);

list_item* get_element(list* lst, int index); // тип данных возврашаемый функцией ? это структура ?
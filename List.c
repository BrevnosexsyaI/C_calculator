#include "List.h"

list* db_create() {
    // �������� ��������� �� ���������� ��������� ������ � ������� ������� ������ ��� ���
    list* lst = (list*)malloc(sizeof(list));

    // ������ �������������� ��������
    lst->count = 0; // ��� ������ ����
    lst->head = NULL; // ������� �������� � ��� ���
    lst->tail = NULL; // � ���������� ����

    return lst;
}
#pragma warning(disable : 4996)	// ��������� ���������������������������� ������	C4996	'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.calc_Chat_Gpt	C : \Users\User\source\repos\calc_Chat_Gpt\calc_Chat_Gpt\List.c	27

void db_insert(list* lst, int index, char* data) {
    // �������� ��������� ���������� �������� ������, 
    // � �������� ��� �������� ��������� �� ������ ������� ������
    list_item* base = lst->head;

    // �������� ��������� ���������� �� ����� ������� � ������� ��� ���� ������
    list_item* new_item = (list_item*)malloc(sizeof(list_item));

    // ������� ������ ������ ������ �������� ��������� ���� ��������� ������,
    // � ������� ��������� �� ����,
    // strlen() �����, ����� ���������� ������ ���� ����� ������ ���������� ������.
    new_item->data = malloc(sizeof(char) * strlen(data));
    strcpy(new_item->data, data); // �������� ���� ������

    // ������ ���� ������ ���� �� ��������� �������,
    // �.�. � ��� ��� ��� ���������, lst->head ������ ��� NULL.
    // ������������� ����� �������, ��� �������� ������� �������� ������.
    if (base == NULL) {
        // ���� ������� ������������, � ������ ��� ��������� ����� NULL.
        new_item->next = NULL;
        new_item->prev = NULL;

        // ��� ����, �� ��� ����� ������ � ��������� � ������.
        lst->head = new_item;
        lst->tail = new_item;
        lst->count++; // �������� ���-�� �� �������
        return;
    }

    // ���� ������, ������� ������ ����� ������ ����, �� ����� ��������� � �����
    if (index < 0) {
        // ������ ������ ����� ��������� �� ����� ���. ������� ����
        base->prev = new_item;
        new_item->prev = NULL;
        new_item->next = base; // � ������ �� ����. ���. � ������ ����� �� ������

        lst->head = new_item; // ��������� ����� ������� �������
    }
    else { // ��� ��� � �������� �������
        base = lst->tail; // �������� � ����� ������

    // ����� �� ������ ���������� �� ����� �������
        base->next = new_item;
        new_item->next = NULL; // ����� �� ����� ����� ������ �� ���������
        new_item->prev = base; // � ���������� � ���� ����� ����� ������

        lst->tail = new_item; // ��������� ����� ������� ������� ������
    }
    lst->count++; // �������� ������ �� �������
}

char* db_read(list* lst, int index) {
    list_item* base = get_element(lst, index);
    if (base == NULL)
        return NULL;

    char* value = malloc(sizeof(char) * strlen(base->data)); // �������� ������ ��� ������
    strcpy(value, base->data); // �������� ������

    return value; // ���������� ���������� ��������
}

int db_search(list* lst, char* data) {
    int i = 0; // ���������� �������
    list_item* base = lst->head; // �������� � ������� ��������
    // ������������� �������� strcmp, ����� �������� ������������ ������
    while (strcmp(base->data, data) != 0) {
        // ���� ������ �� �������� � ��� ��� �� ����, ����� ���������� ��������
        base = base->next;
        i++;
    }
    return i; // ������� ���������� ������ ������ ���������� ������
}

list_item* get_element(list* lst, int index) {
    list_item* base;
    int middle = lst->count / 2; // ��������� �������� ������

    if (index > middle) { // ���� ������ ������ ��������
        base = lst->tail;
        for (int i = lst->count; i > index; i--)
            base = base->prev;
    }
    else { // ���� ������ ������ ��������
        base = lst->head;
        for (int i = 0; i < index; i++)
            base = base->next;
    }

    // ���� �������� ���
    if (base == NULL) {
        printf("\033[3;31mError! The list item was not found...\n\033[0m");
        return NULL;
    }
    return base; // ���������� �������
}

void db_delete(list* lst, int index) {
    list_item* base = get_element(lst, index);
    list_item* prev, * next;

    if (base == NULL)
        return;

    prev = base->prev; // ��������� ����������� ��������
    next = base->next; // �� �������� ��������� �������

    // ��������������� ��������� ��� ����������� �������� �� ���������
    if (prev != NULL)
        prev->next = base->next;

    // � ���� ����� ��� ����������� ��������
    if (next != NULL)
        next->prev = base->prev;

    free(base); // ����������� ������ 
    lst->count--; // ��������� ������ ������ �� �������
}

void db_print(list* lst) {
    list_item* base = lst->head; // ��������� � ������ ������
    puts("\033[43m***Printing a list***\033[0m");

    if (lst->count == 0) { // ���� ������ ������, ��� � �������
        printf("The list is empty\n");
        return;
    }

    int i = 0; // ���������� �������
    while (base != NULL) { // ���� ��� �������� �� ��������� �� ����� �� ����������
        printf("ID: %d || Data: %s\n", i, (char*)base->data); // ������ �� �����
        base = base->next;
        i++;
    }
    // � ����� ������� ����� ������ � ������ ������
    printf("Base size: %d\n", lst->count);
}
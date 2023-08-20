#include "List.h"

list* db_create() {
    // �������� ��������� �� ���������� ��������� ������ � ������� ������� ������ ��� ���
    list* lst = (list*)malloc(sizeof(list));

    if (lst == NULL) {
        // ��������� ������ �� �������, ��������� ������
        fprintf(stderr, "������: �� ������� �������� ������ ��� ������.\n");
        return NULL; // ���������� NULL ��� ��������� ������ �������� �� ��������� ������
    }

    // ������ �������������� ��������
    lst->count = 0; // ��� ������ ����
    lst->head = NULL; // ������� �������� � ��� ���
    lst->tail = NULL; // � ���������� ����

    return lst;
}
#pragma warning(disable : 4996)	// ��������� ���������������������������� ������	C4996	'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.calc_Chat_Gpt	C : \Users\User\source\repos\calc_Chat_Gpt\calc_Chat_Gpt\List.c	27

void db_insert(list* lst, int index, Leksema data) {
    // �������� ��������� ���������� �������� ������, 
    // � �������� ��� �������� ��������� �� ������ ������� ������
    list_item* base = lst->head;

    // �������� ��������� ���������� �� ����� ������� � ������� ��� ���� ������
    list_item* new_item = (list_item*)malloc(sizeof(list_item));
    
    if (new_item == NULL) {
        // ��������� ������ �� �������, ��������� ������
        fprintf(stderr, "������: �� ������� �������� ������ ��� ������.\n");
        return NULL; // ���������� NULL ��� ��������� ������ �������� �� ��������� ������
    }

    new_item->data = data;


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

Leksema* db_read(list* lst, int index) {
    list_item* base = get_element(lst, index);
    Leksema* value = {0};
    if (base == NULL) {
        if (value == NULL) {
            printf("\033[3;31mError! The list item was not found...\n\033[0m");
            return NULL;
        }
        value->type = TYPE_OPERATOR;
    }
    if (value == NULL) {
        printf("\033[3;31mError! The list item was not found...\n\033[0m");
        return NULL;
    }
    value->operation = 'x';  /// ���� ��� ��������� operation == 'x' ���������� ������
    return value;

    value = &(base->data);


    return value; // ���������� ���������� ��������
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

void push_front(list* lst, Leksema lex) {
    list_item* base = lst->head;

    list_item* new_item = (list_item*)malloc(sizeof(list_item));
    if (new_item == NULL) {
        printf("\033[3;31mError! The list item was not found...\n\033[0m");
        return NULL;
    }
    new_item->data = lex;


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
    else {
        base->prev = new_item;
        new_item->prev = NULL;
        new_item->next = base;
        lst->head = new_item;
    }

    lst->count++; // �������� ������ �� �������
}

void push_back(list* lst, Leksema* lex) {
    list_item* base = lst->tail;

    list_item* new_item = (list_item*)malloc(sizeof(list_item));
    if (new_item == NULL) {
        printf("\033[3;31mError! The list item was not found...\n\033[0m");
        return NULL;
    }
    new_item->data = *lex;
    if (base == NULL) {
        // ���� ������� ������������, � ������ ��� ��������� ����� NULL.
        new_item->next = NULL;
        new_item->prev = NULL;

        // ��� ����, �� ��� ����� ������ � ��������� � ������.
        lst->head = new_item;
        lst->tail = new_item;
        lst->count++; // �������� ���-�� �� �������
    }
    else {
        base->next = new_item;
        new_item->next = NULL;
        new_item->prev = base;
        lst->tail = new_item;

    }
    lst->count++;
}

Leksema* pop_front(list* lst) {
    list_item* base = lst->head;

    Leksema* value = {0};

    if (base == NULL) {
        if (value == NULL) {
            printf("\033[3;31mError! The list item was not found...\n\033[0m");
            return NULL;
        }
        value->type = TYPE_OPERATOR;
        value->operation = 'x';  /// ���� ��� ��������� operation == 'x' ���������� ������
        return value;
    }
    else {
        if (base->data.type == TYPE_OPERATOR) {
            if (value == NULL) {
                printf("\033[3;31mError! The list item was not found...\n\033[0m");
                return NULL;
            }
            value->type = TYPE_OPERATOR;
            value->operation = base->data.operation;
        }
        else if (base->data.type == TYPE_NUMBER) {
            if (value == NULL) {
                printf("\033[3;31mError! The list item was not found...\n\033[0m");
                return NULL;
            }
            value->type = TYPE_NUMBER;
            value->numder = base->data.numder;
        }
    }
    return value;
}


Leksema* pop_back(list* lst) {
    list_item* base = lst->tail;

    Leksema* value = {0};
    if (base == NULL) {
        if (value == NULL) {
            printf("\033[3;31mError! The list item was not found...\n\033[0m");
            return NULL;
        }
        value->type = TYPE_OPERATOR;
        value->operation = 'x';  /// ���� ��� ��������� operation == 'x' ���������� ������
        return value;
    }
    else {
        if (base->data.type == TYPE_OPERATOR) {
            if (value == NULL) {
                printf("\033[3;31mError! The list item was not found...\n\033[0m");
                return NULL;
            }
            value->type = TYPE_OPERATOR;
            value->operation = base->data.operation;
        }
        else if (base->data.type == TYPE_NUMBER) {
            if (value == NULL) {
                printf("\033[3;31mError! The list item was not found...\n\033[0m");
                return NULL;
            }
            value->type = TYPE_NUMBER;
            value->numder = base->data.numder;
        }
    }
    return value;

}
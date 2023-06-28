#include "List.h"

list* db_create() {
    // Создадим указатель на переменную структуры списка и выделим немного памяти для нее
    list* lst = (list*)malloc(sizeof(list));

    // задаем первоначальные значения
    lst->count = 0; // наш список пуст
    lst->head = NULL; // первого элемента у нас нет
    lst->tail = NULL; // и последнего тоже

    return lst;
}
#pragma warning(disable : 4996)	// отключаем предупреждениедляСерьезность Ошибка	C4996	'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.calc_Chat_Gpt	C : \Users\User\source\repos\calc_Chat_Gpt\calc_Chat_Gpt\List.c	27

void db_insert(list* lst, int index, char* data) {
    // создадим указатель переменной элемента списка, 
    // и присвоим ему значение указателя на первый элемент списка
    list_item* base = lst->head;

    // создадим указатель переменной на новый элемент и выделим под него память
    list_item* new_item = (list_item*)malloc(sizeof(list_item));

    // выделим память внутри самого элемента структуры куда принимаем данные,
    // и получим указатель на него,
    // strlen() нужен, чтобы выделенная память была равна длинне полученной строки.
    new_item->data = malloc(sizeof(char) * strlen(data));
    strcpy(new_item->data, data); // копируем туда данные

    // Пришла пора решить куда мы определим элемент,
    // т.к. у нас еще нет элементов, lst->head вернет нам NULL.
    // Следовательно нужно условие, при создании первого элемента списка.
    if (base == NULL) {
        // Этот элемент единственный, а значит его указатели будут NULL.
        new_item->next = NULL;
        new_item->prev = NULL;

        // При этом, он сам будет первым и последним в списке.
        lst->head = new_item;
        lst->tail = new_item;
        lst->count++; // Увеличем кол-во на единицу
        return;
    }

    // Если индекс, который пришел будет меньше нуля, то будем вставлять в конец
    if (index < 0) {
        // голова теперь будет ссылаться на новый элм. впереди себя
        base->prev = new_item;
        new_item->prev = NULL;
        new_item->next = base; // а ссылка на след. элм. у нового будет на голову

        lst->head = new_item; // назначаем новый элемент головой
    }
    else { // тут все в обратном порядке
        base = lst->tail; // перейдем в хвост списка

    // пусть он теперь ссылаеться на новый элемент
        base->next = new_item;
        new_item->next = NULL; // Новый не будет иметь ссылки на следующий
        new_item->prev = base; // А предыдущий у него будет хвост списка

        lst->tail = new_item; // Назначаем новый элемент хвостом списка
    }
    lst->count++; // увеличим размер на единицу
}

char* db_read(list* lst, int index) {
    list_item* base = get_element(lst, index);
    if (base == NULL)
        return NULL;

    char* value = malloc(sizeof(char) * strlen(base->data)); // Выделяем память под строку
    strcpy(value, base->data); // копируем данные

    return value; // возвращаем полученное значение
}

int db_search(list* lst, char* data) {
    int i = 0; // организуем счетчик
    list_item* base = lst->head; // перейдем к первому элементу
    // воспользуемся функцией strcmp, чтобы сравнить перебираемые строки
    while (strcmp(base->data, data) != 0) {
        // пока строки не совпадут с тем что бы ищем, будем перебирать элементы
        base = base->next;
        i++;
    }
    return i; // получив совпадение просто вернем полученный индекс
}

list_item* get_element(list* lst, int index) {
    list_item* base;
    int middle = lst->count / 2; // Вычисляем середину списка

    if (index > middle) { // если индекс больше середины
        base = lst->tail;
        for (int i = lst->count; i > index; i--)
            base = base->prev;
    }
    else { // если индекс меньше середины
        base = lst->head;
        for (int i = 0; i < index; i++)
            base = base->next;
    }

    // Если элемента нет
    if (base == NULL) {
        printf("\033[3;31mError! The list item was not found...\n\033[0m");
        return NULL;
    }
    return base; // возвращаем элемент
}

void db_delete(list* lst, int index) {
    list_item* base = get_element(lst, index);
    list_item* prev, * next;

    if (base == NULL)
        return;

    prev = base->prev; // получение предыдущего элемента
    next = base->next; // мы получаем следующий элемент

    // переопределение указателя для предыдущего элемента на следующий
    if (prev != NULL)
        prev->next = base->next;

    // И тоже самое для предыдущего элемента
    if (next != NULL)
        next->prev = base->prev;

    free(base); // Освобождаем память 
    lst->count--; // уменьшаем длинну списка на единицу
}

void db_print(list* lst) {
    list_item* base = lst->head; // переходим к началу списка
    puts("\033[43m***Printing a list***\033[0m");

    if (lst->count == 0) { // если список пустой, так и говорим
        printf("The list is empty\n");
        return;
    }

    int i = 0; // организуем счетчик
    while (base != NULL) { // Пока все элементы не кончаться мы будем их перебирать
        printf("ID: %d || Data: %s\n", i, (char*)base->data); // выводя на экран
        base = base->next;
        i++;
    }
    // В конце покажем какой размер у нашего списка
    printf("Base size: %d\n", lst->count);
}
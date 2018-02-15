#ifndef SINGLELINKEDLISTLIB_LIBRARY_H
#define SINGLELINKEDLISTLIB_LIBRARY_H

/*
 * Структура элементов односвязного спписка
 * обЪявляем новый тип , что б не писсать структуру каждый раз
 */

typedef struct _Single_List_Node
{
    int value = 0 ;
    struct _Single_List_Node *adress ;
} Single_List_Node_t ;


/*
 * Создаем  структуру односвзяного списка
 * Храним разсер списка
 * Указатель на начало
 * указатель на конец
 */

typedef struct _Single_List
{
    /*
     * размер списка
     */

    int size ;

    /*
     * начало списка
     */

    Single_List_Node_t *head ;

    /*
     * конец списка
     */

    Single_List_Node_t *tail ;

} Single_List_t ;

Single_List_t * create_Single_List ( void );

void Single_List_push( Single_List_t *St , int data );

int * Single_List_pop ( Single_List_t *St );

void Single_List_push_back ( Single_List_t *St , int data );

#endif
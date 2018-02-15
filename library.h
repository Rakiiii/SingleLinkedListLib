#ifndef SINGLELINKEDLISTLIB_LIBRARY_H
#define SINGLELINKEDLISTLIB_LIBRARY_H

/*
 * структура описываюшая информацию об автобусах
 */

typedef  struct _Bus
{
    int bus_number ;
    char bus_driver[32] ;
    int bus_position ;
    int road_number ;
} Bus_t ;

/*
 * Структура элементов односвязного спписка
 * обЪявляем новый тип , что б не писсать структуру каждый раз
 */

typedef struct _Single_List_Node
{
    Bus_t value = 0 ;
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

void Single_List_push( Single_List_t *St , Bus_t data );

Bus_t * Single_List_pop ( Single_List_t *St );

void Single_List_push_back ( Single_List_t *St , Bus_t data );

Single_List_Node_t * Single_List_get_prevlast ( Single_List_t *St );

Bus_t * Single_List_pop_back ( Single_List_t *St );

void Single_List_push_nth ( Single_List_t *St , int position , Bus_t data );

Bus_t * Single_List_pop_nth ( Single_List_t *St , int position );

#endif
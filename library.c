#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <windef.h>

/*
 * St - будет обозначать массив
 * все новые типы данных обозначаются через _t в конце
 */

/*
 * Функция инициализации массива
 * возвращает указатель на массив
 */

Single_List_t * create_Single_List ( void )
{
    /*
     * выделяем память
     */

    Single_List_t *St = ( Single_List_t *  )malloc(sizeof( Single_List_t ) ) ;

    /*
     * инициализируем элемекнты массива
     */

    St->size = 0 ;
    St->head = NULL ;
    St->tail = St->head ;

    /*
     * возвращаем указатель
     */

    return St ;
}

/*
 * добовлдяем функциию для добовления элемента в начало односвязного списка
 */

void Single_List_push( Single_List_t *St , Bus_t data )
{
    /*
     * выделяем памать под новый элемент списка
     */

    Single_List_Node_t *node = ( Single_List_Node_t * )malloc(sizeof( Single_List_Node_t ) ) ;

    /*
     * передаем в элемент какое-то значение
     * передаем в адрес элемента адрес начла списка
     */

    node->value = data ;
    node->adress = St->head ;

    /*
     * Двигаем начало списка на место нового элемента
     * увеличиваем размер на 1
     */

    St->head = node ;
    St->size ++ ;

}

/*
 * добовляем функцию извлечения элемента из начала списка
 */

Bus_t * Single_List_pop ( Single_List_t *St )
{
    /*
     * проверяем размер списка
     * если пуст возвращаем нулевой указатель
     */

    if ( St->size == 0 ) return NULL ;

    /*
     * создаем новый элемент списка с адресом начала
     */

    Single_List_Node_t *node = St->head ;

    /*
     * извлекаем значение элемента по этому адресу
     */

    Bus_t * value = node->value ;

    /*
     * уменьшаем размер списка
     * двигаем начало списка на адрес элемента
     */

    St->size -- ;
    St->head = node->adress ;

    /*
     * освобождаем место занимаемое извлекаемым элементом
     */

    free( node ) ;

    /*
     * Проверяем список на пустоту
     * если список пустой обнуляем значение конца и начала
     */

    if ( St->size == 0)
    {
        St->head = NULL ;
        St->tail = Null ;
    }

    /*
     * Возвращаем значение извлеченного элемента
     */

    return value ;
}

/*
 * добовляем функцию добовления элемента в конец списка
 */

void Single_List_push_back ( Single_List_t *St , Bus_t data )
{
    /*
     * выделяем память под новый элемент
     */

    Single_List_Node_t *node = (Single_List_Node_t *) malloc(sizeof(Single_List_Node_t));

    /*
     * передаем значение в список
     */

    node->value = data;

    /*
     * проверяем список на пустоту,если не пуст то прписываем с конца
     * если пуст делаем его первым элементом
     */

    if (St->tail != NULL) St->tail->adress = node;
    else St->head = node;

    /*
     * двигаем конец списка на новый элемент
     * инкрементируем длинну списка
     */

    St->tail = node;
    St->size++;
}

/*
 * функция получения n-го элемента
 */

Single_List_Node_t * Single_List_get_prevlast ( Single_List_t *St )
{
    Single_List_Node_t *node ;
     node = St->head ;

    if ( node->adress == NULL ) return NULL ;

    while ( node->adress->adress ) node = node->adress ;

    return node ;
}

/*
 * функция получения последнего элемента
 */

Bus_t * Single_List_pop_back ( Single_List_t *St )
{

    /*
     * создаем указатель на необходимый узел
     */

    Single_List_Node_t * node ;
    node = St->tail ;

    /*
     * создаем указатель на возвращаемое значение
     */

    Bus_t *value ;
    value = node->value ;

    /*
     *получаем предпоследний элемент
     * делаем его последним
     */

    Single_List_Node_t *prevlast ;
    prevlast = Single_List_get_prevlast( St ) ;
    prevlast->adress = NULL ;
    St->tail = prevlast ;

    /*
     * освобождаем место занимаемое последним элементом
     * дискрементируем размер массива
     * возвращаем значение
     */

    free ( node ) ;

    St->size -- ;

    return value ;
}

/*
 * функция добавление элемента на n-ое место
 */

void Single_List_push_nth ( Single_List_t *St , int position , Bus_t data )
{
    /*
     * создаем указатель на новый элемент
     * создаем счетчик
     * создаем укащатель на для движения по списку
     */

    Single_List_Node_t *node ;
    int i = 0 ;
    Single_List_Node_t *snode ;
    snode = St->head ;

    /*
     * идем до нужного элемента
     */

    while ( i < position && snode->adress )
    {
        snode = snode->adress ;
        i ++ ;
    }

    /*
     * выделяем место под новый элемент списка
     * передвем новому элементу необходимое значение
     */

    node = ( Single_List_Node_t * )malloc( sizeof( Single_List_Node_t ) ) ;
    node->value = data ;

    /*
     * если элемент не последний то добовляем адрес следующего элемента
     * если последний меняем адрес последнего на адрес нового элемента списка
     */

    if ( snode->adress ) node->adress = snode->adress ;
    else
    {
        node->adress = NULL ;
        St->tail = node ;
    }

    /*
     * меняем адрес следующего элемента у предшествующего
     * инкрементируем размер списка
     */

    snode->adress = node ;
    St->size ++ ;
}

/*
 *получение n-го элемента списка
 */

Bus_t * Single_List_pop_nth ( Single_List_t *St , int position )
{
    /*
     * создаем указатель для поискового узла
     * создаем счетчик
     * создаем указатель для возврата значения
     */

    Single_List_Node_t *node ;
    node = St->head ;
    int i = 0 ;
    Bus_t *value ;

    /*
     * ищем позицию для извлечения
     */

    while ( i < position-1 && node->adress )
    {
        i ++ ;
        node = node->adress ;
    }

    /*
     * двигаем указатель предшествующего элемента
     */

    node->adress = node->adress->adress ;

    /*
     * проверяем не является ли удаляемый узел последним
     */

     if ( node->adress->adress == NUll ) St->tail = node ;

    /*
     * двигаемся на удаляемы узел
     * передаем значени для возврата
     */

    node = node->adress ;
    value = node->value ;

    /*
     * освобождаем место занимаемое узлом
     * возвращаем значение
     */

    free( node ) ;
    return value ;
}
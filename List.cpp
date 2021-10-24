//
// Created by PC on 24.10.2021.
//

#include "List.h"
using namespace Prog1;
void List::append( const Point &new_point ) {
    // Создаём новый узел для значения
    // Если произойдёт исключение, контейнер не пострадает
    Node* node = new Node( new_point );
    // Новый узел привязывается к старому головному элементу
    node->next = m_head;
    // Новый узел сам становится головным элементом
    m_head = node;
    cur_size += 1;
}

void List::remove() {
    if( m_head ) { // Если список не пуст:
        Node* newHead = m_head->next; // Сохраняем указатель на второй узел, который станет новым головным элементом
        delete m_head; // Освобождаем память, выделенную для удаляемого головного элемента
        m_head = newHead; // Назначаем новый головной элемент
        cur_size -= 1;
    }
}

List * List::coordinates() const{
    List *answer = new List;
    /* вычисления */
    return answer;
}

List &List::operator =(const List &st)
{
    if (this != &st){
        int cur_size = st.cur_size;
        while( m_head ) remove(); // удаляем старый список
        Node *tmp = st.m_head;
        while (tmp){
            this->append(tmp->point);
            tmp = tmp->next;
        }
    }
    return *this;
}

List &List::operator =(List &&st)
{
    int tmp = cur_size;
    cur_size = st.cur_size;
    st.cur_size = tmp;
    Node *ptr = this->m_head;
    m_head = st.m_head;
    st.m_head = ptr;
    return *this;
}
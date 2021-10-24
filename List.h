//
// Created by PC on 24.10.2021.
//

#ifndef KS_LIST_H
#define KS_LIST_H
namespace Prog1 {
    struct Point {
        float vector[3];
        Point()
        {
            for (int i = 0; i < 3; i ++) vector[i] = 0;
        }
        Point( int x, int y, int z)
        {
            vector[0] = x;
            vector[1] = y;
            vector[2] = z;
        }
    };

    class List {
    private:
        struct Node;
        int cur_size; // длина списка
        Node *m_head; // голова односвязного списка

    public:
        List(): m_head(nullptr), cur_size(0) {};
        ~List() { while( m_head ) remove(); }

        List &operator =(const List &);
        List &operator =(List &&);

        void append(const Point &new_point); // добавление элемента в список
        void remove(); // удаление элемента из списка
        Node *head() const {return m_head;} // получаем ссылку на голову списка
        List *coordinates() const;

    private:
        // Структура узла односвязного списка
        struct Node {
            Node() : next(nullptr) {}
            Node(const Point &new_point) : point(new_point), next(nullptr) {}

            Point point; // Значение узла
            Node *next; // Указатель на следующий узел
        };
    };
}

#endif //KS_LIST_H

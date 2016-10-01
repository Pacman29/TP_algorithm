/*
 * Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды
 * push* и pop*. Формат входных данных. В первой строке количество команд n. n ≤ 1000000.
 * Каждая команда задаётся как 2 целых числа: a b.
 * a = 1 ­ push front
 * a = 2 ­ pop front
 * a = 3 ­ push back
 * a = 4 ­ pop back
 * Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
 * Если дана команда pop*, то число b ­ ожидаемое значение.Если команда pop вызвана для пустой структуры
 * данных, то ожидается “­1”.
 * Формат выходных данных.
 * Требуется напечатать YES ­ если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не
 * оправдалось, то напечатать NO.
 * 4_1. ​Реализовать очередь с динамическим зацикленным буфером.
 */

#include <cstdio>
#include <cstdlib>

template<typename T>
class Queue
{

public:
    Queue(size_t buffer = 1000000)
    {
        this->_buffer = buffer;
        this->arr = (T*)malloc(this->_buffer*sizeof(T));
        for(size_t i = 0; i<this->_buffer; ++i)
            this->arr[i] = 0;
        this->head = this->tail = 0;
    }

    ~Queue()
    {
        free(this->arr);
    }

    void push(T* value)
    {
        this->arr[this->head++] = *value;
        if(!(this->head % this->_buffer))
            this->head = 0;
    }

    int pop(T* value)
    {
        if(this->head == this->tail)
            return -1;
        *value = this->arr[this->tail++];
        if(!(this->tail % this->_buffer))
            this->tail = 0;
        return 0;
    }

private:

    size_t _buffer;
    T* arr;
    size_t head;
    size_t tail;
};

bool check(void)
{
    Queue<int> q;
    size_t n = 0;
    if(scanf("%ld",&n) != 1)
        return -1;
    bool flag = true;
    for(size_t i = 0;flag && i<n;++i)
    {
        int com = 0, value = 0;
        if(scanf("%d %d",&com,&value) !=2)
            continue;
        switch (com) {
        case 3:
        {
            q.push(&value);
            break;
        }
        case 2:
        {
            int tmp = 0;
            if(value == -1)
            {
                if(value != q.pop(&tmp))
                    flag = false;
            }
            else
            {
                if(q.pop(&tmp) == -1)
                {
                    flag = false;
                    break;
                }
                if(value != tmp)
                    flag = false;
            }
            break;
        }
        default:
            break;
        }
    }
    return flag;
}

int main(void)
{
    printf("%s",(check())?("YES"):("NO"));
    return 0;
}

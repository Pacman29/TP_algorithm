//5_1. Скобочная последовательность.
//Дан фрагмент последовательности скобок, состоящей из символов (){}[].
//Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную
//последовательность.
//Длина исходной последовательности ≤ 200000.
//Формат входных данных. Строка, содержащая символы (){}[] и, возможно, перевод строки.
//Формат выходных данных. Если возможно ­ вывести минимальную корректную последовательность, иначе ­
//напечатать "IMPOSSIBLE​".

#include <cstdlib>
#include <cstdio>
#include <cstring>
#define STR_SIZE 200000
template<typename T>
class Stack
{
public:
    Stack()
    {
        this->head = NULL;
    }

    void push(T& value)
    {
        this->head = init_container(value,this->head);
    }

    int pop(T& value)
    {
        if(!this->head)
            return 0;

        value = this->head->value;
        type_container *tmp_ptr = this->head->ptr;
        free(this->head);
        this->head = tmp_ptr;
        return 1;
    }

    bool isEmpty(void)
    {
        return this->head == NULL;
    }

    ~Stack()
    {
        while(this->head)
        {
            type_container* tmp_ptr = this->head;
            this->head = this->head->ptr;
            free(tmp_ptr);
        }
    }

private:
    typedef struct TYPE_C{
        struct TYPE_C* ptr;
        T value;
    } type_container;

    type_container* init_container(T& value, type_container* next)
    {
        type_container *tmp = (type_container*)malloc(sizeof(type_container));
        tmp->ptr = next;
        tmp->value = value;
        return tmp;
    }

    type_container* head;
};

void  check(char* str, size_t str_len)
{
    bool flag = true;
    Stack<char> before;
    Stack<char> after;
    char tmp = 0;
    for(size_t i = 0; i<str_len && flag;++i)
    {
        char tmp_symb = str[i];
        if(tmp_symb == '(' || tmp_symb == '[' || tmp_symb == '{')
            after.push(tmp_symb);
        if(tmp_symb == ')' || tmp_symb == ']' || tmp_symb == '}')
        {
            if(after.isEmpty())
                before.push(tmp_symb);
            else
            {
                after.pop(tmp);
                if((tmp_symb == ')' && tmp != '(') ||
                   (tmp_symb == ']' && tmp != '[') ||
                   (tmp_symb == '}' && tmp != '{') )
                    flag = false;
            }
        }

    }
    if(flag)
    {
        while (before.pop(tmp))
        {
            switch (tmp) {
            case ']':
                tmp = '[';
                break;
            case ')':
                tmp = '(';
                break;
            case '}':
                tmp = '{';
                break;
            }
            printf("%c",tmp);
        }
        printf("%s",str);
        while (after.pop(tmp))
        {
            switch (tmp) {
            case '[':
                tmp = ']';
                break;
            case '(':
                tmp = ')';
                break;
            case '{':
                tmp = '}';
                break;
            }
            printf("%c",tmp);
        }

    }
    else
        printf("IMPOSSIBLE");
}

int main(void)
{
    char* str = (char*)malloc(STR_SIZE*sizeof(char));
    if(!str)
        return 1;
    if(!scanf("%s",str))
        return 1;
    check(str,strlen(str));
    return 0;
}

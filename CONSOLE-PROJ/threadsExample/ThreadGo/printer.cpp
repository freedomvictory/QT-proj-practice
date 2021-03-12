#include "printer.h"


#include <QDebug>



void Printer::doWork(QVector<char> words)
{
    __mutex.lock();
    for(auto val : words)
    {
        printf("%c", val);
    }
    printf("\n");
    __mutex.unlock();
}


void Thread_a::run()
{
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    QVector<char> words;
    for(auto c : letters)
        words.append(c);

    __printer->doWork(words);


}

void Thread_b::run()
{
    char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    QVector<char> words;
    for(auto c : nums)
        words.append(c);

    __printer->doWork(words);

}

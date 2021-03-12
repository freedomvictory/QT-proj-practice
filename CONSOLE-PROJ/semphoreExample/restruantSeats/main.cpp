#include <QCoreApplication>
#include <QThread>
#include <QSemaphore>
#include <QTimer>
#include <QDebug>

/*模拟餐厅：有人进餐厅，有人出餐厅。餐厅里的座位的数量变化*/
/*使用 信号量*/

const int totalSeatsNum = 32;
QSemaphore leftseatsNum(totalSeatsNum);





class GoRestruant : public QThread
{

protected:
    void run()override
    {
        while(true)
        {
            //TODO:
            /* 1. generate rand number(1 - 8),simulate some people
             * go to the restruant
             * 2. request resources(seats)
             * 3. show the total number of people in the restruant
             * And Remain seats
             * 4. sleep
             */
            int n = 1 + qrand() % 7;
            leftseatsNum.acquire(n);
            int leftseates = leftseatsNum.available();
            qDebug() << n << " people go restruant, remain seats:"
                     << leftseates << ", left people:"
                     << (32 - leftseates);
            sleep((3 + qrand() % 5));
        }


    }

private slots:

public:
    ~GoRestruant()
    {
        this->quit();
        this->wait();
    }

};

class OutRestruant : public QThread
{
protected:
    void run() override
    {
        for(;;)
        {
            int leftseats = leftseatsNum.available();
            int leftpeople = 32 - leftseats;
            if(leftpeople > 0)
            {
                // 1 ~ leftpeople
                int outPeople = qrand() % leftpeople + 1;
                leftseatsNum.release(outPeople);
                leftseats = leftseatsNum.available();
                qDebug() << outPeople << " out restruant, reamin seats:"
                         << leftseats << ", left people:"
                         << (32 - leftseats);
            }
            sleep((3 + qrand() % 5));

        }

    }

};














int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GoRestruant goThread;
    OutRestruant outThread;

    goThread.start();
    outThread.start();

    return a.exec();
}

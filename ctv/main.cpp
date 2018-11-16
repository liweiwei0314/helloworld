#include <QCoreApplication>
#include<QThread>
#include <algorithm>
#include<QDebug>
#define N 5
int b[N];

class workthread:public QThread{
  protected:
    void run(){
        int base = *p_val, tmp = 0;
        int *p_head = p_val, *p_tail = p_val + size - 1;
            if (size <= 1) {
                return ;
            }
            while (p_head < p_tail) {
                //调整选定数字和另一端数字的顺序
                if (*p_head > *p_tail) {
                    tmp = *p_head;
                    *p_head = *p_tail;
                    *p_tail = tmp;
                }
                //把非选定数字排除在外
                if (base == *p_head) {
                    //非选定数字在后
                    p_tail--;
                }
                else {
                    //非选定数字在前
                    p_head++;
                }
            }
          //递归调用对左
          workthread*  T1 = new workthread(p_val, p_head - p_val);
          //递归调用对右
          workthread*  T2 = new workthread(p_head + 1, size - (p_head - p_val) - 1);
          T1->start();
          T2->start();

          T1->wait();
          T2->wait();
    }
public:
    workthread(int* c,int d):p_val(c),size(d){}
    ~workthread(){
    }
private:
    int* p_val;
    int size;

};
int main(int argc, char *argv[])
{
    srand(time(NULL));
        for(int i=0; i<N;i++)
        {
            b[i] = rand()%N;
            qDebug("%d ",b[i]);
        }
    workthread* aac = new workthread(b,N);
    aac->start();
    qDebug()<<"--------";
    for(int i=0;i<N;i++){
        qDebug()<<b[i];
    }
    aac->wait();
    return 0;
}

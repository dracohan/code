//http://blog.csdn.net/taolinke/article/details/6295903
# include <stdio.h>
# include <unistd.h> //for sleep()


int main( void )
{
    printf ( "/nstart the dead loop/n" ) ;
    while ( 1)
    {
        printf ( "/b->" ) ;
        fflush ( stdout ) ; //刷新输出缓冲区，如果不做这个动作，上边的输出便不会显示到屏幕上，除非其中有换行操作或者缓冲区，这也许就是所谓到终端行规程吧。

        usleep ( 100000) ;
    }
    return 1;
}	
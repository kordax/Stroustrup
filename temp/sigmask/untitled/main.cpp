#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int done = 0;

// Обработчик сигналов
void handler(int sig)
{
// Ref signal(2) — функция write() безопасна, а printf() — нет.
const char *str = "handled...\n";
write(1, str, strlen(str));
done = 1;
}

void child(void)
{
// Дочерний процесс завершается незамедлительно и посылает
// родительскому процессу сигнал SIGCHLD

printf("дочерний процесс завершается\n");
exit(0);
}

int main(int argc, char *argv[])
{

// Осуществить обработку сигнала SIGCHLD, когда дочерний процесс
// завершится.

signal(SIGCHLD, handler);

sigset_t newset, oldset;


// Определить все сигналы в наборе

sigfillset(&newset);


// Блокировать все сигналы и сохранить старую маску сигналов,

// чтобы ее можно было восстановить позднее

sigprocmask(SIG_BLOCK, &newset, &oldset);
pid_t pid = fork();
if (pid == 0)
child();
printf("родительский процесс ""засыпает""\n");
// Погрузиться в "спячку" с блокировкой всех сигналов.
int r = sleep(3);
// r == 0 указывает на то, что "спячка" длилась полный период.
printf("пробуждение! r=%d\n", r);
// Восстановить старую маску сигналов,
// что приведет к вызову нашего обработчика сигналов.
sigprocmask(SIG_SETMASK, &oldset, NULL);
// Дождаться запуска обработчика сигналов.
while (!done) {
};
printf("завершение\n");
exit(0);
}

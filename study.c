thread - executada pelo sistema operativo, permite executar varias tarefas em simultaneo

pthread_create - cria uma nova thread, recebe como argumentos o ponteiro para a thread, os atributos da thread, a funcao que a thread vai executar e os argumentos dessa funcao 

pthread_join - espera que a thread termine a sua execucao

start_simulation - cria as threads dos filosofos e espera que terminem

end_simulation - destroi os mutexes e liberta a memoria alocada

routine - verifica sempre se algum filosofo morreu, executa a rotina

exec_routine - verifica se os garfos estao disponiveis
                da lock ao estado do philo para nao haver alteraçoes e atualiza o tempo
                coloca os garfos disponiveis novamente depois do philo comer
                depois mete o philo a dormir


start_eating - responsavel por fazer comer o philo
                atualiza o tempo e o tempo de comer
                da lock ao estado do philo para nao haver alteraçoes
                incrementa o numero de refeiçoes
                se o philo morrer retorna 1

start_sleeping - responsavel por fazer dormir o philo
                atualiza o tempo e o tempo de dormir
                se o philo morrer retorna 1


# include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb){
    Queue result;
    CreateQueue(&result);

    while (IDX_HEAD(queue) != IDX_TAIL(queue)){
        ElType val;
        dequeue(&queue, &val);
        if (val != bomb){
            enqueue(&result, val);
        }
    }
    return result;
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/

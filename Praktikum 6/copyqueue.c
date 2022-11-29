# include "copyqueue.h"
# include <stdio.h>

void copyQueue(Queue *queueInput, Queue *queueOutput){
    Queue temp;
    CreateQueue(&temp);
    while (IDX_HEAD(*queueInput) != IDX_UNDEF && IDX_TAIL(*queueInput) != IDX_UNDEF){
        ElType val;
        dequeue(queueInput, &val);
        enqueue(&temp, val);
    }
    while (IDX_HEAD(temp) != IDX_UNDEF && IDX_TAIL(temp) != IDX_UNDEF){
        ElType val;
        dequeue(&temp, &val);
        enqueue(queueInput, val);
        enqueue(queueOutput, val);
    }
}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/
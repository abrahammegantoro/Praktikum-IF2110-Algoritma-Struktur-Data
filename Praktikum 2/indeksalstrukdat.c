# include <stdio.h>

int main(){
    int score, lulus = 0, mahasiswa = 0, total = 0;
    float avg;
    scanf("%d",&score);
    while (score != -999){
        if (score >= 0 && score <= 4){
            if (score >= 3){
                lulus++;
            }
            total += score;
            mahasiswa++;
        }
        
        scanf("%d",&score);
    }
    
    avg = (float)total/(float)mahasiswa;
    if(mahasiswa == 0){
        printf("Tidak ada data\n");
    } else {
        printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
        printf("Nilai rata-rata = %.2f\n", avg);
        if (avg >= 0 && avg < 1){
            printf("Indeks akhir kelas = E\n");
        }
        else if (avg >= 1 && avg < 2){
            printf("Indeks akhir kelas = D\n");
        }
        else if (avg >= 2 && avg < 3){
            printf("Indeks akhir kelas = C\n");
        }
        else if (avg >= 3 && avg < 4){
            printf("Indeks akhir kelas = B\n");
        } 
        else if (avg == 4){
            printf("Indeks akhir kelas = A\n");
        }
    }
    return 0;
}
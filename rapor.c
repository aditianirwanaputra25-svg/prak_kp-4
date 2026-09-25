#include <stdio.h>

#define MAKS_MAHASISWA 5
#define JUMLAH_MK 3

void inputData(char nama[][30], int nilai[][JUMLAH_MK], int jumlah);
float hitungRataRata(int nilai[][JUMLAH_MK], int index);
void tampilkanRapor(
    char nama[][30],
    int nilai[][JUMLAH_MK],
    float rataRata[],
    int jumlah
);


int main() {
    printf("SISTEM RAPOT DIGITAL\n");
    char nama[MAKS_MAHASISWA][30];
    int nilai[MAKS_MAHASISWA][JUMLAH_MK];
    float rataRata[MAKS_MAHASISWA];
    int jumlah, i;
    
    printf("\n===================================================\n");
    printf(" RAPOR DIGITAL\n");
    printf("===================================================\n");

    printf("Jumlah mahasiswa (1-%d): ", MAKS_MAHASISWA);
    scanf("%d", &jumlah);
    
    if (jumlah < 1 || jumlah > MAKS_MAHASISWA) {
        printf("Jumlah mahasiswa tidak valid!\n");
        return 0;
    }
    
    inputData(nama, nilai, jumlah);

    for (i = 0; i < jumlah; i++) {
        rataRata[i] = hitungRataRata(nilai, i);
    }

    tampilkanRapor(nama, nilai, rataRata, jumlah);
    
    return 0;
}

void inputData(char nama[][30], int nilai[][JUMLAH_MK], int jumlah) {
    int i, j;
    
    for (i = 0; i < jumlah; i++) {
            printf("\nMahasiswa ke-%d\n", i + 1);
            printf("Nama        : ");
            scanf("%29s", nama[i]);
    
            for (j = 0; j < JUMLAH_MK; j++) {
                if (j == 0) {
                    printf("Nilai Algoritma     : ");
                } else if (j == 1) {
                    printf("Nilai Pemrograman   : ");
                } else {
                    printf("Nilai Basis Data    : ");
                }
                scanf("%d", &nilai[i][j]);
            }
            
    }
}   
    
    float hitungRataRata(int nilai[][JUMLAH_MK], int index) {
        int j, total = 0;
        
        for (j = 0; j < JUMLAH_MK; j++) {
        total += nilai[index][j];
        }
        
        return (float) total / JUMLAH_MK;
    }



    char tentukanGrade(float rata) {
        if (rata >= 90) return 'A';
        else if (rata >= 80) return 'B';
        else if (rata >= 70) return 'C';
        else if (rata >= 60) return 'D';
        else return 'E';
    }

    void tampilkanRapor(
        char nama[][30],
        int nilai[][JUMLAH_MK],
        float rataRata[],
        int jumlah
    ) {
        int i, j;
        printf("\n===================================================\n");
        printf(" RAPOR DIGITAL\n");
        printf("===================================================\n");
        
        printf("%-15s%-8s%-8s%-8s%-10s%-7s%-s\n",
            "Nama", "Alg", "Prog", "BD", "Rata-rata", "Grade", "Status");
        printf("---------------------------------------------------\n");
        for (i = 0; i < jumlah; i++) {
            printf("%-15s", nama[i]);
        
            for (j = 0; j < JUMLAH_MK; j++) {
                printf("%-8d", nilai[i][j]);
            }
            printf("%-10.2f%-7c", rataRata[i], tentukanGrade(rataRata[i]));
        
            if (rataRata[i] >= 70) {
                printf("%s", "LULUS");
            } else {
                printf("%s", "TIDAK LULUS");
            }
                printf("\n");
        }
        printf("===================================================\n");
    }





    

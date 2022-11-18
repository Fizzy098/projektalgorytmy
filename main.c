#include <stdio.h>
#include <time.h>
#define ilosc 10

int wyszukiwaniedubli(int const *tablicawyjsciowa, int a, int b , int n){
    //sprawdza czy para zlozona z a i b jest w tablicy par
    int i;
    for(i = 0; i < n; i++){
        if(a == tablicawyjsciowa[i] && b == tablicawyjsciowa[i+1]){
            return 1; //juz taka para istnieje
        }
        if(a == tablicawyjsciowa[i+1] && b == tablicawyjsciowa[i]){
            return 1; //juz taka para istnieje
        }
    }
    return 0; //para nie istnieje
} //zabeczpieczenie przed dublami par

void pary(int const *tablica, int *tablicawyjsciowa, int n, int k){
    int i,j, b = 0;
    for (j = 0; j < n; j++) {//wyznaczenie liczby do ktorej bedziemy porownywac
        for (i = j; i < n; i++) {//wyznaczenie liczby porywnywalnej
            if (tablica[j] - tablica[i] == k || tablica[j] - tablica[i] == (-k)) {

                if (wyszukiwaniedubli(tablicawyjsciowa, tablica[j], tablica[i], n) == 0) {
                    //zabezpieczenie przed dublami.jesli juz taka para istnieje zwroci 1  nie wpisze pary do tablicy
                    tablicawyjsciowa[b] = tablica[j];

                        tablicawyjsciowa[b+1] = tablica[i];
                    b += 2;//zaczyna pary co 2

                }
            }
        }
    }
   printf("\nPary: ");
    if(b == 0){
        puts("brak!");
    }
    else{
    for (i = 0; i < b; i += 2) {
        printf("[%d %d]", tablicawyjsciowa[i], tablicawyjsciowa[i + 1]);
        }//wypisanie par
    }
} // wywolanie funkcji, sprawdza po kolei czy kolejna liczba jest od niej mniejsza o k

int main() {
    int k; //roznica miedzy liczbami
    int tablicaliczb[ilosc]; //tablica danych wejscia
    int n = 0; //ilosc liczb w tablicy danych
    int tablicapar[ilosc]; //tablica danych wyjscia (z parami)
    int petla = 0; //do wpisywamnia liczb


    printf("Podaj k:");
    scanf("%d", &k);  //roznica miedzy liczbami
    printf("Podaj liczby, oddziel je spacja a zakoncz enterem: ");

        while(petla != 10) {
            scanf("%d",&tablicaliczb[n]); //wpisywanie liczb
            n++;
            petla = getchar(); //jesli wcisniemy enter zakonczy sie petla
        }

        pary(tablicaliczb,tablicapar,n,k); //wywolanie fukncji
    return 0;

}


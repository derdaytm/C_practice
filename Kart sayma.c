#include <stdlib.h> 
#include <stdio.h>

void kartsayma () ;
void olasilikhesap (int []) ;

int main () {
    int program_akis_kontrol ;

    while ( 1 ) {
        printf ( "Programı kapamak için 0 tuşlayınız.\n" ) ;
        printf ( "Yeni deste için 1 tuşlayınız.\n" ) ;
            scanf ( "%d", &program_akis_kontrol ) ;

        if ( program_akis_kontrol == 0 ) {
            break ; }

        if ( program_akis_kontrol == 1 ) {
            kartsayma () ;  }   }

    return 0 ;  }

void kartsayma () {
    int tuslama, yardimcituslama, dongo_kontrol = 0 ;
    int dizi [ 10 ] = { 32, 32, 32, 32, 32, 32, 32, 32, 32, 128 } ;

    while ( 1 ) {
        printf ( "Çıkmak için 0 tuşlayınız.\n" ) ;
        printf ( "Yeni el için 1 tuşlayınız.\n" ) ;
        printf ( "Olasılık hesap için 11 tuşlayınız.\n" ) ;
            scanf( "%d", &yardimcituslama ) ;

        if ( yardimcituslama == 1 ) {
            while ( dongo_kontrol != 1 ) {
                printf ( "Krupiyer ve sizin elinizdeki kartların puanlarını giriniz : " ) ;
                    scanf ( "%d", &tuslama ) ;

                switch ( tuslama ) {
                    case 1 : 
                        dizi [0]-- ; 
                        break ; 
                    case 2 : 
                        dizi [1]-- ;
                        break ;
                    case 3 : 
                        dizi [2]-- ;
                        break ;  
                    case 4 : 
                        dizi [3]-- ; 
                        break ;
                    case 5 : 
                        dizi [4]-- ; 
                        break ;
                    case 6 : 
                        dizi [5]-- ; 
                        break ;
                    case 7 : 
                        dizi [6]-- ; 
                        break ;
                    case 8 : 
                        dizi [7]-- ; 
                        break ;
                    case 9 : 
                        dizi [8]-- ; 
                        break ;
                    case 10 : 
                        dizi [9]-- ; 
                        break ;
                    case 11 :
                        dongo_kontrol = 1 ;
                        olasilikhesap ( dizi ) ; 
                        break;
                    default :
                        printf ( "Geçersiz değer!\n" ) ;  }   }

            dongo_kontrol = 0 ; }

        if ( yardimcituslama == 0 ) {
            break ; }   }   }

void olasilikhesap ( int dizi [10] ) {
    int eldekikart, yardimci, toplam1 = 0, toplam2 = -1 ;

    printf ( "Elinizdeki kart değerini giriniz : " ) ;
        scanf ( "%d", &eldekikart ) ;
    
    yardimci = 21 - eldekikart ;

    for (int sayim = 0 ; yardimci > sayim ; sayim++) {
        toplam1 = dizi [sayim] + toplam1 ;  }

    for (int sayim = 9 ; yardimci <= sayim ; sayim--) {
        toplam2 = dizi [sayim] + toplam2 ;  }

    printf ( "Olumlu kart sayısı = %d \n", toplam1 ) ;
    printf ( "Olumsuz kart sayısı = %d \n", toplam2 ) ;
    printf ( "Kalan 10 sayısı : %d \n", dizi [9] ); }

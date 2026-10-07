#include <stdio.h>

int main() {
    float total_purchases, discount = 0.0, discounted_total, sales_tax, total;
    char is_student;

    // Meminta input dari pengguna
    printf("Masukkan total pembelian: ");
    scanf("%f", &total_purchases);
    printf("Apakah pembeli seorang pelajar? (y/n): ");
    scanf(" %c", &is_student);

    // Menghitung diskon jika pembeli adalah pelajar
    if (is_student == 'y' || is_student == 'Y') {
        discount = total_purchases * 0.20;
    }

    // Melakukan perhitungan dasar
    discounted_total = total_purchases - discount;
    sales_tax = discounted_total * 0.05;
    total = discounted_total + sales_tax;

    // Menampilkan output sesuai dengan format pada soal
    printf("\n");
    if (is_student == 'y' || is_student == 'Y') {
        printf("Total purchases               $%6.2f\n", total_purchases);
        printf("Student's discount (20%%)       %6.2f\n", discount);
        printf("Discounted total               %6.2f\n", discounted_total);
        printf("Sales tax (5%%)                 %6.2f\n", sales_tax);
        printf("Total                         $%6.2f\n", total);
    } else {
        printf("Total purchases               $ %5.2f\n", total_purchases);
        printf("Sales tax (5%%)                  %4.2f\n", sales_tax);
        printf("Total                         $ %5.2f\n", total);
    }

    return 0;
}

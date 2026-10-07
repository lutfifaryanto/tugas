#include <stdio.h>
#include <math.h>

int main() {
    int weekday_mins, night_mins, weekend_mins, total_mins, extra_mins = 0;
    int pretax_cents, tax_cents, total_cents, avg_cost_cents;
    
    // Konstanta dalam bentuk sen
    const int FLAT_RATE_CENTS = 3999;
    const int EXTRA_RATE_CENTS = 40;
    const double TAX_RATE = 0.0525;

    // Meminta input data penggunaan
    printf("Masukkan menit weekday (hari biasa): ");
    scanf("%d", &weekday_mins);
    printf("Masukkan menit malam (night): ");
    scanf("%d", &night_mins);
    printf("Masukkan menit akhir pekan (weekend): ");
    scanf("%d", &weekend_mins);

    // Menghitung tambahan menit weekday
    if (weekday_mins > 600) {
        extra_mins = weekday_mins - 600;
    }

    // Menghitung tagihan sebelum pajak (dalam sen)
    pretax_cents = FLAT_RATE_CENTS + (extra_mins * EXTRA_RATE_CENTS);
    total_mins = weekday_mins + night_mins + weekend_mins;

    // Menghitung rata-rata biaya per menit (dibulatkan dalam sen)
    if (total_mins > 0) {
        avg_cost_cents = (int)round((double)pretax_cents / total_mins);
    } else {
        avg_cost_cents = 0;
    }

    // Menghitung pajak dan total keseluruhan (dibulatkan dalam sen)
    tax_cents = (int)round(pretax_cents * TAX_RATE);
    total_cents = pretax_cents + tax_cents;

    // Menampilkan output (dibagi 100 untuk mengubah sen menjadi dolar)
    printf("\n--- Rincian Tagihan Chatflow Wireless ---\n");
    printf("Menit weekday digunakan   : %d\n", weekday_mins);
    printf("Menit malam digunakan     : %d\n", night_mins);
    printf("Menit akhir pekan digunaka: %d\n", weekend_mins);
    printf("Tagihan sebelum pajak     : $%.2f\n", pretax_cents / 100.0);
    printf("Rata-rata biaya per menit : $%.2f\n", avg_cost_cents / 100.0);
    printf("Pajak (5.25%%)             : $%.2f\n", tax_cents / 100.0);
    printf("Total Tagihan             : $%.2f\n", total_cents / 100.0);

    return 0;
}

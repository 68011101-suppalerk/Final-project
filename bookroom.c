#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "bookinglist.csv"

struct Booking {
    char name[50];
    char checkIn[20];
    char checkOut[20];
    char roomType[20];
};

// ฟังก์ชันตรวจสอบปีที่มี366วัน
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ฟังก์ชันตรวจสอบวันในเดือน
int isValidDate(int d, int m, int y) {
    if (y < 1900 || y > 2100) return 0; // กันปีผิดปกติ
    if (m < 1 || m > 12) return 0;
    if (d < 1) return 0;

    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) daysInMonth[2] = 29;

    return d <= daysInMonth[m];
}

// ฟังก์ชันรับวัน เดือน ปี ทีละค่า
void inputDate(char *output) {
    int d, m, y;
    do {
        printf("Enter Day: ");
        scanf("%d", &d);
        printf("Enter Month: ");
        scanf("%d", &m);
        printf("Enter Year: ");
        scanf("%d", &y);

        if (!isValidDate(d, m, y)) {
            printf(" Invalid date, please try again!\n");
        } else {
            break;
        }
    } while (1);

    sprintf(output, "%04d-%02d-%02d", y, m, d);
}

// ฟังก์ชันเพิ่มข้อมูล
void addBooking() {
    struct Booking b;
    FILE *fp = fopen(FILENAME, "a"); // append

    if (fp == NULL) {
        printf("Cannot open file!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", b.name);

    printf("\n--- Enter Check-in Date ---\n");
    inputDate(b.checkIn);

    printf("\n--- Enter Check-out Date ---\n");
    inputDate(b.checkOut);

    printf("Enter Room Type: ");
    scanf(" %[^\n]", b.roomType);

    fprintf(fp, "%s,%s,%s,%s\n", b.name, b.checkIn, b.checkOut, b.roomType);
    fclose(fp);

    printf("✅ Booking added successfully!\n");
}

// Menu
void menu() {
    int choice;
    while (1) {
        printf("\n--- Hotel Booking System ---\n");
        printf("1. Add Booking\n");
        printf("2. Show All Bookings\n");
        printf("3. Search Booking\n");
        printf("4. Delete Booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBooking(); break;
            case 2: readBookings(); break;
            case 3: searchBooking(); break;
            case 4: deleteBooking(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
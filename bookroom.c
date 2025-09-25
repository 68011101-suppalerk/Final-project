#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILENAME "bookinglist.csv"

struct Booking {
    char name[200];
    char checkIn[50];
    char checkOut[50];
    char roomType[30];
};

// ฟังก์ชันเพิ่มข้อมูล
void addBooking() {
    struct Booking b;
    FILE *fp = fopen(FILENAME, "a");

    if (fp == NULL) {
        printf("ไม่สามารถเปิดไฟล์ได้\n");
        return;
    }

    printf("กรอกชื่อ: ");
    scanf(" %[^\n]", b.name);
    printf("วันที่ Check-in (yyyy-mm-dd): ");
    scanf(" %[^\n]", b.checkIn);
    printf("วันที่ Check-out (yyyy-mm-dd): ");
    scanf(" %[^\n]", b.checkOut);
    printf("ประเภทห้อง: ");
    scanf(" %[^\n]", b.roomType);

    fprintf(fp, "%s,%s,%s,%s\n", b.name, b.checkIn, b.checkOut, b.roomType);
    fflush(fp);
    fclose(fp);
    printf("บันทึกข้อมูลเสร็จสิ้น!\n");
}


// เมนู
void menu() {
    int choice;
    while (1) {
        printf("--- กรุณาเลือกเมนูการเข้าจองห้องพัก ---\n");
        printf("1. เพิ่มข้อมูลการจอง\n");
        printf("2. แสดงข้อมูลทั้งหมด\n");
        printf("3. ค้นหาข้อมูลการจอง\n");
        printf("4. ลบข้อมูลการจอง\n");
        printf("5. ออกจากโปรแกรม\n");
        printf("เลือก: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                //readBookings();
                break;
            case 3:
                //searchBooking();
                break;
            case 4:
                //deleteBooking();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("เลือกไม่ถูกต้อง!\n");
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "th_TH.UTF-8");
    menu();
    return 0;
}

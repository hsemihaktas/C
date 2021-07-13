/*
 * Hasan Semih Aktaş
 * @since 5.01.2021
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char number[10];
    char name[40], surname[40];
    struct student *next;

}head = {"NUMBER", "NAME", "SURNAME", NULL}; /* head of the list */
struct student *temp = NULL;

int delete (FILE *f, char* no){ /*Numarası verilen öğrenciyi listeden silme fonksiyonu*/

    FILE *f2 = fopen("temp.txt","a+");
    int i = 0, counter = 0;
    struct student *before = NULL;
    struct student *after = NULL;
    struct student *temp = &head;
    while(temp->next != NULL){
        while(i < strlen(no) ){ /* Girilen ogrenci no'dan önceki kişiyi döndürüyor*/
            if(temp->next->number[i] == no[i]){ 
                counter++;
                i++;
            }
            else{
                break;
            }
        }
        if (counter == strlen(no)) break;
        counter = 0;
        i = 0;
        temp = temp->next;
    }
    char l[150];
    while (fgets(l, 150, f) != NULL){
        char search[10];
        strncpy(search,l,strlen(no));/*Ogrenci no satırın ilk basında oldugu icin girilen no'nun boyutu kadar karakteri bir degiskene atıyoruz*/
        if (strncmp(search, no, strlen(no)) == 0){ /*Girilen ogrenci no'daki kişinin dosyaya yazdırmamak için */
            continue;
        }
        else{
            fputs(l,f2);
        }
    }
    fclose(f);
    fclose(f2);
    remove("students.txt");
    if (rename("temp.txt","students.txt") == 0)
        printf("Islem basarili");

    if (temp->next == NULL && *(temp->next->number) == *no){
        free(temp);/*Mallocla alınan yerleri serbest bırakıyor*/
        temp = NULL;
    }
    else{
        before = temp; 
        after = temp->next->next;
        free(temp->next);
        before->next = after; /* Girilen no'yu kaldırmak için girilen no'dan önceki kişiden sonra girilen no'daki sonraki kişinin gelmesini saglıyor*/
    }
    return 1;
}
int add (FILE *f){ /*Listeye yeni bir öğrenci ekleme fonksiyonu*/
    if (f == NULL){
        return 0;
    }
    struct student *newStudent = (struct student*) malloc(sizeof(struct student));
    char newLine[100];
    printf ("Lutfen aralarinda tab kadar bosluk olacak sekilde ogrencinin numarasini,adini ve soyadini giriniz.\n");
    fflush(stdin);
    fgets (newLine, 100, stdin);
    fputs (newLine,f);
    char *number = strtok(newLine, "\t");
    char *name = strtok(NULL, "\t");
    char *surname = strtok (NULL, "\n");

    strncpy(newStudent->number, number, 10);
    strncpy(newStudent->name, name, 40);
    strncpy(newStudent->surname,surname, 40);
    newStudent->next = NULL;

    if (head.next == NULL){
        head.next = newStudent;
    }
    else {
        temp = &head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp ->next = newStudent;
    }
    return 1;
}


int read_students (FILE *f){ /*Dosyayı okumak fonksiyonu */
    if (f == NULL){
        return -1;
    }
    struct student *temp = &head;
    char l[150]; /*Satirdaki yazıları bir yere depolamak için */

    while(fgets(l, 150, f) != NULL){
        temp->next = (struct student *) malloc(sizeof(struct student));/*kayıtlı olan öğrenci icin bellek ayırır*/
        char *number = strtok(l, "\t");
        char *name = strtok(NULL, "\t");
        char *surname = strtok (NULL, "\n");
        if (number != NULL && name != NULL && surname != NULL){
            strncpy(temp->next->number, number, 10);
            strncpy(temp->next->name, name, 40);
            strncpy(temp->next->surname, surname, 40);
            temp = temp->next; 
        }
    }
    temp->next = NULL;/*Son elemanın next'inin olmadığını belirtir*/
    return 0;
}

void print_students(){ /*Kayıtlı olan öğrencileri ekrana yazdırma fonksiyonu */
    temp = head.next;
    if(temp != NULL){
		printf("Kayitli Ogrenci Listesi\n");
	}

    while(temp != NULL){
        printf("%.10s %10.40s %10.40s\n",temp->number, temp->name, temp->surname);
        temp = temp->next;
    }
}

void free_students(){/*Program kapandığında rami serbest bırakmak için kullandım*/
    struct student *temp = head.next;

    while(temp != NULL){
        struct student *nextstudent = temp->next;
        free(temp);
        temp = nextstudent;
    }
}

int main(){
    int choice;
    char choice2 ;
    FILE *f = fopen("students.txt", "a+");
    read_students(f);
    print_students();
    printf ("\nEkleme veya cikarma yapmak icin 1'e cikmak icin 0'a basin...\n");
    scanf("%d",&choice);

    while(1){
        if (choice){
            printf("Ekleme yapmak icin e harfine silmek icin s harfine basin...\n");
            fflush(stdin);
            scanf(" %c",&choice2);
            getchar();
            if (choice2 == 'e')
            {
                if (add(f))
                {
                    printf ("Ogrenci basari ile eklendi.\n");
                }
            }
            else if (choice2 == 's')
            {
                rewind(f);
                fflush(stdin);
                char no[10];
                printf("Silmek istediginiz kisinin numarasini giriniz...\n");
                gets(no);
                delete(f,no);
                f = fopen("students.txt","a+");
            }
        }
        else
        {
            print_students();
            free_students();
            break;
        }
        printf ("\nEkleme veya cikarma yapmak icin 1'e cikmak icin 0'a basin...\n");
        scanf("%d",&choice);
    }

    return 0;
}


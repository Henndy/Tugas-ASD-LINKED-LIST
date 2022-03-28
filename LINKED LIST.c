#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *head;

int main()
{
   int pilihan = 0;


   while(pilihan != 6 )
   {
       system("cls");
       printf("=====================");
       printf("\n     LINKED LIST ");
       printf("\n=====================");
       printf("\n1. Input diawal \n2. Input di akhir \n3. Input sembarang \n4. lihat \n5. Hapus diawal \n6. Hapus diakhir \n7. Hapus sembarang \n8. Keluar\n\n");
       printf("\nMasukan Pilihan: ");
       scanf("%d", &pilihan);

       switch(pilihan)
       {
           case 1 :
           system("cls");
           awal();
           getch();
           break;

           case 2 :
           system("cls");
           akhir();
           getch();
           break;

           case 3 :
            system("cls");
           sembarang();
           getch();
           break;

           case 4 :
           system("cls");
           cetak();
           getch();
           break;

           case 5 :
           hapusAwal();
           break;

           case 6 :
           hapusakhir();
           break;

           case 7 :
           hapussembarang();
           break;

           case 8 :
            exit(0);
            break;

           default:
           printf("Pilihan Tidak Tersedia!");
       }

   }
}


void awal()
{
    struct node *ptr;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }
    else
    {
        printf(" Masukan data: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("|Data berhasil disimpan!\n");
    }
}
void hapusAwal(){
     struct node *ptr;
    if(head == NULL)
    {
        printf("\nList kosong bro!\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Data awal berhasil dihapus!\n");
        getch();
    }
}
void hapusakhir()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("|List kosong|\n");
    }
    else
    {
        ptr->next = head;
            head = ptr; free(ptr);
            printf("Data berhasil dihapus\n");
    }
}
void akhir()
{
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }
    else
    {
        printf("Masukan data : ");
        scanf("%d", &item);
        ptr->data = item;
        if(head==NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("Data berhasil disimpan!\n");
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Data berhasil disimpan!\n");
        }
    }

}

void sembarang()
{
    struct node *ptr, *temp;
    int item, loc, i;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }
    else
    {
        printf("Masukan data : ");
        scanf("%d", &item);
        ptr->data = item;
        printf("Mau simpan di lokasi berapa ? ");
        scanf("%d", &loc);
        temp = head;
        for(i=0; i<loc; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                printf("Data tidak bisa disimpan!!");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Data berhasil disimpan\n");
    }

}
void hapussembarang(){
    system("cls");
    struct node *ptr,*temp,*temp2;
    char *data1;
    if(head == NULL){
        printf("Tidak ada data!\n");
    }else{
        if (head->next != NULL) {
            temp = head;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            ptr = temp->next;
            data1 = ptr->data;
            temp->next = NULL;
            free(ptr);
        } else {
            data1 = head->data;
            head = NULL;
        }
        printf("Berhasil dihapus!\n");
    }
}

void cetak()
{
    struct node *ptr;
    ptr = head;
    if(ptr==NULL)
    {
        printf("Data kosong!\n");
    }
    else
    {
        printf("Cetak isi list .... ");
        while(ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

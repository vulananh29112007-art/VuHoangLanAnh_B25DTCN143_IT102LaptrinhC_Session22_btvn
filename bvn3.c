	#include<stdio.h>
	#include<string.h>
	struct Date {
		int day;
		int month;
		int year;
	}; 
	struct Student {
		char id[10];
		char name[50];
		struct Date date;
		char address[100];
		char phoneNumber[15]; 
	};
	void inputStudent(struct Student list[], int *n){
		int i;
	    printf("Nhap so luong sinh vien: ");
	    scanf("%d", &n);
	    getchar();
		 
	    for(i = 0;i<n;i++){
		    printf("Sinh vien %d\n",i+1);
		
		    printf("Ma so sinh vien: %s\n");
		    fgets(list[i].id,sizeof(list[i].id),stdin);
		    list[i].id[strcspn(list[i].id,"\n")] = '\0';
		
		    printf("Ho va ten: ");
		    fgets(list[i].name,sizeof(list[i].name),stdin);
		    list[i].name[strcspn(list[i].name,"\n")] = '\0';
		
		    printf("Ngay thang nam sinh: ");
		    scanf("%d %d %d",&list[i].date.day,&list[i].date.month,&list[i].date.year);
		    getchar();
		
		    printf("Dia chi: ");
		    fgets(list[i].address,sizeof(list[i].address),stdin);
		    list[i].address[strcspn(list[i].address,"\n")] = '\0';
		    
		    printf("So dien thoai: ");
		    fgets(list[i].phoneNumber,sizeof(list[i].phoneNumber),stdin);
		    list[i].phoneNumber[strcspn(list[i].phoneNumber,"\n")] = '\0';
	    }
	}
	    
	void printfStudent(struct Student list[], int n){
		if(n == 0){
	    	printf("Chua co sinh vien");
	    	return;
		}
		for(int i = 0;i<n;i++){
			printf("Sinh vien %d",i+1);
			printf("Ma so sinh vien: %s\n",list[i].id);
			printf("Ho va ten: %s\n",list[i].name);
			printf("Ngay: %d, thang: %d, nam:%d\n", list[i].date.day, list[i].date.month, list[i].date.year);
			printf("Dia chi sinh: %s",list[i].address);
			printf("So dien thoai: %s",list[i].phoneNumber);
		}
	}
	    
	void addStudent (struct Student list[], int *n){
	    int i = *n;
	        printf("Sinh vien %d\n",i+1);
		
		    printf("Ma so sinh vien: %s\n");
		    fgets(list[i].id,sizeof(list[i].id),stdin);
		    list[i].id[strcspn(list[i].id,"\n")] = '\0';
		
		    printf("Ho va ten: ");
		    fgets(list[i].name,sizeof(list[i].name),stdin);
		    list[i].name[strcspn(list[i].name,"\n")] = '\0';
		
		    printf("Ngay thang nam sinh: ");
		    scanf("%d %d %d",&list[i].date.day,&list[i].date.month,&list[i].date.year);
		    getchar();
		
		    printf("Dia chi ");
		    fgets(list[i].address,sizeof(list[i].address),stdin);
		    list[i].address[strcspn(list[i].address,"\n")] = '\0';
		    
		    printf("So dien: ");
		    fgets(list[i].phoneNumber,sizeof(list[i].phoneNumber),stdin);
		    list[i].phoneNumber[strcspn(list[i].phoneNumber,"\n")] = '\0';
		    
		    (*n)++;
	}
	void deleteStudent (struct Student list[], int *n,char id[]){
		int i, pos=-1;
		
		for(i=0;i<*n;i++){
			if(strcmp(list[i].id, id) == 0){
			pos = i;
			break;
		    }
		}
		
		if(pos == -1){
			printf("Khong tim thay id");
			return;
		}
		
		for(i = pos;i<*n-1;i++){
			list[i] = list[i+1];
		}
		    printf("Xoa thanh cong");
			(*n)--;
	}
void updateStudent(struct Student list[], int n, char id[]) {
    int found = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].id, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay sinh vien.\n");
        return;
    }
	
void sortByName(struct Student list[], int n) {
	struct Student temp;
	
	for (int i = 0; i < n - 1; i++) {
	    for (int j = i + 1; j < n; j++) {
	        if (strcmp(list[i].name, list[j].name) > 0) {
	            temp = list[i];
	            list[i] = list[j];
	            list[j] = temp;
	        }
	    }
	}
}
	
void searchStudent(struct Student list[], int n, char id[]) {
	int i;
	
	for (i = 0; i < n; i++) {
	    if (strcmp(list[i].id, id) == 0) {
	            printf("Ma SV: %s\n", list[i].id);
	            printf("Ho ten: %s\n", list[i].name);
	            printf("Ngay:%d, thang:%d, nam:%d\n", list[i].date.day, list[i].date.month, list[i].date.year);
	            printf("Dia chi: %s\n", list[i].address);
	            printf("Dien thoai: %s\n", list[i].phoneNumber);
	            return;
	        }
	    }
	
	    printf("Khong tim thay sinh vien.\n");
	}
	
	int main() {
	    struct Student list[100];
	    int n = 0;
	    int choice;
	    char id[20];
	
	    do {
	        printf("===== MENU =====\n");
	        printf("1. Nhap danh sach sinh vien\n");
	        printf("2. Hien thi danh sach sinh vien\n");
	        printf("3. Them sinh vien\n");
	        printf("4. Xoa sinh vien theo ma\n");
	        printf("5. Cap nhat sinh vien theo ma\n");
	        printf("6. Sap xep theo ho ten (A-Z)\n");
	        printf("7. Tim kiem sinh vien theo ma\n");
	        printf("8. Thoat\n");
	        printf("Lua chon: ");
	        scanf("%d", &choice);
	
	        switch (choice) {
	        case 1:
	            inputStudent(list, n);
	            break;
	        case 2:
	            printfStudents(list, n);
	            break;
	        case 3:
	            addStudent(list, &n);
	            break;
	        case 4:
	            printf("Nhap ma sinh vien can xoa: ");
	            getchar();
	            fgets(id, sizeof(id), stdin);
	            id[strcspn(id, "\n")] = '\0';
	            deleteStudent(list, &n, id);
	            break;
	        case 5:
	            printf("Nhap ma sinh vien can cap nhat: ");
	            getchar();
	            fgets(id, sizeof(id), stdin);
	            id[strcspn(id, "\n")] = '\0';
	            updateStudent(list, n, id);
	            break;
	        case 6:
	            sortByName(list, n);
	            break;
	        case 7:
	            printf("Nhap ma sinh vien can tim: ");
	            getchar();
	            fgets(id, sizeof(id), stdin);
	            id[strcspn(id, "\n")] = '\0';
	            searchStudent(list, n, id);
	            break;
	        case 8:
	            printf("Thoat chuong trinh.\n");
	            break;
	        default:
	            printf("Lua chon khong hop le.\n");
	        }
	    } while (choice != 8);
	
	    return 0;
	}
	
	    
	 
	


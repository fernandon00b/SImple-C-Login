#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char user[100];
	char password[100];
	char hint[100];
	char answer[100];
}user[100],temp;


int main(){
FILE *data;
int index=3;
int choose=0;
int login=0;
char userlogin[100];
char loginuser[100];
char loginpass[100];
char answer[100];
char passnew[100];
char passconfirm[100];
	//DATA CREATED BY NANDO
	//
	strcpy(user[0].user,"william93");
	strcpy(user[0].password,"william93p");
	strcpy(user[0].hint,"banana");
	strcpy(user[0].answer,"pisang");
	//
	strcpy(user[1].user,"ade96");
	strcpy(user[1].password,"ade96p");
	strcpy(user[1].hint,"watermelon");
	strcpy(user[1].answer,"semangka");
	//
	strcpy(user[2].user,"alfi99");
	strcpy(user[2].password,"alfi99p");
	strcpy(user[2].hint,"orange");
	strcpy(user[2].answer,"jeruk");
	//
	//END
while(choose!=6){
system("cls");
printf("==================================\n");
printf("Binusmaya User Management System\n");
printf("==================================\n");
if(login==1){
printf("Welcome!! %s\n",userlogin);
}
printf("1. Show Data\n");
printf("2. Sorting userName Ascending\n");
printf("3. Login\n");
printf("4. Logout\n");
printf("5. Export data\n");
printf("6. Exit\n");
printf("Input :");scanf("%d",&choose);fflush(stdin);
if(choose==1){
			printf("==============================================================================\n");
		printf("| %-5s | %-15s| %-15s| %-15s| %-15s|\n","No","Username","Password","Hint","Answer");
	for(int i=0;i<index;i++){
		printf("| %-5d | %-15s| %-15s| %-15s| %-15s|\n",i+1,user[i].user,user[i].password,user[i].hint,user[i].answer);
	}
	printf("==============================================================================\n");
	getchar();
}
if(choose==2){
	for(int i=0 ;i<index;i++){
		for(int j=index-1;j>i;j--){
			if(strcmp(user[j].user,user[j-1].user)<0){
				temp=user[j];
				user[j]=user[j-1];
				user[j-1]=temp;
			}
		
		
		}
	}

}
if(choose==3){
printf("Username :");scanf("%[^\n]",loginuser);fflush(stdin);
for(int i = 0;i<index;i++){
	if(strcmp(loginuser,user[i].user)==0){
	printf("Password :");scanf("%[^\n]",loginpass);fflush(stdin);
	if(strcmp(loginpass,user[i].password)==0){
		login=1;
		strcpy(userlogin,user[i].user);
		break;
	}
	if(strcmp(loginpass,user[i].password)!=0){
		printf("Password is wrong!\n");
		printf("Hint :%s\n",user[i].hint);
		printf("answer : ");scanf("%[^\n]",answer);fflush(stdin);
		if(strcmp(answer,user[i].answer)==0){
		printf("Insert new Password:");scanf("%[^\n]",passnew);fflush(stdin);
		printf("Confirm Password:");scanf("%[^\n]",passconfirm);fflush(stdin);
		if(strcmp(passnew,passconfirm)==0){
			printf("Password changed!");
			strcpy(user[i].password,passconfirm);
			getchar();
			break;
		}
		if(strcmp(passnew,passconfirm)!=0){
			printf("confirm password not match!!");
			getchar();
			break;
		}
		}
		if(strcmp(answer,user[i].answer)!=0){
			printf("Hint Not match!!");
			getchar();
			break;
		}
	}
	}
	if(i==index-1){
	printf("user not found!!");
	getchar();
	}
}
}	

if(choose==4){
login=0;

}
if(choose==5){
data=fopen("file.txt","w");
fprintf(data,"==============================================================================\n")	;
fprintf(data,"| %-5s | %-15s| %-15s| %-15s| %-15s|\n","No","Username","Password","Hint","Answer");

for(int i = 0 ;i <index ; i++){
	fprintf(data,"| %-5d | %-15s| %-15s| %-15s| %-15s|\n",i+1,user[i].user,user[i].password,user[i].hint,user[i].answer);
}
fprintf(data,"==============================================================================\n");
fclose(data);
}
}
getchar();
return 0;
}
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
struct ad
{
    char name[30];
    char disease[18],grp[3];
    int cabin,age,sr;
    char phone[11];
}qq[100],pp;
int n,i,j=0,a=0,summ=0,g,num=0;
void add();
void view();
void search();
void edit();
void del();
void show();
void host();
struct bloodbank
{
  
  char name[30];
  char age[3];
  char phone[10];
    char disease[30];
    char add[30];  
    char bgroup[20]; 
    char state[30];
    char country[20];
    char DOB[20];
    char temp[1];
    int serial,dd,mn,yr;
 } x[50],yy;
void adds();
void display();
void edits();
void search1(char str[]);
void Search2();
void dell();
void blod();

struct cov{
    char name[25],add[50],ph[11],grp[3];
    int d,mn,yr,sr;
    struct cov *next;
};
typedef struct cov node;
node* input(node*);
void ed(node*,int,int);
void search3(char b[],node*,int,int);
void dels(node*,int);
void cov();
void ret();
int sum=0,count=0,k,d,j2=0;
char z;
int main()
{ 
char str[20],pass[20];
for(;;) 
{
printf("\n\t AdminID:");
scanf("%s",str);
printf("\n\t Password:");
scanf("%s",pass);              
if(strcmp(str,"Vamshi")==0)   
{
    if(strcmp(pass,"Vamshi920@1")==0)
    break;
    else   
    printf("\n\t Incorrect Password");
}
else
printf("\n\t Incorrect AdminID"); 
} 
char choice;
while(1)
{
  printf("\n\t*EMERGENCY BLOOD AID*");
  printf("\n1.database of hospital\n2.database of bloodbank\n3.database of covid\n4.exit\n");
  printf("enter you choice:");
  scanf(" %c",&choice);
  switch(choice)
  {
    case '1': 
            host();
            break;
    case '2':
            blod();
            break;
    case '3': 
            cov();
            break;
    case '4': exit(0);
    default:
      printf("\n invalid choice:\n");
      break;
      }
   }
 }

void host()
{
    char c='0';
    printf("Simple Hospital Management System\n");
    while(c!='6')
    {

        printf("*Enter your choice*\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption=");
        scanf(" %c",&c);//choice for option
        fflush(stdin);//making it clear
        if(c=='1')//add
        {
            add();
        }
        else if(c=='2')//view
        {
            view();
        }
        else if(c=='3')//search
        {
            search();
        }
        else if(c=='4')//edit
        {
            edit();
        }
        else if(c=='5')//delete
        {
            del();
        }
        else if(c=='6')
        {
            break;
        }
        else
        {
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void add()
{
    FILE *f;
    f=fopen("host.dat","ab+");
    printf("\n\n");
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);
    for(i=0,j=0; i<n; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name = ");
        getchar();
        gets(qq[i].name);
        fflush(stdin);
        printf("Enter blood group:");
        scanf("%s",qq[i].grp);
        fflush(stdout);
        printf("Enter disease = ");
        getchar();
        gets(qq[i].disease);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d",&qq[i].age);
        fflush(stdin);
        printf("Enter cabin no = ");
        scanf("%d",&qq[i].cabin);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%s",qq[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        fseek(f,-sizeof(struct ad),SEEK_END);
        fread(&pp,sizeof(struct ad),1,f);
        qq[i].sr=pp.sr+1;
        fwrite(&qq[i],sizeof(struct ad),1,f);
    }
    fclose(f);
}

void view()
{
    FILE *f;
    f=fopen("host.dat","rb");
    if(f==NULL)
    {
        printf("\n NO DATA");
        return;
    }
    while(fread(&pp,sizeof(struct ad),1,f)!=0)
    {
       printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
    }
    fclose(f);
}
void edit()
{
    FILE *f;
    f=fopen("host.dat","rb+");
    if(f==NULL)
    {
        printf("\n NO DATA");
        return;
    }
    char q;
    int p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n6.Blood group\n");
    printf("Option=");
    scanf(" %c",&q);//option
    if(q<='6')
    {
        printf("Enter the serial no of that patient= (0 - %d)=",num-1);
        scanf("%d",&p);//serial number
            if(q=='1')
            {
                fflush(stdin);
                while(fread(&qq[0],sizeof(struct ad),1,f)!=0)
            {
                if(qq[0].sr==p)
                break;
            }
                printf("Enter the new name=");
                getchar();
                gets(qq[0].name);
            fseek(f,-sizeof(struct ad),SEEK_CUR);
            fwrite(&qq[0],sizeof(struct ad),1,f);

            }
            else if(q=='2')
            {
                fflush(stdin);
            while(fread(&qq[0],sizeof(struct ad),1,f)!=0)
            {
                if(qq[0].sr==p)
                break;
            }
            printf("Enter the new Disease=");
                getchar();
                gets(qq[0].disease);
            fseek(f,-sizeof(struct ad),SEEK_CUR);
            fwrite(&qq[0],sizeof(struct ad),1,f);
            }
            else if(q=='3')
            {
                fflush(stdin);
            while(fread(&qq[0],sizeof(struct ad),1,f)!=0)
            {
                if(qq[0].sr==p)
                break;
            }
                printf("Enter the new Age=");
                scanf("%d",&qq[0].age);
            fseek(f,-sizeof(struct ad),SEEK_CUR);
            fwrite(&qq[0],sizeof(struct ad),1,f);
            }

            else if(q=='4')
            {
                fflush(stdin);
            while(fread(&qq[0],sizeof(struct ad),1,f)!=0)
            {
                if(qq[0].sr==p)
                break;
            }
                printf("Enter the new Cabin no=");
                scanf("%d",&qq[p].cabin);
            fseek(f,-sizeof(struct ad),SEEK_CUR);
            fwrite(&qq[0],sizeof(struct ad),1,f);
            }

            else if(q=='5')
            {
                fflush(stdin);
            while(fread(&qq[0],sizeof(struct ad),1,f)!=0)
            {
                if(qq[0].sr==p)
                break;
            }
                printf("Enter the new Phone no =");
                getchar();
                scanf("%s",qq[0].phone);
            fseek(f,-sizeof(struct ad),SEEK_CUR);
            fwrite(&qq[0],sizeof(struct ad),1,f);
            }
        else if(q=='6')
        {
            while(fread(&qq[0],sizeof(struct ad),1,f)!=0)
            {
                if(qq[0].sr==p)
                break;
            }
                printf("Enter the new blood group =");
                getchar();
                scanf("%s",qq[0].phone);
            fseek(f,-sizeof(struct ad),SEEK_CUR);
            fwrite(&qq[0],sizeof(struct ad),1,f);
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
    fclose(f);
}
void search()
{
    FILE *jj;
    jj=fopen("host.dat","rb");
    if(jj==NULL)
    {
        printf("\n NO DATA");
        return;
    }
    int s,s1=0;
    char u[50],h;
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n7.blood group\n\nOption = ");
    scanf(" %c",&h);
    if(h=='1')
    {
        printf("Enter Serial number of the patient=");
        scanf("%d",&s);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(pp.sr==s)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n SERIAL NUMBER NOT FOUND"); 
    }
    else if(h=='2')
    {
        fflush(stdin);
        printf("Enter your name=");
        getchar();
        gets(u);
        fflush(stdin);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(strcmp(pp.name,u)==0)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n NAME NOT FOUND");
    }
    else if(h=='3')
    {
        fflush(stdin);
        printf("Enter Disease = ");
        getchar();
        gets(u);
        fflush(stdin);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(strcmp(pp.disease,u)==0)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n DISEASE GROUP NOT FOUND");
    }
    else if(h=='4')
    {
        int f=1;
        printf("Enter Cabin number = ");
        scanf("%d",&f);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(pp.cabin==f)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n CABIN NUMBER NOT FOUND");
    }
    else if(h=='5')
    {
        char f[11];
        printf("Enter Phone number = ");
        scanf("%s",f);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(strcmp(pp.phone,f)==0)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n PHONE NUMBER NOT FOUND");
    }
    else if(h=='6')
    {
        int f=1;
        printf("Enter Age = ");
        scanf("%d",&f);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(pp.age==f)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n AGE GROUP NOT FOUND");
    }
    else if(h=='7')
    {
        char f[4];
        printf("Enter blood group = ");
        scanf("%s",f);
        while(fread(&pp,sizeof(struct ad),1,jj)!=0)
        {
           if(strcmp(pp.grp,f)==0)
            {
                s1=1;
                 printf("\n");
        printf("Serial Number=%d\n",pp.sr);
        printf("\nName =%s ",pp.name);
        printf("\nGroup=%s",pp.grp);
        printf("\nDisease =%s",pp.disease);
        printf("\nCabin no = %d\nPhone number = 0%s\nAge=%d",pp.cabin,pp.phone,pp.age);
        printf("\n\n");
            }
        }
        if(s1==0)
        printf("\n BLOOD GROUP NOT FOUND");
    }
    else
        printf("\n\nInvalid input\n\n");
    fclose(jj);
}
void del()
{
    FILE *ff;
    ff=fopen("host.dat","rb");
    if(ff==NULL)
    {
        printf("\n NO DATA TO DELETE");
        return;
    }
    FILE *fg;
    fg=fopen("temp.dat","wb");
    int f,k2=0;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);
            while(fread(&pp,sizeof(struct ad),1,ff)!=0)
            {
                if(pp.sr==f)
                {
                  k2=1;
                  printf("\n RECORD DELETED");
                }
                else
                fwrite(&pp,sizeof(struct ad),1,fg);
            }
            remove("host.dat");
            rename("temp.dat","host.dat");
            if(k2==0)
            printf("\n SERIAL NUMBER NOT FOUND TO DELETE");
        fclose(ff);
    fclose(fg);
}

 void blod(){
  char choice ;
  while(1){

  printf("\n\n*DATABASE OF BLOODBANK\n\n");
  printf("1.INPUT RECORDS\n");
  printf("2.DISPLAY RECORDS\n");
  printf("3.EDIT RECORDS\n");
  printf("4.SEARCH BLOOD GROUP\n");
  printf("5.DELETE RECORD\n");
  printf("6.EXIT\n");
  printf("ENTER YOUR CHOICE\n");
  scanf(" %c",&choice);
  switch(choice){
       case '1': 
               adds();
               break;
        case '2':
               display();
               break;
        case '3':
               edits();
               break;
        case '4':
               Search2();
               break;
        case '5':
               dell();
               break;
        case '6': 
               break;
          default:printf("Enter valid choice\n");                                 
  }
        if(choice=='6')
        break;
}}
void adds(){
    FILE *f;
    f=fopen("blod.dat","a+b");
  printf("How many entry do u want to add\n");
  scanf("%d",&sum);
  for(i=0;i<sum;i++)
  {
    printf("\n\n");
    
    printf("Enter Donors Name\n");
        getchar();      
    gets(x[i].name);
    
    printf("Enter Donors Age\n");
    scanf("%s",x[i].age);
    
    printf("Enter Donors Phone Number\n");
    scanf("%s",x[i].phone);
    
    printf("Enter Donors Address\n");
        getchar();      
    gets(x[i].add);
    
    printf("Enter Donors blood group\n");
    scanf("%s",x[i].bgroup);
    
    printf("Enter Donors State\n");
    scanf("%s",x[i].state);
    
        printf("Enter Donors Country\n");
    scanf("%s",x[i].country);
    
    printf("Enter Donors Date Of Birth\n");
    scanf("%s",x[i].DOB);
    if(NULL==f)
    x[i].serial=0;
    else
    {
        fseek(f,-sizeof(yy),SEEK_END);
    fread(&yy,sizeof(yy),1,f);
    x[i].serial=yy.serial+1;
    }
    //fseek(f,sizeof(bloodbank),SEEK_END);  
    //fwrite(&x[i],sizeof(yy),1,f);
    printf("Have you donated blood in past 3 months(Y/N)\n");
    scanf(" %c",&z);
     if(z=='y'||z=='Y')
     {
          time_t now=time(NULL);  
          struct tm *t = localtime(&now);
          x[i].dd=t->tm_mday;
          x[i].mn=t->tm_mon+3;
          if(x[i].mn>12)
          {
            x[i].mn=x[i].mn-12;
            x[i].yr=t->tm_year+1900+1;
          }
          else
          x[i].yr=t->tm_year+1900;
     }
     else
     {
          time_t now=time(NULL);  
          struct tm *t = localtime(&now);
          x[i].dd=t->tm_mday;
          x[i].mn=t->tm_mon+1;
          x[i].yr=t->tm_year+1900;
     }
     fwrite(&x[i],sizeof(yy),1,f);
     }
    fclose(f);
}
void display(){
    FILE *f;
    f=fopen("blod.dat","r");
    if(f==NULL)
    {
        printf("\n NO DATA");
        return;
    }
    while(fread(&x[0],sizeof(yy),1,f)!=0)
    {
        printf("Serial Number = %d\n",x[0].serial);
  printf("Name :%s \n",x[0].name );
  printf("Age :%s\n",x[0].age );
  printf("Phone Number : %s\n",x[0].phone);
  printf("Address :%s \n",x[0].add);
  printf("Blood Group :%s\n",x[0].bgroup);
  printf("Next donation date :%d/%d/%d",x[0].dd,x[0].mn,x[0].yr);
  printf("\nState : %s\n",x[0].state);
  printf("Country :%s\n",x[0].country);
  printf("Date Of Birth:%s\n",x[0].DOB);
    }
    fclose(f);
}
void edits(){
  FILE *fg;
  fg=fopen("blod.dat","r+b");
  if(fg==NULL)
  {
     printf("\n NO DATA");
     return;
  }
  fclose(fg);
  int b,z3=0;  
  char a1,ch;  
  fflush(stdin);
  printf("\n would like to update doners donation date who donated blood:");
  scanf(" %c",&ch);
  if(ch=='y'||ch=='Y')
  {
       while(ch=='y'||ch=='Y')
        {
            FILE *ff;
            ff=fopen("blod.dat","r+b");
            int n;
            printf("\n how many records want to update:");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                int vv,vv1=0;
                printf("\n enter serial number:");
                scanf("%d",&vv);
             while(fread(&yy,sizeof(struct bloodbank),1,ff)!=0)
                {
                    if(yy.serial==vv)
                    {
                    vv1=1;
                    time_t tt=time(NULL);
                    struct tm *th=localtime(&tt);
                    yy.dd=th->tm_mday;
                    yy.mn=th->tm_mon+4;
                    if(yy.mn>12)
                    {
                        yy.mn=yy.mn-12;
                    yy.yr=th->tm_year+1900+1;
                    }
                    else
                    yy.yr=th->tm_year+1900;
                    fseek(ff,-sizeof(struct bloodbank),SEEK_CUR);
                    fwrite(&yy,sizeof(struct bloodbank),1,ff);
                        printf("\n CHANGES DONE");
                        break;
                    }
                }
                if(vv1==0)
                    printf("\n RECORD NOT FOUND");
                 vv1=0;
                fseek(ff,0*sizeof(struct bloodbank),SEEK_SET);
            }
            printf("\n would like to update more records:");
            scanf(" %c",&ch);
            fclose(ff);
        }
  }
    FILE *f;
  f=fopen("blod.dat","r+b");
  printf(" What do you want to edit\n");
  printf("1.NAME\n2.AGE\n3.PHONE NUMBER\n4.ADDRESS\n5.BLOOD GROUP\n6.STATE\n7.COUNTRY\n8.DATE OF BIRTH\n9.EXIT\n\n");
  printf("enter your choice:");
  scanf(" %c",&a1);
  if (a1<='8'&&a1>'0'){
    printf("enter your serial number:");
    scanf("%d",&b); 
      if(b>=0){
      if(a1=='1'){
         while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new name:");
               scanf("%s",yy.name);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
                z3=0;                     
      }
      else if(a1=='2'){
           while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new age:");
               scanf("%s",yy.age);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
          z3=0;                    
      }
      else if(a1=='3'){
         while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new phone number:");
               scanf("%s",yy.phone);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
                z3=0;
      }
      else if (a1=='4'){
         while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new address:");
               scanf("%s",yy.add);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
           z3=0;      
      }
      else if (a1=='5'){
          while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new blood group:");
               scanf("%s",yy.bgroup);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
           z3=0;
      }
      else if(a1=='6'){
         while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new state:");
               scanf("%s",yy.state);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
                z3=0;     
      }
      else if(a1=='7'){
        while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new country:");
               scanf("%s",yy.country);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
                z3=0;
      }
      else if(a1=='8'){
         while(fread(&yy,sizeof(yy),1,f)!=0)
         {
            if(yy.serial==b)  
            {
               printf("\n enter new DOB:");
               scanf("%s",yy.DOB);
               fseek(f,-sizeof(yy),SEEK_CUR);  
               fwrite(&yy,sizeof(yy),1,f);  
                z3=1;     
            }      
          }
          if(z3==0)
          printf("\n NO RECORD FOUND");
            z3=0;      
      }
      }      
    }
    else if(a1=='9');
    else
    {
        printf("\n\n Invalid Choice \n\n");
    }
    fclose(f);
}
void search1(char str[])
{
    FILE *f;
    f=fopen("blod.dat","rb");
    if(f==NULL)
    {
        printf("\n NO DATA");
        return;
    }
    int gg=0,w;
    char str1[4],chx;
    time_t t=time(NULL);
    struct tm *tf=localtime(&t);
    for(w=0;str[w]!='\0';w++)
    {
        if(isalpha(str[w]))
        {
            chx=str[w];
            chx=chx+32;
            str1[w]=chx;
        }
        else
        str1[w]=str[w];
    }
    str1[w]='\0';
    while(fread(&yy,sizeof(yy),1,f)!=0)
        {
            if(strcmp(yy.bgroup,str)==0||strcmp(yy.bgroup,str1)==0)
            {
                printf("Serial Number : %d\n",yy.serial);
             printf("Name of donor : ");
             puts(yy.name);
             printf("Age of Donor : %s\n",yy.age);
                printf("Address :");
                puts(yy.add);
                printf("Phone Number : %s\n",yy.phone);
                printf("State : %s\n",yy.state);
                printf("Country :%s\n",yy.country);
                printf("DOB:%s\n",yy.DOB);
                gg=1;
                if(yy.mn<=(tf->tm_mon+1)&&yy.yr<=(tf->tm_year+1900)){
                printf("Eligible for donating blood this time ..So please donate\n");
                }
                else {
                   printf("Not Eligible for donating blood this time \n");
                }
            }
       }
    if(gg==0)
    printf("\n 0 results found");
    fclose(f);
}
void Search2(){
  char ch;
  
  printf("Enter The Blood Group you want to search \n");
  printf("\n1.O+\n2.O-\n3.A+\n4.A-\n5.B+\n6.B-\n7.AB+\n8.AB-\n");
  printf("select the option\n");
  scanf(" %c",&ch);
  
  if(ch=='1'){ 
        char str[]="O+";
              search1(str); 
        }
    else if(ch=='2'){ 
        char str[]="O-";
        search1(str);
         }
   else if(ch=='3'){ 
        char str[]="A+";
        search1(str);  
         }
   else if(ch=='4'){ 
        char str[]="A-";
        search1(str);
         }
    else if(ch=='5'){ 
        char str[]="B+";
        search1(str);
         }
    else if(ch=='6'){ 
        char str[]="B-";
        search1(str);
         }
   else if(ch=='7'){ 
        char str[]="AB+";
        search1(str);
         }
   else if(ch=='8'){ 
        char str[]="AB-";
        search1(str);
         }
           else {
             printf("\nEnter valid choice for blood group \n");
           }
          
    }
    void dell()
{
    int s,x2=0;
    char y='y';
    for(;y=='y'||y=='Y';)
    {
        printf("\n enter serial number to delete:");
    scanf("%d",&s);
        FILE *f;
        f=fopen("blod.dat","rb");
        if(f==NULL)
        {
            printf("\n NO DATA TO DELETE");
            return;
        }
        FILE *h;
        h=fopen("temp.dat","wb");
        while(fread(&yy,sizeof(yy),1,f)!=0)
        {
            if(s==yy.serial)
            {
               x2=1;
               printf("\n RECORD DELETED");
            }
            else
            {
               fwrite(&yy,sizeof(yy),1,h);
            }
        }
        remove("blod.dat");
        rename("temp.dat","blod.dat");
        if(x2==0)
        printf("\n SERIAL NUMBER NOT FOUND!!");
       printf("\n press 'y' to delete more records:");
        scanf(" %c",&y); 
        fclose(f);
        fclose(h);
    }
}

node *head1=NULL,*prev1=NULL;
void cov()
{
    //ret();
    node *head=head1,*prev=prev1,*temp;
    char ch[3],c;
    int n1,mn,yr,sr;
    for(;;)
    {
        printf("\n\t ****DATABASE OF COVID-19");
        printf("\n 1.INPUT RECORDS");
        printf("\n 2.DISPLAY RECORDS");
        printf("\n 3.EDIT RECORDS");
        printf("\n 4.SEARCH PLASMA");
        printf("\n 5.DELETE RECORD");
        printf("\n 6.EXIT");
        printf("\n ENTER YOUR OPTION:");
        scanf(" %c",&c);
        switch(c)
        {
            case '1': 
            FILE *fp;
            fp=fopen("cov.dat","ab");
            printf("\n how many records want to enter:");
            scanf("%d",&n1);
            for(int i2=0;i2<n1;i2++)
            {
                temp=input(prev1);
                if(head==NULL)
                {
                    head1=head=temp;
                    prev1=prev=temp;
                    fwrite(temp,sizeof(node),1,fp);
                }
                else
                {
                    prev1->next=temp;
                    prev1=prev=temp;
                    fwrite(temp,sizeof(node),1,fp);
                }
            }
            fclose(fp);
            break;
            case '2': 
            ret();
            temp=head=head1;
            if(temp==NULL)
            printf("\n NO DATA");
            else
            {
                for(;temp!=NULL;)
                {
                    printf("\n SERIAL NUMBER:%d",temp->sr);
                    printf("\n NAME:%s",temp->name);
                    printf("\n ADDRESS:%s",temp->add);
                    printf("\n PHONE NUMBER:%s",temp->ph);
                    printf("\n GROUP:%s",temp->grp);
                    printf("\n NEXT PLASMA DONATION ON:%d/%d/%d",temp->d,temp->mn,temp->yr);
                    temp=temp->next;
                }
             }   
             break;
             case '3': if(head==NULL)
            printf("\n NO DATA TO DELETE");
            else
            ed(head,mn,yr);
              break;
              case '4': 
            printf("\n enter patients plasma type:");
              scanf("%s",ch);
              printf("\n enter todays month and year:");
              scanf("%d%d",&mn,&yr);
              search3(ch,head,mn,yr);
              break;
              case '5':
                printf("\n enter serial number to delete record:");
            scanf("%d",&sr);
            if(head==NULL)
            printf("\n NO DATA TO DELETE");
            else if(head->sr==sr)
            {
               head=head->next;
               head1=head;
               printf("\n RECORD DELETED");     
               if(head==NULL)
               {
                     prev1=prev=NULL;
                     remove("cov.dat");
               }  
               else
               {
                    FILE *o;
              o=fopen("temp.dat","wb");
                  temp=head;
               while(temp!=NULL)
               {
                  fwrite(temp,sizeof(node),1,o);
                temp=temp->next;      
               }
               remove("cov.dat");
               rename("temp.dat","cov.dat");
               printf("\n CHANGES DONE!!");
                    fclose(o);
               } 
            }
            else
            {
               dels(head,sr);
            }
              break;
              case '6': 
            break;
              default: printf("\n INVALID OPTION ENTERED");
        }
        if(c=='6')
        break;
    }
}
node* input(node *prev)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("\n NAME:");
    scanf("%s",temp->name);
    printf("\n ADDRESS:");
    getchar();
    gets(temp->add);
    printf("\n PHONE NUMBER:");
    scanf("%s",temp->ph);
    printf("\n GROUP:");
    scanf("%s",temp->grp);
    printf("\n NEXT PLASMA DONATION ON:");
    scanf("%d%d%d",&temp->d,&temp->mn,&temp->yr);
    temp->next=NULL;
    if(prev==NULL)
    temp->sr=0;
    else 
    temp->sr=prev->sr+1;
    return temp;
}
void ed(node *head,int mn,int yr)
{
    FILE *f;
    f=fopen("cov.dat","r+b");
    node *temp;
    char ch;
    int i1=0,sr,k1=1,k2=0;
    printf("\n press 'y' to change dates of donated plasma members:");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='Y')
    {
        printf("\n enter number of records want to changes:");
        scanf("%d",&i);
        for(int jjj=0;jjj<i;jjj++)
        {
           printf("\n enter serial number:");
           scanf("%d",&sr);
           temp=head;
            k1=1;
            while(temp!=NULL)
            {
                if(temp->sr==sr)
                {
                    k1++;
                    temp->mn=mn+2;
                    temp->yr=yr;
                    printf("\n CHANGES DONE");
                    if(temp->mn>12)
                    {
                    temp->mn=temp->mn-12;
                    temp->yr=temp->yr+1;
                    }
                    fseek(f,k2*sizeof(node),SEEK_SET);
                    fwrite(temp,sizeof(node),1,f);
                    k2=0;
                    break;
                }
                temp=temp->next;
                k2++;
            }
           if(k1==1)
           printf("\n %d SERIAL NUMBER NOT FOUND",sr);
        }
    }
    else
    {
        ch='y';
        k1=1;
        k2=0;
        for(;ch=='y'||ch=='Y';)
        {
             temp=head;
             i1=0;
             k2=0;
             printf("\n ENTER SERIAL NUMBER TO EDIT RECORD:");
             scanf("%d",&sr);
             while(temp!=NULL)
             {
                if(temp->sr==sr)
                {
                    k1++;
                    break;
                }
                k2++;
                temp=temp->next;
             }
             if(k1==1)
            printf("\n SERIAL NUMBER NOT FOUND");
             else
            {
                for(;;)
                {
                    printf("\n 1.EDIT NAME");
                printf("\n 2.EDIT ADDRESS");
                printf("\n 3.EDIT PHONE NUMBER");
                printf("\n 4.EDIT GROUP");
                printf("\n 5.EDIT DATE OF PLASMA DONATION");
                printf("\n 6.GO BACK TO MAIN MENU");
                printf("\n ENTER OPTION:");
                scanf(" %c",&ch);
                switch(ch)
                {
                   case '1': printf("\n enter new name:");
                          scanf("%s",temp->name);
                        printf("\n CHANGES DONE");
                    break;
                    case '2': printf("\n enter new address:");
                    scanf("%s",temp->add);
                        printf("\n CHANGES DONE");
                    break;
                    case '3': printf("\n enter new phone number:");
                    scanf("%s",temp->ph);
                        printf("\n CHANGES DONE");
                    break;
                    case '4': printf("\n enter new blood group:");
                    scanf("%s",temp->grp);
                        printf("\n CHANGES DONE");
                    break;
                    case '5': printf("\n enter new date:");
                    scanf("%d%d%d",&temp->d,&temp->mn,&temp->yr);
                        printf("\n CHANGES DONE");
                    break;
                    case '6': fseek(f,k2*sizeof(node),SEEK_SET);
                        fwrite(temp,sizeof(node),1,f);
                        break;
                    default: printf("\n invalid option");
               
                }
                if(ch=='6')
                break;
                }
            }
            printf("\n press 'y' edit more records:");
                scanf(" %c",&ch);
        }
    }
    fclose(f);
}
void search3(char grp[],node *head,int mn,int yr)
{
    node *temp;
    temp=head;
    int kk=0,w;
    char str1[4],chx;
    for(w=0;grp[w]!='\0';w++)
    {
        if(isupper(grp[w]))
        {
            chx=grp[w];
            chx=chx+32;
            str1[w]=chx;
        }
        else if(islower(grp[w]))
        {
            chx=grp[w];
            chx=chx-32;
            str1[w]=chx;
        }
        else
        str1[w]=grp[w];
    }
    str1[w]='\0';
    for(;temp!=NULL;)
    {
        if((strcmp(temp->grp,grp)==0||strcmp(temp->grp,str1)==0)&&temp->mn<=mn&&temp->yr<=yr)
        {
            printf("\n SERIAL NUMBER:%d",temp->sr);
                    printf("\n NAME:%s",temp->name);
                    printf("\n ADDRESS:%s",temp->add);
                    printf("\n PHONE NUMBER:%s",temp->ph);
                    printf("\n GROUP:%s",temp->grp);
                    printf("\n NEXT PLASMA DONATION ON:%d/%d/%d",temp->d,temp->mn,temp->yr);
            kk++;
        }
        temp=temp->next;
    }
    if(kk==0)
    printf("\n 0 RESULTS FOUND"); 
}
void dels(node *head,int sr)
{
    FILE *f;
    FILE *h;
    h=fopen("temp.dat","wb");
    f=fopen("cov.dat","rb");
    node *temp,*temp1;
    int kkk=0;
    temp=head->next;
    temp1=head;
    while(temp!=NULL)
    {
        if(temp->sr==sr)
        {
            kkk++;
            temp1->next=temp->next;
            free(temp);
            temp=temp1->next;
            printf("\n RECORD DELETED");
            break;
        }
        temp1=temp;
        temp=temp->next;
    }
    temp1=head;
    if(kkk!=0)
    while(temp1!=NULL)
    {
        fwrite(temp1,sizeof(node),1,h);
        temp1=temp1->next;
    }
    else
    printf("\n NO RESULTS FOUND");
    remove("cov.dat");
    rename("temp.dat","cov.dat");
    fclose(f);
    fclose(h);
}
void ret()
{
    if(head1==NULL)
    {
        FILE *h;
        h=fopen("cov.dat","rb");
        if(h==NULL)
        {
            printf("\n FILE NOT FOUND IN DIRECTORY");
            return;
        }
        node *tempy;
        tempy=(node*)malloc(sizeof(node));
        while(fread(tempy,sizeof(node),1,h)!=0)
        {
            if(head1==NULL)
            {
                head1=prev1=tempy;
                head1->next=NULL;
            }
            else
            {
                prev1->next=tempy;
                prev1=tempy;
            }
            tempy=(node*)malloc(sizeof(node));
        }
        fclose(h);
    }
}

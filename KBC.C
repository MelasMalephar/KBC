#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


void rules(); void start();
void game(); void expert(int o);
void check(int s,int ee);
char timer(int q,int sk,int ed);
int getInput(int timeout);

void main()
{ start();}

void start()
{
  char ch;
  clrscr();
  printf("\n\t");
  textcolor(MAGENTA+BLINK);
  cprintf("WELCOME TO KAUN BANEGA CROREPATI");
  textcolor(WHITE);
  printf("\n\n\033[1mChoose from the following options:\n");// \033[1m is for making letter bold
  printf("\n(A) PLAY \t (B) RULES\t (C) Exit \033[0m\n");
  printf("\nYour Choice : ");
  scanf("%c",&ch);
  printf("\n\n\t   ");
  switch(ch)
    { case 'a': case 'A': game();
					    break;
      case 'b': case 'B': rules();
					    break;
      case 'c': case'C':  clrscr();
					    printf("THANK YOU\n\nEFFORTS BY - Namit And Piyush");
					    getch(); exit(0);
					    break;
      default : printf("Invalid choice,Try Again)");
		start();
    }
  getch();
 }

 void rules()
 { clrscr();
   printf("\t\t\t\t");
   textcolor(MAGENTA);
   cprintf("RULES");
   textcolor(WHITE);
   printf("\n\n1. There are 7 questions in the game. Each question has 4 options,you\nhave to select 1 option as per your choice\n");
   delay(1000);
   printf("\n2. You have 2 life lines\n");
   printf("(a)SKIP QUES (ESC Button)   (b)EXPERT'S HELP (E Button)\n");
   delay(1000);
   printf("\n4. There are two levels in this game:\n");
   printf("(I) 1 to 3 ques    (II) 3 to 7\n");
   printf("If you Reach ques 3 , You take away a garunteed amount of Rs.180000\n");
   delay(1000);
   printf("\n5. One wrong answer Before ques 3 will result in termination of the game\n");
   printf("without any cash prize\n");
   delay(1000);
   printf("\n6. You can quit the game at any time after ques 3,and\ntake away the amount of money won\n");
   delay(1000);
   printf("\n7. 7th Question has a time limit of 15 seconds !!!\n");
   puts("\n\t\t\t\tBest of luck!!\n");
   getch();
   start();
 }

 void check(s,ee)
 {
   if (s==0)
     puts("A. Esc = Skip Question\n");
   else
     puts("Lifeline (A) Already Used!!\n");
   if(ee==0)
     puts("B. E = Expert's Advice\t\t\t X = Main Menu\n\n\n\t\t");
   else
     puts("Lifeline (B) Already Used!!\t\t X = Main Menu\n\n\n\t\t");
 }

 void expert(o)
{
  printf("Expert says option (%c) MIGHT be the correct answer",o);
  delay(2000);
}

 void game()
{
   char ans,op;
   int  q1,q2,q3,q4,q5,q6,q7;
   char answer[7][3]={{'d','b','c'},{'b','d','b'},{'b','a','c'},{'a','b','c'},{'c','d','b'},{'a','b','a'},{'a','a','c'}};
   double amnt = 0;
   int exp = 0,skip = 0,e=0;
   textcolor(MAGENTA);
   cprintf("\t\t\t\t LETS PLAY \t\t\t\t");//have to invrease its width
   textcolor(WHITE);
   delay(1500);
   q1 = random(3);
   s1://first question begins (GO TO statement)
   clrscr();
   printf("\n\033[1m\t\t\tQUESTION %d DTU\033[0m\n\n",exp+1);
   printf("\t\t\t\t\t AMOUNT=Rs.20000\n");
   check(skip,e);
   switch(q1)
    {   case 0 : printf("Who is the cr of class B5    ?\n");
				   printf("\n(A) Mayank \t \t (B) Nikhilesh\n(C) Prince \t \t (D) Mukul\n");
				   break;
	      case 1 : printf("Who is Ms. Fresher this year    ?\n");
				   printf("\n(A) Niharika \t \t (B) Rivanshi\n(C) Riya \t \t (D) Sneha\n");
				   break;
	      case 2 : printf("Who is Mr. Fresher this year    ?\n");
				   printf("\n(A) Anirudh \t \t (B) Priya Singh\n(C) Dhairya \t \t (D) Pragyarattan\n");
				   break;
	      default: printf("Logic error q1>2");
     }
    printf("\nYour Choice : ");
    scanf("%c",&ans);
    tolower(ans);
    if(ans==answer[0][q1])
      { printf("CORRECT ANSWER");
      	amnt+=20000;
      	printf("\nYour Amount is %.0lf",amnt);
      	getch();
      }
    else if(ans==27 && skip==0)
      { if(q1<=2 && q1>0)
		      q1=q1-1;
	      else if(q1==0)
		      q1=q1+2;
	      skip++; goto s1;
      }
    else if(ans=='e' && e==0)
      {  op=answer[0][q1];
	       expert(op); e++;
	       goto s1;
      }
    else if(ans>=97 && ans<=100)
      {  printf("INCORRECT ANSWER\n");
	       printf("You won zero Rupees");
	       getch();  start();
      }
    else if(ans=='x')
      {  printf("AMOUNT won Rs.%.0lf",amnt);
      	 getch(); start();
      }
    else if(isalpha(ans))
      { printf("\nInvalid Choice, Try Again.\n");
	      getch(); goto s1;
      }
    else goto s1;
    //1st Question end here
   exp++; q2 = random(3);
   s2://second question begins (GO TO statement)
   clrscr();
   printf("\n\033[1m\t\t\tQUESTION %d FRIENDS\033[0m\n\n",exp+1);
   printf("\t\t\t\t\t AMOUNT=Rs.60000\n");
   check(skip,e);
   switch(q2)
      {   case 0 : printf("What is Chandler Bing job ?\n");
		               printf("\n(A) Transponster \t \t (B) Statistical analysis & data reconfiguration\n(C) Finicial advisor \t \t (D) accountant\n");
		               break;
	        case 1 : printf("How many sisters does Joey have exactly?\n");
		               printf("\n(A) Three \t \t (B) Six\n(C) Five \t \t (D) Seven\n");
		               break;
	        case 2 : printf("What was the name of Ross and Chandler's college band?\n");
		               printf("\n(A) Dirty Pillows \t \t (B) Way/No Way\n(C) New Dawn      \t \t (D) Vagabond\n");
		               break;
	        default: printf("Logic error q2>2");
      }
   printf("\nYour Choice : ");
   scanf("%c",&ans);
   tolower(ans);
   if(ans==answer[1][q2])
      { printf("CORRECT ANSWER");
	      amnt+=60000;
	      printf("\nYour Amount is %.0lf",amnt);
	      getch();
      }
   else if(ans==27 && skip==0)
      { if(q2<=2 && q2>0)
	        q2=q2-1;
	      else if(q2==0)
	      	q2=q2+2;
	      skip++; goto s2;
      }
   else if(ans=='e' && e==0)
      { op=answer[1][q2];
	      expert(op); e++;
	      goto s2;
      }
   else if(ans>=97 && ans<=100)
      {  printf("INCORRECT ANSWER\n");
         printf("You won zero Rupees");
         getch();  start();
      }
   else if(ans=='x')
      { printf("AMOUNT won Rs.%.0lf",amnt);
	      getch(); start();
      }
   else if(isalpha(ans))
      { printf("\nInvalid Choice, Try Again.\n");
	      getch(); goto s2;
      }
    else
       goto s2;
    //second questionend here
    q3 = random(3); exp++;
    s3://first question begins (GO TO statement)
    clrscr();
    printf("\n\033[1m\t\t\tQUESTION %d BIG BANG THEORY\033[0m\n\n",exp+1);
    printf("\t\t\t\t\t AMOUNT=Rs.100000\n");
    check(skip,e);
    switch(q3)
       {   case 0 : printf("What time does Sheldon Cooper wake up??\n");
			              printf("\n(A) 6:30 am \t \t (B) 6:15 am\n(C) 5:45 am \t \t (D) 6:00 am\n");
			              break;
	         case 1 : printf("Sheldon Cooper has oatmeal for breakfast on which day ?\n");
			              printf("\n(A) Monday \t \t (B) Thursday\n(C) Wednesday \t \t (D) Sunday\n");
			              break;
	         case 2 : printf("What is Penny's Age of Conan character called?\n");
				      printf("\n(A) Conan the Barbarian \t \t (B) Hyborian\n(C) Queen Penelope      \t \t (D) Howard of Wolowitz\n");
			              break;
	         default: printf("Logic error q3>2");
	     }
    printf("\nYour Choice : ");
    scanf("%c",&ans);
    tolower(ans);
    if(ans==answer[2][q3])
      { printf("CORRECT ANSWER");
	      amnt+=100000;
	      printf("\nYour Amount is %.0lf",amnt);
	      getch();
      }
    else if(ans>=97 && ans<=100)
      {  printf("INCORRECT ANSWER\n");
         printf("You won zero Rupees");
         getch();  start();
      }
    else if(ans=='e' && e==0)
      {  op=answer[2][q3];
	       expert(op); e++;
	       goto s3;
      }
    else if(ans>=97 && ans<=100)
      {  printf("INCORRECT ANSWER\n");
	       printf("AMOUNT won Rs.180000");
	       getch();  start();
      }
    else if(ans=='x')
      {  printf("AMOUNT won Rs.%.0lf",amnt);
	       getch(); start();
      }
    else if(isalpha(ans))
      {  printf("\nInvalid Choice, Try Again.\n");
	       getch(); goto s3;
      }
    else goto s3;
 //3rd Question end here
    exp++; q4 = random(3);
    s4://second question begins (GO TO statement)
    clrscr();
    printf("\n\033[1m\t\t\tQUESTION %d GAME OF THRONES\033[0m\n\n",exp+1);
    printf("\t\t\t\t\t AMOUNT=Rs.420000\n");
    check(skip,e);
    switch(q4)
       {   case 0 : printf("Who was jon really   ?\n");
		                printf("\n(A) Targaryen \t \t (B) Snow\n(C) Sand \t \t (D) Stark\n");
		                break;
	         case 1 : printf("Lyanna Mormont is Jorah Mormont's...?\n");
		                printf("\n(A) Sister \t \t (B) Cousin\n(C) Niece\t \t (D) Daughter\n");
		                break;
	         case 2 : printf("Name Arya's Direwolf  :-\n");
		                printf("\n(A) Shaggydog \t \t (B) Grey Wind\n(C) Lady \t \t (D) Nymeria\n");
		                break;
	         default: printf("Logic error q4>2");
       }
    printf("\nYour Choice : ");
    scanf("%c",&ans);
    tolower(ans);
    if(ans==answer[3][q4])
       { printf("CORRECT ANSWER");
	       amnt+=420000;
	       printf("\nYour Amount is %.0lf",amnt);
	       getch();
       }
     else if(ans==27 && skip==0)
       { 	 if(q4<=2 && q4>0)
	         q4=q4-1;
	         else if(q4==0)
	         q4=q4+1;
	         skip++; goto s4;
       }
     else if(ans=='e' && e==0)
       { op=answer[3][q4];
	       expert(op); e++;
	       goto s4;
       }
     else if(ans>=97 && ans<=100)
       {  printf("INCORRECT ANSWER\n");
          printf("AMOUNT won Rs.180000");
          getch();  start();
       }
     else if(ans=='x')
       { printf("AMOUNT won Rs.%.0lf",amnt);
	       getch(); start();
       }
    else if(isalpha(ans))
       { 	printf("\nInvalid Choice, Try Again.\n");
	        getch(); goto s4;
       }
    else goto s4;
    //forth question ends here
    exp++; q5=random(3);
    s5://fifth question begins (GO TO statement)
    clrscr();
    printf("\n\033[1m\t\t\tQUESTION %d Anime \033[0m\n\n",exp+1);
    printf("\t\t\t\t\t AMOUNT=Rs.1400000\n");
    check(skip,e);
    switch(q5)
       {   case 0 : printf("Which Anime of the following is oldest ?\n");
		                printf("\n(A) One Piece   \t \t (B) Pokemon\n(C) Dragon Ball \t \t (D) Detective Conan\n");
		                break;
	         case 1 : printf("Light Yagami is the main character of which anime ?\n");
		                printf("\n(A) Code gease   \t \t (B) Assassination Classroom\n(C) Future Diary \t \t (D) Death note\n");
		                break;
	         case 2 : printf("Winner of the 2020 Crunchy Roll Anime Awards under Best animation?\n");
		                printf("\n(A) Demon Slayer       \t \t (B) Mob Psycho 100\n(C) God Of Highschool \t \t (D) The Rising of the shield hero\n");
		                break;
	         default: printf("Logic error q5>2");
	     }
    printf("\nYour Choice : ");
    scanf("%c",&ans);
    tolower(ans);
    if(ans==answer[4][q5])
       { printf("CORRECT ANSWER");
	       amnt+=1400000;
	       printf("\nYour Amount is %.0lf",amnt);
	       getch();
       }
    else if(ans==27 && skip==0)
       {  if(q5<=2 && q5>0)
	          q5=q5-1;
	        else if(q5==0)
	          q5=q5+2;
	        skip++; goto s5;
       }
    else if(ans=='e' && e==0)
       { op=answer[4][q5];
	       expert(op); e++;
	       goto s5;
    	 }
    else if(ans>=97 && ans<=100)
       {  printf("INCORRECT ANSWER\n");
          printf("AMOUNT won Rs.180000");
          getch();  start();
       }
    else if(ans=='x')
	     { printf("AMOUNT won Rs.%.0lf",amnt);
	       getch(); start();
	     }
    else if(isalpha(ans))
	     { printf("\nInvalid Choice, Try Again.\n");
	       getch(); goto s5;
	     }
    else goto s5;
     //fifth questionend here
   q6 = random(3); exp++;
   s6://first question begins (GO TO statement)
   clrscr();
   printf("\n\033[1m\t\t\tQUESTION %d SPORTS \033[0m\n\n",exp+1);
   printf("\t\t\t\t\t AMOUNT=Rs.3000000\n");
   check(skip,e);
	 switch(q6)
	    {   case 0 : printf("In which year was the opening edition of the ICC Women's T20 World Cup played?\n");
		               printf("\n(A) 2009 \t \t \t (B) 2010\n(C) 2018 \t \t \t (D) 2008\n");
		               break;
	        case 1 : printf("Which country has won the most World Cups?\n");
		               printf("\n(A) Uruguay \t \t (B) Brazil\n(C) Mexico \t \t (D) Argentina\n");
		               break;
	        case 2 : printf("When was the first event where the 'baby gloves' were made mandatory?\n");
		               printf("\n(A) UFC 14 \t \t (B) UFC 9\n(C) UFC 17 \t \t (D) UFC 10\n");
		               break;
	        default: printf("Logic error q6>2");
	    }
   printf("\nYour Choice : ");
   scanf("%c",&ans);
   tolower(ans);
   if(ans==answer[5][q6])
       { printf("CORRECT ANSWER");
	       amnt+=3000000;
	       printf("\nYour Amount is %.0lf",amnt);
	       getch();
       }
   else if(ans==27 && skip==0)
       {  if(q6<=2 && q6>0)
	          q6=q6-1;
	        else if(q6==0)
	          q6=q6+1;
	        skip++; goto s6;
       }
   else if(ans=='e' && e==0)
       {  op=answer[5][q6];
	        expert(op); e++;
	        goto s6;
       }
   else if(ans>=97 && ans<=100)
       {  printf("INCORRECT ANSWER\n");
          printf("AMOUNT won Rs.180000");
          getch();  start();
       }
   else if(ans=='x')
       {  printf("AMOUNT won Rs.%.0lf",amnt);
	        getch(); start();
       }
   else if(isalpha(ans))
       { printf("\nInvalid Choice, Try Again.\n");
	       getch(); goto s6;
       }
   else goto s6;
    //sixth Question end here
    exp++; q7 = random(3);
    s7://seventh question begins (GO TO statement)
    ans=timer(q7,skip,e);
    if(ans==answer[6][q7])
      { clrscr();
        printf("\n\n\t");
	textcolor(MAGENTA+BLINK);
	cprintf("AP CROREPATI BAN GAYE !!! Bhai Party");
	textcolor(MAGENTA);
	puts("\n");
	cprintf("THANK YOU EFFORTS BY - Namit And Piyush");
	puts("\n");
	getch();
      }
    else if(ans==27 && skip==0)
      {  if(q7<=2 && q7>0)
	   q7=q7-1;
	 else if(q7==0)
	   q7=q7+2;
	 skip++; goto s7;
      }
    else if(ans=='x')
      { printf("AMOUNT won Rs.%.0lf",amnt);
	getch(); start();
      }
    else if(ans>=97 && ans<=100)
	  {  printf("INCORRECT ANSWER\n");
	      printf("AMOUNT won Rs.180000");
	      getch();  start();
	  }
   exit(0);
 }

 char timer(q,sk,ed)
 {
   int i;
   char a;
   for(i=30;i>0; delay(1000),i--)
   { clrscr();
     printf("\n\033[1m\t\t\tQUESTION 7 Missecalaneous \033[0m\n\n");
     printf("\t\t\t\t\t AMOUNT=Rs.5000000\n");
     check(sk,ed);
     textcolor(WHITE+BLINK);
     cprintf("%48d s Remaining",i/2);
     textcolor(WHITE);
     puts("\n\n");
     switch(q)
     {   case 0 : printf("7.With which Film would you relate the lines'AAL IZZ WELL'?\n");
		  printf("\n(A) 3 Idiots \t \t (B) My Name is Khan\n(C) Golmaal \t \t (D) Welcome\n");
		  break;
	case 1 : printf("7.Which country hosted the 2010 Commonwealth Games?\n");
		 printf("\n(A) China \t \t (B) Russia\n(C) India \t \t (D) Australia\n");
		 break;
	case 2 : printf("7.Which of these colours shares its name with a Flower?\n");
		 printf("\n(A) Red \t \t (B) Yellow\n(C) Pink \t \t (D) Violet\n");
		 break;
	default: printf("Logic error q7>3");
 }
      printf("\nYour Choice : ");
       if ((a = getInput(10)) != EOF)
       {
	 if(a=='e' && ed==0)
	   { if(q<2)
	       {expert('a'); ed++;}
       else
	 {expert('c'); ed++;}
	   }
   else if(isalpha(a) && a<=96 && a>=101)
	printf("\nInvalid Choice, Try Again.\n");
	 else
	  return a;
       }
	 i--;
 }
 printf("\nTime Up!!\n");
 getch();
 return 'd';
}

int getInput(timeout)
{
    for (; timeout != 0; timeout--)
    {
	if (kbhit())
	{
	    return getch();
	}
      return EOF;
   } }

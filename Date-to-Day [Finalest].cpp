#include<iostream>
using namespace std;

class Day
{
    int date;
    int month;
    int year;

public:

    void read();
    int checkDays();
    void logic();
    void display(int);
};

void Day::read()
{
    cout<<"\n\nEnter the date  : ";
    cin>>date;
    cout<<"Enter the Month : ";
    cin>>month;
    cout<<"Enter the Year  : ";
    cin>>year;

}

int Day::checkDays()
{
    if(month>0 && month<13)
    {
          if(month==2)
          {
              if((year%400==0)||(year%4==0 && year%100!=0))
                 {
                    if(date>=30)
                        {
                            cout<<"\n\a"<<date<<" is Invalid Date ";
                            return 0;
                        }
                 }

               else
                 {
                    if(date>=29)
                       {
                           cout<<"\n\a"<<date<<" is Invalid Date ";
                           return 0;
                       }
                 }
          }

          else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
            {
                 if(date>=32)
                    {
                        cout<<"\n\a"<<date<<" is Invalid Date ";
                        return 0;
                    }
            }

           else
             {
                 if(date>=31)
                    {
                        cout<<"\n\a"<<date<<" is Invalid Date ";
                        return 0;
                    }
             }
    }
    else
    {
        cout<<"\n\a"<<month<<" is Invalid Month";
        return 0;
    }
}

void Day::logic()
{
    int yr,m,n,d,i,a,y;
    char x,z;

  for(yr=1;yr<=year;yr++)
  {

    for(m=1;m<13;m++)
    {
        if(m==1 && yr==1)
            z='f';
         if(yr==year)
         {
              if(m==month+1)
              {
                break;
            }
         }

    if(m==2)
     {
         if((yr%400==0)||(yr%4==0 && yr%100!=0))
         {
               n=29;
         }

         else
         {
                n= 28;
         }
     }

     else
     {
         if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
         {
                n= 31;
         }

        else
        {
                n= 30;
        }
     }


        for(d=1;d<=n;d++)
        {
            for(i=1;i<8;i++)
            {
             for(a=1;a<5;a++)
            {
            if(d==i || d==i+7*a)
            {
                for(y=1; y<8 ; y++)
               {

                    x=z;
                    x++;

                   if(i==y)
                     {
                         if(m==month && d==date && yr==year)
                                     {
                                        display(x);
                                        break;
                                     }
                         if(x=='h')
                            {
                                x='a';
                                z=x;
                            }
                        else
                           z=x;
                     }
               }

            }
              if(d<15)
                break;

            }
        }
        }
    }

  }
}

void Day::display(int x)
{
            cout<<"\nDate : "<<date<<"-"<<month<<"-"<<year;
            cout<<"\nDay  : ";

             switch(x)
            {
                 case 'b' :cout<<"Wednesday";break;
                 case 'c' :cout<<"Thursday";break;
                 case 'd' :cout<<"Friday";break;
                 case 'e' :cout<<"Saturday";break;
                 case 'f' :cout<<"Sunday";break;
                 case 'g' :cout<<"Monday";break;
                 case 'h' :cout<<"Tuesday";break;
            }
}

int main()
{
    Day d;
    int ch,i;

    do
    {
        top:

        cout<<"\n\n\n*-*-*-*-*  MENU  *-*-*-*-*";
        cout<<"\n\n1) Day from given Date";
        cout<<"\n2) Exit";

        cout<<"\nEnter the Choice : ";
        cin>>ch;

        if(ch>0 && ch<3)
        {
            if(ch==1)
            {
                up:

                d.read();
                if(d.checkDays()==0)
                    goto up;
                else
                    d.logic();
                    goto top;

            }
            else
               cout<<"\nGood Bye...\n";
        }
        else
            cout<<"\n\aInvalid Choice ";


    }while(ch!=2);

    return 0;
}

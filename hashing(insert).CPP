
 /**************************************************************************
  **************************************************************************

  A C++ Program to show an example of Hashing.

  **************************************************************************
  **************************************************************************/

 /*************************************************************************

	  By :
		Muhammad Tahir Shahzad  [ MTS ]
		B.C.S Honours  [ 2000-04 ]
		Government College University Lahore
		Pakistan

      E-mail :  mtshome@wol.net.pk

    Web-Site :  www.mts-home.cjb.net  [ www.wol.net.pk/mtshome ]
		www.mtshome.cjb.net   [ www.geocities.com/mtahirshahzad ]

  *************************************************************************/

 /**************************************************************************/
 /**************************************************************************/
 //-----------------------------  Header Files  ---------------------------//
 /**************************************************************************/
 /**************************************************************************/

 # include <iostream.h>
 # include  <fstream.h>
 # include   <string.h>
 # include    <stdio.h>
 # include    <conio.h>

 /**************************************************************************/
 /**************************************************************************/
 //-----------------  Class Declaration & Definition  ---------------------//
 /**************************************************************************/
 /**************************************************************************/

 /**************************************************************************/
 //---------------------------------  Node  -------------------------------//
 /**************************************************************************/

 class Node
 {
    public:
       char sData[25];

       Node* Next;
 };

 /**************************************************************************/
 /**************************************************************************/
 //-------------------------  Global Declarations  ------------------------//
 /**************************************************************************/
 /**************************************************************************/

 # define MAX_ENTRIES  25

 Node* HashTable[MAX_ENTRIES]={NULL};
 Node* Top[MAX_ENTRIES]={NULL};

 /**************************************************************************/
 /**************************************************************************/
 //-------------------------  Function Definitions  -----------------------//
 /**************************************************************************/
 /**************************************************************************/

 /**************************************************************************/
 //------------------------  generate_hash_key( )  ------------------------//
 /**************************************************************************/

 const int generate_hash_key(const char* sData)
 {
    int iHashKey = 0;
    int iLength = strlen(sData);

    int iCode = 0;

    for (int i = 0; i < iLength; i ++)
	iCode += (int)sData[i];

    iHashKey = (iCode%MAX_ENTRIES);

    return iHashKey;
 }

 /**************************************************************************/
 //---------------------------  insert_sData( )  ---------------------------//
 /**************************************************************************/

 void insert_sData( )
 {
    char sData[25];

    cout<<"\n\n\n\t *********   New Element   ********* "<<endl<<endl;
    cout<<"\t Enter a value : ";
    gets(sData);

    int index=generate_hash_key(sData);

    Node* Entry=new Node;

    if(!Entry)
    {
       cout<<"\n\n\n\t Fatal Error : Unable to allcate memory to stroe new element."<<endl;
       cout<<"\n\n\t\t Pres any key to return to Menu. ";

       getch( );
       return;
    }

    if(HashTable[index]==NULL)
    {
       strcpy(Entry->sData,sData);
       Entry->Next=NULL;
       HashTable[index]=Entry;
       Top[index]=Entry;
    }

    else
    {
       strcpy(Entry->sData,sData);
       Entry->Next=NULL;
       Top[index]->Next=Entry;
       Top[index]=Entry;
    }

    cout<<"\n\n\t\t Pres any key to return to Menu. ";

    getch( );
 }

 /**************************************************************************/
 //----------------------------  print_sData( )  ---------------------------//
 /**************************************************************************/

 void print_sData( )
 {
    clrscr( );

    cout<<"\n\n\t *****  HashTable & Data  *****\n"<<endl;

    Node* Print;

    for(int index=0;index<MAX_ENTRIES;index++)
    {
       if(index<10)
	  cout<<"\t HashTable[0"<<index<<"] : ";

       else
	  cout<<"\t HashTable["<<index<<"] : ";

       Print=HashTable[index];

       if(Print!=NULL)
       {
	  while(Print!=NULL)
	  {
	     cout<<Print->sData;

	     Print=Print->Next;

	     if(Print!=NULL)
		cout<<" , ";
	  }

	  cout<<endl;
       }

       else
	  cout<<"-"<<endl;
    }

    cout<<"\n\n\t\t Pres any key to return to Menu. ";

    getch( );
 }

 /**************************************************************************/
 //----------------------------  search_sData( )  --------------------------//
 /**************************************************************************/

 void search_sData( )
 {
    char sData[25];

    cout<<"\n\n\n\t *****  Search an Element  *****\n"<<endl;
    cout<<"\t Enter a value : ";
    cin>>sData;

    int flag=0;
    int index=generate_hash_key(sData);

    Node* Print=HashTable[index];

    if(Print!=NULL)
    {
       while(Print!=NULL)
       {
	  if(strcmp(Print->sData,sData) == 0)
	     flag++;

	  Print=Print->Next;
       }

       if(flag)
	  cout<<"\n\n\t ***  The Search Element is found "<<flag<<" times.";
    }

    if(!flag)
       cout<<"\n\n\t ***  The Search Element is not found."<<endl;

    cout<<"\n\n\n\t\t Pres any key to return to Menu. ";

    getch( );
 }

 /**************************************************************************/
 //---------------------------  show_working( )  --------------------------//
 /**************************************************************************/

 void show_working( )
 {
    char Key=NULL;

    do
    {
       clrscr( );

       gotoxy(10,5);
       cout<<"**********   Implementation of Hashing   **********"<<endl;

       gotoxy(10,8);
       cout<<"Select one of the listed operation :"<<endl;

       gotoxy(15,10);
       cout<<"- Press \'I\' to Insert an Element"<<endl;

       gotoxy(15,12);
       cout<<"- Press \'P\' to Print the HashTable & Data"<<endl;

       gotoxy(15,14);
       cout<<"- Press \'S\' to Search an Element"<<endl;

       gotoxy(15,16);
       cout<<"- Press \'E\' to Exit"<<endl;

       Input:

       gotoxy(10,20);
       cout<<"                      ";

       gotoxy(10,20);
       cout<<"Enter your Choice : ";

       Key=getche( );

       if(int(Key)==27 || Key=='e' || Key=='E')
	  break;

       else if(Key=='i' || Key=='I')
	  insert_sData( );

       else if(Key=='p' || Key=='P')
	  print_sData( );

       else if(Key=='s' || Key=='S')
	  search_sData( );

       else
	  goto Input;
    }
    while(1);
 }

 /**************************************************************************/
 /**************************************************************************/
 //--------------------------------  main( )  -----------------------------//
 /**************************************************************************/
 /**************************************************************************/

 int main( )
 {
    textmode(C4350);

    show_working( );

    return 0;
 }

 /**************************************************************************/
 /**************************************************************************/
 //-------------------------------  THE END  ------------------------------//
 /**************************************************************************/
 /**************************************************************************/
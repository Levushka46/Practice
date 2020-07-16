//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <cstring>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;

class Student{
 public:
 char* Family;   	 //Фамилия
 char* borndate;     //Дата рождения
 char* include_date; //Дата поступления
 char* go_out;       //Отчисление
 char* address;      //Проживание
 char* group;        //Группа

  Student()
  {
	this->Family=new char [255];
	strcpy(Family,"Студент\0'");
	this->borndate=new char [255];
	strcpy(borndate,"09.08.2000\0");
	this->include_date=new char [255];
	strcpy(include_date,"09.08.2000\0");
	this->go_out=new char [255];
	strcpy(go_out,"09.08.2000\0");
	this->address=new char [255];
	strcpy(address,"Ленина\0");
	this->group=new char [255];
	strcpy(group,"213\0");
  }
  void familyrecr(char* t)
  {
   strcpy(Family,t);
  }
  void borndaterecr(char* t)
  {
	strcpy(borndate,t);
  }
  void inclrecr(char* t)
  {
   strcpy(include_date,t);
  }
  void gorecr(char* t)
  {
	strcpy(go_out,t);
  }
  void addressrecr(char* t)
  {
	strcpy(address,t);
  }
  void  grouprecr(char* t)
  {
	strcpy(group,t);
  }
};
const char * LBox[5]= {"Группы:", "113", "213", "313", "413"};
int k=0,k1=0;//базовое кол-во студентов
int m=5;
int i=0,j=0,z=0;// заполнение стринггрида
int razvernyti=0;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	for(int i = 0; i < 5; i ++)
	ListBox1->Items->Add(LBox[i]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int i=0,j=0;//строки, они же студенты
 k=StrToInt(Edit1->Text);
 Student* mas=new Student[k];
 StringGrid1->RowCount=k+1;

 for (i = 1; i <=k; i++)
 {   z=0;
	while (z<m)
	{
		StringGrid1->Cells[z][i]=mas[i-1].Family; //[столбец][строка]
		z++;
		StringGrid1->Cells[z][i]=mas[i-1].borndate;
		z++;
		StringGrid1->Cells[z][i]=mas[i-1].include_date;
		z++;
		StringGrid1->Cells[z][i]=mas[i-1].go_out;
		z++;
		StringGrid1->Cells[z][i]=mas[i-1].address;
		z++;
		StringGrid1->Cells[z][i]=mas[i-1].group;
	}
 }
 delete [] mas;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{


  StringGrid1->Cells[0][0]="Фамилия";
  StringGrid1->Cells[1][0]="Дата рождения";
  StringGrid1->Cells[2][0]="Дата поступления";
  StringGrid1->Cells[3][0]="Дата отчисления";
  StringGrid1->Cells[4][0]="Адрес";
  StringGrid1->Cells[5][0]="Группа";

  StringGrid2->Cells[0][0]="Фамилия";
  StringGrid2->Cells[1][0]="Дата рождения";
  StringGrid2->Cells[2][0]="Дата поступления";
  StringGrid2->Cells[3][0]="Дата отчисления";
  StringGrid2->Cells[4][0]="Адрес";
  StringGrid2->Cells[5][0]="Группа";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  char* str=new char [255];//считывание строки
  k1=StrToInt(Edit2->Text);
  StringGrid1->RowCount=k1+1;
  Student* mas1=new Student[k1];

  if (OpenDialog1->Execute())
 {
		ifstream input(OpenDialog1->FileName.c_str());
		for (i = 0; i<k1;i++)
		{
		input.getline(str,255,'\n');
		 mas1[i].familyrecr(str);
		input.getline(str,255,'\n');
		  mas1[i].borndaterecr(str);
		input.getline(str,255,'\n');
		  mas1[i].inclrecr(str);
		input.getline(str,255,'\n');
		  mas1[i].gorecr(str);
		input.getline(str,255,'\n');
		  mas1[i].addressrecr(str);
		input.getline(str,255,'\n');
		  mas1[i].grouprecr(str);
		}
		input.close();
 }

   for (i = 1; i <=k1; i++)
	{
	z=0;
	while (z<m)
		{
		StringGrid1->Cells[z][i]=mas1[i-1].Family;		//[столбец][строка]
		z++;
		StringGrid1->Cells[z][i]=mas1[i-1].borndate;
		z++;
		StringGrid1->Cells[z][i]=mas1[i-1].include_date;
		z++;
		StringGrid1->Cells[z][i]=mas1[i-1].go_out;
		z++;
		StringGrid1->Cells[z][i]=mas1[i-1].address;
		z++;
		StringGrid1->Cells[z][i]=mas1[i-1].group;
		}
	}
	delete [] mas1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 AnsiString s;
 char* str2=new char[255];//буфер
 int kolvo=StringGrid1->RowCount;
 kolvo--;
 Student* copymas=new Student[kolvo];

 for (i = 1; i <=kolvo; i++)
	{  z=0;
	while (z<m)
		{
		s=StringGrid1->Cells[z][i].c_str();
		strcpy(str2,s.c_str());
		copymas[i-1].familyrecr(str2);
		z++;

		s=StringGrid1->Cells[z][i].c_str();
		strcpy(str2,s.c_str());
		copymas[i-1].borndaterecr(str2);
		z++;

		s=StringGrid1->Cells[z][i].c_str();
		strcpy(str2,s.c_str());
		copymas[i-1].inclrecr(str2);
		z++;

		s=StringGrid1->Cells[z][i].c_str();
		strcpy(str2,s.c_str());
		copymas[i-1].gorecr(str2);
		z++;

		s=StringGrid1->Cells[z][i].c_str();
		strcpy(str2,s.c_str());
		copymas[i-1].addressrecr(str2);
		z++;

		s=StringGrid1->Cells[z][i].c_str();
		strcpy(str2,s.c_str());
		copymas[i-1].grouprecr(str2);
		}
	}

	if (OpenDialog2->Execute())
 {
   ofstream fout(OpenDialog2->FileName.c_str());
	 for (int er=0; er < kolvo; er++) {
	 fout<<copymas[er].Family<<'\n';
	 fout<<copymas[er].borndate<<'\n';
	 fout<<copymas[er].include_date<<'\n';
	 fout<<copymas[er].go_out<<'\n';
	 fout<<copymas[er].address<<'\n';
	 fout<<copymas[er].group<<'\n';
   }
   fout.close();
 }
 delete [] copymas;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	char* str3=new char[255];
	char* strc=new char[12];
	AnsiString s2;
	s2=ListBox1->Items->Strings[ListBox1->ItemIndex];
	strcpy(strc,s2.c_str());

	int max;
	max=StringGrid1->RowCount;
	max--;
	Student* sortmas=new Student[max];

	for (i = 1; i <=max; i++)
	{
	z=0;
	while (z<m)
		{
		s2=StringGrid1->Cells[z][i].c_str();
		strcpy(str3,s2.c_str());
		sortmas[i-1].familyrecr(str3);
		z++;

		s2=StringGrid1->Cells[z][i].c_str();
		strcpy(str3,s2.c_str());
		sortmas[i-1].borndaterecr(str3);
		z++;

		s2=StringGrid1->Cells[z][i].c_str();
		strcpy(str3,s2.c_str());
		sortmas[i-1].inclrecr(str3);
		z++;

		s2=StringGrid1->Cells[z][i].c_str();
		strcpy(str3,s2.c_str());
		sortmas[i-1].gorecr(str3);
		z++;

		s2=StringGrid1->Cells[z][i].c_str();
		strcpy(str3,s2.c_str());
		sortmas[i-1].addressrecr(str3);
		z++;

		s2=StringGrid1->Cells[z][i].c_str();
		strcpy(str3,s2.c_str());
		sortmas[i-1].grouprecr(str3);
		}
	}
	int kolvo=0;
	for (i=1; i <=max; i++) {
		if (StringGrid1->Cells[5][i]==strc) {
		 kolvo++;
		}
	}
 StringGrid2->Visible=true;
 Button5->Visible=true;
 StringGrid2->RowCount=kolvo+1;
 int strvi=0;

	Student grmas[kolvo];
	for (i=1; i <=max; i++) {
		if (StringGrid1->Cells[5][i]==strc) {
		  grmas[strvi]=sortmas[i-1];
		  strvi++;
		}
	}

	for (i = 1; i <=strvi; i++)
 {   z=0;
	while (z<m)
	{
		StringGrid2->Cells[z][i]=grmas[i-1].Family; //[столбец][строка]
		z++;
		StringGrid2->Cells[z][i]=grmas[i-1].borndate;
		z++;
		StringGrid2->Cells[z][i]=grmas[i-1].include_date;
		z++;
		StringGrid2->Cells[z][i]=grmas[i-1].go_out;
		z++;
		StringGrid2->Cells[z][i]=grmas[i-1].address;
		z++;
		StringGrid2->Cells[z][i]=grmas[i-1].group;
	}
 }
 delete [] sortmas;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 AnsiString s3;
 char* str4=new char[255];//буфер
 int kolvo=StringGrid2->RowCount;
 kolvo--;
 Student* copymas=new Student[kolvo];

 for (i = 1; i <=kolvo; i++)
	{  z=0;
	while (z<m)
		{
		s3=StringGrid2->Cells[z][i].c_str();
		strcpy(str4,s3.c_str());
		copymas[i-1].familyrecr(str4);
		z++;

		s3=StringGrid2->Cells[z][i].c_str();
		strcpy(str4,s3.c_str());
		copymas[i-1].borndaterecr(str4);
		z++;

		s3=StringGrid2->Cells[z][i].c_str();
		strcpy(str4,s3.c_str());
		copymas[i-1].inclrecr(str4);
		z++;

		s3=StringGrid2->Cells[z][i].c_str();
		strcpy(str4,s3.c_str());
		copymas[i-1].gorecr(str4);
		z++;

		s3=StringGrid2->Cells[z][i].c_str();
		strcpy(str4,s3.c_str());
		copymas[i-1].addressrecr(str4);
		z++;

		s3=StringGrid2->Cells[z][i].c_str();
		strcpy(str4,s3.c_str());
		copymas[i-1].grouprecr(str4);
		}
	}

	if (OpenDialog3->Execute())
 {
   ofstream fout(OpenDialog3->FileName.c_str());
	 for (int er1=0; er1 < kolvo; er1++) {
	 fout<<copymas[er1].Family<<'\n';
	 fout<<copymas[er1].borndate<<'\n';
	 fout<<copymas[er1].include_date<<'\n';
	 fout<<copymas[er1].go_out<<'\n';
	 fout<<copymas[er1].address<<'\n';
	 fout<<copymas[er1].group<<'\n';
   }
   fout.close();
 }
  delete [] copymas;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
int razzmer;
razzmer=StringGrid1->RowCount;
razzmer--;
Student* sortirmas=new Student[razzmer];
AnsiString s4;
char* strsortir=new char[255];
for (i = 1; i <=razzmer; i++)
	{  z=0;
	while (z<m)
		{
		s4=StringGrid1->Cells[z][i].c_str();
		strcpy(strsortir,s4.c_str());
		sortirmas[i-1].familyrecr(strsortir);
		z++;

		s4=StringGrid1->Cells[z][i].c_str();
		strcpy(strsortir,s4.c_str());
		sortirmas[i-1].borndaterecr(strsortir);
		z++;

		s4=StringGrid1->Cells[z][i].c_str();
		strcpy(strsortir,s4.c_str());
		sortirmas[i-1].inclrecr(strsortir);
		z++;

		s4=StringGrid1->Cells[z][i].c_str();
		strcpy(strsortir,s4.c_str());
		sortirmas[i-1].gorecr(strsortir);
		z++;

		s4=StringGrid1->Cells[z][i].c_str();
		strcpy(strsortir,s4.c_str());
		sortirmas[i-1].addressrecr(strsortir);
		z++;

		s4=StringGrid1->Cells[z][i].c_str();
		strcpy(strsortir,s4.c_str());
		sortirmas[i-1].grouprecr(strsortir);
		}
	}

	for (i = 1; i < razzmer; i++)
	{
		for (j = 0; j < razzmer-1; j++)
		{
			if (strcmp(sortirmas[j].Family, sortirmas[j + 1].Family) > 0)
			{
			swap(sortirmas[j], sortirmas[j + 1]);
			}
		}
	}

   for (i = 1; i <=razzmer; i++)
	{
	z=0;
	while (z<m)
		{
		StringGrid1->Cells[z][i]=sortirmas[i-1].Family;		//[столбец][строка]
		z++;
		StringGrid1->Cells[z][i]=sortirmas[i-1].borndate;
		z++;
		StringGrid1->Cells[z][i]=sortirmas[i-1].include_date;
		z++;
		StringGrid1->Cells[z][i]=sortirmas[i-1].go_out;
		z++;
		StringGrid1->Cells[z][i]=sortirmas[i-1].address;
		z++;
		StringGrid1->Cells[z][i]=sortirmas[i-1].group;
		}
	}
    delete []sortirmas;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if (razvernyti%2==0) {
	   Form1->Constraints->MaxHeight=690;
		Form1->Height=690;
		Form1->Constraints->MinHeight=690;
		razvernyti++;
	}
	else
	if (razvernyti%2>0) {
		Form1->Constraints->MaxHeight=350;
		Form1->Height=350;
		Form1->Constraints->MinHeight=350;
		 razvernyti++;
	}


}
//---------------------------------------------------------------------------





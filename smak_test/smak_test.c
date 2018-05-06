/*=============================================================================
                    Programa de teste de libsk_access.so
					importacao dinamica.
                    Compilar com >gcc -o foo foo.c -ldl
                    ou gcc -m32 -o foo foo.c -ldl   (em maquinas 64 bits)
                    
   V1.0 - 09/09/2011
==============================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <curses.h>
#include <string.h>

	 void *lib;
	 char *error;

/* Prototipos das funções  */
	 void (*Send_Data)(char data);
    void (*Send_Disp_Ctrl)(char data);
	 void (*Clear_Disp)();
	 void (*Clear_L1)();
	 void (*Clear_L2)();
	 void (*Cursor_Off)();
	 void (*Cursor_On)();
	 void (*Cursor_Blink)();
	 void (*Back_Space)();
	 void (*Line_Feed)();
	 void (*Carriage_Return)();
	 void (*Gotoxy)(char x, char y);
	 void (*Disp_Char)(char data);
	 void (*Disp)(char *data);
	 char (*Get_Cursor)(char *x_pos, char *y_pos);
	 char (*Get_Status)();
	 void (*Set_Page0)();
	 void (*Set_Page1)();
	 void (*Free_Sk_Access)();
	 int  (*GetOperatingSystem)();
	 void (*Set_Eco_On)();
	 void (*Set_Eco_Off)();
	 void (*Set_Udg)(char caracter, char def0, char def1, char def2, char def3, char def4,
						  char def5, char def6, char def7);
	 int  (*Set_Interface)(char *interf);
	 void (*Get_Dll_Version)(char *ver);
	 int  (*Select_Interface)();
	 void (*Reset_Interface)();
	 void (*Redirect)();
	 int  (*Get_Data_Rs)();
	 int  (*Get_Data)();
	 void (*Get_Firmware_Version)();
	 _Bool(*Get_Com_Type)();
	 void (*Keyb_Reset)();
	 void (*Log_On)();
	 void (*Log_Off)();
	 void (*Get_Serial_Number)(char *ser);
	 void (*Get_Coms)(char *Coms);
	 void (*Update_Leds_On)();
	 void (*Update_Leds_Off)();
	 void (*Scroll_Enable_On)();
	 void (*Scroll_Enable_Off)();
	 void (*Enable_Keyboard)();
	 void (*Disable_Keyboard)();
	 void (*Set_Psw_On)();
	 void (*Set_Psw_Off)();
	 int  (*Task_Exist)(char *ExeFileName);
	 int  (*Kill_Task)(char *ExeFileName);
	 int  (*Get_Current_Interface)();
	 int  (*Buffer_In_Data)();

/*=============================================================================
                     Executa dlsym com tratamenteo de erro
==============================================================================*/    
void *dl_sym(void *handler,char *name){
  char *error;
  void *result;
  result = dlsym(handler,name);
  if ((error = dlerror()) != NULL)  {
	 fputs(error, stderr);
	 exit(1);
  }
  return(result);
}
/*=============================================================================
                               Abre Shared Object
==============================================================================*/
void Open_So(){
	 
/* Abre So  */
//	 lib = dlopen("/usr/lib/libsk_access.so" , RTLD_NOW);
	 lib = dlopen("./libsk_access.so" , RTLD_NOW);
	 if (!lib) {
		  fputs (dlerror(), stderr);
		  exit(1);
	 }
	 
/* Refencia funcões  */
	 Send_Data = dl_sym( lib , "Send_Data");
    Send_Disp_Ctrl = dl_sym( lib , "Send_Disp_Ctrl");
	 Clear_Disp = dl_sym( lib , "Clear_Disp");
	 Clear_L1 = dl_sym( lib , "Clear_L1");
	 Clear_L2 = dl_sym( lib , "Clear_L2");
	 Cursor_Off = dl_sym( lib , "Cursor_Off");
	 Cursor_On = dl_sym( lib , "Cursor_On");
	 Cursor_Blink = dl_sym( lib , "Cursor_Blink");
	 Back_Space = dl_sym( lib , "Back_Space");
	 Line_Feed = dl_sym( lib , "Line_Feed");
	 Carriage_Return = dl_sym( lib , "Carriage_Return");
	 Gotoxy = dl_sym( lib , "Gotoxy");
	 Disp_Char = dl_sym( lib , "Disp_Char" );
	 Disp = dl_sym( lib , "Disp");
	 Get_Cursor = dl_sym( lib , "Get_Cursor");
	 Get_Status = dl_sym( lib , "Get_Status");
	 Set_Page0 = dl_sym( lib , "Set_Page0");
	 Set_Page1 = dl_sym( lib , "Set_Page1");
	 Free_Sk_Access = dl_sym( lib , "Free_Sk_Access");
	 GetOperatingSystem = dl_sym( lib , "GetOperatingSystem");
	 Set_Eco_On = dl_sym( lib , "Set_Eco_On");
	 Set_Eco_Off = dl_sym( lib , "Set_Eco_Off");
	 Set_Udg = dl_sym( lib , "Set_Udg");
	 Set_Interface = dl_sym( lib , "Set_Interface");
	 Get_Dll_Version = dl_sym( lib , "Get_Dll_Version");
	 Select_Interface = dl_sym( lib , "Select_Interface");
	 Reset_Interface = dl_sym( lib , "Reset_Interface");
	 Redirect = dl_sym( lib , "Redirect");
	 Get_Data_Rs = dl_sym( lib , "Get_Data_Rs");
	 Get_Data = dl_sym( lib , "Get_Data");
	 Get_Firmware_Version = dl_sym( lib , "Get_Firmware_Version");
	 Get_Com_Type = dl_sym( lib , "Get_Com_Type");
	 Keyb_Reset = dl_sym( lib , "Keyb_Reset");
	 Log_On = dl_sym( lib , "Log_On" );
	 Log_Off = dl_sym( lib , "Log_Off");
	 Get_Serial_Number = dl_sym( lib , "Get_Serial_Number");
//	 Get_Coms = dl_sym( lib , "Get_Coms");								//Funcoes nao implementadas		
//	 Update_Leds_On = dl_sym( lib , "Update_Leds_On");
//	 Update_Leds_Off = dl_sym( lib , "Update_Leds_Off");
//	 Scroll_Enable_On = dl_sym( lib , "Scroll_Enable_On");
//	 Scroll_Enable_Off = dl_sym( lib , "Scroll_Enable_Off");
	 Enable_Keyboard = dl_sym( lib , "Enable_Keyboard");
	 Disable_Keyboard = dl_sym( lib , "Disable_Keyboard");
	 Set_Psw_On = dl_sym( lib , "Set_Psw_On");
	 Set_Psw_Off = dl_sym( lib , "Set_Psw_Off");
//	 Task_Exist = dl_sym( lib , "Task_Exist");
//	 Kill_Task = dl_sym( lib , "Kill_Task");
	 Get_Current_Interface = dl_sym( lib , "Get_Current_Interface");
	 Buffer_In_Data = dl_sym( lib , "Buffer_In_Data");
}
/*=============================================================================
                             Le entrada do usuario
==============================================================================*/
int Get_User_Input(){
  char ch[10];
  int c;
  
  for(c=0;c<5;c++)
	 printf("\n");
  
  printf(" 1=Send_Data(0x41)       2=Send_Disp_Ctrl     3=Clear_Disp         4=Clear_L1\n");
  printf(" 5=Clear_L2              6=Cursor_Off         7=Cursor_On          8=Cursor_Blink\n");
  printf(" 9=Back_Space           10=Line_Feed         11=Carriage_Return   12=Gotoxy(20,2)\n");
  printf("13=Disp_Char(""A"")		14=Disp(""Teste Teclado Smak"");              15=Get_Cursor\n");
  printf("16=Get_Status           17=Set_Page0         18=Set_Page1         19=GetOperatingSystem\n");
  printf("20=Set_Eco_On           21=Set_Eco_Off       22=Set_Psw_On        23=Set_Psw_Off\n");
  printf("24=Get_Dll_Version      25=Get_Firmware_Version                   26=Get_Serial_Number\n");
  printf("27=Enable_keyboard      28=Disable_keyboard  29=Log_On            30=Log_Off\n");
  printf("31=Keyb_Reset           32=Reset_Interface   33=Redirect\n");
  printf("34=Exit\n");
  
  
  gets(ch);
  
  return(atoi(ch));
}
/*=============================================================================
                            Executa funçõao da So
==============================================================================*/
void Exec_So(int func){
  
  unsigned char a,b,c,d;
  int i,f,g;
  char s[100];
  
  
  switch (func){
	 case 1:(*Send_Data)((char)0x41);
				break;
	 case 2:(*Send_Disp_Ctrl)((char)0x01);
	         break;
	 case 3:(*Clear_Disp)();
			   break;
	 case 4:(*Clear_L1)();
		      break;
	 case 5:(*Clear_L2)();
		      break;
	 case 6:(*Cursor_Off)();
		      break;
	 case 7:(*Cursor_On)();
		      break;
	 case 8:(*Cursor_Blink)();
		      break;
	 case 9:(*Back_Space)();
		      break;
	 case 10:(*Line_Feed)();
		      break;
	 case 11:(*Carriage_Return)();
		      break;
	 case 12:(*Gotoxy)(20,2);
		      break;
	 case 13:(*Disp_Char)((char)0x41);
		      break;
	 case 14:do{
				char ch[10];
				printf("Digite algo e pressioner ENTRA, para sair digite 99 + ENTRA\n");
				gets(ch);
				(*Disp)(ch);
			}while (true);	 
//			  (*Disp)("Teste Teclado Smak");
		      break;
	 case 15:a = (*Get_Cursor)(&b , &c);
				printf("Cursor em x=%d e y=%d, index=%d\n",b,c,a);
		      break;
	 case 16:a = (*Get_Status)();
	         switch(a){
				  case(0):printf("Status = OK");
				          break;
				  case(1):printf("Status = Err");
				          break;
				  case(0xff):printf("Status = Time_Out");
				          break;
				}
		      break;				
	 case 17:(*Set_Page0)();
		      break;
	 case 18:(*Set_Page1)();
		      break;
	 case 19:i = (*GetOperatingSystem)();
				printf("Operating System = %d",i);
		      break;
	 case 20:(*Set_Eco_On)();
		      break;
	 case 21:(*Set_Eco_Off)();
		      break;
	 case 22:(*Set_Psw_On)();
		      break;
	 case 23:(*Set_Psw_Off)();
		      break;
	 case 24:(*Get_Dll_Version)(s);
				printf("Dll Version = %s",s);
		      break;
	 case 25:(*Get_Firmware_Version)(s);
	 			printf("Firmware Version = %s",s);
		      break;
	 case 26:(*Get_Serial_Number)(s);
	 			printf("Serial Number = %s",s);	 
		      break;
	 case 27:(*Enable_Keyboard)();
	 			break;
	 case 28:(*Disable_Keyboard)();
	 			break;
	 case 29:(*Log_On)();
	 			break;
	 case 30:(*Log_Off)();
	 			break;
	 case 31:(*Keyb_Reset)();
	 			break;
	 case 32:(*Reset_Interface)();
	 			break;				
	 case 33:(*Redirect)();
	 			break;
	 case 34:(*Free_Sk_Access)();
	         break;
  }//Switch
}
/*=============================================================================
                             Programa principal
==============================================================================*/

int main(int argc, char **argv) {
  
    int x;
	 
	 Open_So();
	 (*Log_On)();
	do{
		char ch[10];
		printf("Digite algo e pressione ENTRA, para sair digite 99 + ENTRA\n");
		gets(ch);
		x = atoi(ch);
		(*Clear_Disp)();
		(*Disp)(ch);
	}while (x!=99);	 	 
/*	 do{
	   x = Get_User_Input();
		Exec_So(x);
	 }while (x!=34);	 
*/
	 dlclose(lib);
}
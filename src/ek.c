/***************************************************************************
*    Uzak Diyarlar, Rom2.4b6 tabanl� T�rk�e Mud                            *
*    http://www.uzakdiyarlar.com                                           *
*    http://sourceforge.net/projects/uzakdiyarlar                          *
*    �zg�r Y�lmaz (yelbuke@gmail.com)                                      *
***************************************************************************/
#include "ek.h"

const struct pers_suffix_type pers_suffix_table[] =
{
	{"sS"	,"birisinin"	,"bir �l�ms�z�n"	,"n"	,"�n"	,"in"	,"un"	,"�n"	},
	{"mM"	,"birisini"		,"bir �l�ms�z�"		,"y"	,"�"	,"i"	,"u"	,"�"	},
	{"eE"	,"birisine"		,"bir �l�ms�ze"		,"y"	,"a"	,"e"	,"a"	,"e"	},
	{"yY"	,"birisinde"	,"bir �l�ms�zde"	,"d"	,"a"	,"e"	,"a"	,"e"	},
	{"zZ"	,"birisinden"	,"bir �l�ms�zden"	,"d"	,"an"	,"en"	,"an"	,"en"	},
    {NULL	,NULL			,NULL				,NULL	,NULL	,NULL	,NULL	,NULL	}
};

char *ekler (CHAR_DATA *to, CHAR_DATA *ch, char *format)
{
	int say;//pers_suffix_table'da kacinci elemanin okunacagini tutuyor.
	char *i, *ek;// i BUF'u point edecek.
	char buf[MAX_STRING_LENGTH];//return olacak bilgi burada 
	/* SAY de�i�kenine de�eri atan�yor */
	for(say=0;pers_suffix_table[say].belirtec[0] != '\0';say++)
	{
		if(	pers_suffix_table[say].belirtec[0]==*format ||
			pers_suffix_table[say].belirtec[1]==*format	)
				break;
	}
	if(say>=5)//tablodaki do�ru eleman� bulamad��� i�in ��kme olmas�n diye.
		say=1;
	buf[0]='\0';
	i=NULL;
	if(can_see(to,ch))
	{
		sprintf(buf,"%s%s",	!IS_NPC(ch)?ch->name:ch->short_descr,
							!IS_NPC(ch)?"'":"");
		/*  sondaki sessizin yumu�amas�. asl�nda tek heceli kelimelerde
		 *  yumusama olmaz. ama tek hece kontrol� yok.
		 */
		if(IS_NPC(ch))
		{
			switch( ch->short_descr[strlen(ch->short_descr)-1] )
			{
				case 'p':
					buf[strlen(buf)-1]='b';
					break;
				case '�':
					buf[strlen(buf)-1]='c';
					break;
				case 't':
					buf[strlen(buf)-1]='d';
					break;
				case 'k':
					buf[strlen(buf)-1]='g';
					break;
			}
		}
		ek=NULL;// ek ve i yerine BUF kullanilabilir mi
		ek=son_harf_unlu(ch,say);
		strcat(buf,ek);
		i=buf;
		return i;
	}
	strcpy(buf,pers_suffix_table[say].birisi);
	i=buf;
	return i;
}

char * son_harf_unlu(CHAR_DATA *ch, int say)
{
	char isim[MAX_STRING_LENGTH];
	char buf[MAX_STRING_LENGTH];
	char *ptr;
	int number;
	ptr=buf;

	(!IS_NPC(ch))?strcpy(isim,ch->name):strcpy(isim,ch->short_descr);
	
	buf[0]='\0';
	for(number=1;strlen(isim)>=number;number++)
	{
		switch(isim[strlen(isim)-number])
		{
			case 'a': case '�':
				if(say>2)
				{
					sprintf(buf,"d%s",pers_suffix_table[say].bir);
					return ptr;
				}
				sprintf(buf,"%s%s",(number==1)?(pers_suffix_table[say].sesli_eki):(""),pers_suffix_table[say].bir);
				return ptr;
			case 'e': case 'i':
				if(say>2)
				{
					sprintf(buf,"d%s",pers_suffix_table[say].iki);
					return ptr;
				}
				sprintf(buf,"%s%s",(number==1)?(pers_suffix_table[say].sesli_eki):(""),pers_suffix_table[say].iki);
				return ptr;
			case 'o': case 'u':
				if(say>2)
				{
					sprintf(buf,"d%s",pers_suffix_table[say].uc);
					return ptr;
				}
				sprintf(buf,"%s%s",(number==1)?(pers_suffix_table[say].sesli_eki):(""),pers_suffix_table[say].uc);
				return ptr;
			case '�': case '�':
				if(say>2)
				{
					sprintf(buf,"d%s",pers_suffix_table[say].dort);
					return ptr;
				}
				sprintf(buf,"%s%s",(number==1)?(pers_suffix_table[say].sesli_eki):(""),pers_suffix_table[say].dort);
				return ptr;
		}
	}
	sprintf(buf,"%s",pers_suffix_table[say].bir);
	return ptr;
}

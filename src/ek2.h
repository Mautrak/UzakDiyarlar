/***************************************************************************
*    Uzak Diyarlar, Rom2.4b6 tabanl� T�rk�e Mud                            *
*    http://www.uzakdiyarlar.com                                           *
*    http://sourceforge.net/projects/uzakdiyarlar                          *
*    �zg�r Y�lmaz (yelbuke@gmail.com)                                      *
***************************************************************************/
struct sonek_type
{
	char *ek[5];
};

extern	const	struct	sonek_type	sonek_table[];


bool	bu_harf_unlu_mu		args((char harf));
bool	son_harf_unlu_mu	args((char *sozcuk));
char	son_unlu_harf_hangisi	args((char *sozcuk));
char	*ek_olustur		args((char *sozcuk, char tip));

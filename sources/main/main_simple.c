/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:04:01 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/28 11:26:32 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

void	afficherSeparateur(const char *nom);
int		check_string (char * s1, char *s2);

int	test_strncmp ();
int	test_isalpha ();
int	test_isdigit ();
int test_isalnum ();
int test_isascii ();
int test_isprint ();
int test_strlen  ();
int	test_memcmp  ();
int	test_strdup  ();
int	test_strchr  ();
int	test_strlcat ();
int	test_atoi    ();
int	test_substr  ();
int test_strnstr ();
int test_strjoin ();
int test_memchr  ();
int test_strtrim ();
int test_split   ();
int test_itoa    ();
int test_strmapi ();
int test_striteri();
int test_putchar ();
int test_putstr  ();
int test_putendl ();
int test_putnbr  ();
int test_memset  ();
int test_bzero   ();
int test_memcpy  ();
int test_memmove ();
int test_strlcpy ();
int test_toupper ();
int test_tolower ();
int test_strrchr ();
int test_calloc  ();

typedef struct 
{
    const char *nom;
    int (*test)(void);
    int etat;
} TestFonction;


int	main(/*int nbargs, char **args*/)
{
	TestFonction tests[] = 
	{
		{"ft_isalpha"   , test_isalpha   , 0},
		{"ft_isdigit"   , test_isdigit   , 0},
		{"ft_isalnum"   , test_isalnum   , 0},
		{"ft_isascii"   , test_isascii   , 0},
		{"ft_isprint"   , test_isprint   , 0},
		{"ft_strlen"    , test_strlen    , 0},
		{"ft_memset"    , test_memset    , 0},
		{"ft_bzero"     , test_bzero     , 0},
		{"ft_memcpy"    , test_memcpy    , 0},
		{"ft_memmove"   , test_memmove   , 0},
		{"ft_strlcpy"   , test_strlcpy   , 0},
		{"ft_strlcat"   , test_strlcat   , 0},
		{"ft_toupper"   , test_toupper   , 0},
		{"ft_tolower"   , test_tolower   , 0},
		{"ft_strchr"    , test_strchr    , 0},
		{"ft_strrchr"   , test_strrchr   , 0},
		{"ft_strncmp"   , test_strncmp   , 0},
		{"ft_memchr"    , test_memchr    , 0},
		{"ft_memcmp"    , test_memcmp    , 0},
		{"ft_strnstr"   , test_strnstr   , 0},
		{"ft_atoi"      , test_atoi      , 0},
		{"ft_calloc"    , test_calloc    , 0},
		{"ft_strdup"    , test_strdup    , 0},
		{"ft_substr"    , test_substr    , 0},
		{"ft_strjoin"   , test_strjoin   , 0},
		{"ft_strtrim"   , test_strtrim   , 0},
		{"ft_split"     , test_split     , 0},
		{"ft_itoa"      , test_itoa      , 0},
		{"ft_strmapi"   , test_strmapi   , 0},
		{"ft_striteri"  , test_striteri  , 0},
		{"ft_putchar_fd", test_putchar   , 0},
		{"ft_putstr_fd" , test_putstr    , 0},
		{"ft_putendl_fd", test_putendl   , 0},
		{"ft_putnbr_fd" , test_putnbr    , 0},
	};

	int nombreTests = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < nombreTests; i++) 
	{
        afficherSeparateur(tests[i].nom);
        tests[i].etat = tests[i].test();
        printf("\n");
    }

	printf ("+-----------------------------------------------------------------------------------------------+\n");
	printf ("|                                            Resultats                                          |\n");
	printf ("+-----------------------------------------------------------------------------------------------+\n");

	printf("\n");

	printf("%-25s %10s\n\n", "FONCTIONS", "RESULTAT");
	
	for (int i = 0; i < nombreTests; i++)
	{
		if (tests[i].etat == 0)
			printf("%-25s %20s\n", tests[i].nom, "\033[31mKO\033[00m");
		else if (tests[i].etat == 1)
			printf("%-25s %20s\n", tests[i].nom, "\033[32mOK\033[00m");
		else
			printf("%-25s %20s\n", tests[i].nom, "\033[33m??\033[00m");
	}

	printf("\nCoin coin !\n");
}

/* ------------------------------ ft_calloc.c ---------------------------- */

int check_calloc(size_t nmemb, size_t size);

int test_calloc ()
{
	int result = 1;

    if (!check_calloc(      10,    sizeof(int))) {result = 0;}
    if (!check_calloc(      10, sizeof(double))) {result = 0;}
    if (!check_calloc(       5,              0)) {result = 0;}
    if (!check_calloc(    1000,   sizeof(char))) {result = 0;}

    return result;
}

int check_calloc(size_t nmemb, size_t size)
{
    void *ptr_lib =    calloc(nmemb, size);
    void *ptr_ft  = ft_calloc(nmemb, size);

    printf("\033[35mft_calloc && calloc (%lu, %lu)\033[00m\n\n", nmemb, size);

    if (ptr_lib == NULL && ptr_ft == NULL)
    {
        printf("\033[32mOK\033[00m : Les deux fonctions retournent NULL (overflow ou erreur).\n");
        return 1;
    }
    if (ptr_lib == NULL || ptr_ft == NULL)
    {
        printf("\033[31mKO\033[00m : Une seule fonction retourne NULL.\n");
        free(ptr_lib);
        free(ptr_ft);
        return 0;
    }

    int cmp = (memcmp(ptr_lib, ptr_ft, nmemb * size) == 0);

    if (!cmp)
        printf("\033[31mKO\033[00m : Les zones mémoire ne sont pas identiques.\n");
    else
        printf("\033[32mOK\033[00m : Zones mémoire identiques et initialisées à zéro.\n");

    free(ptr_lib);
    free(ptr_ft);
    return cmp;
}

/* ------------------------------ ft_bzero.c ---------------------------- */

int check_bzero();

int test_bzero ()
{
	int	result = 1;

	if (!check_bzero()) {result = 0;}

    return (result);
}

int check_bzero ()
{
	char str[] = "The leader at Cyllage Gym in Rock Pokémon.";
	printf("\033[35m------------ Fonction libc ------------\033[00m\n");
	printf("\n\033[34mBefore bzero():\033[00m %s\n\n", str);
	bzero(str + 11, 6);
	printf("\033[34mAfter bzero():\033[00m %s\n\n", str);
	
	printf("\033[35m------------ Fonction libft ------------\033[00m\n");
	char str1[] = "The leader at Cyllage Gym in Rock Pokémon.";
	printf("\n\033[34mBefore bzero():\033[00m %s\n\n", str1);
	ft_bzero(str1 + 11, 6);
	printf("\033[34mAfter bzero():\033[00m %s\n\n", str1);

	return(!strcmp(str, str1));
}

/* ------------------------------ ft_memset.c ---------------------------- */

int	check_memset (char *s, int c, size_t n);

int	test_memset ()
{
	int	result = 1;
	char str1[] = "Swimmer Girls gave a Micle Berry to Slowpoke.";
	char str2[] = "You can earn the Thunder Badge at Vermilion Gym.";

	if (!check_memset( str1     , '*', 12)) {result = 0;}
	if (!check_memset((str2 + 6), '@',  5)) {result = 0;}

    return (result);
}

int	check_memset (char *s, int c, size_t n)
{
	int	result = 1;
	char *dup = strdup(s);
	char *rep = memset(dup, c, n);

	printf("\033[35mft_memset(%s, %d, %lu)\033[00m\n\n", s, c, n);
	ft_memset(s, c, n);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", s);

	result = check_string(rep, s);
	free(dup);
	return (result);
}

/* ------------------------------ ft_putnbr_fd.c ---------------------------- */

int test_putnbr ()
{
	int n1 =    1456;
	int n2 =     -12;
	int n3 =       0;
	int n4 = INT_MAX;
	int n5 = INT_MIN;

	ft_putnbr_fd(n1, 1);
	printf(" / %d\n", n1);
	ft_putnbr_fd(n2, 1);
	printf(" / %d\n", n2);
	ft_putnbr_fd(n3, 1);
	printf(" / %d\n", n3);
	ft_putnbr_fd(n4, 1);
	printf(" / %d\n", n4);
	ft_putnbr_fd(n5, 1);
	printf(" / %d\n", n5);
	
	return (2);
}

/* ------------------------------ ft_putendl_fd.c ---------------------------- */

int test_putendl ()
{
	ft_putendl_fd("Nurse took Route 9 from Spikemuth to Route 9 Tunnel.", 1);
	return (2);
}

/* ------------------------------ ft_putstr_fd.c ---------------------------- */

int test_putstr ()
{
	ft_putstr_fd("The leader at Laverre Gym specializes in Fairy Pokémon.\n", 1);
	return (2);
}

/* ------------------------------ ft_putchar_fd.c ---------------------------- */

int test_putchar ()
{
	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	return (2);
}

/* ------------------------------ ft_striteri.c ---------------------------- */

int		check_striteri(char *s, char *rep);

void	iter(unsigned int i, char * s) 
{
	if (i % 2 == 0)
		*s = toupper(*s);
}

int test_striteri ()
{
	int	result = 1;
	char s1[] = "You can earn the Volcano Badge at Cinnabar Gym.";
	char s2[] = "";
	
	if (!check_striteri(s1, "YoU CaN EaRn tHe VOlCaNo BAdGe aT CiNnAbAr GYm.")) {result = 0;}
	if (!check_striteri(s2,                                                "")) {result = 0;}

	return (result);
}

int check_striteri (char *s, char *rep)
{
	int	result = 1;

	printf("\033[35mft_striteri(%s)\033[00m\n\n", s);
	ft_striteri(s, iter);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", s);

	result = check_string(rep, s);
	return (result);
}


/* ------------------------------ ft_strmapi.c ---------------------------- */

char 	strmapi_destroyer(unsigned int i, char c);
int		check_schnappi(char *s, char *rep);

int test_strmapi ()
{
	int	result = 1;
	char *s1 = "Paras evolved into Parasect.";
	char *s2 = "";
	
	if (!check_schnappi(s1, "PaRaS EvOlVeD InTo PArAsEcT.")) {result = 0;}
	if (!check_schnappi(s2,                             "")) {result = 0;}

	return (result);
}

int		check_schnappi(char *s, char *rep)
{
	int	result = 1;

	printf("\033[35mft_strmapi(%s)\033[00m\n\n", s);
	char *dup2 = ft_strmapi(s, strmapi_destroyer);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", dup2);

	result = check_string(rep, dup2);
	free (dup2);
	return (result);
}

char strmapi_destroyer(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper(c));
	else
		return (c);
}

/* ------------------------------ ft_split.c ---------------------------- */

int test_split (void)
{
	int result = 1;
	
	char *string = "Umbreon User journeyed along       Route 12.    ";
	char c = ' ';

	char **test = ft_split(string, c);

	printf("1er  mot = |%s|\n", test[0]);
	if(!check_string(test[0],  "Umbreon")) {result = 0;}
	printf("2eme mot = |%s|\n", test[1]);
	if(!check_string(test[1],     "User")) {result = 0;}
	printf("3eme mot = |%s|\n", test[2]);
	if(!check_string(test[2],"journeyed")) {result = 0;}
	printf("4eme mot = |%s|\n", test[3]);
	if(!check_string(test[3],    "along")) {result = 0;}
	printf("5eme mot = |%s|\n", test[4]);
	if(!check_string(test[4],    "Route")) {result = 0;}
	printf("6eme mot = |%s|\n", test[5]);
	if(!check_string(test[5],      "12.")) {result = 0;}
	printf("7eme mot = |%s|\n", test[6]);
	if(test[6])                            {result = 0;}

	free(test[0]);
	free(test[1]);
	free(test[2]);
	free(test[3]);
	free(test[4]);
	free(test[5]);
	free(test[6]);
	free(test);

	return (result);
}

/* ------------------------------ ft_itoa.c ---------------------------- */

int	check_itoa (int n, char *rep);

int test_itoa (void)
{
	int result = 1;
	
	int	n1 =    1095;
	int n2 =    -465;
	int n3 =       0;
	int n4 = INT_MAX;
	int n5 = INT_MIN;

	if (!check_itoa(n1,           "1095")) {result = 0;}
	if (!check_itoa(n2,           "-465")) {result = 0;}
	if (!check_itoa(n3,              "0")) {result = 0;}
	if (!check_itoa(n4,     "2147483647")) {result = 0;}
	if (!check_itoa(n5,    "-2147483648")) {result = 0;}
	
	return (result);
}

int	check_itoa (int n, char *rep)
{
	int	result = 1;

	printf("\033[35mft_itoa(%d)\033[00m\n\n", n);
	char *dup2 = ft_itoa(n);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", dup2);

	result = check_string(rep, dup2);
	free (dup2);
	return (result);
}


/* ------------------------------ ft_strtrim.c ---------------------------- */

int check_strtrim (char *s1, char *set, char *rep);

int test_strtrim ()
{
	int 	result = 1;
	char	*string1 = "  064515Psyduck evolved into 6 Golduck.564127";
	char	*string2 = "";
	char	*set = " 0123456789";

	if (!check_strtrim(string1,     set, "Psyduck evolved into 6 Golduck.")) {result = 0;}
	if (!check_strtrim(string1, string2,                           string1)) {result = 0;}
	if (!check_strtrim(string2,     set,                                "")) {result = 0;}

	return (result);
}

int check_strtrim (char *s1, char *set, char *rep)
{
	int	result = 1;

	printf("\033[35mft_strtrim(%s, %s)\033[00m\n\n", s1, set);
	char *dup2 = ft_strtrim(s1, set);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", dup2);

	result = check_string(dup2, rep);
	free(dup2);

	return (result);
}

/* ------------------------------ ft_strjoin.c ---------------------------- */

int check_strjoin (char *s1, char *s2, char *rep);

int test_strjoin ()
{
	int 	result = 1;
	char	*string1 = "Psyduck evolved into Golduck.";
	char	*string2 = " Golduck isn't a psy pokemon.";
	char	*string3 = "";
	//char	*string4 = NULL;

	if (!check_strjoin(string1, string2, "Psyduck evolved into Golduck. Golduck isn't a psy pokemon.")) {result = 0;}
	if (!check_strjoin(string1, string3,                              "Psyduck evolved into Golduck.")) {result = 0;}
	if (!check_strjoin(string3, string2,                              " Golduck isn't a psy pokemon.")) {result = 0;}
	if (!check_strjoin(string3, string3,                                                           "")) {result = 0;}
	// if (!check_strjoin(string1, string4, "")) {result = 0;}
	// if (!check_strjoin(string4, string1, "")) {result = 0;}
	// if (!check_strjoin(string4, string4, "")) {result = 0;}

	return (result);
}

int check_strjoin (char *s1, char *s2, char *rep)
{
	int	result = 1;

	printf("\033[35mft_subjoin(%s, %s)\033[00m\n\n", s1, s2);
	char *dup2 = ft_strjoin(s1, s2);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", dup2);

	result = check_string(dup2, rep);
	free(dup2);
	return (result);
}

/* ------------------------------ ft_substr.c ---------------------------- */

int	check_substr();

int	test_substr ()
{
	int	result = 1;
	char *string1 = "The leader at Celadon Gym specializes in Grass Pokémon.";
	char *string2 = "0123456789";

	if (check_substr(string1,   7,  12, "der at Celad") != 1) {result = 0;}
	if (check_substr(string1, 789,  12, ""            ) != 1) {result = 0;}
	if (check_substr(string2,   8, 456, "89"          ) != 1) {result = 0;}
	if (check_substr(string2,   9,  10, "9"           ) != 1) {result = 0;}
	if (check_substr(   NULL,   9,  10, NULL          ) != 1) {result = 0;}

	return (result);
}

int	check_substr(char *s, unsigned int start, size_t len, char *rep)
{
	int result = 1;
	
	printf("\033[35mft_substr(%s, %d, %lu)\033[00m\n\n", s, start, len);
	char *dup2 = ft_substr(s, start, len);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", dup2);

	result = check_string(dup2, rep);
	free(dup2);
	return (result);
}

/* ------------------------------ ft_strdup.c ---------------------------- */

int	test_strdup ()
{
	int	result = 1;

	char	*string   = "Sir duck lord the third says : 'Coin coin'";
	char	*string1  = "";
	char	*copy     = ft_strdup(string);
	char	*copy1    = ft_strdup(string1);

	printf("\033[35mft_strdup(%s)\033[00m\n\n", string);
	char *dup2 = strdup(string);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", dup2);
	free(dup2);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", copy);
	
	if (strcmp(string, copy) != 0)
		result = 0;

	printf("\033[35mft_strdup(%s)\033[00m\n\n", string1);
	char *dup = strdup(string1);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", dup);
	free(dup);
	printf("\033[34mTon resultat :\033[00m\n%s\n", copy1);
	
	if (strcmp(string1, copy1) != 0)
		result = 0;

	free(copy);
	free(copy1);
		
	return (result);
}

/* ------------------------------ ft_strlen.c ---------------------------- */

int	check_strlen (char * str);

int	test_strlen ()
{
	int result = 1;
	
	char  string1[] = "CanardCoin";
	char  string2[] =          "T";
	char  string3[] =           "";

	printf ("%-12s   %4s   %4s\n\n", "PHRASE", "LIBC", "TOI");

	int i =    strlen(string1);
	int j = ft_strlen(string1);
	printf ("%-12s : %4d / %4d\n", string1, i, j);
	if (i != j) {result = 0;}

	i =    strlen(string2);
	j = ft_strlen(string2);
	printf ("%-12s : %4d / %4d\n", string2, i, j);
	if (i != j) {result = 0;}

	i =    strlen(string3);
	j = ft_strlen(string3);
	printf ("%-12s : %4d / %4d\n", string3, i, j);
	if (i != j) {result = 0;}

	return (result);
}

/* ------------------------------ ft_isalpha.c ---------------------------- */

int	test_isalpha ()
{
	int result =    1;
	
	int  c1 =  'b';
	int  c2 =  'O';
	int  c3 =  'a';
	int  c4 =  'z';
	int  c5 =  'A';
	int  c6 =  'Z';
	int  c7 =  '5';
	int  c8 =  '#';

	printf("     %4s   %4s\n\n", "LIBC", "TOI");

	int i =    isalpha(c1);
	int j = ft_isalpha(c1);
	printf("%2c : %4d / %4d\n", c1, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalpha(c2);
	j = ft_isalpha(c2);
	printf("%2c : %4d / %4d\n", c2, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalpha(c3);
	j = ft_isalpha(c3);
	printf("%2c : %4d / %4d\n", c3, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalpha(c4);
	j = ft_isalpha(c4);
	printf("%2c : %4d / %4d\n", c4, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}
	
	i =    isalpha(c5);
	j = ft_isalpha(c5);
	printf("%2c : %4d / %4d\n", c5, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalpha(c6);
	j = ft_isalpha(c6);
	printf("%2c : %4d / %4d\n", c6, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}
	
	i =    isalpha(c7);
	j = ft_isalpha(c7);
	printf("%2c : %4d / %4d\n", c7, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalpha(c8);
	j = ft_isalpha(c8);
	printf("%2c : %4d / %4d\n", c8, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	return(result);
}

/* ------------------------------ ft_isdigit.c ---------------------------- */

int	test_isdigit ()
{
	int result = 1;
	
	int  c1 =  '0';
	int  c2 =  '9';
	int  c3 =  'a';
	int  c4 =  'Z';
	int  c5 =  '>';
	int  c6 =  '#';

	printf("     %4s   %4s\n\n", "LIBC", "TOI");
	
	int i =    isdigit(c1);
	int j = ft_isdigit(c1);
	printf("%2c : %4d / %4d\n", c1, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isdigit(c2);
	j = ft_isdigit(c2);
	printf("%2c : %4d / %4d\n", c2, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}


	i =    isdigit(c3);
	j = ft_isdigit(c3);
	printf("%2c : %4d / %4d\n", c3, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isdigit(c4);
	j = ft_isdigit(c4);
	printf("%2c : %4d / %4d\n", c4, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isdigit(c5);
	j = ft_isdigit(c5);
	printf("%2c : %4d / %4d\n", c5, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isdigit(c6);
	j = ft_isdigit(c6);
	printf("%2c : %4d / %4d\n", c6, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	return(result);
}

/* ------------------------------ ft_isalnum.c ---------------------------- */

int	test_isalnum ()
{
	int result = 1;
	
	int  c1 =  '0';
	int  c2 =  '9';
	int  c3 =  'a';
	int  c4 =  'Z';
	int  c5 =  '>';
	int  c6 =  '#';

	printf("     %4s   %4s\n\n", "LIBC", "TOI");
	
	int i =    isalnum(c1);
	int j = ft_isalnum(c1);
	printf("%2c : %4d / %4d\n", c1, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalnum(c2);
	j = ft_isalnum(c2);
	printf("%2c : %4d / %4d\n", c2, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}


	i =    isalnum(c3);
	j = ft_isalnum(c3);
	printf("%2c : %4d / %4d\n", c3, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalnum(c4);
	j = ft_isalnum(c4);
	printf("%2c : %4d / %4d\n", c4, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalnum(c5);
	j = ft_isalnum(c5);
	printf("%2c : %4d / %4d\n", c5, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isalnum(c6);
	j = ft_isalnum(c6);
	printf("%2c : %4d / %4d\n", c6, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	return(result);
}

/* ------------------------------ ft_isascii.c ---------------------------- */

int	test_isascii ()
{
	int result = 1;
	
	int  c1 =  '0';
	int  c2 =  '9';
	int  c3 =  'a';
	int  c4 =  'Z';
	int  c5 =  177;
	int  c6 =   -2;
	int  c7 =  127;
	int  c8 =  128;

	printf("     %4s   %4s\n\n", "LIBC", "TOI");
	
	int i =    isascii(c1);
	int j = ft_isascii(c1);
	printf("%2c : %4d / %4d\n", c1, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isascii(c2);
	j = ft_isascii(c2);
	printf("%2c : %4d / %4d\n", c2, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}


	i =    isascii(c3);
	j = ft_isascii(c3);
	printf("%2c : %4d / %4d\n", c3, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isascii(c4);
	j = ft_isascii(c4);
	printf("%2c : %4d / %4d\n", c4, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isascii(c5);
	j = ft_isascii(c5);
	printf("%2c : %4d / %4d\n", c5, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isascii(c6);
	j = ft_isascii(c6);
	printf("%2c : %4d / %4d\n", c6, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isascii(c7);
	j = ft_isascii(c7);
	printf("%2c  : %4d / %4d\n", c7, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isascii(c8);
	j = ft_isascii(c8);
	printf("%2c : %4d / %4d\n", c8, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	return(result);
}

/* ------------------------------ ft_isprint.c ---------------------------- */

int	test_isprint ()
{
	int result = 1;
	
	int  c1 =  '0';
	int  c2 =  '9';
	int  c3 =  'a';
	int  c4 =  'Z';
	int  c5 =  ';';
	int  c6 = '\0';
	int  c7 = '\r';

	printf("     %5s   %5s\n\n", "LIBC", "TOI");
	
	int i =    isprint(c1);
	int j = ft_isprint(c1);
	printf("%2c : %5d / %5d\n", c1, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isprint(c2);
	j = ft_isprint(c2);
	printf("%2c : %5d / %5d\n", c2, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}


	i =    isprint(c3);
	j = ft_isprint(c3);
	printf("%2c : %5d / %5d\n", c3, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isprint(c4);
	j = ft_isprint(c4);
	printf("%2c : %5d / %5d\n", c4, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isprint(c5);
	j = ft_isprint(c5);
	printf("%2c : %5d / %5d\n", c5, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isprint(c6);
	j = ft_isprint(c6);
	printf("%2c  : %5d / %5d\n", c6, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	i =    isprint(c7);
	j = ft_isprint(c7);
	printf("%2c   : %5d / %5d\n", c7, i, j);
	if ((i != 0 && j == 0) || (i == 0 && j != 0)) {result = 0;}

	return(result);
}

/* ------------------------------ ft_atoi.c ---------------------------- */

int	check_atoi (char * string);

int test_atoi ()
{
	int  result    = 0;
	char string1[] =  "\n\v   ---+--+1234ab567";
	char string2[] =            "\n    +123478";
	char string3[] =                 "-3141592";
	char string4[] =                   "784665";
	char string5[] =                   "784q65";
	char string6[] =                     "1234";
	char string7[] =                   "-+1234";

	/*1 :*/ result += check_atoi(string1);
	/*2 :*/ result += check_atoi(string2);
	/*3 :*/ result += check_atoi(string3);
	/*4 :*/ result += check_atoi(string4);
	/*5 :*/ result += check_atoi(string5);
	/*6 :*/ result += check_atoi(string6);
	/*7 :*/ result += check_atoi(string7);

	return (result == 7);
}

int	check_atoi (char * string)
{
	int i = ft_atoi(string);
	int j = atoi(string);

	printf("Test \"%s\" : %d / %d (", string, i, j);
	if (i == j)
	{
		printf("\033[34mYepee !\033[00m)\n");
		return (1);
	}
	else
	{
		printf("\033[35Oh dang it !\033[00m)\n");
		return (0);
	}
}

/* ---------------------------- ft_strnstr.c --------------------------- */

int	check_strnstr (char *str, char *to_find, size_t len, char *rep);

int test_strnstr ()
{
	int	 result = 1;
	char string1[] = "Hello this is a test i";
	char string2[] = "";
	char to_find1[] = "is";
	char to_find2[] = "coin";
	char to_find3[] = "";

	if (!check_strnstr(string1, to_find1, 23,         "is is a test i")) {result = 0;}
	if (!check_strnstr(string1, to_find2,  5,                     NULL)) {result = 0;}
	if (!check_strnstr(string1, to_find3, 23, "Hello this is a test i")) {result = 0;}
	if (!check_strnstr(string2, to_find1,  5,                     NULL)) {result = 0;}
	if (!check_strnstr(string1, to_find1, 89,         "is is a test i")) {result = 0;}

	return (result);
}

int	check_strnstr (char *str, char *to_find, size_t len, char *rep)
{
	int ret = 1;
	char *result   = ft_strnstr(str, to_find, len);

	printf("\033[35mft_strnstr(%s, %s, %lu)\033[00m\n\n", str, to_find, len);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", rep);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", result);
	
	ret = check_string(rep, result);
	return (ret);
}

/* ---------------------------- ft_memcmp.c --------------------------- */

int	test_memcmp()
{
	int		result    = 1;
	char	string1[] = "COIN";
	char	string2[] = "COIABCDEF";
	char	string3[] = "Oui";
	char	string4[] = "";
	char	string5[] = "";
	char	string6[] = "canards";
	char	string7[] = "canard";
	char	string8[] = "t\200";
	char	string9[] = "t\0";

	printf("%11s %17s   %17s %4s   %4s   %4s\n\n", " ", "CHAINE 1", "CHAINE 2", "N ", "TOI", "LIBC");

	int n = 4;
	int i = ft_memcmp(string1, string1, n);
	int j =    memcmp(string1, string1, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string1, string1, n, i, j);
	if (i != j) {result = 0;}

	n = 9;
	i = ft_memcmp(string1, string1, n);
	j =    memcmp(string1, string1, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string1, string1, n, i, j);
	if (i != j) {result = 0;}
	
	n = 3;
	i = ft_memcmp(string1, string2, n);
	j =    memcmp(string1, string2, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string1, string2, n, i, j);
	if (i != j) {result = 0;}
	
	n = 4;
	i = ft_memcmp(string1, string2, n);
	j =    memcmp(string1, string2, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string1, string2, n, i, j);
	if (i != j) {result = 0;}
	
	n = 3;
	i = ft_memcmp(string1, string3, n);
	j =    memcmp(string1, string3, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string1, string3, n, i, j);
	if (i != j) {result = 0;}
	
	n = 0;
	i = ft_memcmp(string4, string5, n);
	j =    memcmp(string4, string5, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string4, string5, n, i, j);
	if (i != j) {result = 0;}

	n = 7;
	i = ft_memcmp(string6, string7, n);
	j =    memcmp(string6, string7, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string6, string7, n, i, j);
	if (i != j) {result = 0;}
	
	n = 7;
	i = ft_memcmp(string7, string6, n);
	j =    memcmp(string7, string6, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string7, string6, n, i, j);
	if (i != j) {result = 0;}

	n = 87;
	i = ft_memcmp(string7, string6, n);
	j =    memcmp(string7, string6, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string7, string6, n, i, j);
	if (i != j) {result = 0;}

	n = 2;
	i = ft_memcmp(string8, string9, n);
	j =    memcmp(string8, string9, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2d) : %4d / %4d\n", string8, string9, n, i, j);
	if (i != j) {result = 0;}

	return (result);
}

/* ---------------------------- ft_memchr.c --------------------------- */

int check_memchr(const char *s, int c, size_t n);

int test_memchr ()
{
	int result = 0;
    char str1[] = "Bonjour, coin coin ?";
    char str2[] = "Quack quack !";
    char str3[] = "1234567890";

    /*1: */ result += check_memchr(str1, 'c', strlen(str1));
    /*2: */ result += check_memchr(str2, 'z', strlen(str2));
    /*3: */ result += check_memchr(str3, '1', strlen(str3));
    /*4: */ result += check_memchr(str3, '0', strlen(str3));
    /*5: */ result += check_memchr(str1, 'B',            0);

    return (result == 5);
}

int check_memchr(const char *s, int c, size_t n)
{
    char *result_lib = memchr(s, c, n);
    char *result_ft  = ft_memchr(s, c, n);

    printf("\033[35mft_memchr(\"%s\", '%c', %zu)\033[00m\n", (const char *)s, (char)c, n);
    printf("\033[34mResultat attendu :\033[00m %s\n", result_lib);
    printf("\033[34mTon resultat :\033[00m %s\n\n", result_ft);

    int rep = (result_lib == result_ft);

    return rep;
}


/* ---------------------------- ft_strncmp.c --------------------------- */

int check_strncmp (char *s1, char *s2, size_t n);

int	test_strncmp ()
{
	int		result    = 1;
	char	string1[] = "COIN";
	char	string2[] = "COIABCDEF";
	char	string3[] = "Oui";
	char	string4[] = "";
	char	string5[] = "";
	char	string6[] = "canards";
	char	string7[] = "canard";
	char	string8[] = "test\200";
	char	string9[] = "test\0";

	printf("%11s %17s   %17s %4s   %4s   %4s\n\n", " ", "CHAINE 1", "CHAINE 2", "N ", "TOI", "LIBC");

	int n = 4;
	if (!check_strncmp(string1, string1, n)) {result = 0;}
	
	n = 3;
	if (!check_strncmp(string1, string2, n)) {result = 0;}

	n = 4;
	if (!check_strncmp(string1, string2, n)) {result = 0;}

	n = 3;
	if (!check_strncmp(string1, string3, n)) {result = 0;}

	n = 0;
	if (!check_strncmp(string4, string5, n)) {result = 0;}

	n = 7;
	if (!check_strncmp(string6, string7, n)) {result = 0;}
	
	n = 7;
	if (!check_strncmp(string7, string6, n)) {result = 0;}

	n = 87;
	if (!check_strncmp(string7, string6, n)) {result = 0;}

	n = 9;
	if (!check_strncmp(string8, string9, n)) {result = 0;}

	return (result);
}

int check_strncmp (char *s1, char *s2, size_t n)
{
	int i = ft_strncmp(s1, s2, n);
	int j =    strncmp(s1, s2, n);
	printf("Comparaison \"%15s\" / \"%15s\" (%2lu) : %4d / %4d\n", s1, s2, n, i, j);
	
	if (i > 0 && j > 0)
		return 1;
	else if (i < 0 && j < 0)
		return 1;
	else if (i == 0 && j == 0)
		return 1;
	else
		return 0;
}

/* ---------------------------- ft_strrchr.c --------------------------- */

int check_strrchr(char *str, char c);

int test_strrchr(void)
{
	int	result = 0;
	
    char    *str = "Canard coin coin";
	
	/*1 */ result += check_strrchr(str,         'C'       );
	/*2 */ result += check_strrchr(str,         'i'       );
	/*3 */ result += check_strrchr(str,         'z'       );
	/*4 */ result += check_strrchr(str,          0        );
	
	return (result == 4);
}

int check_strrchr(char *str, char c)
{
	char *result_ft  = ft_strrchr(str, c);
	char *result_lib =    strrchr(str, c);

	printf("\033[35mft_strrchr(%s, %c)\033[00m\n\n", str, c);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", result_lib);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", result_ft);

	return (check_string(result_ft, result_lib));
}

/* ---------------------------- ft_strchr.c --------------------------- */

int check_strchr(char *str, char c);

int test_strchr(void)
{
	int	result = 0;
	
    char    *str = "Canard coin coin";
	
	/*1 */ result += check_strchr(str,         'C'       );
	/*2 */ result += check_strchr(str,         'i'       );
	/*3 */ result += check_strchr(str,         'z'       );
	/*4 */ result += check_strchr(str,          0        );
	
	return (result == 4);
}

int check_strchr(char *str, char c)
{
	char *result_ft  = ft_strchr(str, c);
	char *result_lib =    strchr(str, c);

	printf("\033[35mft_strchr(%s, %c)\033[00m\n\n", str, c);
	printf("\033[34mResultat attendu :\033[00m\n%s\n", result_lib);
	printf("\033[34mTon resultat :\033[00m\n%s\n\n", result_ft);

	return (check_string(result_ft, result_lib));
}

/* ---------------------------- ft_tolower.c --------------------------- */

int test_tolower()
{
    printf("\033[35m------------ Fonction libc ------------\033[00m\n");
    char src[] = "Y0uth Athlete us3d @ Lure Ball to catch Diglett.";

    printf("\n\033[34mBefore tolower():\033[00m %s\n\n", src);

    for (size_t i = 0; src[i]; i++)
    {
        src[i] = tolower(src[i]);
    }

    printf("\033[34mAfter tolower():\033[00m %s\n\n", src);
	
	printf("\033[35m------------ Fonction libft ------------\033[00m\n");
	char src1[] = "Y0uth Athlete us3d @ Lure Ball to catch Diglett.";
	printf("\n\033[34mBefore tolower():\033[00m %s\n\n", src1);

    for (size_t i = 0; src1[i]; i++)
    {
        src1[i] = ft_tolower(src1[i]);
    }
    printf("\033[34mAfter tolower():\033[00m %s\n\n", src1);

    return (check_string(src, src1));
}

/* ---------------------------- ft_toupper.c --------------------------- */

int test_toupper()
{
	printf("\033[35m------------ Fonction libc ------------\033[00m\n");
    char src[] = "The le@der at Cyllage Gym in Rock Pok3mon.";

    printf("\n\033[34mBefore toupper():\033[00m %s\n\n", src);

    for (size_t i = 0; src[i]; i++)
    {
        src[i] = toupper(src[i]);
    }

    printf("\033[34mAfter toupper():\033[00m %s\n\n", src);
	
	printf("\033[35m------------ Fonction libft ------------\033[00m\n");
	char src1[] = "The le@der at Cyllage Gym in Rock Pok3mon.";
	printf("\n\033[34mBefore toupper():\033[00m %s\n\n", src1);

    for (size_t i = 0; src1[i]; i++)
    {
        src1[i] = ft_toupper(src1[i]);
    }
    printf("\033[34mAfter toupper():\033[00m %s\n\n", src1);

    return (check_string(src, src1));
}

/* ---------------------------- ft_memmove.c --------------------------- */

int test_memmove()
{
	size_t value = 12;

	char src[] = "The leader at Cyllage Gym in Rock Pokemon.";
	char dest[] = "Gym Challenger gave a Chople Berry to Exeggutor.";

    printf("Source : %s\nValue : %lu\n\n", src, value);

	printf("\033[35m------------ Fonction libc ------------\033[00m\n");
    printf("\n\033[34mBefore memmove():\033[00m %s\n\n", dest);
    memmove(dest, src, value);
    printf("\033[34mAfter memmove():\033[00m %s\n\n", dest);
	
	char src1[] = "The leader at Cyllage Gym in Rock Pokemon.";
	char dest1[] = "Gym Challenger gave a Chople Berry to Exeggutor.";

	printf("\033[35m------------ Fonction libft ------------\033[00m\n");
	printf("\n\033[34mBefore ft_memmove():\033[00m %s\n\n", dest1);
    ft_memmove(dest1, src1, value);
    printf("\033[34mAfter ft_memmove():\033[00m %s\n\n", dest1);

    return (!strcmp(dest, dest1));
}

/* ---------------------------- ft_memcpy.c --------------------------- */

int	test_memcpy()
{
	size_t value = 35;

	char src[] = "Zapdos was found in Route 17.";
	char dest[] = "Golf Buddies spotted Kadabra in Kanto";

    printf("Source : %s\nValue : %lu\n\n", src, value);

	printf("\033[35m------------ Fonction libc ------------\033[00m\n");
    printf("\n\033[34mBefore memcpy():\033[00m %s\n\n", dest);
    memcpy(dest + 5, src, value);
    printf("\033[34mAfter memcpy():\033[00m %s\n\n", dest);

	char src1[] = "Zapdos was found in Route 17.";
	char dest1[] = "Golf Buddies spotted Kadabra in Kanto";
	
	printf("\033[35m------------ Fonction libft ------------\033[00m\n");
	printf("\n\033[34mBefore ft_memcpy():\033[00m %s\n\n", dest1);
    ft_memcpy(dest1 + 5, src1, value);
    printf("\033[34mAfter ft_memcpy():\033[00m %s\n\n", dest1);

    return (!strcmp(dest, dest1));
}

/* ---------------------------- ft_strlcat.c --------------------------- */

int	check_strlcat(char *dest, char *str, size_t value);

int test_strlcat(void)
{
    int result = 0;
    char str1[] = "abcd";
    char str2[] = "AAAAAAAAAAA";
    char dest1[30] = "pqrstuvwxyz";
    char dest2[30] = {0};
    char dest3[30] = {0};

    result += check_strlcat(dest1, str1, 5);
    result += check_strlcat(dest2, str2, 5);
    result += check_strlcat(dest3, str2, 0);

    return (result == 3);
}

int check_strlcat(char *dest, char *str, size_t value)
{
    char *dest_copy1 = malloc(strlen(dest) + strlen(str) + 1);
    char *dest_copy2 = malloc(strlen(dest) + strlen(str) + 1);
	
    if (!dest_copy1 || !dest_copy2) 
		return 0;

    strcpy(dest_copy1, dest);
    strcpy(dest_copy2, dest);

    size_t result_lib =    strlcat(dest_copy1, str, value);
    size_t result_ft  = ft_strlcat(dest_copy2, str, value);

    printf("\033[35mft_strlcat(%s, %s, %zu)\033[00m\n\n", dest, str, value);
    printf("\033[34mResultat attendu :\033[00m\n%s (%zu)\n", dest_copy1, result_lib);
    printf("\033[34mTon resultat :\033[00m\n%s (%zu)\n\n", dest_copy2, result_ft);

    int rep = (strcmp(dest_copy1, dest_copy2) == 0) && (result_lib == result_ft);
    free(dest_copy1);
    free(dest_copy2);
    return rep;
}



/* ---------------------------- ft_strlcpy.c --------------------------- */

int test_strlcpy ()
{
    char str1[] = "Hello World";
    char dest1[] = "AAAAAAAAAAAAAAAAAAAA";
    char dest2[] = "AAAAAAAAAAAAAAAAAAAA";
	size_t value = 6;

	printf("Source : %s\nValue : %lu\n\n", str1, value);

	printf("\033[35m------------ Fonction libc ------------\033[00m\n");
    printf("\n\033[34mBefore strlcpy():\033[00m %s\n\n", dest2);
    int i = strlcpy(dest2, str1, value);
    printf("\033[34mAfter strlcpy():\033[00m %s (%d)\n\n", dest2, i);
	
	printf("\033[35m------------ Fonction libft ------------\033[00m\n");
	printf("\n\033[34mBefore ft_strlcpy():\033[00m %s\n\n", dest1);
    i = ft_strlcpy(dest1, str1, value);
    printf("\033[34mAfter ft_strlcpy():\033[00m %s (%d)\n\n", dest1, i);

    return (!strcmp(dest1, dest2));
}

int check_string (char * s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
		{
			return(1);
		}
		return (0);
	}
	return (strcmp(s1, s2) == 0);
}

void afficherSeparateur(const char *nom) 
{
	int len = ft_strlen(nom);
	int espaceTotal = 93; // 4 = 2 pour les | et 2 pour les espaces autour du nom
    int espaceGauche = (espaceTotal - len) / 2;
    int espaceDroite = espaceTotal - len - espaceGauche;
	
    printf("+-----------------------------------------------------------------------------------------------+\n");
    printf("|");
    	for (int i = 0; i < espaceGauche; i++) printf(" ");
    printf(" %s ", nom);
    	for (int i = 0; i < espaceDroite; i++) printf(" ");
    printf("|\n");
    printf("+-----------------------------------------------------------------------------------------------+\n\n");
}
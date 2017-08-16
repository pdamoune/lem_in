/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:42:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 19:56:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# define ABS(X) X < 0 ? -X : X
# define INFO	__FILE__, __FUNCTION__, __LINE__

typedef struct s_list	t_list;

struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
};

/*
** Fonctions perso
*/

int			get_next_line(const int fd, char **line);
int			ft_printf(const char *format, ...);
int			ft_error(int args, ...);

/*
** Fonctions de comparaisons de caracteres
*/

int			ft_isblank(int c);
int			ft_isspace(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isxdigit(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
int			ft_toupper(int c);
int			ft_islower(int c);
int			ft_tolower(int c);
void		ft_strtoupper(char *str);
int			ft_isint(const char *nbr);

/*
** 				Outils chaines de carateres
*/

size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strcstr(const char *haystack, const char *needle, int c);
char		*ft_strnstr(const char *haystack, const char *ndl, size_t len);
void		ft_striter(char *str, void (*f)(char *));
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
void		ft_strdel(char **str);
char		*ft_conv_bin(char *str, int b_one, int b_zero);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
char		*ft_itoa(int n);
char		*ft_lltoa_base(long long n, unsigned int base);
char		*ft_ulltoa_base(unsigned long long n, unsigned int base);
void		ft_swap(int *a, int *b);
void		ft_sort_params(int argc, char **argv);
char		*ft_strrev(char *str);
char		*ft_strnew(size_t size);
char		*ft_strmap(const char *str, char (*f)(char));
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char		*ft_strsub(const char *str, unsigned int start, size_t len);
char		*ft_strjoin(char *str1, const char *str2);
char		*ft_strtrim(const char *str);
char		*ft_strctrim(const char *str, int c);
char		**ft_strsplit(const char *str, char c);
char		**ft_strcsplit(const char *str, char c);
int			ft_count_c_words(const char *str, char c);
int			ft_count_occur(char *str, int c);
int			ft_sqrt(int nb);
int			ft_sqrt_min(int nb);
int			ft_strequ(const char *str1, const char *str2);
int			ft_strnequ(const char *str1, const char *str2, size_t n);
int			ft_strdift(const char *str1, const char *str2);

/*
** 				Outils zone memoire
*/

void		ft_bzero(void *s, size_t n);
void		ft_memdel(void **ap);
void		ft_tabdel(char **tab, int size);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memrealloc(void *ptr, size_t old_size, size_t new_size);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memalloc(size_t size);

/*
**				Fonctions d affichage
*/

void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_putendl(const char *str);
void		ft_putnbrel(int nb);
void		ft_putnbr_bin(int n, int base);
void		ft_putnbr(int n);
void		ft_displaytab(char **tab);
void		ft_putaddr(void *ptr);

/*
**				Fonctions file descriptor
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *str, int fd);
void		ft_putendl_fd(const char *str, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
** 				Listes chainees
*/

void		ft_lstadd_first(t_list **alst, t_list *new_list);
int			ft_lstadd_last(t_list **alst, t_list *new_list);
void		ft_lstadd(t_list **alst, t_list *new_list);
void		ft_lstclr_first(t_list **lst);
void		ft_lstclr_last(t_list **lst);
t_list		*ft_lstcpy(t_list *new_list);
void		ft_lstdel(t_list **alst, void (*del)(void *));
void		ft_lstptrdel(t_list **alst);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstfind(t_list *list, void *data, int (*cmp)());
t_list		*ft_lstfirst(t_list *list);
void		ft_lstforeach(t_list *list, void (*f)(void *));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstlast(t_list *list);
size_t		ft_lstlen(t_list *lst);
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstnew(void const *content, size_t content_size);
t_list		*ft_lstptr(void *ptr);
t_list		*ft_lstdup(t_list *list);
int			ft_lstsortlen(t_list *list);
void		ft_lstswap_content(t_list *lst1, t_list *lst2);

#endif

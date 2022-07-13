/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:45:45 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/13 23:14:43 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>	// size_t, malloc, free
# include <unistd.h>	// read, write

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192	// 2^13 bytes
# endif

// Linked list struct:
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Linked list functions:
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// <ctype.h> functions:
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

// <string.h> functions:
// Memory:
int			ft_memcmp(const void *s1, const void *s2, size_t size);
void		*ft_memchr(const void *s, int c, size_t size);
void		*ft_memset(void *s, int c, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
// Strings:
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
// BSD (<bsd/string.h>):
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *s1, const char *s2, size_t size);

// <stdlib.h> functions:
int			ft_atoi(const char *s);
long long	ft_atoll(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);

// <strings.h> functions:
void		ft_bzero(void *s, size_t size);	// Deprecated; use memset instead

// Libft specific functions:
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// Custom functions:
// To string:
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
char		*ft_xtoa(unsigned int n);
char		*ft_xto_uppercase_a(unsigned int n);
char		*ft_ptoa(void *p);
// Miscellaneous:
char		*ft_strmerge(char *s1, char *s2);
char		*get_next_line(int fd);
int			ft_atoi_base(char *str, char *base);
void		ft_null_free(void **p);
void		ft_free_matrix(void ***p, size_t line_count);
void		ft_free_char_matrix(char ***m);
char		**ft_partial_split(char const *s, char delimiter, char stopper);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dashvydk <dashvydk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 11:23:57 by dashvydk          #+#    #+#             */
/*   Updated: 2025-03-13 11:23:57 by dashvydk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// # include<stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
// memory
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t count);
int					ft_memcmp(void *s1, void *s2, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
// string
char				*ft_strchr(const char *str, int chr);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(char *haystack, char *needle,
						unsigned int size);
char				*ft_strrchr(const char *str, int chr);
size_t				ft_strlcat(char *restrict dest, const char *restrict src,
						size_t n);
size_t				ft_strlcpy(char *restrict dest, const char *restrict src,
						size_t n);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t num, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s1, char const *set);
// put functions
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
// awful functions
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
// bonus
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

#endif

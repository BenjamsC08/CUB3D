#include "libft.h"

t_gc	*init_gc()
{
	t_gc	*head;
	void	*ptr;

	ptr = malloc(1);
	head = ft_dlstnew(ptr);
	if (!head)
		return (free(ptr), NULL);
	return (head);
}

void	*ft_gcalloc(t_gc **head, t_uint size)
{
	void		*ptr;
	t_gc		*node;

	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	node = ft_dlstnew(ptr);
	if (!node)
		return (free(ptr), NULL);
	ft_dlstadd_back(head, node);
	return (ptr);
}

void	*ft_gc_addnode(t_dlist **head, void *ptr)
{
	t_gc		*node;

	if (!ptr)
		return (NULL);
	node = ft_dlstnew(ptr);
	if (!node)
		return (free(ptr), NULL);
	ft_dlstadd_back(head, node);
	return (ptr);
}

void	ft_clear_gc(t_gc **head)
{
	ft_dlstclear(head, &free);
}

// Example utilisation
/*int main()*/
/*{*/
/*    t_gc *head_gc;*/
/*    char *str;*/
/*    char *str1;*/
/*    int *int_ptr;*/
/**/
/*    head_gc = init_gc();*/
/*    str = ft_gcalloc(&head_gc, sizeof(char *));*/
/*    if (!str)*/
/*        return (ft_clear_gc(&head_gc), 1);*/
/*    str = "blaoblao";*/
/*    str1 = ft_gc_addnode(&head_gc, ft_strdup("lololololo"));*/
/*    if (!str1)*/
/*        return (ft_clear_gc(&head_gc), 1);*/
/*    int_ptr = ft_gc_addnode(&head_gc, malloc(sizeof(int)));*/
/*    if (!int_ptr)*/
/*        return (ft_clear_gc(&head_gc), 1);*/
/*    *int_ptr = 42;*/
/*    ft_clear_gc(&head_gc);*/
/*    return (0);*/
/*}*/

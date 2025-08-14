#include "libft.h"

void 	ft_lstremove_if(t_list **head, void *ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*head && !cmp((*head)->content, ref, sizeof(void *)))
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	i = *head;
	while (i && i->next)
	{
		if (!cmp(i->next->content, ref, sizeof(void *)))
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}

void ft_dlstremove_if(t_dlist **head, void *ref, int (*cmp)())
{
    t_dlist *tmp;
    t_dlist *i;

    while (*head && !cmp((*head)->content, ref, sizeof(void *)))
    {
        tmp = *head;
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
		free(tmp->content);
        free(tmp);
    }
    i = *head;
    while (i && i->next)
    {
        if (!cmp(i->next->content, ref, sizeof(void *)))
        {
            tmp = i->next;
            i->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = i;
			free(tmp->content);
            free(tmp);
        }
        else
            i = i->next;
    }
}

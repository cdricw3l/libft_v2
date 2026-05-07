/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:06:26 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 13:56:16 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void *d_split(char ***split)
{
    char **ptr;
    int i;

    i = 0;
    ptr = *split;
    while (ptr[i])
    {
        free(ptr[i]);
        ptr[i] = NULL;
        i++;
    }
    free(*split);
    *split = NULL;
    return (NULL);
}

void delete_str(void *ptr)
{
    char *str;

    str = (char *)ptr;
    free(str);
    str = NULL;
}

t_list **create_list(char **split, int test_mode)
{
    char **ptr;
    t_list **lst;
    t_list *new_node;
    int i;
    
    if (!split)
        return(NULL);
    lst = malloc(sizeof(t_list *));
    if (!lst)
        return (d_split(&split));
    *lst = NULL;
    ptr = split;
    i = 0;
    while (*ptr)
    {
        new_node = ft_lstnew(ft_strdup(*ptr));
        if(i == 3 && test_mode == 1)
        {
            ft_lstdelone(new_node, delete_str);
            new_node = NULL;
        }
        if(!new_node)
        {
            ft_lstclear(lst, delete_str);
            free(lst);
            d_split(&split);
            return(NULL);
        }
        ft_lstadd_back(lst, new_node);
        ptr++;
        i++;
    }
    return(lst);
}

void print_lst(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        NL;
        printf("node %d addresse -> %p\n", i++,lst);
        printf("content: %s\n", (char *)lst->content);
        printf("next node addresse %p\n", lst->next);
        lst = lst->next;
    }
    
}

int main(void)
{
    t_list **list;
    char **split;

    split = ft_split("hello_berlin_comment_ca_va_?", '_');
    if(!split)
        return (1);
    list = create_list(split, 0);
    
    if(!list)
    {
        printf("Erreur creation list\n");
        free(list);
        return (1);
    }
    else
        print_lst(*list);
        
    ft_lstclear(list, delete_str);

    
    assert(list && *list == NULL);
    
    d_split(&split);
    //free(list);
    return (0);
}
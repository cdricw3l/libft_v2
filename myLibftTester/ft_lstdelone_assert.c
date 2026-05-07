#include "assertion.h"

void clean_split(void *ptr)
{
    char ***split;
    int i;

    split = (char ***)ptr;
    i = 0;
    while ((*split)[i])
    {
        free((*split)[i]);
        (*split)[i] = NULL;
        i++;
    }
    free((*split));
    (*split) = NULL;
}

void clean_tab(void *ptr)
{
    int ***data;
    int i;

    data = (int ***)ptr;
    i = 0;
    while ((*data)[i])
    {
        free((*data)[i]);
        (*data)[i] = NULL;
        i++;
    }
    free(*data);
    *data = NULL;
}

int **create_arr(int nb, int term)
{
    int i;
    int j;
    int **tab;
    int *arr;

    tab = malloc(sizeof(int **) * (nb + 1));
    if (!tab)
        return (NULL);
    i = 0;
    assert(nb == 5);
    while (i < nb)
    {
        arr = malloc(sizeof(int *) * term);
        if (!arr)
        {
            j = 0;
            while (j < i)
            {
                free(tab[j]);
                tab[j] = NULL;
                j++;
            }
            return (NULL);
        }
        j = 0;
        while (j < term)
        {
            arr[j] = j;
            j++;
        }
        tab[i] = arr;
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

void print_tab(int **arr, int terme)
{
    int i;
    int j;

    i = 0;
    assert(arr && arr[0]);
    while (arr[i])
    {

        printf("tab %d: ", i);
        j = 0;
        while (j < terme)
            printf("%d ", arr[i][j++]);
        NL;
        i++;
    }
    
}

void ft_lstdelone_assert(void)
{

    char **split;
    int **data;
    t_list *node;

    //test 1

    split = ft_split("hello_berlin_comment_ca_va?", '_');
    if(!split)
        return ;
    node = ft_lstnew(&split);
    if(!node)
    {
        clean_split(split);
        return ;
    }

    ft_lstdelone(node, clean_split);
    if (!split)
        printf("Delete content node test %d"TEST_OK"\n", 1);
    else
        printf("Delete content node test %d"TEST_NOK"\n", 1);
        

    data = create_arr(5, 5);
    if (!data)
    {
        printf("error data\n");
        return ;
    }
    printf("tableau creer avec succes\n");
    node->content = &data;
    print_tab(*(int ***)((node->content)), 5);
    ft_lstdelone(node, clean_tab);
    if (!data )
        printf("Delete content node test %d"TEST_OK"\n", 2);
    else
        printf("Delete content node test %d"TEST_NOK"\n", 2);
        
}
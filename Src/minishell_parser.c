/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:23:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/24 22:02:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

void	get_cmd_list(int *lexer, char **cursor, t_pars_tree **ptr)
{
	while (**cursor != '\0')
	{
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		get_word(lexer, cursor, ptr);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		get_redirection(lexer, cursor, ptr);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		get_pipe(lexer, cursor, ptr);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		get_ctl_cmd(lexer, cursor, ptr);
	}
}

static void print_node(t_pars_tree *node)
{
    printf("[%s](type:%d)", node->word, node->type);
}

static void print_tree_helper(t_pars_tree *root, int level)
{
    if (root == NULL)
        return;
    // Print the current node
    for (int i = 0; i < level; i++)
	{
		if (i + 1 == level)
        	printf("└---");
		else
			printf ("	");
	}
    print_node(root);
    printf("\n");

    // Recursively print the left and right subtrees
    print_tree_helper(root->left, level + 1);
    print_tree_helper(root->right, level + 1);
}

static void print_tree(t_pars_tree *head)
{
    print_tree_helper(head, 0);
}

t_pars_tree	*minishell_parser(char *cmdline, char *envp[])
{
	t_pars_tree		*tree;
	int				lexer;

	tree = NULL;
	lexer = 0;
	get_cmd_list(&lexer, &cmdline, &tree);
	get_variable(envp, tree);
	print_tree(tree);
	return (tree);
}

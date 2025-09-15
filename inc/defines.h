/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:55:02 by myli-pen          #+#    #+#             */
/*   Updated: 2025/09/02 16:55:47 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdbool.h>
# include <stdint.h>
# include <sys/types.h>
# include <stddef.h>
# include <limits.h>

# define ERROR_INVALID_EXIT		255
# define ERROR_S_TERMINATED		130
# define ERROR_CMD_NOTFOUND		127
# define ERROR_CMD_CANTEXEC		126
# define ERROR					-1
# define SUCCESS				0

typedef int cmd_func(t_cmd, t_state);

typedef struct s_state
{
	int			pid_count; //can be parsed from the number of | characters
	pid_t		*pids;
	int			exit_status;
	char		**env_var;
}	t_state;

typedef struct s_cmd
{
	enum e_pipe_type	pipe_type;
	enum t_builtin		builtin_cmd;
	char				**args; //MIKA we can change this memb if parser refines args to data (each command call in one shell command has its own args).
	struct s_cmd		*left;
	struct s_cmd		*right;
	int					pipe_fds[2];
	int					exit_status;
}	t_cmd;

typedef enum e_pipe_type
{
	SIMPLE,
	PIPELINE
}	t_pipe_type;

typedef enum e_builtin_type
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtin;

#endif

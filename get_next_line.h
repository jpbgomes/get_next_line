/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:34 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/24 17:47:53 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H
  #include <fcntl.h>
  #include <unistd.h>
  #include <stdio.h>

  char *get_next_line(int fd);
#endif

#ifndef BUFFER_SIZE
  #define BUFFER_SIZE 42
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:17:45 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 12:53:41 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

// Main Function
int	main(void)
{
	// Redirect stdout to results.txt
	redirect_stdout_to_file("results.txt");

	// Run Mandatory Tests
	test_mandatory();
	
	// Run Bonus Tests
	test_bonus();

	// Restore stdout to terminal
	restore_stdout();

	return (0);
}

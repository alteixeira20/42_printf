/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:17:45 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/28 16:17:50 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

// Main Function
int	main(void)
{
	// Redirect stdout to results.txt
	redirect_stdout_to_file("results.txt");

	// Run Mandatory Tests
	test_mandatory_diu();
	
	// Run Bonus Tests
	test_bonus_diu();

	// Restore stdout to terminal
	restore_stdout();

	return (0);
}

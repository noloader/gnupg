/* dsa.h  -  DSA signature algorithm
 *	Copyright (C) 1998 Free Software Foundation, Inc.
 *
 * This file is part of GnuPG.
 *
 * GnuPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GnuPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#ifndef G10_DSA_H
#define G10_DSA_H

int dsa_generate( int algo, unsigned nbits, MPI *skey, MPI **retfactors );
int dsa_check_secret_key( int algo, MPI *skey );
int dsa_sign( int algo, MPI *resarr, MPI data, MPI *skey );
int dsa_verify( int algo, MPI hash, MPI *data, MPI *pkey );
unsigned dsa_get_nbits( int algo, MPI *pkey );
const char *dsa_get_info( int algo, int *npkey, int *nskey,
				    int *nenc, int *nsig, int *use );

#endif /*G10_DSA_H*/

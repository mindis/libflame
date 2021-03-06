/*

    Copyright (C) 2014, The University of Texas at Austin

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

extern fla_gemm_t* flash_gemm_cntl_op_bp;
extern fla_trsm_t* flash_trsm_cntl_bp;

fla_lu_t*          flash_lu_nopiv_cntl_leaf;
fla_lu_t*          flash_lu_nopiv_cntl;
fla_blocksize_t*   flash_lu_nopiv_bsize;

void FLASH_LU_nopiv_cntl_init()
{
	// Set blocksize for hierarchical storage.
	flash_lu_nopiv_bsize       = FLA_Blocksize_create( 1, 1, 1, 1 );

	// Create a control tree that assumes A is a b x b block.
	flash_lu_nopiv_cntl_leaf   = FLA_Cntl_lu_obj_create( FLA_HIER,
	                                                     FLA_SUBPROBLEM,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL );

	// Create a control tree that assumes A is large.
	flash_lu_nopiv_cntl        = FLA_Cntl_lu_obj_create( FLA_HIER,
	                                                     FLA_BLOCKED_VARIANT5,
	                                                     flash_lu_nopiv_bsize,
	                                                     flash_lu_nopiv_cntl_leaf,
	                                                     flash_gemm_cntl_op_bp,
	                                                     NULL,
	                                                     NULL,
	                                                     flash_trsm_cntl_bp,
	                                                     flash_trsm_cntl_bp,
	                                                     NULL,
	                                                     NULL );
}

void FLASH_LU_nopiv_cntl_finalize()
{
	FLA_Cntl_obj_free( flash_lu_nopiv_cntl_leaf );
	FLA_Cntl_obj_free( flash_lu_nopiv_cntl );

	FLA_Blocksize_free( flash_lu_nopiv_bsize );
}


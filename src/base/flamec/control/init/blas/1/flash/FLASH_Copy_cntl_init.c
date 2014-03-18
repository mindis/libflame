
#include "FLAME.h"

fla_copy_t*        flash_copy_cntl_blas;
fla_copy_t*        flash_copy_cntl_tb;
fla_copy_t*        flash_copy_cntl;
fla_blocksize_t*   flash_copy_bsize;

void FLASH_Copy_cntl_init()
{
	// Set blocksize for hierarchical storage.
	flash_copy_bsize     = FLA_Blocksize_create( 1, 1, 1, 1 );

	// Create a control tree that assumes A and B are small.
	flash_copy_cntl_blas = FLA_Cntl_copy_obj_create( FLA_HIER,
	                                                 FLA_SUBPROBLEM,
	                                                 NULL,
	                                                 NULL );

	// Create a control tree that marches through A and B vertically.
	flash_copy_cntl_tb   = FLA_Cntl_copy_obj_create( FLA_HIER,
	                                                 FLA_BLOCKED_VARIANT1,
	                                                 flash_copy_bsize,
	                                                 flash_copy_cntl_blas );

	// Create a control tree that marches through A and B horizontally, then
	// vertically.
	flash_copy_cntl      = FLA_Cntl_copy_obj_create( FLA_HIER,
	                                                 FLA_BLOCKED_VARIANT3,
	                                                 flash_copy_bsize,
	                                                 flash_copy_cntl_tb );
}

void FLASH_Copy_cntl_finalize()
{
	FLA_Cntl_obj_free( flash_copy_cntl_blas );

	FLA_Cntl_obj_free( flash_copy_cntl_tb );
	FLA_Cntl_obj_free( flash_copy_cntl );

	FLA_Blocksize_free( flash_copy_bsize );
}

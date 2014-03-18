
#include "FLAME.h"

FLA_Error FLA_Tridiag_UT_realify_check( FLA_Uplo uplo, FLA_Obj A, FLA_Obj d )
{
  FLA_Error e_val;

  e_val = FLA_Check_valid_uplo( uplo );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_floating_object( A );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_nonconstant_object( A );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_identical_object_datatype( A, d );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_square( A );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_if_vector( d );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_object_width_equals( A, FLA_Obj_vector_dim( d ) );
  FLA_Check_error_code( e_val );

  return FLA_SUCCESS;
}


// --- FLA_Bsvd_francis_v_opt_var1() -------------------------------------------

FLA_Error FLA_Bsvd_francis_v_opt_var1( FLA_Obj shift, FLA_Obj g, FLA_Obj h, FLA_Obj d, FLA_Obj e );
FLA_Error FLA_Bsvd_francis_v_ops_var1( int       m_A,
                                       float     shift,
                                       scomplex* buff_g, int inc_g, 
                                       scomplex* buff_h, int inc_h, 
                                       float*    buff_d, int inc_d, 
                                       float*    buff_e, int inc_e ); 
FLA_Error FLA_Bsvd_francis_v_opd_var1( int       m_A,
                                       double    shift,
                                       dcomplex* buff_g, int inc_g, 
                                       dcomplex* buff_h, int inc_h, 
                                       double*   buff_d, int inc_d, 
                                       double*   buff_e, int inc_e ); 

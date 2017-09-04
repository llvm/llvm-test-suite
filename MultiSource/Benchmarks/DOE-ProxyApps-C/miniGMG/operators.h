//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
  void                  apply_op(domain_type *domain, int level, int Ax_id,  int x_id,   double a, double b);
  void                  residual(domain_type *domain, int level, int res_id, int phi_id, int rhs_id, double a, double b);
  void                    smooth(domain_type *domain, int level, int phi_id, int rhs_id, double a, double b);
  void            rebuild_lambda(domain_type *domain, int level, double a, double b);
//------------------------------------------------------------------------------------------------------------------------------
  void  residual_and_restriction(domain_type *domain, int level_f, int phi_id, int rhs_id, int level_c, int res_id, double a, double b);
  void               restriction(domain_type *domain, int level_f, int id_c, int id_f);
  void         restriction_betas(domain_type *domain, int level_f, int level_c);
  void    interpolation_constant(domain_type *domain, int level_f, double prescale_f, int id_f, int id_c);
  void      interpolation_linear(domain_type *domain, int level_f, double prescale_f, int id_f, int id_c);
//------------------------------------------------------------------------------------------------------------------------------
  void         exchange_boundary(domain_type *domain, int level, int grid_id, int exchange_faces, int exchange_edges, int exchange_corners);
//------------------------------------------------------------------------------------------------------------------------------
double                       dot(domain_type *domain, int level, int id_a, int id_b);
double                      norm(domain_type *domain, int level, int grid_id);
double                      mean(domain_type *domain, int level, int id_a);
  void                 add_grids(domain_type *domain, int level, int id_c, double scale_a, int id_a, double scale_b, int id_b);
  void                scale_grid(domain_type *domain, int level, int id_c, double scale_a, int id_a);
  void                 zero_grid(domain_type *domain, int level, int grid_id);
//  void                shift_grid(domain_type *domain, int level, int id_c, int id_a, double shift_a);
  void                 mul_grids(domain_type *domain, int level, int id_c, double scale, int id_a, int id_b);
//  void initialize_grid_to_scalar(domain_type *domain, int level, int grid_id, double scalar);
//------------------------------------------------------------------------------------------------------------------------------
  void      project_cell_to_face(domain_type *domain, int level, int id_cell, int id_face, int dir);
//------------------------------------------------------------------------------------------------------------------------------
  void              matmul_grids(domain_type *domain, int level, double *C, int *id_A, int *id_B, int rows, int cols, int A_equals_B_transpose);
//------------------------------------------------------------------------------------------------------------------------------
  void        initialize_problem(domain_type *domain, int level, double hLevel, double a, double b);
//------------------------------------------------------------------------------------------------------------------------------
//  void __box_smooth_GSRB_multiple(box_type *box, int phi_id, int rhs_id, double a, double b, int sweep);
//  void __box_smooth_GSRB_multiple_threaded(box_type *box, int phi_id, int rhs_id, double a, double b, int sweep);

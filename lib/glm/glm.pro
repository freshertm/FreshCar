TEMPLATE=lib
CONFIG += staticlib
TARGET=libglm
DESTDIR=../bin


SOURCES=detail/glm.cpp
INCLUDEPATH+=../

#HEADERS += \
#common.hpp       ext.hpp  geometric.hpp  integer.hpp  mat2x3.hpp  mat3x2.hpp  mat3x4.hpp  mat4x3.hpp  matrix.hpp   trigonometric.hpp  vec3.hpp  vector_relational.hpp
#exponential.hpp  fwd.hpp  glm.hpp        mat2x2.hpp   mat2x4.hpp  mat3x3.hpp  mat4x2.hpp  mat4x4.hpp  packing.hpp  vec2.hpp           vec4.hpp


#/detail
#_features.hpp      _vectorize.hpp        func_matrix.hpp             intrinsic_exponential.hpp    intrinsic_vector_relational.hpp  type_half.hpp    type_mat2x4.hpp  type_mat4x3.hpp  type_vec3.hpp
#_fixes.hpp         func_common.hpp       func_packing.hpp            intrinsic_geometric.hpp      precision.hpp                    type_int.hpp     type_mat3x2.hpp  type_mat4x4.hpp  type_vec4.hpp
#_noise.hpp         func_exponential.hpp  func_trigonometric.hpp      intrinsic_integer.hpp        setup.hpp                        type_mat.hpp     type_mat3x3.hpp  type_vec.hpp
#_swizzle.hpp       func_geometric.hpp    func_vector_relational.hpp  intrinsic_matrix.hpp         type_float.hpp                   type_mat2x2.hpp  type_mat3x4.hpp  type_vec1.hpp
#_swizzle_func.hpp  func_integer.hpp      intrinsic_common.hpp        intrinsic_trigonometric.hpp  type_gentype.hpp                 type_mat2x3.hpp  type_mat4x2.hpp  type_vec2.hpp


#/gtc

#bitfield.hpp     constants.hpp  integer.hpp        matrix_integer.hpp  matrix_transform.hpp  packing.hpp     random.hpp      round.hpp           type_ptr.hpp  vec1.hpp
#color_space.hpp  epsilon.hpp    matrix_access.hpp  matrix_inverse.hpp  noise.hpp             quaternion.hpp  reciprocal.hpp  type_precision.hpp  ulp.hpp

#/gtx
#associated_min_max.hpp  dual_quaternion.hpp    handed_coordinate_space.hpp  matrix_interpolation.hpp  normalize_dot.hpp      range.hpp                   simd_vec4.hpp       vector_query.hpp
#bit.hpp                 euler_angles.hpp       hash.hpp                     matrix_major_storage.hpp  number_precision.hpp   raw_data.hpp                spline.hpp          wrap.hpp
#closest_point.hpp       extend.hpp             integer.hpp                  matrix_operation.hpp      optimum_pow.hpp        rotate_normalized_axis.hpp  std_based_type.hpp
#color_space.hpp         extented_min_max.hpp   intersect.hpp                matrix_query.hpp          orthonormalize.hpp     rotate_vector.hpp           string_cast.hpp
#color_space_YCoCg.hpp   fast_exponential.hpp   io.hpp                       matrix_transform_2d.hpp   perpendicular.hpp      scalar_multiplication.hpp   transform.hpp
#common.hpp              fast_square_root.hpp   log_base.hpp                 mixed_product.hpp         polar_coordinates.hpp  scalar_relational.hpp       transform2.hpp
#compatibility.hpp       fast_trigonometry.hpp  matrix_cross_product.hpp     norm.hpp                  projection.hpp         simd_mat4.hpp               type_aligned.hpp
#component_wise.hpp      gradient_paint.hpp     matrix_decompose.hpp         normal.hpp                quaternion.hpp         simd_quat.hpp               vector_angle.hpp

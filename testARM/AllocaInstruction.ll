@__const.main.b = private unnamed_addr constant [3 x i32] [i32 1, i32 2, i32 3], align 4
@__const.main.c = private unnamed_addr constant [3 x [3 x i32]] [[3 x i32] [i32 1, i32 2, i32 3], [3 x i32] [i32 2, i32 3, i32 4], [3 x i32] [i32 3, i32 4, i32 5]], align 16
@__const.main.e = private unnamed_addr constant [3 x float] [float 1.000000e+00, float 2.000000e+00, float 3.000000e+00], align 4
@__const.main.f = private unnamed_addr constant [3 x [3 x float]] [[3 x float] [float 1.000000e+00, float 2.000000e+00, float 3.000000e+00], [3 x float] [float 2.000000e+00, float 3.000000e+00, float 4.000000e+00], [3 x float] [float 3.000000e+00, float 4.000000e+00, float 5.000000e+00]], align 16

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca [3 x i32], align 4
  %4 = alloca [3 x [3 x i32]], align 16
  %5 = alloca float, align 4
  %6 = alloca [3 x float], align 4
  %7 = alloca [3 x [3 x float]], align 16
  store i32 0, i32* %1, align 4
  store i32 1, i32* %2, align 4
  %8 = bitcast [3 x i32]* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %8, i8* align 4 bitcast ([3 x i32]* @__const.main.b to i8*), i64 12, i1 false)
  %9 = bitcast [3 x [3 x i32]]* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %9, i8* align 16 bitcast ([3 x [3 x i32]]* @__const.main.c to i8*), i64 36, i1 false)
  store float 1.000000e+00, float* %5, align 4
  %10 = bitcast [3 x float]* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %10, i8* align 4 bitcast ([3 x float]* @__const.main.e to i8*), i64 12, i1 false)
  %11 = bitcast [3 x [3 x float]]* %7 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %11, i8* align 16 bitcast ([3 x [3 x float]]* @__const.main.f to i8*), i64 36, i1 false)
  ret i32 0
}

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #1


